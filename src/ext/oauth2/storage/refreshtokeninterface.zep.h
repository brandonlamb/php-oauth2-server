
extern zend_class_entry *oauth2_storage_refreshtokeninterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_Storage_RefreshTokenInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_refreshtokeninterface_getrefreshtoken, 0, 0, 1)
	ZEND_ARG_INFO(0, refresh_token)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_refreshtokeninterface_setrefreshtoken, 0, 0, 4)
	ZEND_ARG_INFO(0, refresh_token)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, user_id)
	ZEND_ARG_INFO(0, expires)
	ZEND_ARG_INFO(0, scope)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_refreshtokeninterface_unsetrefreshtoken, 0, 0, 1)
	ZEND_ARG_INFO(0, refresh_token)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_storage_refreshtokeninterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_Storage_RefreshTokenInterface, getRefreshToken, arginfo_oauth2_storage_refreshtokeninterface_getrefreshtoken)
	PHP_ABSTRACT_ME(OAuth2_Storage_RefreshTokenInterface, setRefreshToken, arginfo_oauth2_storage_refreshtokeninterface_setrefreshtoken)
	PHP_ABSTRACT_ME(OAuth2_Storage_RefreshTokenInterface, unsetRefreshToken, arginfo_oauth2_storage_refreshtokeninterface_unsetrefreshtoken)
  PHP_FE_END
};
