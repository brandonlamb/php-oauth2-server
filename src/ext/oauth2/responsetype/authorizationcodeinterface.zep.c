
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
ZEPHIR_INIT_CLASS(OAuth2_ResponseType_AuthorizationCodeInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\ResponseType, AuthorizationCodeInterface, oauth2, responsetype_authorizationcodeinterface, oauth2_responsetype_authorizationcodeinterface_method_entry);

	zend_class_implements(oauth2_responsetype_authorizationcodeinterface_ce TSRMLS_CC, 1, oauth2_responsetype_responsetypeinterface_ce);
	return SUCCESS;

}

/**
 * @return boolean TRUE if the grant type requires a redirect_uri, FALSE if not
 */
ZEPHIR_DOC_METHOD(OAuth2_ResponseType_AuthorizationCodeInterface, enforceRedirect);

/**
 * Handle the creation of the authorization code.
 *
 * @param string client_id client identifier related to the authorization code
 * @param string user_id user id associated with the authorization code
 * @param string redirect_uri an absolute URI to which the authorization server will redirect the
 * user-agent to when the end-user authorization step is completed.
 * @param string scope OPTIONAL scopes to be stored in space-separated string.
 * @return string
 *
 * @see http://tools.ietf.org/html/rfc6749#section-4
 * @ingroup oauth2_section_4
 */
ZEPHIR_DOC_METHOD(OAuth2_ResponseType_AuthorizationCodeInterface, createAuthorizationCode);

