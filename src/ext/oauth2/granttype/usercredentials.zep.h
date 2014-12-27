
extern zend_class_entry *oauth2_granttype_usercredentials_ce;

ZEPHIR_INIT_CLASS(OAuth2_GrantType_UserCredentials);

PHP_METHOD(OAuth2_GrantType_UserCredentials, __construct);
PHP_METHOD(OAuth2_GrantType_UserCredentials, getQuerystringIdentifier);
PHP_METHOD(OAuth2_GrantType_UserCredentials, validateRequest);
PHP_METHOD(OAuth2_GrantType_UserCredentials, getClientId);
PHP_METHOD(OAuth2_GrantType_UserCredentials, getUserId);
PHP_METHOD(OAuth2_GrantType_UserCredentials, getScope);
PHP_METHOD(OAuth2_GrantType_UserCredentials, createAccessToken);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_granttype_usercredentials___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, storage, OAuth2\\Storage\\UserCredentialsInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_granttype_usercredentials_validaterequest, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_granttype_usercredentials_createaccesstoken, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, accessToken, OAuth2\\ResponseType\\AccessTokenInterface, 0)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, user_id)
	ZEND_ARG_INFO(0, scope)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_granttype_usercredentials_method_entry) {
	PHP_ME(OAuth2_GrantType_UserCredentials, __construct, arginfo_oauth2_granttype_usercredentials___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth2_GrantType_UserCredentials, getQuerystringIdentifier, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_UserCredentials, validateRequest, arginfo_oauth2_granttype_usercredentials_validaterequest, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_UserCredentials, getClientId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_UserCredentials, getUserId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_UserCredentials, getScope, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_UserCredentials, createAccessToken, arginfo_oauth2_granttype_usercredentials_createaccesstoken, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
