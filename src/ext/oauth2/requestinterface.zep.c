
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(OAuth2_RequestInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2, RequestInterface, oauth2, requestinterface, oauth2_requestinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(OAuth2_RequestInterface, query);

ZEPHIR_DOC_METHOD(OAuth2_RequestInterface, request);

ZEPHIR_DOC_METHOD(OAuth2_RequestInterface, server);

ZEPHIR_DOC_METHOD(OAuth2_RequestInterface, headers);

ZEPHIR_DOC_METHOD(OAuth2_RequestInterface, getAllQueryParameters);

