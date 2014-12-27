
namespace OAuth2\ResponseType;

interface ResponseTypeInterface
{
    public function getAuthorizeResponse(var params, string! user_id = null) -> array;
}
