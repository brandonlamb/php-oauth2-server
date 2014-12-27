
extern zend_class_entry *oauth2_tokentype_tokentypeinterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_TokenType_TokenTypeInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_tokentype_tokentypeinterface_getaccesstokenparameter, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_tokentype_tokentypeinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_TokenType_TokenTypeInterface, getTokenType, NULL)
	PHP_ABSTRACT_ME(OAuth2_TokenType_TokenTypeInterface, getAccessTokenParameter, arginfo_oauth2_tokentype_tokentypeinterface_getaccesstokenparameter)
  PHP_FE_END
};
