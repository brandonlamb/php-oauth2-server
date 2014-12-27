
extern zend_class_entry *oauth2_tokentype_bearer_ce;

ZEPHIR_INIT_CLASS(OAuth2_TokenType_Bearer);

PHP_METHOD(OAuth2_TokenType_Bearer, __construct);
PHP_METHOD(OAuth2_TokenType_Bearer, getTokenType);
PHP_METHOD(OAuth2_TokenType_Bearer, requestHasToken);
PHP_METHOD(OAuth2_TokenType_Bearer, getAccessTokenParameter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_tokentype_bearer___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, config, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_tokentype_bearer_requesthastoken, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_tokentype_bearer_getaccesstokenparameter, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_tokentype_bearer_method_entry) {
	PHP_ME(OAuth2_TokenType_Bearer, __construct, arginfo_oauth2_tokentype_bearer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth2_TokenType_Bearer, getTokenType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_TokenType_Bearer, requestHasToken, arginfo_oauth2_tokentype_bearer_requesthastoken, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_TokenType_Bearer, getAccessTokenParameter, arginfo_oauth2_tokentype_bearer_getaccesstokenparameter, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
