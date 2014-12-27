
namespace OAuth2;

interface RequestInterface
{
    public function query(string! name, string $default = null) -> string;
    public function request(string! name, string $default = null) -> string;
    public function server(string! name, string $default = null) -> string;
    public function headers(string! name, string $default = null) -> string;
    public function getAllQueryParameters() -> array;
}
