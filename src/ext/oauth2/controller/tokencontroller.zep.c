
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
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * @see OAuth2\Controller\TokenControllerInterface
 */
ZEPHIR_INIT_CLASS(OAuth2_Controller_TokenController) {

	ZEPHIR_REGISTER_CLASS(OAuth2\\Controller, TokenController, oauth2, controller_tokencontroller, oauth2_controller_tokencontroller_method_entry, 0);

	zend_declare_property_null(oauth2_controller_tokencontroller_ce, SL("accessToken"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_controller_tokencontroller_ce, SL("grantTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_controller_tokencontroller_ce, SL("clientAssertionType"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_controller_tokencontroller_ce, SL("scopeUtil"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_controller_tokencontroller_ce, SL("clientStorage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(oauth2_controller_tokencontroller_ce TSRMLS_CC, 1, oauth2_controller_tokencontrollerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(OAuth2_Controller_TokenController, __construct) {

	zval *_10;
	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_3, *_6;
	HashPosition _2, _5;
	zend_bool _0, _1;
	zval *grantTypes = NULL;
	zval *accessToken, *clientStorage, *grantTypes_param = NULL, *clientAssertionType = NULL, *scopeUtil = NULL, *grantType = NULL, **_4, **_7, *_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &accessToken, &clientStorage, &grantTypes_param, &clientAssertionType, &scopeUtil);

	if (!grantTypes_param) {
		ZEPHIR_INIT_VAR(grantTypes);
		array_init(grantTypes);
	} else {
		zephir_get_arrval(grantTypes, grantTypes_param);
	}
	if (!clientAssertionType) {
		clientAssertionType = ZEPHIR_GLOBAL(global_null);
	}
	if (!scopeUtil) {
		scopeUtil = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_instance_of_ev(accessToken, oauth2_responsetype_accesstokeninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'accessToken' must be an instance of 'OAuth2\\ResponseType\\AccessTokenInterface'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(clientStorage, oauth2_storage_clientinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'clientStorage' must be an instance of 'OAuth2\\Storage\\ClientInterface'", "", 0);
		return;
	}
	_0 = Z_TYPE_P(clientAssertionType) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(clientAssertionType, oauth2_clientassertiontype_clientassertiontypeinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'clientAssertionType' must be an instance of 'OAuth2\\ClientAssertionType\\ClientAssertionTypeInterface'", "", 0);
		return;
	}
	_1 = Z_TYPE_P(scopeUtil) != IS_NULL;
	if (_1) {
		_1 = !zephir_instance_of_ev(scopeUtil, oauth2_scopeinterface_ce TSRMLS_CC);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'scopeUtil' must be an instance of 'OAuth2\\ScopeInterface'", "", 0);
		return;
	}
	if (Z_TYPE_P(clientAssertionType) == IS_NULL) {
		zephir_is_iterable(grantTypes, &_3, &_2, 0, 0, "oauth2/controller/tokencontroller.zep", 34);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(grantType, _4);
			if (!(zephir_instance_of_ev(grantType, oauth2_clientassertiontype_clientassertiontypeinterface_ce TSRMLS_CC))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "You must supply an instance of OAuth2\\ClientAssertionType\\ClientAssertionTypeInterface or only use grant types which implement OAuth2\\ClientAssertionType\\ClientAssertionTypeInterface", "oauth2/controller/tokencontroller.zep", 31);
				return;
			}
		}
	}
	zephir_update_property_this(this_ptr, SL("clientAssertionType"), clientAssertionType TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("accessToken"), accessToken TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("clientStorage"), clientStorage TSRMLS_CC);
	zephir_is_iterable(grantTypes, &_6, &_5, 0, 0, "oauth2/controller/tokencontroller.zep", 44);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(grantType, _7);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addgranttype", &_8, grantType);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(scopeUtil) == IS_NULL) {
		ZEPHIR_INIT_VAR(_9);
		object_init_ex(_9, spl_ce_LogicException);
		ZEPHIR_INIT_VAR(_10);
		ZEPHIR_CONCAT_SS(_10, "Must pass a scope to ", "TokenController:__construct");
		ZEPHIR_CALL_METHOD(NULL, _9, "__construct", NULL, _10);
		zephir_check_call_status();
		zephir_throw_exception_debug(_9, "oauth2/controller/tokencontroller.zep", 45 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("scopeUtil"), scopeUtil TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(OAuth2_Controller_TokenController, handleTokenRequest) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *response, *token = NULL, *_0;

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
	ZEPHIR_CALL_METHOD(&token, this_ptr, "grantaccesstoken", NULL, request, response);
	zephir_check_call_status();
	if (zephir_is_true(token)) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_LONG(_0, 200);
		ZEPHIR_CALL_METHOD(NULL, response, "setstatuscode", NULL, _0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, response, "addparameters", NULL, token);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_1);
		array_init_size(_1, 3);
		add_assoc_stringl_ex(_1, SS("Cache-Control"), SL("no-store"), 1);
		add_assoc_stringl_ex(_1, SS("Pragma"), SL("no-cache"), 1);
		ZEPHIR_CALL_METHOD(NULL, response, "addhttpheaders", NULL, _1);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Grant or deny a requested access token.
 * This would be called from the "/token" endpoint as defined in the spec.
 * You can call your endpoint whatever you want.
 *
 * @param RequestInterface request Request object to grant access token
 * @param ResponseInterface response
 *
 * @throws InvalidArgumentException
 * @throws LogicException
 *
 * @see http://tools.ietf.org/html/rfc6749#section-4
 * @see http://tools.ietf.org/html/rfc6749#section-10.6
 * @see http://tools.ietf.org/html/rfc6749#section-4.1.3
 *
 * @ingroup oauth2_section_4
 */
PHP_METHOD(OAuth2_Controller_TokenController, grantAccessToken) {

	zend_bool _14;
	zephir_nts_static zephir_fcall_cache_entry *_10 = NULL;
	zval *_6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *response, *grantTypeIdentifier = NULL, *grantType, *clientId = NULL, *storedClientId = NULL, *requestedScope = NULL, *availableScope = NULL, *clientScope = NULL, *defaultScope = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5, *_7, _8 = zval_used_for_init, *_9 = NULL, *_11, *_12, *_13, *_15, *_16, *_17 = NULL, *_18, *_19 = NULL;

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
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "REQUEST_METHOD", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, request, "server", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_fast_strtolower(_0, _1);
	if (!ZEPHIR_IS_STRING(_0, "post")) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 405);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "invalid_request", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "The request method must be POST when requesting an access token", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "#section-3.2", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _2, _3, _4, _5);
		zephir_check_temp_parameter(_3);
		zephir_check_temp_parameter(_4);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6);
		array_init_size(_6, 2);
		add_assoc_stringl_ex(_6, SS("Allow"), SL("POST"), 1);
		ZEPHIR_CALL_METHOD(NULL, response, "addhttpheaders", NULL, _6);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "grant_type", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&grantTypeIdentifier, request, "request", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!(zephir_is_true(grantTypeIdentifier))) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 400);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "invalid_request", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "The grant type was not specified in the request", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _2, _3, _4);
		zephir_check_temp_parameter(_3);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("grantTypes"), PH_NOISY_CC);
	if (!(zephir_array_isset(_7, grantTypeIdentifier))) {
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_STRING(&_8, "Grant type \"%s\" not supported", 0);
		ZEPHIR_CALL_FUNCTION(&_9, "sprintf", &_10, &_8, grantTypeIdentifier);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 400);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "unsupported_grant_type", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _2, _3, _9);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("grantTypes"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(grantType);
	zephir_array_fetch(&grantType, _11, grantTypeIdentifier, PH_NOISY, "oauth2/controller/tokencontroller.zep", 108 TSRMLS_CC);
	if (!(zephir_instance_of_ev(grantType, oauth2_clientassertiontype_clientassertiontypeinterface_ce TSRMLS_CC))) {
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("clientAssertionType"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_9, _12, "validaterequest", NULL, request, response);
		zephir_check_call_status();
		if (!(zephir_is_true(_9))) {
			RETURN_MM_NULL();
		}
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("clientAssertionType"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&clientId, _13, "getclientid", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_9, grantType, "validaterequest", NULL, request, response);
	zephir_check_call_status();
	if (!(zephir_is_true(_9))) {
		RETURN_MM_NULL();
	}
	if (zephir_instance_of_ev(grantType, oauth2_clientassertiontype_clientassertiontypeinterface_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&clientId, grantType, "getclientid", NULL);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&storedClientId, grantType, "getclientid", NULL);
		zephir_check_call_status();
		_14 = Z_TYPE_P(storedClientId) != IS_NULL;
		if (_14) {
			_14 = !ZEPHIR_IS_EQUAL(storedClientId, clientId);
		}
		if (_14) {
			ZEPHIR_SINIT_NVAR(_8);
			ZVAL_STRING(&_8, "%s doesn't exist or is invalid for the client", 0);
			ZEPHIR_CALL_FUNCTION(&_9, "sprintf", &_10, &_8, grantTypeIdentifier);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_LONG(_2, 400);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _2, _3, _9);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
	}
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("clientStorage"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_9, _12, "checkrestrictedgranttype", NULL, clientId, grantTypeIdentifier);
	zephir_check_call_status();
	if (!(zephir_is_true(_9))) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 400);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "unauthorized_client", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "The grant type is unauthorized for this client_id", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _2, _3, _4);
		zephir_check_temp_parameter(_3);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("scopeUtil"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&requestedScope, _12, "getscopefromrequest", NULL, request);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&availableScope, grantType, "getscope", NULL);
	zephir_check_call_status();
	if (zephir_is_true(requestedScope)) {
		if (zephir_is_true(availableScope)) {
			_13 = zephir_fetch_nproperty_this(this_ptr, SL("scopeUtil"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_9, _13, "checkscope", NULL, requestedScope, availableScope);
			zephir_check_call_status();
			if (!(zephir_is_true(_9))) {
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_LONG(_2, 400);
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_STRING(_3, "invalid_scope", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_4);
				ZVAL_STRING(_4, "The scope requested is invalid for this request", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _2, _3, _4);
				zephir_check_temp_parameter(_3);
				zephir_check_temp_parameter(_4);
				zephir_check_call_status();
				RETURN_MM_NULL();
			}
		} else {
			_15 = zephir_fetch_nproperty_this(this_ptr, SL("clientStorage"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&clientScope, _15, "getclientscope", NULL, clientId);
			zephir_check_call_status();
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("scopeUtil"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_17, _16, "scopeexists", NULL, requestedScope);
			zephir_check_call_status();
			if (zephir_is_true(clientScope)) {
				_18 = zephir_fetch_nproperty_this(this_ptr, SL("scopeUtil"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_19, _18, "checkscope", NULL, requestedScope, clientScope);
				zephir_check_call_status();
				if (!(zephir_is_true(_19))) {
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_LONG(_2, 400);
					ZEPHIR_INIT_NVAR(_3);
					ZVAL_STRING(_3, "invalid_scope", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_INIT_NVAR(_4);
					ZVAL_STRING(_4, "The scope requested is invalid for this client", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _2, _3, _4);
					zephir_check_temp_parameter(_3);
					zephir_check_temp_parameter(_4);
					zephir_check_call_status();
					RETURN_MM_NULL();
				}
			} else if (!(zephir_is_true(_17))) {
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_LONG(_2, 400);
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_STRING(_3, "invalid_scope", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_4);
				ZVAL_STRING(_4, "An unsupported scope was requested", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _2, _3, _4);
				zephir_check_temp_parameter(_3);
				zephir_check_temp_parameter(_4);
				zephir_check_call_status();
				RETURN_MM_NULL();
			}
		}
	} else if (zephir_is_true(availableScope)) {
		ZEPHIR_CPY_WRT(requestedScope, availableScope);
	} else {
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("scopeUtil"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&defaultScope, _12, "getdefaultscope", NULL, clientId);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(defaultScope)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_LONG(_2, 400);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "invalid_scope", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "This application requires you specify a scope parameter", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _2, _3, _4);
			zephir_check_temp_parameter(_3);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
		ZEPHIR_CPY_WRT(requestedScope, defaultScope);
	}
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("accessToken"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_9, grantType, "getuserid", NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(grantType, "createaccesstoken", NULL, _12, clientId, _9, requestedScope);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * addGrantType
 *
 * @param grantType - OAuth2\GrantTypeInterface
 * the grant type to add for the specified identifier
 * @param identifier - string
 * a string passed in as "grant_type" in the response that will call this grantType
 */
PHP_METHOD(OAuth2_Controller_TokenController, addGrantType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *grantType, *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &grantType, &identifier);

	if (!identifier) {
		ZEPHIR_CPY_WRT(identifier, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(identifier);
	}


	if (!(zephir_instance_of_ev(grantType, oauth2_granttype_granttypeinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'grantType' must be an instance of 'OAuth2\\GrantType\\GrantTypeInterface'", "", 0);
		return;
	}
	_0 = Z_TYPE_P(identifier) == IS_NULL;
	if (!(_0)) {
		_0 = zephir_is_numeric(identifier);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&identifier, grantType, "getquerystringidentifier", NULL);
		zephir_check_call_status();
	}
	zephir_update_property_array(this_ptr, SL("grantTypes"), identifier, grantType TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

