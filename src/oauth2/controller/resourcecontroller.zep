
/**
 * @see OAuth2\Controller\ResourceControllerInterface
 */

namespace OAuth2\Controller;

use OAuth2\TokenType\TokenTypeInterface;
use OAuth2\Storage\AccessTokenInterface;
use OAuth2\ScopeInterface;
use OAuth2\RequestInterface;
use OAuth2\ResponseInterface;
use OAuth2\Scope;

class ResourceController implements ResourceControllerInterface
{
    private token;
    protected tokenType;
    protected tokenStorage;
    protected config;
    protected scopeUtil;

    public function __construct(<TokenTypeInterface> tokenType, <AccessTokenInterface> tokenStorage, array config = [], <ScopeInterface> scopeUtil = null)
    {
        let this->tokenType = tokenType;
        let this->tokenStorage = tokenStorage;

        let this->config = array_merge([
            "www_realm": "Service"
        ], config);

        if typeof scopeUtil == "null" {
            throw new \LogicException("Must pass a scope to " . __METHOD__);
            //scopeUtil = new Scope();
        }

        let this->scopeUtil = scopeUtil;
    }

    public function verifyResourceRequest(<RequestInterface> request, <ResponseInterface> response, string! scope = null) -> boolean
    {
        var token;

        let token = this->getAccessTokenData(request, response);

        // Check if we have token data
        if typeof token == "null" {
            return false;
        }

        // Check scope, if provided If token doesn"t have a scope, it"s
        // null/empty, or it"s insufficient, then throw 403
        // @see http://tools.ietf.org/html/rfc6750#section-3.1
        if scope && (!isset token["scope"] || !token["scope"] || !this->scopeUtil->checkScope(scope, token["scope"])) {
            response->setError(403, "insufficient_scope", "The request requires higher privileges than provided by the access token");
            response->addHttpHeaders([
                "WWW-Authenticate": sprintf(
                    "%s realm=\"%s\", scope=\"%s\", error=\"%s\", error_description=\"%s\"",
                    this->tokenType->getTokenType(),
                    this->config["www_realm"],
                    scope,
                    response->getParameter("error"),
                    response->getParameter("error_description")
                )
            ]);

            return false;
        }

        // allow retrieval of the token
        let this->token = token;

        return (bool) token;
    }

    public function getAccessTokenData(<RequestInterface> request, <ResponseInterface> response) -> array | null
    {
        var token_param, token, authHeader, error, error_description;

        // Get the token parameter
        let token_param = this->tokenType->getAccessTokenParameter(request, response);
        if token_param {
            // Get the stored token data (from the implementing subclass)
            // Check we have a well formed token
            // Check token expiration (expires is a mandatory paramter)
            let token = this->tokenStorage->getAccessToken(token_param);

            if !token {
                response->setError(401, "invalid_token", "The access token provided is invalid");
            } elseif (!isset token["expires"] || !isset token["client_id"]) {
                response->setError(401, "malformed_token", "Malformed token (missing \"expires\")");
            } elseif (isset token["expires"] && time() > token["expires"]) {
                response->setError(401, "expired_token", "The access token provided has expired");
            } else {
                return token;
            }
        }

        let authHeader = sprintf(
            "%s realm=\"%s\"",
            this->tokenType->getTokenType(),
            this->config["www_realm"]
        );

        let error = response->getParameter("error");
        if error {
            let authHeader = sprintf(
                "%s, error=\"%s\"",
                authHeader,
                error
            );

            let error_description = response->getParameter("error_description");
            if error_description {
                let authHeader = sprintf(
                    "%s, error_description=\"%s\"",
                    authHeader,
                    error_description
                );
            }
        }

        response->addHttpHeaders(["WWW-Authenticate": authHeader]);

        return null;
    }

    // convenience method to allow retrieval of the token
    public function getToken() -> array
    {
        return this->token;
    }
}
