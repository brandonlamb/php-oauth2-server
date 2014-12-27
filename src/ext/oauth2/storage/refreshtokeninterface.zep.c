
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Implement this interface to specify where the OAuth2 Server
 * should get/save refresh tokens for the "Refresh Token"
 * grant type
 *
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
ZEPHIR_INIT_CLASS(OAuth2_Storage_RefreshTokenInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\Storage, RefreshTokenInterface, oauth2, storage_refreshtokeninterface, oauth2_storage_refreshtokeninterface_method_entry);

	zend_class_implements(oauth2_storage_refreshtokeninterface_ce TSRMLS_CC, 1, oauth2_storage_storageinterface_ce);
	return SUCCESS;

}

/**
 * Grant refresh access tokens.
 *
 * Retrieve the stored data for the given refresh token.
 *
 * Required for OAuth2::GRANT_TYPE_REFRESH_TOKEN.
 *
 * @param string refresh_token Refresh token to be check with.
 *
 * @return array
 * An associative array as below, and NULL if the refresh_token is
 * invalid:
 * - refresh_token: Refresh token identifier.
 * - client_id: Client identifier.
 * - user_id: User identifier.
 * - expires: Expiration unix timestamp, or 0 if the token doesn't expire.
 * - scope: (optional) Scope values in space-separated string.
 *
 * @see http://tools.ietf.org/html/rfc6749#section-6
 *
 * @ingroup oauth2_section_6
 */
ZEPHIR_DOC_METHOD(OAuth2_Storage_RefreshTokenInterface, getRefreshToken);

/**
 * Take the provided refresh token values and store them somewhere.
 *
 * This function should be the storage counterpart to getRefreshToken().
 *
 * If storage fails for some reason, we're not currently checking for
 * any sort of success/failure, so you should bail out of the script
 * and provide a descriptive fail message.
 *
 * Required for OAuth2::GRANT_TYPE_REFRESH_TOKEN.
 *
 * @param string refresh_token Refresh token to be stored.
 * @param string client_id Client identifier to be stored.
 * @param string user_id User identifier to be stored.
 * @param int expires Expiration timestamp to be stored. 0 if the token doesn't expire.
 * @param string scope (optional) Scopes to be stored in space-separated string.
 *
 * @ingroup oauth2_section_6
 */
ZEPHIR_DOC_METHOD(OAuth2_Storage_RefreshTokenInterface, setRefreshToken);

/**
 * Expire a used refresh token.
 *
 * This is not explicitly required in the spec, but is almost implied.
 * After granting a new refresh token, the old one is no longer useful and
 * so should be forcibly expired in the data store so it can't be used again.
 *
 * If storage fails for some reason, we're not currently checking for
 * any sort of success/failure, so you should bail out of the script
 * and provide a descriptive fail message.
 *
 * @param string refresh_token Refresh token to be expirse.
 *
 * @ingroup oauth2_section_6
 */
ZEPHIR_DOC_METHOD(OAuth2_Storage_RefreshTokenInterface, unsetRefreshToken);

