
/**
 * @package \OAuth2\GrantType
 * @author Brent Shaffer <bshafs at gmail dot com>
 */

namespace OAuth2\GrantType;

use OAuth2\Storage\AuthorizationCodeInterface;
use OAuth2\ResponseType\AccessTokenInterface;
use OAuth2\RequestInterface;
use OAuth2\ResponseInterface;

class AuthorizationCode implements GrantTypeInterface
{
    protected storage;
    protected authCode;

    /**
     * @param OAuth2\Storage\AuthorizationCodeInterface storage REQUIRED Storage class for retrieving authorization code information
     */
    public function __construct(<AuthorizationCodeInterface> storage)
    {
        let this->storage = storage;
    }

    public function getQuerystringIdentifier() -> string
    {
        return "authorization_code";
    }

    public function validateRequest(<RequestInterface> request, <ResponseInterface> response) -> boolean
    {
        var code, authCode;

        if !request->request("code") {
            response->setError(400, "invalid_request", "Missing parameter: \"code\" is required");
            return false;
        }

        let code = request->request("code");
        let authCode = this->storage->getAuthorizationCode(code);

        if !authCode {
            response->setError(400, "invalid_grant", "Authorization code doesn't exist or is invalid for the client");
            return false;
        }

        // 4.1.3 - ensure that the "redirect_uri" parameter is present if the "redirect_uri" parameter was included in the initial authorization request
        // @uri - http://tools.ietf.org/html/rfc6749#section-4.1.3
        if isset authCode["redirect_uri"] && authCode["redirect_uri"] {
            if !request->request("redirect_uri") || urldecode(request->request("redirect_uri")) != authCode["redirect_uri"] {
                response->setError(400, "redirect_uri_mismatch", "The redirect URI is missing or do not match", "#section-4.1.3");
                return false;
            }
        }

        if !isset authCode["expires"] {
            throw new \Exception("Storage must return authcode with a value for \"expires\"");
        }

        if authCode["expires"] < time() {
            response->setError(400, "invalid_grant", "The authorization code has expired");
            return false;
        }

        if !isset authCode["code"] {
            // used to expire the code after the access token is granted
            let authCode["code"] = code;
        }

        let this->authCode = authCode;

        return true;
    }

    public function getClientId() -> string | null
    {
        return this->authCode["client_id"];
    }

    public function getScope() -> string | null
    {
        return isset this->authCode["scope"] ? this->authCode["scope"] : null;
    }

    public function getUserId() -> string | null
    {
        return isset this->authCode["user_id"] ? this->authCode["user_id"] : null;
    }

    public function createAccessToken(<AccessTokenInterface> accessToken, string! client_id, string! user_id, string! scope) -> string
    {
        var token;
        let token = accessToken->createAccessToken(client_id, user_id, scope);
        this->storage->expireAuthorizationCode(this->authCode["code"]);
        return token;
    }
}
