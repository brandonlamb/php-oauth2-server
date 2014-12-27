
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Interface for all OAuth2 Grant Types
 */
ZEPHIR_INIT_CLASS(OAuth2_GrantType_GrantTypeInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\GrantType, GrantTypeInterface, oauth2, granttype_granttypeinterface, oauth2_granttype_granttypeinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(OAuth2_GrantType_GrantTypeInterface, getQuerystringIdentifier);

ZEPHIR_DOC_METHOD(OAuth2_GrantType_GrantTypeInterface, validateRequest);

ZEPHIR_DOC_METHOD(OAuth2_GrantType_GrantTypeInterface, getClientId);

ZEPHIR_DOC_METHOD(OAuth2_GrantType_GrantTypeInterface, getUserId);

ZEPHIR_DOC_METHOD(OAuth2_GrantType_GrantTypeInterface, getScope);

ZEPHIR_DOC_METHOD(OAuth2_GrantType_GrantTypeInterface, createAccessToken);

