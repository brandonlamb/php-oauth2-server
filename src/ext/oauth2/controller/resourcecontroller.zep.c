
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
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"


/**
 * @see OAuth2\Controller\ResourceControllerInterface
 */
ZEPHIR_INIT_CLASS(OAuth2_Controller_ResourceController) {

	ZEPHIR_REGISTER_CLASS(OAuth2\\Controller, ResourceController, oauth2, controller_resourcecontroller, oauth2_controller_resourcecontroller_method_entry, 0);

	zend_declare_property_null(oauth2_controller_resourcecontroller_ce, SL("token"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(oauth2_controller_resourcecontroller_ce, SL("tokenType"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_controller_resourcecontroller_ce, SL("tokenStorage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_controller_resourcecontroller_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_controller_resourcecontroller_ce, SL("scopeUtil"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(oauth2_controller_resourcecontroller_ce TSRMLS_CC, 1, oauth2_controller_resourcecontrollerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(OAuth2_Controller_ResourceController, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_4;
	zend_bool _0;
	zval *config = NULL, *_2;
	zval *tokenType, *tokenStorage, *config_param = NULL, *scopeUtil = NULL, *_1, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &tokenType, &tokenStorage, &config_param, &scopeUtil);

	if (!config_param) {
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	} else {
		zephir_get_arrval(config, config_param);
	}
	if (!scopeUtil) {
		scopeUtil = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_instance_of_ev(tokenType, oauth2_tokentype_tokentypeinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'tokenType' must be an instance of 'OAuth2\\TokenType\\TokenTypeInterface'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(tokenStorage, oauth2_storage_accesstokeninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'tokenStorage' must be an instance of 'OAuth2\\Storage\\AccessTokenInterface'", "", 0);
		return;
	}
	_0 = Z_TYPE_P(scopeUtil) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(scopeUtil, oauth2_scopeinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'scopeUtil' must be an instance of 'OAuth2\\ScopeInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("tokenType"), tokenType TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("tokenStorage"), tokenStorage TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 2);
	add_assoc_stringl_ex(_2, SS("www_realm"), SL("Service"), 1);
	zephir_fast_array_merge(_1, &(_2), &(config) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("config"), _1 TSRMLS_CC);
	if (Z_TYPE_P(scopeUtil) == IS_NULL) {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, spl_ce_LogicException);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SS(_4, "Must pass a scope to ", "ResourceController:__construct");
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "oauth2/controller/resourcecontroller.zep", 33 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("scopeUtil"), scopeUtil TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(OAuth2_Controller_ResourceController, verifyResourceRequest) {

	zephir_nts_static zephir_fcall_cache_entry *_19 = NULL;
	zval *_10;
	zend_bool _0, _1, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *scope = NULL;
	zval *request, *response, *scope_param = NULL, *token = NULL, *_2, *_4, *_5 = NULL, *_6, *_7 = NULL, *_8, *_9, *_11, *_12 = NULL, *_13, *_14, *_15 = NULL, *_16 = NULL, _17, *_18 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &request, &response, &scope_param);

	if (!scope_param) {
		ZEPHIR_INIT_VAR(scope);
		ZVAL_EMPTY_STRING(scope);
	} else {
	if (unlikely(Z_TYPE_P(scope_param) != IS_STRING && Z_TYPE_P(scope_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'scope' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(scope_param) == IS_STRING)) {
		zephir_get_strval(scope, scope_param);
	} else {
		ZEPHIR_INIT_VAR(scope);
		ZVAL_EMPTY_STRING(scope);
	}
	}


	if (!(zephir_instance_of_ev(request, oauth2_requestinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'request' must be an instance of 'OAuth2\\RequestInterface'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(response, oauth2_responseinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'response' must be an instance of 'OAuth2\\ResponseInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&token, this_ptr, "getaccesstokendata", NULL, request, response);
	zephir_check_call_status();
	if (Z_TYPE_P(token) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	_0 = zephir_is_true(scope);
	if (_0) {
		_1 = !zephir_array_isset_string(token, SS("scope"));
		if (!(_1)) {
			ZEPHIR_OBS_VAR(_2);
			zephir_array_fetch_string(&_2, token, SL("scope"), PH_NOISY, "oauth2/controller/resourcecontroller.zep", 54 TSRMLS_CC);
			_1 = !zephir_is_true(_2);
		}
		_3 = _1;
		if (!(_3)) {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("scopeUtil"), PH_NOISY_CC);
			zephir_array_fetch_string(&_6, token, SL("scope"), PH_NOISY | PH_READONLY, "oauth2/controller/resourcecontroller.zep", 54 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_5, _4, "checkscope", NULL, scope, _6);
			zephir_check_call_status();
			_3 = !zephir_is_true(_5);
		}
		_0 = _3;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_7);
		ZVAL_LONG(_7, 403);
		ZEPHIR_INIT_VAR(_8);
		ZVAL_STRING(_8, "insufficient_scope", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_9);
		ZVAL_STRING(_9, "The request requires higher privileges than provided by the access token", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _7, _8, _9);
		zephir_check_temp_parameter(_8);
		zephir_check_temp_parameter(_9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_10);
		array_init_size(_10, 2);
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("tokenType"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_12, _11, "gettokentype", NULL);
		zephir_check_call_status();
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_14, _13, SL("www_realm"), PH_NOISY | PH_READONLY, "oauth2/controller/resourcecontroller.zep", 60 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_STRING(_7, "error", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_15, response, "getparameter", NULL, _7);
		zephir_check_temp_parameter(_7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_STRING(_7, "error_description", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_16, response, "getparameter", NULL, _7);
		zephir_check_temp_parameter(_7);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_17);
		ZVAL_STRING(&_17, "%s realm=\"%s\", scope=\"%s\", error=\"%s\", error_description=\"%s\"", 0);
		ZEPHIR_CALL_FUNCTION(&_18, "sprintf", &_19, &_17, _12, _14, scope, _15, _16);
		zephir_check_call_status();
		zephir_array_update_string(&_10, SL("WWW-Authenticate"), &_18, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, response, "addhttpheaders", NULL, _10);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_this(this_ptr, SL("token"), token TSRMLS_CC);
	RETURN_MM_BOOL(zephir_get_boolval(token));

}

PHP_METHOD(OAuth2_Controller_ResourceController, getAccessTokenData) {

	zval *_13;
	zephir_nts_static zephir_fcall_cache_entry *_11 = NULL;
	zend_bool _2, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *response, *token_param = NULL, *token = NULL, *authHeader = NULL, *error = NULL, *error_description = NULL, *_0, *_1, *_4 = NULL, *_5, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9, _10 = zval_used_for_init, *_12 = NULL;

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
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("tokenType"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&token_param, _0, "getaccesstokenparameter", NULL, request, response);
	zephir_check_call_status();
	if (zephir_is_true(token_param)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("tokenStorage"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&token, _1, "getaccesstoken", NULL, token_param);
		zephir_check_call_status();
		_2 = !zephir_array_isset_string(token, SS("expires"));
		if (!(_2)) {
			_2 = !zephir_array_isset_string(token, SS("client_id"));
		}
		_3 = zephir_array_isset_string(token, SS("expires"));
		if (_3) {
			ZEPHIR_CALL_FUNCTION(&_4, "time", NULL);
			zephir_check_call_status();
			zephir_array_fetch_string(&_5, token, SL("expires"), PH_NOISY | PH_READONLY, "oauth2/controller/resourcecontroller.zep", 92 TSRMLS_CC);
			_3 = ZEPHIR_GT(_4, _5);
		}
		if (!(zephir_is_true(token))) {
			ZEPHIR_INIT_VAR(_6);
			ZVAL_LONG(_6, 401);
			ZEPHIR_INIT_VAR(_7);
			ZVAL_STRING(_7, "invalid_token", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_8);
			ZVAL_STRING(_8, "The access token provided is invalid", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _6, _7, _8);
			zephir_check_temp_parameter(_7);
			zephir_check_temp_parameter(_8);
			zephir_check_call_status();
		} else if (_2) {
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_LONG(_6, 401);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_STRING(_7, "malformed_token", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_STRING(_8, "Malformed token (missing \"expires\")", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _6, _7, _8);
			zephir_check_temp_parameter(_7);
			zephir_check_temp_parameter(_8);
			zephir_check_call_status();
		} else if (_3) {
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_LONG(_6, 401);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_STRING(_7, "expired_token", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_STRING(_8, "The access token provided has expired", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _6, _7, _8);
			zephir_check_temp_parameter(_7);
			zephir_check_temp_parameter(_8);
			zephir_check_call_status();
		} else {
			RETURN_CCTOR(token);
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("tokenType"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_4, _1, "gettokentype", NULL);
	zephir_check_call_status();
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_5, _9, SL("www_realm"), PH_NOISY | PH_READONLY, "oauth2/controller/resourcecontroller.zep", 103 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_STRING(&_10, "%s realm=\"%s\"", 0);
	ZEPHIR_CALL_FUNCTION(&authHeader, "sprintf", &_11, &_10, _4, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "error", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&error, response, "getparameter", NULL, _6);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	if (zephir_is_true(error)) {
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_STRING(&_10, "%s, error=\"%s\"", 0);
		ZEPHIR_CALL_FUNCTION(&_12, "sprintf", &_11, &_10, authHeader, error);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(authHeader, _12);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "error_description", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&error_description, response, "getparameter", NULL, _6);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		if (zephir_is_true(error_description)) {
			ZEPHIR_SINIT_NVAR(_10);
			ZVAL_STRING(&_10, "%s, error_description=\"%s\"", 0);
			ZEPHIR_CALL_FUNCTION(&_12, "sprintf", &_11, &_10, authHeader, error_description);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(authHeader, _12);
		}
	}
	ZEPHIR_INIT_VAR(_13);
	array_init_size(_13, 2);
	zephir_array_update_string(&_13, SL("WWW-Authenticate"), &authHeader, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, response, "addhttpheaders", NULL, _13);
	zephir_check_call_status();
	RETURN_MM_NULL();

}

PHP_METHOD(OAuth2_Controller_ResourceController, getToken) {


	RETURN_MEMBER(this_ptr, "token");

}

