
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Interface which represents an object response.  Meant to handle and display the proper OAuth2 Responses
 * for errors and successes
 *
 * @see OAuth2\Response
 */
ZEPHIR_INIT_CLASS(OAuth2_ResponseInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2, ResponseInterface, oauth2, responseinterface, oauth2_responseinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(OAuth2_ResponseInterface, addParameters);

ZEPHIR_DOC_METHOD(OAuth2_ResponseInterface, addHttpHeaders);

ZEPHIR_DOC_METHOD(OAuth2_ResponseInterface, setStatusCode);

ZEPHIR_DOC_METHOD(OAuth2_ResponseInterface, setError);

ZEPHIR_DOC_METHOD(OAuth2_ResponseInterface, setRedirect);

ZEPHIR_DOC_METHOD(OAuth2_ResponseInterface, getParameter);

