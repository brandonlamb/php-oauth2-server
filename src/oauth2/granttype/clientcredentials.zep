
/**
 * @author Brent Shaffer <bshafs at gmail dot com>
 *
 * @see OAuth2\ClientAssertionType_HttpBasic
 */

namespace OAuth2\GrantType;

use OAuth2\ClientAssertionType\HttpBasic;
use OAuth2\ResponseType\AccessTokenInterface;
use OAuth2\Storage\ClientCredentialsInterface;

class ClientCredentials extends HttpBasic implements GrantTypeInterface
{
    private clientData;

    public function __construct(<ClientCredentialsInterface> storage, array config = [])
    {
        // The client credentials grant type MUST only be used by confidential clients
        // @see http://tools.ietf.org/html/rfc6749#section-4.4
        let config["allow_public_clients"] = false;

        parent::__construct(storage, config);
    }

    public function getQuerystringIdentifier() -> string
    {
        return "client_credentials";
    }

    public function getScope() -> string | null
    {
        this->loadClientData();
        return isset this->clientData["scope"] ? this->clientData["scope"] : null;
    }

    public function getUserId() -> string | null
    {
        this->loadClientData();
        return isset this->clientData["user_id"] ? this->clientData["user_id"] : null;
    }

    public function createAccessToken(<AccessTokenInterface> accessToken, string! client_id, string! user_id, string! scope) -> string
    {
        // Client Credentials Grant does NOT include a refresh token
        // @see http://tools.ietf.org/html/rfc6749#section-4.4.3
        boolean includeRefreshToken;
        let includeRefreshToken = false;

        return accessToken->createAccessToken(client_id, user_id, scope, includeRefreshToken);
    }

    private function loadClientData() -> void
    {
        if !this->clientData {
            let this->clientData = this->storage->getClientDetails(this->getClientId());
        }
    }
}
