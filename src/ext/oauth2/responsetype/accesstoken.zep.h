
extern zend_class_entry *oauth2_responsetype_accesstoken_ce;

ZEPHIR_INIT_CLASS(OAuth2_ResponseType_AccessToken);

PHP_METHOD(OAuth2_ResponseType_AccessToken, __construct);
PHP_METHOD(OAuth2_ResponseType_AccessToken, getAuthorizeResponse);
PHP_METHOD(OAuth2_ResponseType_AccessToken, createAccessToken);
PHP_METHOD(OAuth2_ResponseType_AccessToken, generateAccessToken);
PHP_METHOD(OAuth2_ResponseType_AccessToken, generateRefreshToken);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_responsetype_accesstoken___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, tokenStorage, OAuth2\\Storage\\AccessTokenInterface, 0)
	ZEND_ARG_OBJ_INFO(0, refreshStorage, OAuth2\\Storage\\RefreshTokenInterface, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_responsetype_accesstoken_getauthorizeresponse, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, user_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_responsetype_accesstoken_createaccesstoken, 0, 0, 2)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, user_id)
	ZEND_ARG_INFO(0, scope)
	ZEND_ARG_INFO(0, includeRefreshToken)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_responsetype_accesstoken_method_entry) {
	PHP_ME(OAuth2_ResponseType_AccessToken, __construct, arginfo_oauth2_responsetype_accesstoken___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth2_ResponseType_AccessToken, getAuthorizeResponse, arginfo_oauth2_responsetype_accesstoken_getauthorizeresponse, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_ResponseType_AccessToken, createAccessToken, arginfo_oauth2_responsetype_accesstoken_createaccesstoken, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_ResponseType_AccessToken, generateAccessToken, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(OAuth2_ResponseType_AccessToken, generateRefreshToken, NULL, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
