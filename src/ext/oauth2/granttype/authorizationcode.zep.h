
extern zend_class_entry *oauth2_granttype_authorizationcode_ce;

ZEPHIR_INIT_CLASS(OAuth2_GrantType_AuthorizationCode);

PHP_METHOD(OAuth2_GrantType_AuthorizationCode, __construct);
PHP_METHOD(OAuth2_GrantType_AuthorizationCode, getQuerystringIdentifier);
PHP_METHOD(OAuth2_GrantType_AuthorizationCode, validateRequest);
PHP_METHOD(OAuth2_GrantType_AuthorizationCode, getClientId);
PHP_METHOD(OAuth2_GrantType_AuthorizationCode, getScope);
PHP_METHOD(OAuth2_GrantType_AuthorizationCode, getUserId);
PHP_METHOD(OAuth2_GrantType_AuthorizationCode, createAccessToken);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_granttype_authorizationcode___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, storage, OAuth2\\Storage\\AuthorizationCodeInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_granttype_authorizationcode_validaterequest, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_granttype_authorizationcode_createaccesstoken, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, accessToken, OAuth2\\ResponseType\\AccessTokenInterface, 0)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, user_id)
	ZEND_ARG_INFO(0, scope)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_granttype_authorizationcode_method_entry) {
	PHP_ME(OAuth2_GrantType_AuthorizationCode, __construct, arginfo_oauth2_granttype_authorizationcode___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth2_GrantType_AuthorizationCode, getQuerystringIdentifier, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_AuthorizationCode, validateRequest, arginfo_oauth2_granttype_authorizationcode_validaterequest, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_AuthorizationCode, getClientId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_AuthorizationCode, getScope, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_AuthorizationCode, getUserId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_AuthorizationCode, createAccessToken, arginfo_oauth2_granttype_authorizationcode_createaccesstoken, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
