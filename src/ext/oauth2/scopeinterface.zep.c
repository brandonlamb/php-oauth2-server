
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Class to handle scope implementation logic
 *
 * @see OAuth2\Storage\ScopeInterface
 */
ZEPHIR_INIT_CLASS(OAuth2_ScopeInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2, ScopeInterface, oauth2, scopeinterface, oauth2_scopeinterface_method_entry);

	zend_class_implements(oauth2_scopeinterface_ce TSRMLS_CC, 1, oauth2_storage_scopeinterface_ce);
	return SUCCESS;

}

/**
 * Check if everything in required scope is contained in available scope.
 *
 * @param string required_scope A space-separated string of scopes.
 * @param string available_scope
 * @return boolean  TRUE if everything in required scope is contained in available scope,
 * and FALSE if it isn't.
 *
 * @see http://tools.ietf.org/html/rfc6749#section-7
 *
 * @ingroup oauth2_section_7
 */
ZEPHIR_DOC_METHOD(OAuth2_ScopeInterface, checkScope);

/**
 * Return scope info from request
 *
 * @param \OAuth2\RequestInterface request Request object to check
 *
 * @return string representation of requested scope
 */
ZEPHIR_DOC_METHOD(OAuth2_ScopeInterface, getScopeFromRequest);

