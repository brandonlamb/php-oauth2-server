
extern zend_class_entry *oauth2_controller_resourcecontrollerinterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_Controller_ResourceControllerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_controller_resourcecontrollerinterface_verifyresourcerequest, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
	ZEND_ARG_INFO(0, scope)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_controller_resourcecontrollerinterface_getaccesstokendata, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_controller_resourcecontrollerinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_Controller_ResourceControllerInterface, verifyResourceRequest, arginfo_oauth2_controller_resourcecontrollerinterface_verifyresourcerequest)
	PHP_ABSTRACT_ME(OAuth2_Controller_ResourceControllerInterface, getAccessTokenData, arginfo_oauth2_controller_resourcecontrollerinterface_getaccesstokendata)
  PHP_FE_END
};
