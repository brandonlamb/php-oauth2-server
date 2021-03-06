
/**
 * Implement this interface to specify where the OAuth2 Server
 * should retrieve user credentials for the
 * "Resource Owner Password Credentials" grant type
 *
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
namespace OAuth2\Storage;

interface UserCredentialsInterface extends StorageInterface
{
    /**
     * Grant access tokens for basic user credentials.
     *
     * Check the supplied username and password for validity.
     *
     * You can also use the $client_id param to do any checks required based
     * on a client, if you need that.
     *
     * Required for OAuth2::GRANT_TYPE_USER_CREDENTIALS.
     *
     * @param string username Username to be check with.
     * @param string password Password to be check with.
     *
     * @return bool TRUE if the username and password are valid, and FALSE if
     * it isn't. Moreover, if the username and password are valid, and you want to
     *
     * @see http://tools.ietf.org/html/rfc6749#section-4.3
     *
     * @ingroup oauth2_section_4
     */
    public function checkUserCredentials(string! username, string! password) -> boolean;

    /**
     * @param string username
     * @return array
     * ARRAY the associated "user_id" and optional "scope" values
     * This function MUST return FALSE if the requested user does not exist or is
     * invalid. "scope" is a space-separated list of restricted scopes.
     * @code
     * return array(
     *     "user_id"  => USER_ID,    // REQUIRED user_id to be stored with the authorization code or access token
     *     "scope"    => SCOPE       // OPTIONAL space-separated list of restricted scopes
     * );
     * @endcode
     */
    public function getUserDetails(string! username) -> array;
}
