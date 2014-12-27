
/**
* This is not yet supported!
*/

namespace OAuth2\TokenType;

use OAuth2\RequestInterface;
use OAuth2\ResponseInterface;

class Mac implements TokenTypeInterface
{
    public function getTokenType() -> string
    {
        return "mac";
    }

    public function getAccessTokenParameter(<RequestInterface> request, <ResponseInterface> response) -> string
    {
        throw new \LogicException("Not supported");
    }
}
