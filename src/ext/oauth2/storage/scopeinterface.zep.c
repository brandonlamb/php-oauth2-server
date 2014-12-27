
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
 * should retrieve data involving the relevent scopes associated
 * with this implementation.
 *
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
ZEPHIR_INIT_CLASS(OAuth2_Storage_ScopeInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\Storage, ScopeInterface, oauth2, storage_scopeinterface, oauth2_storage_scopeinterface_method_entry);

	zend_class_implements(oauth2_storage_scopeinterface_ce TSRMLS_CC, 1, oauth2_storage_storageinterface_ce);
	return SUCCESS;

}

/**
 * Check if the provided scope exists.
 *
 * @param stirng scope A space-separated string of scopes.
 *
 * @return boolean TRUE if it exists, FALSE otherwise.
 */
ZEPHIR_DOC_METHOD(OAuth2_Storage_ScopeInterface, scopeExists);

/**
 * The default scope to use in the event the client
 * does not request one. By returning "false", a
 * request_error is returned by the server to force a
 * scope request by the client. By returning "null",
 * opt out of requiring scopes
 *
 * @param string client_id An optional client id that can be used to
 * return customized default scopes.
 *
 * @return string - string representation of default scope, null if
 * scopes are not defined, or false to force scope request by the client
 *
 * ex:
 *     'default'
 * ex:
 *     null
 */
ZEPHIR_DOC_METHOD(OAuth2_Storage_ScopeInterface, getDefaultScope);

