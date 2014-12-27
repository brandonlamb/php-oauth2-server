
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 *  This controller is called when a token is being requested.
 *  it is called to handle all grant types the application supports.
 *  It also validates the client's credentials
 *
 *  ex:
 *  > $tokenController->handleTokenRequest(OAuth2\Request::createFromGlobals(), $response = new OAuth2\Response());
 *  > $response->send();
 *
 */
ZEPHIR_INIT_CLASS(OAuth2_Controller_TokenControllerInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\Controller, TokenControllerInterface, oauth2, controller_tokencontrollerinterface, oauth2_controller_tokencontrollerinterface_method_entry);

	return SUCCESS;

}

/**
 * handleTokenRequest
 *
 * @param OAuth2\RequestInterface request - The current http request
 * @param OAuth2\ResponseInterface response- An instance of OAuth2\ResponseInterface to contain the response data
 */
ZEPHIR_DOC_METHOD(OAuth2_Controller_TokenControllerInterface, handleTokenRequest);

/**
 * grantAccessToken
 *
 * @param OAuth2\RequestInterface request - The current http request
 * @param OAuth2\ResponseInterface response- An instance of OAuth2\ResponseInterface to contain the response data
 */
ZEPHIR_DOC_METHOD(OAuth2_Controller_TokenControllerInterface, grantAccessToken);

