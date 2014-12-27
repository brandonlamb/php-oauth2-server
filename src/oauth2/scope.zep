
/**
* @see OAuth2\ScopeInterface
*/

namespace OAuth2;

use OAuth2\Storage\ScopeInterface as ScopeStorageInterface;

class Scope implements ScopeInterface
{
    protected storage;

    /**
     * @param mixed storage
     * Either an array of supported scopes, or an instance of OAuth2\Storage\ScopeInterface
     */
    public function __construct(<ScopeStorageInterface> storage)
    {
        if typeof storage != "object" {
            throw new \InvalidArgumentException("Argument 1 to OAuth2\\Scope must be null, an array, or instance of OAuth2\\Storage\\ScopeInterface");
        }

        if !(storage instanceof ScopeStorageInterface) {
            throw new \InvalidArgumentException("Argument 1 to OAuth2\\Scope must be null, an array, or instance of OAuth2\\Storage\\ScopeInterface");
        }

        let this->storage = storage;
    }

    /**
     * Check if everything in required scope is contained in available scope.
     *
     * @param string required_scope A space-separated string of scopes.
     *
     * @return boolean  TRUE if everything in required scope is contained in available scope,
     * and FALSE if it isn't.
     *
     * @see http://tools.ietf.org/html/rfc6749#section-7
     *
     * @ingroup oauth2_section_7
     */
    public function checkScope(string! required_scope, string! available_scope) -> boolean
    {
        var scope1, scope2;
        let scope1 = explode(" ", trim(required_scope));
        let scope2 = explode(" ", trim(available_scope));
        return count(array_diff(scope1, scope2)) == 0;
    }

    /**
     * Check if the provided scope exists in storage.
     *
     * @param string! scope A space-separated string of scopes.
     *
     * @return boolean TRUE if it exists, FALSE otherwise.
     */
    public function scopeExists(string! scope) -> boolean
    {
        var scopes, reservedScope, nonReservedScopes;

        // Check reserved scopes first.
        let scopes = explode(" ", trim(scope));
        let reservedScope = this->getReservedScopes();
        let nonReservedScopes = array_diff(scopes, reservedScope);

        if count(nonReservedScopes) == 0 {
            return true;
        };

        // Check the storage for non-reserved scopes.
        let nonReservedScopes = implode(" ", nonReservedScopes);

        return this->storage->scopeExists(nonReservedScopes);
    }

    public function getScopeFromRequest(<RequestInterface> request) -> string
    {
        // "scope" is valid if passed in either POST or QUERY
        return request->request("scope", request->query("scope"));
    }

    public function getDefaultScope(string! client_id = null) -> string
    {
        return this->storage->getDefaultScope(client_id);
    }

    /**
     * Get reserved scopes needed by the server.
     *
     * In case OpenID Connect is used, these scopes must include:
     * 'openid', offline_access'.
     *
     * @return
     * An array of reserved scopes.
     */
    public function getReservedScopes()
    {
        return ["openid", "offline_access"];
    }
}
