
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
 * should retrieve client information
 *
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
ZEPHIR_INIT_CLASS(OAuth2_Storage_ClientInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\Storage, ClientInterface, oauth2, storage_clientinterface, oauth2_storage_clientinterface_method_entry);

	zend_class_implements(oauth2_storage_clientinterface_ce TSRMLS_CC, 1, oauth2_storage_storageinterface_ce);
	return SUCCESS;

}

/**
 * Get client details corresponding client_id.
 *
 * OAuth says we should store request URIs for each registered client.
 * Implement this function to grab the stored URI for a given client id.
 *
 * @param string client_id Client identifier to be check with.
 *
 * @return array
 *               Client details. The only mandatory key in the array is "redirect_uri".
 *               This function MUST return FALSE if the given client does not exist or is
 *               invalid. "redirect_uri" can be space-delimited to allow for multiple valid uris.
 *               <code>
 *               return array(
 *               "redirect_uri" => REDIRECT_URI,      // REQUIRED redirect_uri registered for the client
 *               "client_id"    => CLIENT_ID,         // OPTIONAL the client id
 *               "grant_types"  => GRANT_TYPES,       // OPTIONAL an array of restricted grant types
 *               "user_id"      => USER_ID,           // OPTIONAL the user identifier associated with this client
 *               "scope"        => SCOPE,             // OPTIONAL the scopes allowed for this client
 *               );
 *               </code>
 *
 * @ingroup oauth2_section_4
 */
ZEPHIR_DOC_METHOD(OAuth2_Storage_ClientInterface, getClientDetails);

/**
 * Get the scope associated with this client
 *
 * @param string client_id
 * @return string  the space-delineated scope list for the specified client_id
 */
ZEPHIR_DOC_METHOD(OAuth2_Storage_ClientInterface, getClientScope);

/**
 * Check restricted grant types of corresponding client identifier.
 *
 * If you want to restrict clients to certain grant types, override this
 * function.
 *
 * @param string client_id Client identifier to be check with.
 * @param string grant_type Grant type to be check with
 *
 * @return boolean  TRUE if the grant type is supported by this client identifier, and
 * FALSE if it isn't.
 *
 * @ingroup oauth2_section_4
 */
ZEPHIR_DOC_METHOD(OAuth2_Storage_ClientInterface, checkRestrictedGrantType);

