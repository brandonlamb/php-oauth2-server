
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Interface for all OAuth2 Client Assertion Types
 */
ZEPHIR_INIT_CLASS(OAuth2_ClientAssertionType_ClientAssertionTypeInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\ClientAssertionType, ClientAssertionTypeInterface, oauth2, clientassertiontype_clientassertiontypeinterface, oauth2_clientassertiontype_clientassertiontypeinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(OAuth2_ClientAssertionType_ClientAssertionTypeInterface, validateRequest);

ZEPHIR_DOC_METHOD(OAuth2_ClientAssertionType_ClientAssertionTypeInterface, getClientId);

