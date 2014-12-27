
extern zend_class_entry *oauth2_granttype_refreshtoken_ce;

ZEPHIR_INIT_CLASS(OAuth2_GrantType_RefreshToken);

PHP_METHOD(OAuth2_GrantType_RefreshToken, __construct);
PHP_METHOD(OAuth2_GrantType_RefreshToken, getQuerystringIdentifier);
PHP_METHOD(OAuth2_GrantType_RefreshToken, validateRequest);
PHP_METHOD(OAuth2_GrantType_RefreshToken, getClientId);
PHP_METHOD(OAuth2_GrantType_RefreshToken, getUserId);
PHP_METHOD(OAuth2_GrantType_RefreshToken, getScope);
PHP_METHOD(OAuth2_GrantType_RefreshToken, createAccessToken);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_granttype_refreshtoken___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, storage, OAuth2\\Storage\\RefreshTokenInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, config, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_granttype_refreshtoken_validaterequest, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_granttype_refreshtoken_createaccesstoken, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, accessToken, OAuth2\\ResponseType\\AccessTokenInterface, 0)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, user_id)
	ZEND_ARG_INFO(0, scope)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_granttype_refreshtoken_method_entry) {
	PHP_ME(OAuth2_GrantType_RefreshToken, __construct, arginfo_oauth2_granttype_refreshtoken___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth2_GrantType_RefreshToken, getQuerystringIdentifier, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_RefreshToken, validateRequest, arginfo_oauth2_granttype_refreshtoken_validaterequest, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_RefreshToken, getClientId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_RefreshToken, getUserId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_RefreshToken, getScope, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_RefreshToken, createAccessToken, arginfo_oauth2_granttype_refreshtoken_createaccesstoken, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
