
/**
 * Interface which represents an object response.  Meant to handle and display the proper OAuth2 Responses
 * for errors and successes
 *
 * @see OAuth2\Response
 */
namespace OAuth2;

interface ResponseInterface
{
    public function addParameters(array parameters) -> void;
    public function addHttpHeaders(array httpHeaders) -> void;
    public function setStatusCode(int statusCode) -> void;
    public function setError(int statusCode, string! name, string! description = null, string! uri = null) -> void;
    public function setRedirect(int statusCode, string! url, string! state = null, string! error = null, string! errorDescription = null, string! errorUri = null) -> void;
    public function getParameter(string! name, string! $default = null) -> string;
}
