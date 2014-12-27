
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Base storage interface
 */
ZEPHIR_INIT_CLASS(OAuth2_Storage_StorageInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\Storage, StorageInterface, oauth2, storage_storageinterface, NULL);

	return SUCCESS;

}

