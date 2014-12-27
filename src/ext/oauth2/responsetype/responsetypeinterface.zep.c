
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(OAuth2_ResponseType_ResponseTypeInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\ResponseType, ResponseTypeInterface, oauth2, responsetype_responsetypeinterface, oauth2_responsetype_responsetypeinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(OAuth2_ResponseType_ResponseTypeInterface, getAuthorizeResponse);

