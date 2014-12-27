
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(OAuth2_TokenType_TokenTypeInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\TokenType, TokenTypeInterface, oauth2, tokentype_tokentypeinterface, oauth2_tokentype_tokentypeinterface_method_entry);

	return SUCCESS;

}

/**
 * Token type identification string
 *
 * ex: "bearer" or "mac"
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth2_TokenType_TokenTypeInterface, getTokenType);

/**
 * Retrieves the token string from the request object
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth2_TokenType_TokenTypeInterface, getAccessTokenParameter);

