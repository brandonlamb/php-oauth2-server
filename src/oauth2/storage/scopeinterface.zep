
/**
 * Implement this interface to specify where the OAuth2 Server
 * should retrieve data involving the relevent scopes associated
 * with this implementation.
 *
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
namespace OAuth2\Storage;

interface ScopeInterface extends StorageInterface
{
    /**
     * Check if the provided scope exists.
     *
     * @param stirng scope A space-separated string of scopes.
     *
     * @return boolean TRUE if it exists, FALSE otherwise.
     */
    public function scopeExists(string! scope) -> boolean;

    /**
     * The default scope to use in the event the client
     * does not request one. By returning "false", a
     * request_error is returned by the server to force a
     * scope request by the client. By returning "null",
     * opt out of requiring scopes
     *
     * @param string client_id An optional client id that can be used to
     * return customized default scopes.
     *
     * @return string - string representation of default scope, null if
     * scopes are not defined, or false to force scope request by the client
     *
     * ex:
     *     'default'
     * ex:
     *     null
     */
    public function getDefaultScope(string! client_id = null) -> string;
}
