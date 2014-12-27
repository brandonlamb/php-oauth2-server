
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 *  This controller is called when a user should be authorized
 *  by an authorization server.  As OAuth2 does not handle
 *  authorization directly, this controller ensures the request is valid, but
 *  requires the application to determine the value of $is_authorized
 *
 *  ex:
 *  > $user_id = $this->somehowDetermineUserId();
 *  > $is_authorized = $this->somehowDetermineUserAuthorization();
 *  > $response = new OAuth2\Response();
 *  > $authorizeController->handleAuthorizeRequest(
 *  >     OAuth2\Request::createFromGlobals(),
 *  >     $response,
 *  >     $is_authorized,
 *  >     $user_id);
 *  > $response->send();
 *
 */
ZEPHIR_INIT_CLASS(OAuth2_Controller_AuthorizeControllerInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\Controller, AuthorizeControllerInterface, oauth2, controller_authorizecontrollerinterface, oauth2_controller_authorizecontrollerinterface_method_entry);

	/**
	 * List of possible authentication response types.
	 * The "authorization_code" mechanism exclusively supports "code"
	 * and the "implicit" mechanism exclusively supports "token".
	 *
	 * @var string
	 * @see http://tools.ietf.org/html/rfc6749#section-4.1.1
	 * @see http://tools.ietf.org/html/rfc6749#section-4.2.1
	 */
	zend_declare_class_constant_string(oauth2_controller_authorizecontrollerinterface_ce, SL("RESPONSE_TYPE_AUTHORIZATION_CODE"), "code" TSRMLS_CC);

	zend_declare_class_constant_string(oauth2_controller_authorizecontrollerinterface_ce, SL("RESPONSE_TYPE_ACCESS_TOKEN"), "token" TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param OAuth2\RequestInterface request - The current http request
 * @param OAuth2\ResponseInterface response- An instance of OAuth2\ResponseInterface to contain the response data
 * @param boolean is_authorized
 * @param string user_id
 */
ZEPHIR_DOC_METHOD(OAuth2_Controller_AuthorizeControllerInterface, handleAuthorizeRequest);

/**
 * @param OAuth2\RequestInterface request - The current http request
 * @param OAuth2\ResponseInterface response- An instance of OAuth2\ResponseInterface to contain the response data
 * @return boolean
 */
ZEPHIR_DOC_METHOD(OAuth2_Controller_AuthorizeControllerInterface, validateAuthorizeRequest);

