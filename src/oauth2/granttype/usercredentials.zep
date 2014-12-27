
/**
 * @package \OAuth2\GrantType
 * @author Brent Shaffer <bshafs at gmail dot com>
 */

namespace OAuth2\GrantType;

use OAuth2\Storage\UserCredentialsInterface;
use OAuth2\ResponseType\AccessTokenInterface;
use OAuth2\RequestInterface;
use OAuth2\ResponseInterface;

class UserCredentials implements GrantTypeInterface
{
    private userInfo;
    protected storage;

    /**
     * Constructor
     *
     * @param OAuth2\Storage\UserCredentialsInterface $storage REQUIRED Storage class for retrieving user credentials information
     */
    public function __construct(<UserCredentialsInterface> storage)
    {
        let this->storage = storage;
    }

    public function getQuerystringIdentifier() -> string
    {
        return "password";
    }

    public function validateRequest(<RequestInterface> request, <ResponseInterface> response) -> boolean
    {
        var userInfo;

        if !request->request("password") || !request->request("username") {
            response->setError(400, "invalid_request", "Missing parameters: \"username\" and \"password\" required");
            return false;
        }

        if !this->storage->checkUserCredentials(request->request("username"), request->request("password")) {
            response->setError(401, "invalid_grant", "Invalid username and password combination");
            return false;
        }

        let userInfo = this->storage->getUserDetails(request->request("username"));

        if empty userInfo {
            response->setError(400, "invalid_grant", "Unable to retrieve user information");
            return false;
        }

        if !isset userInfo["user_id"] {
            throw new \LogicException("you must set the user_id on the array returned by getUserDetails");
        }

        let this->userInfo = userInfo;

        return true;
    }

    public function getClientId() -> string | null
    {
        return null;
    }

    public function getUserId() -> string | null
    {
        return this->userInfo["user_id"];
    }

    public function getScope() -> string | null
    {
        return isset this->userInfo["scope"] ? this->userInfo["scope"] : null;
    }

    public function createAccessToken(<AccessTokenInterface> accessToken, string! client_id, string! user_id, string! scope) -> string
    {
        return accessToken->createAccessToken(client_id, user_id, scope);
    }
}
