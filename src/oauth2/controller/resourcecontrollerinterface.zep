
/**
 *  This controller is called when a "resource" is requested.
 *  call verifyResourceRequest in order to determine if the request
 *  contains a valid token.
 *
 *  ex:
 *  > if (!$resourceController->verifyResourceRequest(OAuth2\Request::createFromGlobals(), $response = new OAuth2\Response())) {
 *  >     $response->send(); // authorization failed
 *  >     die();
 *  > }
 *  > return json_encode($resource); // valid token!  Send the stuff!
 *
 */

namespace OAuth2\Controller;

use OAuth2\RequestInterface;
use OAuth2\ResponseInterface;

interface ResourceControllerInterface
{
    /**
     * @param OAuth2\RequestInterface request - The current http request
     * @param OAuth2\ResponseInterface response- An instance of OAuth2\ResponseInterface to contain the response data
     * @param string scope
     * @return boolean
     */
    public function verifyResourceRequest(<RequestInterface> request, <ResponseInterface> response, string! scope = null) -> boolean;

    /**
     * @param OAuth2\RequestInterface request - The current http request
     * @param OAuth2\ResponseInterface response- An instance of OAuth2\ResponseInterface to contain the response data
     * @return string | null
     */
    public function getAccessTokenData(<RequestInterface> request, <ResponseInterface> response) -> string | null;
}
