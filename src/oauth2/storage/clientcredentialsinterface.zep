
/**
 * Implement this interface to specify how the OAuth2 Server
 * should verify client credentials
 *
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
namespace OAuth2\Storage;

interface ClientCredentialsInterface extends ClientInterface
{
    /**
     * Make sure that the client credentials is valid.
     *
     * @param string client_id Client identifier to be check with.
     * @param string client_secret (optional) If a secret is required, check
     * that they've given the right one.
     *
     * @return bool
     * TRUE if the client credentials are valid, and MUST return FALSE if it isn't.
     * @endcode
     *
     * @see http://tools.ietf.org/html/rfc6749#section-3.1
     *
     * @ingroup oauth2_section_3
     */
    public function checkClientCredentials(string! client_id, string! client_secret = null) -> boolean;

    /**
     * Determine if the client is a "public" client, and therefore
     * does not require passing credentials for certain grant types
     *
     * @param string client_id Client identifier to be check with.
     *
     * @return boolean  TRUE if the client is public, and FALSE if it isn't.
     * @endcode
     *
     * @see http://tools.ietf.org/html/rfc6749#section-2.3
     * @see https://github.com/bshaffer/oauth2-server-php/issues/257
     *
     * @ingroup oauth2_section_2
     */
    public function isPublicClient(string! client_id) -> boolean;
}
