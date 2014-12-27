
extern zend_class_entry *oauth2_tokentype_mac_ce;

ZEPHIR_INIT_CLASS(OAuth2_TokenType_Mac);

PHP_METHOD(OAuth2_TokenType_Mac, getTokenType);
PHP_METHOD(OAuth2_TokenType_Mac, getAccessTokenParameter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_tokentype_mac_getaccesstokenparameter, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_tokentype_mac_method_entry) {
	PHP_ME(OAuth2_TokenType_Mac, getTokenType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_TokenType_Mac, getAccessTokenParameter, arginfo_oauth2_tokentype_mac_getaccesstokenparameter, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
