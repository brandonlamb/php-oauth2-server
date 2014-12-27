
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
#include "ext/spl/spl_exceptions.h"


/**
 * @package \OAuth2\GrantType
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
ZEPHIR_INIT_CLASS(OAuth2_GrantType_RefreshToken) {

	ZEPHIR_REGISTER_CLASS(OAuth2\\GrantType, RefreshToken, oauth2, granttype_refreshtoken, oauth2_granttype_refreshtoken_method_entry, 0);

	zend_declare_property_null(oauth2_granttype_refreshtoken_ce, SL("refreshToken"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(oauth2_granttype_refreshtoken_ce, SL("storage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_granttype_refreshtoken_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(oauth2_granttype_refreshtoken_ce TSRMLS_CC, 1, oauth2_granttype_granttypeinterface_ce);
	return SUCCESS;

}

/**
 * @param OAuth2\Storage\RefreshTokenInterface storage REQUIRED Storage class for retrieving refresh token information
 * @param array config  OPTIONAL Configuration options for the server
 * <code>
 * $config = array(
 * "always_issue_new_refresh_token": true, // whether to issue a new refresh token upon successful token request
 * );
 * </code>
 */
PHP_METHOD(OAuth2_GrantType_RefreshToken, __construct) {

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


	if (!(zephir_instance_of_ev(storage, oauth2_storage_refreshtokeninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'storage' must be an instance of 'OAuth2\\Storage\\RefreshTokenInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("storage"), storage TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 2);
	zephir_array_update_string(&_1, SL("always_issue_new_refresh_token"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_fast_array_merge(_0, &(_1), &(config) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("config"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(OAuth2_GrantType_RefreshToken, getQuerystringIdentifier) {


	RETURN_STRING("refresh_token", 1);

}

PHP_METHOD(OAuth2_GrantType_RefreshToken, validateRequest) {

	zend_bool _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *response, *refreshToken = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL, *_6, *_8, *_9 = NULL;

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
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "refresh_token", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, request, "request", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "invalid_request", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "Missing parameter: \"refresh_token\" is required", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "refresh_token", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_5, request, "request", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&refreshToken, _4, "getrefreshtoken", NULL, _5);
	zephir_check_call_status();
	if (!(zephir_is_true(refreshToken))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "Invalid refresh token", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_string(&_6, refreshToken, SL("expires"), PH_NOISY | PH_READONLY, "oauth2/granttype/refreshtoken.zep", 57 TSRMLS_CC);
	_7 = ZEPHIR_GT_LONG(_6, 0);
	if (_7) {
		zephir_array_fetch_string(&_8, refreshToken, SL("expires"), PH_NOISY | PH_READONLY, "oauth2/granttype/refreshtoken.zep", 57 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_9, "time", NULL);
		zephir_check_call_status();
		_7 = ZEPHIR_LT(_8, _9);
	}
	if (_7) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "Refresh token has expired", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_this(this_ptr, SL("refreshToken"), refreshToken TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

PHP_METHOD(OAuth2_GrantType_RefreshToken, getClientId) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("refreshToken"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("client_id"), PH_NOISY | PH_READONLY, "oauth2/granttype/refreshtoken.zep", 70 TSRMLS_CC);
	RETURN_CTORW(_1);

}

PHP_METHOD(OAuth2_GrantType_RefreshToken, getUserId) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("refreshToken"), PH_NOISY_CC);
	if (zephir_array_isset_string(_1, SS("user_id"))) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("refreshToken"), PH_NOISY_CC);
		zephir_array_fetch_string(&_0, _2, SL("user_id"), PH_NOISY, "oauth2/granttype/refreshtoken.zep", 75 TSRMLS_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(OAuth2_GrantType_RefreshToken, getScope) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("refreshToken"), PH_NOISY_CC);
	if (zephir_array_isset_string(_1, SS("scope"))) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("refreshToken"), PH_NOISY_CC);
		zephir_array_fetch_string(&_0, _2, SL("scope"), PH_NOISY, "oauth2/granttype/refreshtoken.zep", 80 TSRMLS_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(OAuth2_GrantType_RefreshToken, createAccessToken) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *client_id = NULL, *user_id = NULL, *scope = NULL;
	zval *accessToken, *client_id_param = NULL, *user_id_param = NULL, *scope_param = NULL, *issueNewRefreshToken, *token = NULL, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &accessToken, &client_id_param, &user_id_param, &scope_param);

	if (unlikely(Z_TYPE_P(client_id_param) != IS_STRING && Z_TYPE_P(client_id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'client_id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(client_id_param) == IS_STRING)) {
		zephir_get_strval(client_id, client_id_param);
	} else {
		ZEPHIR_INIT_VAR(client_id);
		ZVAL_EMPTY_STRING(client_id);
	}
	if (unlikely(Z_TYPE_P(user_id_param) != IS_STRING && Z_TYPE_P(user_id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'user_id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(user_id_param) == IS_STRING)) {
		zephir_get_strval(user_id, user_id_param);
	} else {
		ZEPHIR_INIT_VAR(user_id);
		ZVAL_EMPTY_STRING(user_id);
	}
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


	if (!(zephir_instance_of_ev(accessToken, oauth2_responsetype_accesstokeninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'accessToken' must be an instance of 'OAuth2\\ResponseType\\AccessTokenInterface'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(issueNewRefreshToken);
	zephir_array_fetch_string(&issueNewRefreshToken, _0, SL("always_issue_new_refresh_token"), PH_NOISY, "oauth2/granttype/refreshtoken.zep", 90 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&token, accessToken, "createaccesstoken", NULL, client_id, user_id, scope, issueNewRefreshToken);
	zephir_check_call_status();
	if (zephir_is_true(issueNewRefreshToken)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("refreshToken"), PH_NOISY_CC);
		zephir_array_fetch_string(&_3, _2, SL("refresh_token"), PH_NOISY | PH_READONLY, "oauth2/granttype/refreshtoken.zep", 94 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, _1, "unsetrefreshtoken", NULL, _3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(token);

}

