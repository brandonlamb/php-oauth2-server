
/**
 * @package \OAuth2\ResponseType
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
namespace OAuth2\ResponseType;

interface AccessTokenInterface extends ResponseTypeInterface
{
    /**
     * Handle the creation of access token, also issue refresh token if supported / desirable.
     *
     * @param string client_id client identifier related to the access token.
     * @param string user_id user ID associated with the access token
     * @param string scope OPTONAL scopes to be stored in space-separated string.
     * @param bool includeRefreshToken if true, a new refresh_token will be added to the response
     * @return string
     * @see http://tools.ietf.org/html/rfc6749#section-5
     * @ingroup oauth2_section_5
     */
    public function createAccessToken(string! client_id, string! user_id, string! scope = null, boolean includeRefreshToken = true) -> string;
}
