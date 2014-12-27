
/**
 * Validate a client via Http Basic authentication
 *
 * @author Brent Shaffer <bshafs at gmail dot com>
 */

namespace OAuth2\ClientAssertionType;

use OAuth2\Storage\ClientCredentialsInterface;
use OAuth2\RequestInterface;
use OAuth2\ResponseInterface;

class HttpBasic implements ClientAssertionTypeInterface
{
    private clientData;
    protected storage;
    protected config;

    /**
     * @param \OAuth2\Storage\ClientCredentialsInterface clientStorage
     * REQUIRED Storage class for retrieving client credentials information
     * @param array config OPTIONAL Configuration options for the server
     * <code>
     * $config = array(
     * "allow_credentials_in_request_body" => true, // whether to look for credentials in the POST body in addition to the Authorize HTTP Header
     * "allow_public_clients"  => true // if true, "public clients" (clients without a secret) may be authenticated
     * );
     * </code>
     */
    public function __construct(<ClientCredentialsInterface> storage, array config = [])
    {
        let this->storage = storage;
        let this->config = array_merge([
            "allow_credentials_in_request_body": true,
            "allow_public_clients": true
        ], config);
    }

    public function validateRequest(<RequestInterface> request, <ResponseInterface> response) -> boolean
    {
        var clientData;

        let clientData = this->getClientCredentials(request, response);
        if !clientData {
            return false;
        }

        if !isset clientData["client_id"] {
            throw new \LogicException("The clientData array must have \"client_id\" set");
        }

        //if !isset clientData["client_secret"] || clientData["client_secret"] == "" {
        if empty clientData["client_secret"] {
            if !isset this->config["allow_public_clients"] {
                response->setError(400, "invalid_client", "client credentials are required");
                return false;
            }

            if !this->storage->isPublicClient(clientData["client_id"]) {
                response->setError(400, "invalid_client", "This client is invalid or must authenticate using a client secret");
                return false;
            }
        } else {
            if this->storage->checkClientCredentials(clientData["client_id"], clientData["client_secret"]) === false {
                response->setError(400, "invalid_client", "The client credentials are invalid");
                return false;
            }
        }

        let this->clientData = clientData;

        return true;
    }

    public function getClientId() -> string
    {
        return this->clientData["client_id"];
    }

    /**
     * Internal function used to get the client credentials from HTTP basic
     * auth or POST data.
     *
     * According to the spec (draft 20), the client_id can be provided in
     * the Basic Authorization header (recommended) or via GET/POST.
     *
     * @return array
     * A list containing the client identifier and password, for example
     * @code
     * return array(
     *     "client_id"     => CLIENT_ID,        // REQUIRED the client id
     *     "client_secret" => CLIENT_SECRET,    // OPTIONAL the client secret (may be omitted for public clients)
     * );
     * @endcode
     *
     * @see http://tools.ietf.org/html/rfc6749#section-2.3.1
     *
     * @ingroup oauth2_section_2
     */
    public function getClientCredentials(<RequestInterface> request, <ResponseInterface> response = null) -> array | null
    {
        var message;

        if typeof request->headers("PHP_AUTH_USER") !== "null" && typeof request->headers("PHP_AUTH_PW") !== "null" {
            return [
                "client_id": request->headers("PHP_AUTH_USER"),
                "client_secret": request->headers("PHP_AUTH_PW")
            ];
        }

        if isset this->config["allow_credentials_in_request_body"] {
            // Using POST for HttpBasic authorization is not recommended, but is supported by specification
            if typeof $request->request("client_id") !== "null" {
                // client_secret can be null if the client"s password is an empty string
                // @see http://tools.ietf.org/html/rfc6749#section-2.3.1
                return [
                    "client_id": request->request("client_id"),
                    "client_secret": request->request("client_secret")
                ];
            }
        }

        if response {
            let message = isset this->config["allow_credentials_in_request_body"] ? " or body" : "";
            response->setError(400, "invalid_client", "Client credentials were not found in the headers".$message);
        }

        return null;
    }
}
