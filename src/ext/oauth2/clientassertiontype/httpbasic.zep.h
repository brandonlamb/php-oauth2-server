
extern zend_class_entry *oauth2_clientassertiontype_httpbasic_ce;

ZEPHIR_INIT_CLASS(OAuth2_ClientAssertionType_HttpBasic);

PHP_METHOD(OAuth2_ClientAssertionType_HttpBasic, __construct);
PHP_METHOD(OAuth2_ClientAssertionType_HttpBasic, validateRequest);
PHP_METHOD(OAuth2_ClientAssertionType_HttpBasic, getClientId);
PHP_METHOD(OAuth2_ClientAssertionType_HttpBasic, getClientCredentials);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_clientassertiontype_httpbasic___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, storage, OAuth2\\Storage\\ClientCredentialsInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, config, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_clientassertiontype_httpbasic_validaterequest, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_clientassertiontype_httpbasic_getclientcredentials, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_clientassertiontype_httpbasic_method_entry) {
	PHP_ME(OAuth2_ClientAssertionType_HttpBasic, __construct, arginfo_oauth2_clientassertiontype_httpbasic___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth2_ClientAssertionType_HttpBasic, validateRequest, arginfo_oauth2_clientassertiontype_httpbasic_validaterequest, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_ClientAssertionType_HttpBasic, getClientId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_ClientAssertionType_HttpBasic, getClientCredentials, arginfo_oauth2_clientassertiontype_httpbasic_getclientcredentials, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
