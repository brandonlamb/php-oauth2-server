
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
 * should get/save access tokens
 *
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
ZEPHIR_INIT_CLASS(OAuth2_Storage_AccessTokenInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\Storage, AccessTokenInterface, oauth2, storage_accesstokeninterface, oauth2_storage_accesstokeninterface_method_entry);

	zend_class_implements(oauth2_storage_accesstokeninterface_ce TSRMLS_CC, 1, oauth2_storage_storageinterface_ce);
	return SUCCESS;

}

/**
 * Look up the supplied oauth_token from storage.
 *
 * We need to retrieve access token data as we create and verify tokens.
 *
 * @param string oauth_token oauth_token to be check with.
 *
 * @return array
 * An associative array as below, and return NULL if the supplied oauth_token
 * is invalid:
 * - expires: Stored expiration in unix timestamp.
 * - client_id: (optional) Stored client identifier.
 * - user_id: (optional) Stored user identifier.
 * - scope: (optional) Stored scope values in space-separated string.
 * - id_token: (optional) Stored id_token (if "use_openid_connect" is true).
 *
 * @ingroup oauth2_section_7
 */
ZEPHIR_DOC_METHOD(OAuth2_Storage_AccessTokenInterface, getAccessToken);

/**
 * Store the supplied access token values to storage.
 *
 * We need to store access token data as we create and verify tokens.
 *
 * @param string oauth_token oauth_token to be stored.
 * @param string client_id client identifier to be stored.
 * @param string user_id user identifier to be stored.
 * @param int expires expiration to be stored as a Unix timestamp.
 * @param string scope OPTIONAL Scopes to be stored in space-separated string.
 *
 * @ingroup oauth2_section_4
 */
ZEPHIR_DOC_METHOD(OAuth2_Storage_AccessTokenInterface, setAccessToken);

