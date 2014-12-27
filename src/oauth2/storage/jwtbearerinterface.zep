
/**
 * Implement this interface to specify where the OAuth2 Server
 * should get the JWT key for clients
 *
 * @TODO consider extending ClientInterface, as this will almost always
 * be the same storage as retrieving clientData
 *
 * @author F21
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
namespace OAuth2\Storage;

interface JwtBearerInterface extends StorageInterface
{
    /**
     * Get the public key associated with a client_id
     *
     * @param string client_id Client identifier to be checked with.
     *
     * @return string Return the public key for the client_id if it exists, and MUST return FALSE if it doesn't.
     */
    public function getClientKey(string! client_id, string! subject) -> string;

    /**
     * Get a jti (JSON token identifier) by matching against the client_id, subject, audience and expiration.
     *
     * @param string client_id Client identifier to match.
     * @param string subject The subject to match.
     * @param string audience The audience to match.
     * @param int expiration The expiration of the jti.
     * @param string jti The jti to match.
     *
     * @return array
     * An associative array as below, and return NULL if the jti does not exist.
     * - issuer: Stored client identifier.
     * - subject: Stored subject.
     * - audience: Stored audience.
     * - expires: Stored expiration in unix timestamp.
     * - jti: The stored jti.
     */
    public function getJti(string! client_id, string! subject, string! audience, int expiration, string! jti) -> array;

    /**
     * Store a used jti so that we can check against it to prevent replay attacks.
     *
     * @param string client_id Client identifier to insert.
     * @param string subject The subject to insert.
     * @param string audience The audience to insert.
     * @param int expiration The expiration of the jti.
     * @param string jti The jti to insert.
     */
    public function setJti(string! client_id, string! subject, string! audience, int expiration, string! jti) -> void;
}
