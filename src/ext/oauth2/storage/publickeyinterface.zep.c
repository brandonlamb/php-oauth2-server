
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Implement this interface to specify where the OAuth2 Server
 * should get public/private key information
 *
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
ZEPHIR_INIT_CLASS(OAuth2_Storage_PublicKeyInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\Storage, PublicKeyInterface, oauth2, storage_publickeyinterface, oauth2_storage_publickeyinterface_method_entry);

	zend_class_implements(oauth2_storage_publickeyinterface_ce TSRMLS_CC, 1, oauth2_storage_storageinterface_ce);
	return SUCCESS;

}

ZEPHIR_DOC_METHOD(OAuth2_Storage_PublicKeyInterface, getPublicKey);

ZEPHIR_DOC_METHOD(OAuth2_Storage_PublicKeyInterface, getPrivateKey);

ZEPHIR_DOC_METHOD(OAuth2_Storage_PublicKeyInterface, getEncryptionAlgorithm);

