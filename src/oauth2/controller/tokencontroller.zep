/**
 * @see OAuth2\Controller\TokenControllerInterface
 */

namespace OAuth2\Controller;

use OAuth2\ResponseType\AccessTokenInterface;
use OAuth2\ClientAssertionType\ClientAssertionTypeInterface;
use OAuth2\GrantType\GrantTypeInterface;
use OAuth2\ScopeInterface;
use OAuth2\Scope;
use OAuth2\Storage\ClientInterface;
use OAuth2\RequestInterface;
use OAuth2\ResponseInterface;

class TokenController implements TokenControllerInterface
{
    protected accessToken;
    protected grantTypes;
    protected clientAssertionType;
    protected scopeUtil;
    protected clientStorage;

    public function __construct(<AccessTokenInterface> accessToken, <ClientInterface> clientStorage, array grantTypes = [], <ClientAssertionTypeInterface> clientAssertionType = null, <ScopeInterface> scopeUtil = null)
    {
        var grantType;

        if typeof clientAssertionType == "null" {
            for grantType in grantTypes {
                if !(grantType instanceof ClientAssertionTypeInterface) {
                    throw new \InvalidArgumentException("You must supply an instance of OAuth2\\ClientAssertionType\\ClientAssertionTypeInterface or only use grant types which implement OAuth2\\ClientAssertionType\\ClientAssertionTypeInterface");
                }
            }
        }

        let this->clientAssertionType = clientAssertionType;
        let this->accessToken = accessToken;
        let this->clientStorage = clientStorage;

        for grantType in grantTypes {
            this->addGrantType(grantType);
        }

        if typeof scopeUtil == "null" {
            throw new \LogicException("Must pass a scope to " . __METHOD__);
            //let scopeUtil = new Scope();
        }

        let this->scopeUtil = scopeUtil;
    }

    public function handleTokenRequest(<RequestInterface> request, <ResponseInterface> response) -> void
    {
        var token;

        let token = this->grantAccessToken(request, response);
        if token {
            // @see http://tools.ietf.org/html/rfc6749#section-5.1
            // server MUST disable caching in headers when tokens are involved
            response->setStatusCode(200);
            response->addParameters(token);
            response->addHttpHeaders(["Cache-Control": "no-store", "Pragma": "no-cache"]);
        }
    }

    /**
     * Grant or deny a requested access token.
     * This would be called from the "/token" endpoint as defined in the spec.
     * You can call your endpoint whatever you want.
     *
     * @param RequestInterface request Request object to grant access token
     * @param ResponseInterface response
     *
     * @throws InvalidArgumentException
     * @throws LogicException
     *
     * @see http://tools.ietf.org/html/rfc6749#section-4
     * @see http://tools.ietf.org/html/rfc6749#section-10.6
     * @see http://tools.ietf.org/html/rfc6749#section-4.1.3
     *
     * @ingroup oauth2_section_4
     */
    public function grantAccessToken(<RequestInterface> request, <ResponseInterface> response) -> null | string
    {
        var grantTypeIdentifier, grantType, clientId, storedClientId,
            requestedScope, availableScope, clientScope, defaultScope;

        if strtolower(request->server("REQUEST_METHOD")) != "post" {
            response->setError(405, "invalid_request", "The request method must be POST when requesting an access token", "#section-3.2");
            response->addHttpHeaders(["Allow": "POST"]);
            return null;
        }

        // Determine grant type from request and validate the request for that grant type
        let grantTypeIdentifier = request->request("grant_type");
        if !grantTypeIdentifier {
            response->setError(400, "invalid_request", "The grant type was not specified in the request");
            return null;
        }

        if !isset this->grantTypes[grantTypeIdentifier] {
            // TODO: If this is an OAuth2 supported grant type that we have chosen
            // not to implement, throw a 501 Not Implemented instead
            response->setError(400, "unsupported_grant_type", sprintf("Grant type \"%s\" not supported", grantTypeIdentifier));
            return null;
        }

        let grantType = this->grantTypes[grantTypeIdentifier];

        // Retrieve the client information from the request ClientAssertionTypes
        // allow for grant types which also assert the client data in which case
        // ClientAssertion is handled in the validateRequest method
        // @see OAuth2\GrantType\JWTBearer
        // @see OAuth2\GrantType\ClientCredentials
        if !(grantType instanceof ClientAssertionTypeInterface) {
            if !this->clientAssertionType->validateRequest(request, response) {
                return null;
            }
            let clientId = this->clientAssertionType->getClientId();
        }

        // Retrieve the grant type information from the request The
        // GrantTypeInterface object handles all validation. If the object is an
        // instance of ClientAssertionTypeInterface, That logic is handled here as well
        if !grantType->validateRequest(request, response) {
            return null;
        }

        if (grantType instanceof ClientAssertionTypeInterface) {
            let clientId = grantType->getClientId();
        } else {
            // validate the Client ID (if applicable)
            let storedClientId = grantType->getClientId();
            if typeof storedClientId != "null" && storedClientId != clientId {
                response->setError(400, "invalid_grant", sprintf("%s doesn't exist or is invalid for the client", grantTypeIdentifier));
                return null;
            }
        }

        // Validate the client can use the requested grant type
        if !this->clientStorage->checkRestrictedGrantType(clientId, grantTypeIdentifier) {
            response->setError(400, "unauthorized_client", "The grant type is unauthorized for this client_id");
            return null;
        }

        /**
         * Validate the scope of the token
         *
         * requestedScope - the scope specified in the token request
         * availableScope - the scope associated with the grant type
         *  ex: in the case of the "Authorization Code" grant type,
         *  the scope is specified in the authorize request
         *
         * @see http://tools.ietf.org/html/rfc6749#section-3.3
         */

        let requestedScope = this->scopeUtil->getScopeFromRequest(request);
        let availableScope = grantType->getScope();

        if requestedScope {
            // validate the requested scope
            if availableScope {
                if !this->scopeUtil->checkScope(requestedScope, availableScope) {
                    response->setError(400, "invalid_scope", "The scope requested is invalid for this request");
                    return null;
                }
            } else {
                // validate the client has access to this scope
                let clientScope = this->clientStorage->getClientScope(clientId);
                if clientScope {
                    if !this->scopeUtil->checkScope(requestedScope, clientScope) {
                        response->setError(400, "invalid_scope", "The scope requested is invalid for this client");
                        return null;
                    }
                } elseif !this->scopeUtil->scopeExists(requestedScope) {
                    response->setError(400, "invalid_scope", "An unsupported scope was requested");
                    return null;
                }
            }
        } elseif availableScope {
            // use the scope associated with this grant type
            let requestedScope = availableScope;
        } else {
            // use a globally-defined default scope
            let defaultScope = this->scopeUtil->getDefaultScope(clientId);

            // "false" means default scopes are not allowed
            if defaultScope === false {
                response->setError(400, "invalid_scope", "This application requires you specify a scope parameter");
                return null;
            }

            let requestedScope = $defaultScope;
        }

        return grantType->createAccessToken(this->accessToken, clientId, grantType->getUserId(), requestedScope);
    }

    /**
     * addGrantType
     *
     * @param grantType - OAuth2\GrantTypeInterface
     * the grant type to add for the specified identifier
     * @param identifier - string
     * a string passed in as "grant_type" in the response that will call this grantType
     */
    public function addGrantType(<GrantTypeInterface> grantType, var identifier = null) -> void
    {
        if typeof identifier == "null" || is_numeric(identifier) {
            let identifier = grantType->getQuerystringIdentifier();
        }

        let this->grantTypes[identifier] = grantType;
    }
}
