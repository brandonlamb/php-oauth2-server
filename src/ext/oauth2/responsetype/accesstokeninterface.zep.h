
extern zend_class_entry *oauth2_responsetype_accesstokeninterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_ResponseType_AccessTokenInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_responsetype_accesstokeninterface_createaccesstoken, 0, 0, 2)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, user_id)
	ZEND_ARG_INFO(0, scope)
	ZEND_ARG_INFO(0, includeRefreshToken)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_responsetype_accesstokeninterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_ResponseType_AccessTokenInterface, createAccessToken, arginfo_oauth2_responsetype_accesstokeninterface_createaccesstoken)
  PHP_FE_END
};
