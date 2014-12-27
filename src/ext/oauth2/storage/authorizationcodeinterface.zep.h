
extern zend_class_entry *oauth2_storage_authorizationcodeinterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_Storage_AuthorizationCodeInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_authorizationcodeinterface_getauthorizationcode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_authorizationcodeinterface_setauthorizationcode, 0, 0, 5)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, user_id)
	ZEND_ARG_INFO(0, redirect_uri)
	ZEND_ARG_INFO(0, expires)
	ZEND_ARG_INFO(0, scope)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_authorizationcodeinterface_expireauthorizationcode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_storage_authorizationcodeinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_Storage_AuthorizationCodeInterface, getAuthorizationCode, arginfo_oauth2_storage_authorizationcodeinterface_getauthorizationcode)
	PHP_ABSTRACT_ME(OAuth2_Storage_AuthorizationCodeInterface, setAuthorizationCode, arginfo_oauth2_storage_authorizationcodeinterface_setauthorizationcode)
	PHP_ABSTRACT_ME(OAuth2_Storage_AuthorizationCodeInterface, expireAuthorizationCode, arginfo_oauth2_storage_authorizationcodeinterface_expireauthorizationcode)
  PHP_FE_END
};
