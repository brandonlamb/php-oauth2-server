
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 *  This controller is called when a "resource" is requested.
 *  call verifyResourceRequest in order to determine if the request
 *  contains a valid token.
 *
 *  ex:
 *  > if (!$resourceController->verifyResourceRequest(OAuth2\Request::createFromGlobals(), $response = new OAuth2\Response())) {
 *  >     $response->send(); // authorization failed
 *  >     die();
 *  > }
 *  > return json_encode($resource); // valid token!  Send the stuff!
 *
 */
ZEPHIR_INIT_CLASS(OAuth2_Controller_ResourceControllerInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth2\\Controller, ResourceControllerInterface, oauth2, controller_resourcecontrollerinterface, oauth2_controller_resourcecontrollerinterface_method_entry);

	return SUCCESS;

}

/**
 * @param OAuth2\RequestInterface request - The current http request
 * @param OAuth2\ResponseInterface response- An instance of OAuth2\ResponseInterface to contain the response data
 * @param string scope
 * @return boolean
 */
ZEPHIR_DOC_METHOD(OAuth2_Controller_ResourceControllerInterface, verifyResourceRequest);

/**
 * @param OAuth2\RequestInterface request - The current http request
 * @param OAuth2\ResponseInterface response- An instance of OAuth2\ResponseInterface to contain the response data
 * @return string | null
 */
ZEPHIR_DOC_METHOD(OAuth2_Controller_ResourceControllerInterface, getAccessTokenData);

