
extern zend_class_entry *oauth2_controller_tokencontroller_ce;

ZEPHIR_INIT_CLASS(OAuth2_Controller_TokenController);

PHP_METHOD(OAuth2_Controller_TokenController, __construct);
PHP_METHOD(OAuth2_Controller_TokenController, handleTokenRequest);
PHP_METHOD(OAuth2_Controller_TokenController, grantAccessToken);
PHP_METHOD(OAuth2_Controller_TokenController, addGrantType);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_controller_tokencontroller___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, accessToken, OAuth2\\ResponseType\\AccessTokenInterface, 0)
	ZEND_ARG_OBJ_INFO(0, clientStorage, OAuth2\\Storage\\ClientInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, grantTypes, 1)
	ZEND_ARG_OBJ_INFO(0, clientAssertionType, OAuth2\\ClientAssertionType\\ClientAssertionTypeInterface, 1)
	ZEND_ARG_OBJ_INFO(0, scopeUtil, OAuth2\\ScopeInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_controller_tokencontroller_handletokenrequest, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_controller_tokencontroller_grantaccesstoken, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_controller_tokencontroller_addgranttype, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, grantType, OAuth2\\GrantType\\GrantTypeInterface, 0)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_controller_tokencontroller_method_entry) {
	PHP_ME(OAuth2_Controller_TokenController, __construct, arginfo_oauth2_controller_tokencontroller___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth2_Controller_TokenController, handleTokenRequest, arginfo_oauth2_controller_tokencontroller_handletokenrequest, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_Controller_TokenController, grantAccessToken, arginfo_oauth2_controller_tokencontroller_grantaccesstoken, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_Controller_TokenController, addGrantType, arginfo_oauth2_controller_tokencontroller_addgranttype, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
