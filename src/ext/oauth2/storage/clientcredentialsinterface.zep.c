
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Implement this interface to specify how the OAuth2 Server
 * should verify client credentials
 *
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
ZEPHIR_INIT_CLASS(OAuth2_Storage_ClientCredentialsInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\Storage, ClientCredentialsInterface, oauth2, storage_clientcredentialsinterface, oauth2_storage_clientcredentialsinterface_method_entry);

	zend_class_implements(oauth2_storage_clientcredentialsinterface_ce TSRMLS_CC, 1, oauth2_storage_clientinterface_ce);
	return SUCCESS;

}

/**
 * Make sure that the client credentials is valid.
 *
 * @param string client_id Client identifier to be check with.
 * @param string client_secret (optional) If a secret is required, check
 * that they've given the right one.
 *
 * @return bool
 * TRUE if the client credentials are valid, and MUST return FALSE if it isn't.
 * @endcode
 *
 * @see http://tools.ietf.org/html/rfc6749#section-3.1
 *
 * @ingroup oauth2_section_3
 */
ZEPHIR_DOC_METHOD(OAuth2_Storage_ClientCredentialsInterface, checkClientCredentials);

/**
 * Determine if the client is a "public" client, and therefore
 * does not require passing credentials for certain grant types
 *
 * @param string client_id Client identifier to be check with.
 *
 * @return boolean  TRUE if the client is public, and FALSE if it isn't.
 * @endcode
 *
 * @see http://tools.ietf.org/html/rfc6749#section-2.3
 * @see https://github.com/bshaffer/oauth2-server-php/issues/257
 *
 * @ingroup oauth2_section_2
 */
ZEPHIR_DOC_METHOD(OAuth2_Storage_ClientCredentialsInterface, isPublicClient);

