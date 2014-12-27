
extern zend_class_entry *oauth2_storage_accesstokeninterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_Storage_AccessTokenInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_accesstokeninterface_getaccesstoken, 0, 0, 1)
	ZEND_ARG_INFO(0, oauth_token)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_accesstokeninterface_setaccesstoken, 0, 0, 4)
	ZEND_ARG_INFO(0, oauth_token)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, user_id)
	ZEND_ARG_INFO(0, expires)
	ZEND_ARG_INFO(0, scope)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_storage_accesstokeninterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_Storage_AccessTokenInterface, getAccessToken, arginfo_oauth2_storage_accesstokeninterface_getaccesstoken)
	PHP_ABSTRACT_ME(OAuth2_Storage_AccessTokenInterface, setAccessToken, arginfo_oauth2_storage_accesstokeninterface_setaccesstoken)
  PHP_FE_END
};
