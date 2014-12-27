
/**
 * @package \OAuth2\ResponseType
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
namespace OAuth2\ResponseType;

interface AuthorizationCodeInterface extends ResponseTypeInterface
{
    /**
     * @return boolean TRUE if the grant type requires a redirect_uri, FALSE if not
     */
    public function enforceRedirect() -> boolean;

    /**
     * Handle the creation of the authorization code.
     *
     * @param string client_id client identifier related to the authorization code
     * @param string user_id user id associated with the authorization code
     * @param string redirect_uri an absolute URI to which the authorization server will redirect the
     * user-agent to when the end-user authorization step is completed.
     * @param string scope OPTIONAL scopes to be stored in space-separated string.
     * @return string
     *
     * @see http://tools.ietf.org/html/rfc6749#section-4
     * @ingroup oauth2_section_4
     */
    public function createAuthorizationCode(string! client_id, string! user_id, string! redirect_uri, string! scope = null) -> string;
}
