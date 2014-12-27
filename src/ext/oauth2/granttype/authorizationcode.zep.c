
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


/**
 * @package \OAuth2\GrantType
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
ZEPHIR_INIT_CLASS(OAuth2_GrantType_AuthorizationCode) {

	ZEPHIR_REGISTER_CLASS(OAuth2\\GrantType, AuthorizationCode, oauth2, granttype_authorizationcode, oauth2_granttype_authorizationcode_method_entry, 0);

	zend_declare_property_null(oauth2_granttype_authorizationcode_ce, SL("storage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_granttype_authorizationcode_ce, SL("authCode"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(oauth2_granttype_authorizationcode_ce TSRMLS_CC, 1, oauth2_granttype_granttypeinterface_ce);
	return SUCCESS;

}

/**
 * @param OAuth2\Storage\AuthorizationCodeInterface storage REQUIRED Storage class for retrieving authorization code information
 */
PHP_METHOD(OAuth2_GrantType_AuthorizationCode, __construct) {

	zval *storage;

	zephir_fetch_params(0, 1, 0, &storage);



	if (!(zephir_instance_of_ev(storage, oauth2_storage_authorizationcodeinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'storage' must be an instance of 'OAuth2\\Storage\\AuthorizationCodeInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("storage"), storage TSRMLS_CC);

}

PHP_METHOD(OAuth2_GrantType_AuthorizationCode, getQuerystringIdentifier) {


	RETURN_STRING("authorization_code", 1);

}

PHP_METHOD(OAuth2_GrantType_AuthorizationCode, validateRequest) {

	zephir_nts_static zephir_fcall_cache_entry *_11 = NULL;
	zend_bool _5, _8;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *response, *code = NULL, *authCode = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4, *_6, *_7 = NULL, *_9 = NULL, *_10 = NULL, *_12, *_13;

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
	ZVAL_STRING(_1, "code", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, request, "request", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "invalid_request", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "Missing parameter: \"code\" is required", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "code", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&code, request, "request", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&authCode, _4, "getauthorizationcode", NULL, code);
	zephir_check_call_status();
	if (!(zephir_is_true(authCode))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "Authorization code doesn't exist or is invalid for the client", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_5 = zephir_array_isset_string(authCode, SS("redirect_uri"));
	if (_5) {
		zephir_array_fetch_string(&_6, authCode, SL("redirect_uri"), PH_NOISY | PH_READONLY, "oauth2/granttype/authorizationcode.zep", 51 TSRMLS_CC);
		_5 = zephir_is_true(_6);
	}
	if (_5) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "redirect_uri", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_7, request, "request", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		_8 = !zephir_is_true(_7);
		if (!(_8)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "redirect_uri", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_9, request, "request", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_10, "urldecode", &_11, _9);
			zephir_check_call_status();
			zephir_array_fetch_string(&_12, authCode, SL("redirect_uri"), PH_NOISY | PH_READONLY, "oauth2/granttype/authorizationcode.zep", 52 TSRMLS_CC);
			_8 = !ZEPHIR_IS_EQUAL(_10, _12);
		}
		if (_8) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_LONG(_1, 400);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "redirect_uri_mismatch", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "The redirect URI is missing or do not match", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_13);
			ZVAL_STRING(_13, "#section-4.1.3", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3, _13);
			zephir_check_temp_parameter(_2);
			zephir_check_temp_parameter(_3);
			zephir_check_temp_parameter(_13);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	if (!(zephir_array_isset_string(authCode, SS("expires")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Storage must return authcode with a value for \"expires\"", "oauth2/granttype/authorizationcode.zep", 59);
		return;
	}
	zephir_array_fetch_string(&_12, authCode, SL("expires"), PH_NOISY | PH_READONLY, "oauth2/granttype/authorizationcode.zep", 62 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_7, "time", NULL);
	zephir_check_call_status();
	if (ZEPHIR_LT(_12, _7)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "The authorization code has expired", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_array_isset_string(authCode, SS("code")))) {
		zephir_array_update_string(&authCode, SL("code"), &code, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_this(this_ptr, SL("authCode"), authCode TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

PHP_METHOD(OAuth2_GrantType_AuthorizationCode, getClientId) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("authCode"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("client_id"), PH_NOISY | PH_READONLY, "oauth2/granttype/authorizationcode.zep", 79 TSRMLS_CC);
	RETURN_CTORW(_1);

}

PHP_METHOD(OAuth2_GrantType_AuthorizationCode, getScope) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("authCode"), PH_NOISY_CC);
	if (zephir_array_isset_string(_1, SS("scope"))) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("authCode"), PH_NOISY_CC);
		zephir_array_fetch_string(&_0, _2, SL("scope"), PH_NOISY, "oauth2/granttype/authorizationcode.zep", 84 TSRMLS_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(OAuth2_GrantType_AuthorizationCode, getUserId) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("authCode"), PH_NOISY_CC);
	if (zephir_array_isset_string(_1, SS("user_id"))) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("authCode"), PH_NOISY_CC);
		zephir_array_fetch_string(&_0, _2, SL("user_id"), PH_NOISY, "oauth2/granttype/authorizationcode.zep", 89 TSRMLS_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(OAuth2_GrantType_AuthorizationCode, createAccessToken) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *client_id = NULL, *user_id = NULL, *scope = NULL;
	zval *accessToken, *client_id_param = NULL, *user_id_param = NULL, *scope_param = NULL, *token = NULL, *_0, *_1, *_2;

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
	ZEPHIR_CALL_METHOD(&token, accessToken, "createaccesstoken", NULL, client_id, user_id, scope);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("authCode"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("code"), PH_NOISY | PH_READONLY, "oauth2/granttype/authorizationcode.zep", 96 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "expireauthorizationcode", NULL, _2);
	zephir_check_call_status();
	RETURN_CCTOR(token);

}

