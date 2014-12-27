
extern zend_class_entry *oauth2_granttype_jwtbearer_ce;

ZEPHIR_INIT_CLASS(OAuth2_GrantType_JwtBearer);

PHP_METHOD(OAuth2_GrantType_JwtBearer, __construct);
PHP_METHOD(OAuth2_GrantType_JwtBearer, getQuerystringIdentifier);
PHP_METHOD(OAuth2_GrantType_JwtBearer, validateRequest);
PHP_METHOD(OAuth2_GrantType_JwtBearer, getClientId);
PHP_METHOD(OAuth2_GrantType_JwtBearer, getUserId);
PHP_METHOD(OAuth2_GrantType_JwtBearer, getScope);
PHP_METHOD(OAuth2_GrantType_JwtBearer, createAccessToken);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_granttype_jwtbearer___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, storage, OAuth2\\Storage\\JwtBearerInterface, 0)
	ZEND_ARG_INFO(0, audience)
	ZEND_ARG_OBJ_INFO(0, jwtUtil, OAuth2\\Encryption\\EncryptionInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_granttype_jwtbearer_validaterequest, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_granttype_jwtbearer_createaccesstoken, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, accessToken, OAuth2\\ResponseType\\AccessTokenInterface, 0)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, user_id)
	ZEND_ARG_INFO(0, scope)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_granttype_jwtbearer_method_entry) {
	PHP_ME(OAuth2_GrantType_JwtBearer, __construct, arginfo_oauth2_granttype_jwtbearer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth2_GrantType_JwtBearer, getQuerystringIdentifier, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_JwtBearer, validateRequest, arginfo_oauth2_granttype_jwtbearer_validaterequest, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_JwtBearer, getClientId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_JwtBearer, getUserId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_JwtBearer, getScope, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_GrantType_JwtBearer, createAccessToken, arginfo_oauth2_granttype_jwtbearer_createaccesstoken, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
