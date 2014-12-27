
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


/**
 * Validate a client via Http Basic authentication
 *
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
ZEPHIR_INIT_CLASS(OAuth2_ClientAssertionType_HttpBasic) {

	ZEPHIR_REGISTER_CLASS(OAuth2\\ClientAssertionType, HttpBasic, oauth2, clientassertiontype_httpbasic, oauth2_clientassertiontype_httpbasic_method_entry, 0);

	zend_declare_property_null(oauth2_clientassertiontype_httpbasic_ce, SL("clientData"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(oauth2_clientassertiontype_httpbasic_ce, SL("storage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_clientassertiontype_httpbasic_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(oauth2_clientassertiontype_httpbasic_ce TSRMLS_CC, 1, oauth2_clientassertiontype_clientassertiontypeinterface_ce);
	return SUCCESS;

}

/**
 * @param \OAuth2\Storage\ClientCredentialsInterface clientStorage
 * REQUIRED Storage class for retrieving client credentials information
 * @param array config OPTIONAL Configuration options for the server
 * <code>
 * $config = array(
 * "allow_credentials_in_request_body" => true, // whether to look for credentials in the POST body in addition to the Authorize HTTP Header
 * "allow_public_clients"  => true // if true, "public clients" (clients without a secret) may be authenticated
 * );
 * </code>
 */
PHP_METHOD(OAuth2_ClientAssertionType_HttpBasic, __construct) {

	zval *config = NULL, *_1;
	zval *storage, *config_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &storage, &config_param);

	if (!config_param) {
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	} else {
		zephir_get_arrval(config, config_param);
	}


	if (!(zephir_instance_of_ev(storage, oauth2_storage_clientcredentialsinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'storage' must be an instance of 'OAuth2\\Storage\\ClientCredentialsInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("storage"), storage TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 3);
	zephir_array_update_string(&_1, SL("allow_credentials_in_request_body"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("allow_public_clients"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_fast_array_merge(_0, &(_1), &(config) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("config"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(OAuth2_ClientAssertionType_HttpBasic, validateRequest) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *response, *clientData = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5, *_6 = NULL, *_7, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &request, &response);



	if (!(zephir_instance_of_ev(request, oauth2_requestinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'request' must be an instance of 'OAuth2\\RequestInterface'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(response, oauth2_responseinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'response' must be an instance of 'OAuth2\\ResponseInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&clientData, this_ptr, "getclientcredentials", NULL, request, response);
	zephir_check_call_status();
	if (!(zephir_is_true(clientData))) {
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_array_isset_string(clientData, SS("client_id")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_LogicException, "The clientData array must have \"client_id\" set", "oauth2/clientassertiontype/httpbasic.zep", 50);
		return;
	}
	zephir_array_fetch_string(&_0, clientData, SL("client_secret"), PH_NOISY | PH_READONLY, "oauth2/clientassertiontype/httpbasic.zep", 54 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		if (!(zephir_array_isset_string(_1, SS("allow_public_clients")))) {
			ZEPHIR_INIT_VAR(_2);
			ZVAL_LONG(_2, 400);
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "invalid_client", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_4);
			ZVAL_STRING(_4, "client credentials are required", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _2, _3, _4);
			zephir_check_temp_parameter(_3);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
		zephir_array_fetch_string(&_7, clientData, SL("client_id"), PH_NOISY | PH_READONLY, "oauth2/clientassertiontype/httpbasic.zep", 60 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_6, _5, "ispublicclient", NULL, _7);
		zephir_check_call_status();
		if (!(zephir_is_true(_6))) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_LONG(_2, 400);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "invalid_client", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "This client is invalid or must authenticate using a client secret", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _2, _3, _4);
			zephir_check_temp_parameter(_3);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
		zephir_array_fetch_string(&_7, clientData, SL("client_id"), PH_NOISY | PH_READONLY, "oauth2/clientassertiontype/httpbasic.zep", 65 TSRMLS_CC);
		zephir_array_fetch_string(&_8, clientData, SL("client_secret"), PH_NOISY | PH_READONLY, "oauth2/clientassertiontype/httpbasic.zep", 65 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_6, _1, "checkclientcredentials", NULL, _7, _8);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_6)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_LONG(_2, 400);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "invalid_client", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "The client credentials are invalid", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _2, _3, _4);
			zephir_check_temp_parameter(_3);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	zephir_update_property_this(this_ptr, SL("clientData"), clientData TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

PHP_METHOD(OAuth2_ClientAssertionType_HttpBasic, getClientId) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("clientData"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("client_id"), PH_NOISY | PH_READONLY, "oauth2/clientassertiontype/httpbasic.zep", 78 TSRMLS_CC);
	RETURN_CTORW(_1);

}

/**
 * Internal function used to get the client credentials from HTTP basic
 * auth or POST data.
 *
 * According to the spec (draft 20), the client_id can be provided in
 * the Basic Authorization header (recommended) or via GET/POST.
 *
 * @return array
 * A list containing the client identifier and password, for example
 * @code
 * return array(
 *     "client_id"     => CLIENT_ID,        // REQUIRED the client id
 *     "client_secret" => CLIENT_SECRET,    // OPTIONAL the client secret (may be omitted for public clients)
 * );
 * @endcode
 *
 * @see http://tools.ietf.org/html/rfc6749#section-2.3.1
 *
 * @ingroup oauth2_section_2
 */
PHP_METHOD(OAuth2_ClientAssertionType_HttpBasic, getClientCredentials) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0, _3;
	zval *request, *response = NULL, *message = NULL, *_1 = NULL, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7 = NULL, *_8, *_9, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &request, &response);

	if (!response) {
		response = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_instance_of_ev(request, oauth2_requestinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'request' must be an instance of 'OAuth2\\RequestInterface'", "", 0);
		return;
	}
	_0 = Z_TYPE_P(response) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(response, oauth2_responseinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'response' must be an instance of 'OAuth2\\ResponseInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "PHP_AUTH_USER", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, request, "headers", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_3 = Z_TYPE_P(_1) != IS_NULL;
	if (_3) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "PHP_AUTH_PW", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_4, request, "headers", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		_3 = Z_TYPE_P(_4) != IS_NULL;
	}
	if (_3) {
		array_init_size(return_value, 3);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "PHP_AUTH_USER", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5, request, "headers", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&return_value, SL("client_id"), &_5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "PHP_AUTH_PW", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5, request, "headers", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&return_value, SL("client_secret"), &_5, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	if (zephir_array_isset_string(_6, SS("allow_credentials_in_request_body"))) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "client_id", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5, request, "request", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (Z_TYPE_P(_5) != IS_NULL) {
			array_init_size(return_value, 3);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "client_id", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_7, request, "request", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			zephir_array_update_string(&return_value, SL("client_id"), &_7, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "client_secret", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_7, request, "request", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			zephir_array_update_string(&return_value, SL("client_secret"), &_7, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		}
	}
	if (zephir_is_true(response)) {
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		if (zephir_array_isset_string(_8, SS("allow_credentials_in_request_body"))) {
			ZEPHIR_INIT_VAR(message);
			ZVAL_STRING(message, " or body", 1);
		} else {
			ZEPHIR_INIT_NVAR(message);
			ZVAL_STRING(message, "", 1);
		}
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_CONCAT_SV(_9, "Client credentials were not found in the headers", message);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 400);
		ZEPHIR_INIT_VAR(_10);
		ZVAL_STRING(_10, "invalid_client", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _2, _10, _9);
		zephir_check_temp_parameter(_10);
		zephir_check_call_status();
	}
	RETURN_MM_NULL();

}

