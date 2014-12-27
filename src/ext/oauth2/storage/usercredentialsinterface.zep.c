
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
 * should retrieve user credentials for the
 * "Resource Owner Password Credentials" grant type
 *
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
ZEPHIR_INIT_CLASS(OAuth2_Storage_UserCredentialsInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\Storage, UserCredentialsInterface, oauth2, storage_usercredentialsinterface, oauth2_storage_usercredentialsinterface_method_entry);

	zend_class_implements(oauth2_storage_usercredentialsinterface_ce TSRMLS_CC, 1, oauth2_storage_storageinterface_ce);
	return SUCCESS;

}

/**
 * Grant access tokens for basic user credentials.
 *
 * Check the supplied username and password for validity.
 *
 * You can also use the $client_id param to do any checks required based
 * on a client, if you need that.
 *
 * Required for OAuth2::GRANT_TYPE_USER_CREDENTIALS.
 *
 * @param string username Username to be check with.
 * @param string password Password to be check with.
 *
 * @return bool TRUE if the username and password are valid, and FALSE if
 * it isn't. Moreover, if the username and password are valid, and you want to
 *
 * @see http://tools.ietf.org/html/rfc6749#section-4.3
 *
 * @ingroup oauth2_section_4
 */
ZEPHIR_DOC_METHOD(OAuth2_Storage_UserCredentialsInterface, checkUserCredentials);

/**
 * @param string username
 * @return array
 * ARRAY the associated "user_id" and optional "scope" values
 * This function MUST return FALSE if the requested user does not exist or is
 * invalid. "scope" is a space-separated list of restricted scopes.
 * @code
 * return array(
 *     "user_id"  => USER_ID,    // REQUIRED user_id to be stored with the authorization code or access token
 *     "scope"    => SCOPE       // OPTIONAL space-separated list of restricted scopes
 * );
 * @endcode
 */
ZEPHIR_DOC_METHOD(OAuth2_Storage_UserCredentialsInterface, getUserDetails);

