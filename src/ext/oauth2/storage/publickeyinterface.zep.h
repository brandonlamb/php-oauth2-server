
extern zend_class_entry *oauth2_storage_publickeyinterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_Storage_PublicKeyInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_publickeyinterface_getpublickey, 0, 0, 0)
	ZEND_ARG_INFO(0, client_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_publickeyinterface_getprivatekey, 0, 0, 0)
	ZEND_ARG_INFO(0, client_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_publickeyinterface_getencryptionalgorithm, 0, 0, 0)
	ZEND_ARG_INFO(0, client_id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_storage_publickeyinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_Storage_PublicKeyInterface, getPublicKey, arginfo_oauth2_storage_publickeyinterface_getpublickey)
	PHP_ABSTRACT_ME(OAuth2_Storage_PublicKeyInterface, getPrivateKey, arginfo_oauth2_storage_publickeyinterface_getprivatekey)
	PHP_ABSTRACT_ME(OAuth2_Storage_PublicKeyInterface, getEncryptionAlgorithm, arginfo_oauth2_storage_publickeyinterface_getencryptionalgorithm)
  PHP_FE_END
};
