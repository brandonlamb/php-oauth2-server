
namespace OAuth2\TokenType;

use OAuth2\RequestInterface;
use OAuth2\ResponseInterface;

interface TokenTypeInterface
{
    /**
     * Token type identification string
     *
     * ex: "bearer" or "mac"
     * @return string
     */
    public function getTokenType() -> string;

    /**
     * Retrieves the token string from the request object
     * @return string
     */
    public function getAccessTokenParameter(<RequestInterface> request, <ResponseInterface> response) -> string;
}
