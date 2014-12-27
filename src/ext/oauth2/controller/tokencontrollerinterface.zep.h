
extern zend_class_entry *oauth2_controller_tokencontrollerinterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_Controller_TokenControllerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_controller_tokencontrollerinterface_handletokenrequest, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_controller_tokencontrollerinterface_grantaccesstoken, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_controller_tokencontrollerinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_Controller_TokenControllerInterface, handleTokenRequest, arginfo_oauth2_controller_tokencontrollerinterface_handletokenrequest)
	PHP_ABSTRACT_ME(OAuth2_Controller_TokenControllerInterface, grantAccessToken, arginfo_oauth2_controller_tokencontrollerinterface_grantaccesstoken)
  PHP_FE_END
};
