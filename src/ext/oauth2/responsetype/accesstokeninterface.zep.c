
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * @package \OAuth2\ResponseType
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
ZEPHIR_INIT_CLASS(OAuth2_ResponseType_AccessTokenInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\ResponseType, AccessTokenInterface, oauth2, responsetype_accesstokeninterface, oauth2_responsetype_accesstokeninterface_method_entry);

	zend_class_implements(oauth2_responsetype_accesstokeninterface_ce TSRMLS_CC, 1, oauth2_responsetype_responsetypeinterface_ce);
	return SUCCESS;

}

/**
 * Handle the creation of access token, also issue refresh token if supported / desirable.
 *
 * @param string client_id client identifier related to the access token.
 * @param string user_id user ID associated with the access token
 * @param string scope OPTONAL scopes to be stored in space-separated string.
 * @param bool includeRefreshToken if true, a new refresh_token will be added to the response
 * @return string
 * @see http://tools.ietf.org/html/rfc6749#section-5
 * @ingroup oauth2_section_5
 */
ZEPHIR_DOC_METHOD(OAuth2_ResponseType_AccessTokenInterface, createAccessToken);

