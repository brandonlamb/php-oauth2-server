
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(OAuth2_Encryption_EncryptionInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\Encryption, EncryptionInterface, oauth2, encryption_encryptioninterface, oauth2_encryption_encryptioninterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(OAuth2_Encryption_EncryptionInterface, encode);

ZEPHIR_DOC_METHOD(OAuth2_Encryption_EncryptionInterface, decode);

ZEPHIR_DOC_METHOD(OAuth2_Encryption_EncryptionInterface, urlSafeB64Encode);

ZEPHIR_DOC_METHOD(OAuth2_Encryption_EncryptionInterface, urlSafeB64Decode);

