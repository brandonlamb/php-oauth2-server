
extern zend_class_entry *oauth2_storage_jwtbearerinterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_Storage_JwtBearerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_jwtbearerinterface_getclientkey, 0, 0, 2)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, subject)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_jwtbearerinterface_getjti, 0, 0, 5)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, subject)
	ZEND_ARG_INFO(0, audience)
	ZEND_ARG_INFO(0, expiration)
	ZEND_ARG_INFO(0, jti)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_jwtbearerinterface_setjti, 0, 0, 5)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, subject)
	ZEND_ARG_INFO(0, audience)
	ZEND_ARG_INFO(0, expiration)
	ZEND_ARG_INFO(0, jti)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_storage_jwtbearerinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_Storage_JwtBearerInterface, getClientKey, arginfo_oauth2_storage_jwtbearerinterface_getclientkey)
	PHP_ABSTRACT_ME(OAuth2_Storage_JwtBearerInterface, getJti, arginfo_oauth2_storage_jwtbearerinterface_getjti)
	PHP_ABSTRACT_ME(OAuth2_Storage_JwtBearerInterface, setJti, arginfo_oauth2_storage_jwtbearerinterface_setjti)
  PHP_FE_END
};
