
extern zend_class_entry *oauth2_encryption_encryptioninterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_Encryption_EncryptionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_encryption_encryptioninterface_encode, 0, 0, 2)
	ZEND_ARG_INFO(0, payload)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, algorithm)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_encryption_encryptioninterface_decode, 0, 0, 2)
	ZEND_ARG_INFO(0, payload)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, algorithm)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_encryption_encryptioninterface_urlsafeb64encode, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_encryption_encryptioninterface_urlsafeb64decode, 0, 0, 1)
	ZEND_ARG_INFO(0, b64)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_encryption_encryptioninterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_Encryption_EncryptionInterface, encode, arginfo_oauth2_encryption_encryptioninterface_encode)
	PHP_ABSTRACT_ME(OAuth2_Encryption_EncryptionInterface, decode, arginfo_oauth2_encryption_encryptioninterface_decode)
	PHP_ABSTRACT_ME(OAuth2_Encryption_EncryptionInterface, urlSafeB64Encode, arginfo_oauth2_encryption_encryptioninterface_urlsafeb64encode)
	PHP_ABSTRACT_ME(OAuth2_Encryption_EncryptionInterface, urlSafeB64Decode, arginfo_oauth2_encryption_encryptioninterface_urlsafeb64decode)
  PHP_FE_END
};
