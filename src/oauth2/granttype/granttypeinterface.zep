
/**
 * Interface for all OAuth2 Grant Types
 */

namespace OAuth2\GrantType;

use OAuth2\ResponseType\AccessTokenInterface;
use OAuth2\RequestInterface;
use OAuth2\ResponseInterface;

interface GrantTypeInterface
{
    public function getQuerystringIdentifier() -> string;
    public function validateRequest(<RequestInterface> request, <ResponseInterface> response) -> boolean;
    public function getClientId() -> string | null;
    public function getUserId() -> string | null;
    public function getScope() -> string | null;
    public function createAccessToken(<AccessTokenInterface> accessToken, string! client_id, string! user_id, string! scope) -> string;
}
