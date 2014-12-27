
/**
 * Implement this interface to specify where the OAuth2 Server
 * should get public/private key information
 *
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
namespace OAuth2\Storage;

interface PublicKeyInterface extends StorageInterface
{
    public function getPublicKey(string! client_id = null) -> string;
    public function getPrivateKey(string! client_id = null) -> string;
    public function getEncryptionAlgorithm(string! client_id = null) -> string;
}
