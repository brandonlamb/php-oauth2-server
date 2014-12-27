
/**
 * Class to handle scope implementation logic
 *
 * @see OAuth2\Storage\ScopeInterface
 */

namespace OAuth2;

use OAuth2\Storage\ScopeInterface as ScopeStorageInterface;

interface ScopeInterface extends ScopeStorageInterface
{
    /**
     * Check if everything in required scope is contained in available scope.
     *
     * @param string required_scope A space-separated string of scopes.
     * @param string available_scope
     * @return boolean  TRUE if everything in required scope is contained in available scope,
     * and FALSE if it isn't.
     *
     * @see http://tools.ietf.org/html/rfc6749#section-7
     *
     * @ingroup oauth2_section_7
     */
    public function checkScope(string! required_scope, string! available_scope) -> boolean;

    /**
     * Return scope info from request
     *
     * @param \OAuth2\RequestInterface request Request object to check
     *
     * @return string representation of requested scope
     */
    public function getScopeFromRequest(<RequestInterface> request) -> string;
}
