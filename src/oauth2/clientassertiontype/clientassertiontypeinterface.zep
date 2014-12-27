
/**
 * Interface for all OAuth2 Client Assertion Types
 */

namespace OAuth2\ClientAssertionType;

use OAuth2\RequestInterface;
use OAuth2\ResponseInterface;

interface ClientAssertionTypeInterface
{
    public function validateRequest(<RequestInterface> request, <ResponseInterface> response) -> boolean;
    public function getClientId() -> string;
}
