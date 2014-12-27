
namespace OAuth2\Encryption;

interface EncryptionInterface
{
    public function encode(string! payload, string! key, string! algorithm = null) -> string;
    public function decode(string! payload, string! key, string! algorithm = null);
    public function urlSafeB64Encode(string! data);
    public function urlSafeB64Decode(string! b64);
}
