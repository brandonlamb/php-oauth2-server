
extern zend_class_entry *oauth2_responsetype_authorizationcode_ce;

ZEPHIR_INIT_CLASS(OAuth2_ResponseType_AuthorizationCode);

PHP_METHOD(OAuth2_ResponseType_AuthorizationCode, __construct);
PHP_METHOD(OAuth2_ResponseType_AuthorizationCode, getAuthorizeResponse);
PHP_METHOD(OAuth2_ResponseType_AuthorizationCode, createAuthorizationCode);
PHP_METHOD(OAuth2_ResponseType_AuthorizationCode, enforceRedirect);
PHP_METHOD(OAuth2_ResponseType_AuthorizationCode, generateAuthorizationCode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_responsetype_authorizationcode___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, storage, OAuth2\\Storage\\AuthorizationCodeInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, config, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_responsetype_authorizationcode_getauthorizeresponse, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, user_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_responsetype_authorizationcode_createauthorizationcode, 0, 0, 3)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, user_id)
	ZEND_ARG_INFO(0, redirect_uri)
	ZEND_ARG_INFO(0, scope)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_responsetype_authorizationcode_method_entry) {
	PHP_ME(OAuth2_ResponseType_AuthorizationCode, __construct, arginfo_oauth2_responsetype_authorizationcode___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth2_ResponseType_AuthorizationCode, getAuthorizeResponse, arginfo_oauth2_responsetype_authorizationcode_getauthorizeresponse, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_ResponseType_AuthorizationCode, createAuthorizationCode, arginfo_oauth2_responsetype_authorizationcode_createauthorizationcode, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_ResponseType_AuthorizationCode, enforceRedirect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_ResponseType_AuthorizationCode, generateAuthorizationCode, NULL, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
