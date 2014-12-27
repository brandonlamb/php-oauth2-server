
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * No specific methods, but allows the library to check "instanceof"
 * against interface rather than class
 *
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
ZEPHIR_INIT_CLASS(OAuth2_Storage_JwtAccessTokenInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\Storage, JwtAccessTokenInterface, oauth2, storage_jwtaccesstokeninterface, NULL);

	zend_class_implements(oauth2_storage_jwtaccesstokeninterface_ce TSRMLS_CC, 1, oauth2_storage_accesstokeninterface_ce);
	return SUCCESS;

}

