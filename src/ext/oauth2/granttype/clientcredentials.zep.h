
extern zend_class_entry *oauth2_granttype_clientcredentials_ce;

ZEPHIR_INIT_CLASS(OAuth2_GrantType_ClientCredentials);

PHP_METHOD(OAuth2_GrantType_ClientCredentials, __construct);
PHP_METHOD(OAuth2_GrantType_ClientCredentials, getQuerystringIdentifier);
PHP_METHOD(OAuth2_GrantType_ClientCredentials, getScope);
PHP_METHOD(OAuth2_GrantType_ClientCredentials, getUserId);
PHP_METHOD(OAuth2_GrantType_ClientCredentials, createAccessToken);
PHP_METHOD(OAuth2_GrantType_ClientCredentials, loadClientData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_granttype_clientcredentials___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, storage, OAuth2\\Storage\\ClientCredentialsInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, config, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_granttype_clientcredentials_createaccesstoken, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, accessToken, OAuth2\\ResponseType\\AccessTokenInterface, 0)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, user_id)
	ZEND_ARG_INFO(0, scope)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_granttype_clientcredentials_method_entry) {
	PHP_ME(OAuth2_GrantType_ClientCredentials, __construct, arginfo_oauth2_granttype_clientcredentials___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth2_GrantType_ClientCredentials, getQuerystringIdentifier, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_ClientCredentials, getScope, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_ClientCredentials, getUserId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_ClientCredentials, createAccessToken, arginfo_oauth2_granttype_clientcredentials_createaccesstoken, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_ClientCredentials, loadClientData, NULL, ZEND_ACC_PRIVATE)
  PHP_FE_END
};
