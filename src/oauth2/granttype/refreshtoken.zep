
/**
 * @package \OAuth2\GrantType
 * @author Brent Shaffer <bshafs at gmail dot com>
 */

namespace OAuth2\GrantType;

use OAuth2\Storage\RefreshTokenInterface;
use OAuth2\ResponseType\AccessTokenInterface;
use OAuth2\RequestInterface;
use OAuth2\ResponseInterface;

class RefreshToken implements GrantTypeInterface
{
    private refreshToken;
    protected storage;
    protected config;

    /**
     * @param OAuth2\Storage\RefreshTokenInterface storage REQUIRED Storage class for retrieving refresh token information
     * @param array config  OPTIONAL Configuration options for the server
     * <code>
     * $config = array(
     * "always_issue_new_refresh_token": true, // whether to issue a new refresh token upon successful token request
     * );
     * </code>
     */
    public function __construct(<RefreshTokenInterface> storage, array config = [])
    {
        let this->storage = storage;
        let this->config = array_merge([
            "always_issue_new_refresh_token": false
        ], config);
    }

    public function getQuerystringIdentifier() -> string
    {
        return "refresh_token";
    }

    public function validateRequest(<RequestInterface> request, <ResponseInterface> response) -> boolean
    {
        var refreshToken;

        if !request->request("refresh_token") {
            response->setError(400, "invalid_request", "Missing parameter: \"refresh_token\" is required");
            return false;
        }

        let refreshToken = this->storage->getRefreshToken(request->request("refresh_token"));
        if !refreshToken {
            response->setError(400, "invalid_grant", "Invalid refresh token");
            return false;
        }

        if refreshToken["expires"] > 0 && refreshToken["expires"] < time() {
            response->setError(400, "invalid_grant", "Refresh token has expired");
            return false;
        }

        // store the refresh token locally so we can delete it when a new refresh token is generated
        let this->refreshToken = refreshToken;

        return true;
    }

    public function getClientId() -> string | null
    {
        return this->refreshToken["client_id"];
    }

    public function getUserId() -> string | null
    {
        return isset this->refreshToken["user_id"] ? this->refreshToken["user_id"] : null;
    }

    public function getScope() -> string | null
    {
        return isset this->refreshToken["scope"] ? this->refreshToken["scope"] : null;
    }

    public function createAccessToken(<AccessTokenInterface> accessToken, string! client_id, string! user_id, string! scope) -> string
    {
        var issueNewRefreshToken, token;

        // It is optional to force a new refresh token when a refresh token is used.
        // However, if a new refresh token is issued, the old one MUST be expired
        // @see http://tools.ietf.org/html/rfc6749#section-6
        let issueNewRefreshToken = this->config["always_issue_new_refresh_token"];
        let token = accessToken->createAccessToken(client_id, user_id, scope, issueNewRefreshToken);

        if issueNewRefreshToken {
            this->storage->unsetRefreshToken(this->refreshToken["refresh_token"]);
        }

        return token;
    }
}
