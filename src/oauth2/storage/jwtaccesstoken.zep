
/**
 * JWT Access token
 * @author Brent Shaffer <bshafs at gmail dot com>
 */

namespace OAuth2\Storage;

use OAuth2\Encryption\EncryptionInterface;
use OAuth2\Encryption\Jwt;

class JwtAccessToken implements JwtAccessTokenInterface
{
    protected publicKeyStorage;
    protected tokenStorage;
    protected encryptionUtil;

    /**
     * @param OAuth2\Encryption\PublicKeyInterface publicKeyStorage the public key encryption to use
     * @param OAuth2\Storage\AccessTokenInterfacetokenStorage OPTIONAL persist the access token to another storage. This is useful if
     * you want to retain access token grant information somewhere, but
     * is not necessary when using this grant type.
     * @param OAuth2\Encryption\EncryptionInterface encryptionUtil   OPTIONAL class to use for "encode" and "decode" functions.
     */
    public function __construct(<PublicKeyInterface> publicKeyStorage, <AccessTokenInterface> tokenStorage = null, <EncryptionInterface> encryptionUtil = null)
    {
        let this->publicKeyStorage = $publicKeyStorage;
        let this->tokenStorage = $tokenStorage;

        if typeof encryptionUtil == "null" {
            let encryptionUtil = new Jwt;
        }
        let this->encryptionUtil = encryptionUtil;
    }

    public function getAccessToken(string! oauth_token) -> boolean | array
    {
        var tokenData, client_id, public_key, algorithm;

        // just decode the token, don"t verify
        let tokenData = this->encryptionUtil->decode(oauth_token, null, false);
        if !tokenData {
            return false;
        }

        let client_id  = isset tokenData["aud"] ? tokenData["aud"] : null;
        let public_key = this->publicKeyStorage->getPublicKey(client_id);
        let algorithm  = this->publicKeyStorage->getEncryptionAlgorithm(client_id);

        // now that we have the client_id, verify the token
        if this->encryptionUtil->decode(oauth_token, public_key, true) === false {
            return false;
        }

        // normalize the JWT claims to the format expected by other components in this library
        return this->convertJwtToOAuth2(tokenData);
    }

    public function setAccessToken(string! oauth_token, string! client_id, string! user_id, int expires, string! scope = null) -> void
    {
        if this->tokenStorage {
            this->tokenStorage->setAccessToken(oauth_token, client_id, user_id, expires, scope);
        }
    }

    // converts a JWT access token into an OAuth2-friendly format
    protected function convertJwtToOAuth2(array tokenData) -> array
    {
        var keyMapping, jwtKey, oauth2Key;

        let keyMapping = [
            "aud": "client_id",
            "exp": "expires",
            "sub": "user_id"
        ];

        for jwtKey, oauth2Key in keyMapping {
            if isset tokenData[jwtKey] {
                let tokenData[oauth2Key] = tokenData[jwtKey];
                unset tokenData[jwtKey];
            }
        }

        return tokenData;
    }
}
