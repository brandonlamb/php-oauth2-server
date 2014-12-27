/**
 *  This controller is called when a token is being requested.
 *  it is called to handle all grant types the application supports.
 *  It also validates the client's credentials
 *
 *  ex:
 *  > $tokenController->handleTokenRequest(OAuth2\Request::createFromGlobals(), $response = new OAuth2\Response());
 *  > $response->send();
 *
 */

namespace OAuth2\Controller;

use OAuth2\RequestInterface;
use OAuth2\ResponseInterface;

interface TokenControllerInterface
{
    /**
     * handleTokenRequest
     *
     * @param OAuth2\RequestInterface request - The current http request
     * @param OAuth2\ResponseInterface response- An instance of OAuth2\ResponseInterface to contain the response data
     */
    public function handleTokenRequest(<RequestInterface> request, <ResponseInterface> response) -> void;

    /**
     * grantAccessToken
     *
     * @param OAuth2\RequestInterface request - The current http request
     * @param OAuth2\ResponseInterface response- An instance of OAuth2\ResponseInterface to contain the response data
     */
    public function grantAccessToken(<RequestInterface> request, <ResponseInterface> response) -> void;
}
