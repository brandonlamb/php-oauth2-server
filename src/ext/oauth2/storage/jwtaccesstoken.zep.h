
extern zend_class_entry *oauth2_storage_jwtaccesstoken_ce;

ZEPHIR_INIT_CLASS(OAuth2_Storage_JwtAccessToken);

PHP_METHOD(OAuth2_Storage_JwtAccessToken, __construct);
PHP_METHOD(OAuth2_Storage_JwtAccessToken, getAccessToken);
PHP_METHOD(OAuth2_Storage_JwtAccessToken, setAccessToken);
PHP_METHOD(OAuth2_Storage_JwtAccessToken, convertJwtToOAuth2);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_jwtaccesstoken___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, publicKeyStorage, OAuth2\\Storage\\PublicKeyInterface, 0)
	ZEND_ARG_OBJ_INFO(0, tokenStorage, OAuth2\\Storage\\AccessTokenInterface, 1)
	ZEND_ARG_OBJ_INFO(0, encryptionUtil, OAuth2\\Encryption\\EncryptionInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_jwtaccesstoken_getaccesstoken, 0, 0, 1)
	ZEND_ARG_INFO(0, oauth_token)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_jwtaccesstoken_setaccesstoken, 0, 0, 4)
	ZEND_ARG_INFO(0, oauth_token)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, user_id)
	ZEND_ARG_INFO(0, expires)
	ZEND_ARG_INFO(0, scope)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_jwtaccesstoken_convertjwttooauth2, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, tokenData, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_storage_jwtaccesstoken_method_entry) {
	PHP_ME(OAuth2_Storage_JwtAccessToken, __construct, arginfo_oauth2_storage_jwtaccesstoken___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth2_Storage_JwtAccessToken, getAccessToken, arginfo_oauth2_storage_jwtaccesstoken_getaccesstoken, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_Storage_JwtAccessToken, setAccessToken, arginfo_oauth2_storage_jwtaccesstoken_setaccesstoken, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_Storage_JwtAccessToken, convertJwtToOAuth2, arginfo_oauth2_storage_jwtaccesstoken_convertjwttooauth2, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
