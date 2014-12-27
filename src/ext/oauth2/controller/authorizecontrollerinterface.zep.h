
extern zend_class_entry *oauth2_controller_authorizecontrollerinterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_Controller_AuthorizeControllerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_controller_authorizecontrollerinterface_handleauthorizerequest, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
	ZEND_ARG_INFO(0, is_authorized)
	ZEND_ARG_INFO(0, user_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_controller_authorizecontrollerinterface_validateauthorizerequest, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_controller_authorizecontrollerinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_Controller_AuthorizeControllerInterface, handleAuthorizeRequest, arginfo_oauth2_controller_authorizecontrollerinterface_handleauthorizerequest)
	PHP_ABSTRACT_ME(OAuth2_Controller_AuthorizeControllerInterface, validateAuthorizeRequest, arginfo_oauth2_controller_authorizecontrollerinterface_validateauthorizerequest)
  PHP_FE_END
};
