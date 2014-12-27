
extern zend_class_entry *oauth2_responsetype_authorizationcodeinterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_ResponseType_AuthorizationCodeInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_responsetype_authorizationcodeinterface_createauthorizationcode, 0, 0, 3)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, user_id)
	ZEND_ARG_INFO(0, redirect_uri)
	ZEND_ARG_INFO(0, scope)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_responsetype_authorizationcodeinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_ResponseType_AuthorizationCodeInterface, enforceRedirect, NULL)
	PHP_ABSTRACT_ME(OAuth2_ResponseType_AuthorizationCodeInterface, createAuthorizationCode, arginfo_oauth2_responsetype_authorizationcodeinterface_createauthorizationcode)
  PHP_FE_END
};
