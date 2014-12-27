
extern zend_class_entry *oauth2_controller_resourcecontroller_ce;

ZEPHIR_INIT_CLASS(OAuth2_Controller_ResourceController);

PHP_METHOD(OAuth2_Controller_ResourceController, __construct);
PHP_METHOD(OAuth2_Controller_ResourceController, verifyResourceRequest);
PHP_METHOD(OAuth2_Controller_ResourceController, getAccessTokenData);
PHP_METHOD(OAuth2_Controller_ResourceController, getToken);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_controller_resourcecontroller___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, tokenType, OAuth2\\TokenType\\TokenTypeInterface, 0)
	ZEND_ARG_OBJ_INFO(0, tokenStorage, OAuth2\\Storage\\AccessTokenInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, config, 1)
	ZEND_ARG_OBJ_INFO(0, scopeUtil, OAuth2\\ScopeInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_controller_resourcecontroller_verifyresourcerequest, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
	ZEND_ARG_INFO(0, scope)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_controller_resourcecontroller_getaccesstokendata, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_controller_resourcecontroller_method_entry) {
	PHP_ME(OAuth2_Controller_ResourceController, __construct, arginfo_oauth2_controller_resourcecontroller___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth2_Controller_ResourceController, verifyResourceRequest, arginfo_oauth2_controller_resourcecontroller_verifyresourcerequest, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_Controller_ResourceController, getAccessTokenData, arginfo_oauth2_controller_resourcecontroller_getaccesstokendata, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_Controller_ResourceController, getToken, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
