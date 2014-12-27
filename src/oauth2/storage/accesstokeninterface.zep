
/**
 * Implement this interface to specify where the OAuth2 Server
 * should get/save access tokens
 *
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
namespace OAuth2\Storage;

interface AccessTokenInterface extends StorageInterface
{
    /**
     * Look up the supplied oauth_token from storage.
     *
     * We need to retrieve access token data as we create and verify tokens.
     *
     * @param string oauth_token oauth_token to be check with.
     *
     * @return array
     * An associative array as below, and return NULL if the supplied oauth_token
     * is invalid:
     * - expires: Stored expiration in unix timestamp.
     * - client_id: (optional) Stored client identifier.
     * - user_id: (optional) Stored user identifier.
     * - scope: (optional) Stored scope values in space-separated string.
     * - id_token: (optional) Stored id_token (if "use_openid_connect" is true).
     *
     * @ingroup oauth2_section_7
     */
    public function getAccessToken(string! oauth_token) -> array;

    /**
     * Store the supplied access token values to storage.
     *
     * We need to store access token data as we create and verify tokens.
     *
     * @param string oauth_token oauth_token to be stored.
     * @param string client_id client identifier to be stored.
     * @param string user_id user identifier to be stored.
     * @param int expires expiration to be stored as a Unix timestamp.
     * @param string scope OPTIONAL Scopes to be stored in space-separated string.
     *
     * @ingroup oauth2_section_4
     */
    public function setAccessToken(string! oauth_token, string! client_id, string! user_id, int expires, string! scope = null) -> void;
}
