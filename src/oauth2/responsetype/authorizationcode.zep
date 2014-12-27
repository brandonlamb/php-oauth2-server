
/**
 * @package \OAuth2\ResponseType
 * @author Brent Shaffer <bshafs at gmail dot com>
 */

namespace OAuth2\ResponseType;

use OAuth2\Storage\AuthorizationCodeInterface as AuthorizationCodeStorageInterface;

class AuthorizationCode implements AuthorizationCodeInterface
{
    protected storage;
    protected config;

    public function __construct(<AuthorizationCodeStorageInterface> storage, array config = [])
    {
        let this->storage = storage;
        let this->config = array_merge([
            "enforce_redirect"  : false,
            "auth_code_lifetime": 30
        ], config);
    }

    public function getAuthorizeResponse(var params, string user_id = null) -> array
    {
        var result;

        // build the URL to redirect to
        let result = ["query": []];

        let params = array_merge([
            "scope": null,
            "state": null
        ], params);

        let result["query"]["code"] = this->createAuthorizationCode(params["client_id"], user_id, params["redirect_uri"], params["scope"]);

        if isset params["state"] {
            let result["query"]["state"] = params["state"];
        }

        return [params["redirect_uri"], result];
    }

    /**
     * Handle the creation of the authorization code.
     *
     * @param string client_id Client identifier related to the authorization code
     * @param string user_id User ID associated with the authorization code
     * @param string redirect_uri An absolute URI to which the authorization server will redirect the
     * user-agent to when the end-user authorization step is completed.
     * @param string scope (optional) Scopes to be stored in space-separated string.
     * @return strin
     *
     * @see http://tools.ietf.org/html/rfc6749#section-4
     * @ingroup oauth2_section_4
     */
    public function createAuthorizationCode(string! client_id, string! user_id, string! redirect_uri, string! scope = null) -> string
    {
        var code;

        let code = this->generateAuthorizationCode();
        this->storage->setAuthorizationCode(code, client_id, user_id, redirect_uri, time() + this->config["auth_code_lifetime"], scope);

        return code;
    }

    /**
     * @return boolean  TRUE if the grant type requires a redirect_uri, FALSE if not
     */
    public function enforceRedirect() -> boolean
    {
        return this->config["enforce_redirect"];
    }

    /**
     * Generates an unique auth code.
     *
     * Implementing classes may want to override this function to implement
     * other auth code generation schemes.
     *
     * @return string An unique auth code.
     *
     * @ingroup oauth2_section_4
     */
    protected function generateAuthorizationCode() -> string
    {
        var randomData;
        int tokenLen;

        let tokenLen = 40;

        if function_exists("mcrypt_create_iv") {
            let randomData = mcrypt_create_iv(100, MCRYPT_DEV_URANDOM);
        } elseif (function_exists("openssl_random_pseudo_bytes")) {
            let randomData = openssl_random_pseudo_bytes(100);
        } elseif (file_exists("/dev/urandom")) {
            // Get 100 bytes of random data
            let randomData = file_get_contents("/dev/urandom", false, null, 0, 100) . uniqid(mt_rand(), true);
        } else {
            let randomData = mt_rand() . mt_rand() . mt_rand() . mt_rand() . microtime(true) . uniqid(mt_rand(), true);
        }

        return substr(hash("sha512", randomData), 0, tokenLen);
    }
}
