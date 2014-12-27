
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
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/concat.h"


/**
 * @package \OAuth2\ResponseType
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
ZEPHIR_INIT_CLASS(OAuth2_ResponseType_AccessToken) {

	ZEPHIR_REGISTER_CLASS(OAuth2\\ResponseType, AccessToken, oauth2, responsetype_accesstoken, oauth2_responsetype_accesstoken_method_entry, 0);

	zend_declare_property_null(oauth2_responsetype_accesstoken_ce, SL("tokenStorage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_responsetype_accesstoken_ce, SL("refreshStorage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_responsetype_accesstoken_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(oauth2_responsetype_accesstoken_ce TSRMLS_CC, 1, oauth2_responsetype_accesstokeninterface_ce);
	return SUCCESS;

}

/**
 * @param OAuth2\Storage\AccessTokenInterface tokenStorage Storage class for saving access token information
 * @param OAuth2\Storage\RefreshTokenInterface refreshStorage OPTIONAL Storage class for saving refresh token information
 * @param array config OPTIONAL Configuration options for the server
 * <code>
 * $config = array(
 * "token_type": "bearer",              // token type identifier
 * "access_lifetime": 3600,             // time before access token expires
 * "refresh_token_lifetime": 1209600,   // time before refresh token expires
 * );
 * </endcode>
 */
PHP_METHOD(OAuth2_ResponseType_AccessToken, __construct) {

	zend_bool _0;
	zval *config = NULL, *_2;
	zval *tokenStorage, *refreshStorage = NULL, *config_param = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &tokenStorage, &refreshStorage, &config_param);

	if (!refreshStorage) {
		refreshStorage = ZEPHIR_GLOBAL(global_null);
	}
	if (!config_param) {
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	} else {
		zephir_get_arrval(config, config_param);
	}


	if (!(zephir_instance_of_ev(tokenStorage, oauth2_storage_accesstokeninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'tokenStorage' must be an instance of 'OAuth2\\Storage\\AccessTokenInterface'", "", 0);
		return;
	}
	_0 = Z_TYPE_P(refreshStorage) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(refreshStorage, oauth2_storage_refreshtokeninterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'refreshStorage' must be an instance of 'OAuth2\\Storage\\RefreshTokenInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("tokenStorage"), tokenStorage TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("refreshStorage"), refreshStorage TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 4);
	add_assoc_stringl_ex(_2, SS("token_type"), SL("bearer"), 1);
	add_assoc_long_ex(_2, SS("access_lifetime"), 3600);
	add_assoc_long_ex(_2, SS("refresh_token_lifetime"), 1209600);
	zephir_fast_array_merge(_1, &(_2), &(config) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("config"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(OAuth2_ResponseType_AccessToken, getAuthorizeResponse) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zend_bool includeRefreshToken;
	zval *user_id = NULL;
	zval *params = NULL, *user_id_param = NULL, *result, *_0 = NULL, *_2 = NULL, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params, &user_id_param);

	ZEPHIR_SEPARATE_PARAM(params);
	if (!user_id_param) {
		ZEPHIR_INIT_VAR(user_id);
		ZVAL_EMPTY_STRING(user_id);
	} else {
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
	}


	ZEPHIR_INIT_VAR(result);
	array_init_size(result, 2);
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_array_update_string(&result, SL("query"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 3);
	zephir_array_update_string(&_1, SL("scope"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("state"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_fast_array_merge(_0, &(_1), &(params) TSRMLS_CC);
	ZEPHIR_CPY_WRT(params, _0);
	includeRefreshToken = 0;
	zephir_array_fetch_string(&_3, params, SL("client_id"), PH_NOISY | PH_READONLY, "oauth2/responsetype/accesstoken.zep", 58 TSRMLS_CC);
	zephir_array_fetch_string(&_4, params, SL("scope"), PH_NOISY | PH_READONLY, "oauth2/responsetype/accesstoken.zep", 58 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "createaccesstoken", NULL, _3, user_id, _4, (includeRefreshToken ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	zephir_array_update_string(&result, SL("fragment"), &_2, PH_COPY | PH_SEPARATE);
	if (zephir_array_isset_string(params, SS("state"))) {
		zephir_array_fetch_string(&_5, params, SL("state"), PH_NOISY | PH_READONLY, "oauth2/responsetype/accesstoken.zep", 61 TSRMLS_CC);
		zephir_array_update_multi(&result, &_5 TSRMLS_CC, SL("ss"), 4, SL("fragment"), SL("state"));
	}
	array_init_size(return_value, 3);
	ZEPHIR_OBS_VAR(_6);
	zephir_array_fetch_string(&_6, params, SL("redirect_uri"), PH_NOISY, "oauth2/responsetype/accesstoken.zep", 64 TSRMLS_CC);
	zephir_array_fast_append(return_value, _6);
	zephir_array_fast_append(return_value, result);
	RETURN_MM();

}

/**
 * Handle the creation of access token, also issue refresh token if supported / desirable.
 *
 * @param string client_id client identifier related to the access token.
 * @param string user_id user ID associated with the access token
 * @param $scope OPTIONAL scopes to be stored in space-separated string.
 * @param bool includeRefreshToken if true, a new refresh_token will be added to the response
 * @return string
 *
 * @see http://tools.ietf.org/html/rfc6749#section-5
 * @ingroup oauth2_section_5
 */
PHP_METHOD(OAuth2_ResponseType_AccessToken, createAccessToken) {

	zephir_fcall_cache_entry *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool includeRefreshToken, _12;
	zval *client_id_param = NULL, *user_id_param = NULL, *scope_param = NULL, *includeRefreshToken_param = NULL, *token, *expires = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, *_4, *_5, *_6 = NULL, *_7, *_8, *_10, *_11, *_13, *_14, *_15 = NULL, *_16, *_17;
	zval *client_id = NULL, *user_id = NULL, *scope = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &client_id_param, &user_id_param, &scope_param, &includeRefreshToken_param);

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
	if (!includeRefreshToken_param) {
		includeRefreshToken = 1;
	} else {
		includeRefreshToken = zephir_get_boolval(includeRefreshToken_param);
	}


	ZEPHIR_INIT_VAR(token);
	array_init_size(token, 6);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "generateaccesstoken", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&token, SL("access_token"), &_0, PH_COPY | PH_SEPARATE);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_array_fetch_string(&_2, _1, SL("access_lifetime"), PH_NOISY, "oauth2/responsetype/accesstoken.zep", 85 TSRMLS_CC);
	zephir_array_update_string(&token, SL("expires_in"), &_2, PH_COPY | PH_SEPARATE);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_NVAR(_2);
	zephir_array_fetch_string(&_2, _3, SL("token_type"), PH_NOISY, "oauth2/responsetype/accesstoken.zep", 86 TSRMLS_CC);
	zephir_array_update_string(&token, SL("token_type"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&token, SL("scope"), &scope, PH_COPY | PH_SEPARATE);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("tokenStorage"), PH_NOISY_CC);
	zephir_array_fetch_string(&_5, token, SL("access_token"), PH_NOISY | PH_READONLY, "oauth2/responsetype/accesstoken.zep", 90 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_8, _7, SL("access_lifetime"), PH_NOISY | PH_READONLY, "oauth2/responsetype/accesstoken.zep", 90 TSRMLS_CC);
	if (zephir_is_true(_8)) {
		ZEPHIR_CALL_FUNCTION(&_0, "time", &_9);
		zephir_check_call_status();
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_11, _10, SL("access_lifetime"), PH_NOISY | PH_READONLY, "oauth2/responsetype/accesstoken.zep", 90 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_6);
		zephir_add_function(_6, _0, _11 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_NULL(_6);
	}
	ZEPHIR_CALL_METHOD(NULL, _4, "setaccesstoken", NULL, _5, client_id, user_id, _6, scope);
	zephir_check_call_status();
	_12 = includeRefreshToken;
	if (_12) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("refreshStorage"), PH_NOISY_CC);
		_12 = zephir_is_true(_13);
	}
	if (_12) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "generaterefreshtoken", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&token, SL("refresh_token"), &_0, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(expires);
		ZVAL_LONG(expires, 0);
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_11, _14, SL("refresh_token_lifetime"), PH_NOISY | PH_READONLY, "oauth2/responsetype/accesstoken.zep", 98 TSRMLS_CC);
		if (ZEPHIR_GT_LONG(_11, 0)) {
			ZEPHIR_CALL_FUNCTION(&_15, "time", &_9);
			zephir_check_call_status();
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
			zephir_array_fetch_string(&_17, _16, SL("refresh_token_lifetime"), PH_NOISY | PH_READONLY, "oauth2/responsetype/accesstoken.zep", 99 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(expires);
			zephir_add_function(expires, _15, _17 TSRMLS_CC);
		}
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("refreshStorage"), PH_NOISY_CC);
		zephir_array_fetch_string(&_17, token, SL("refresh_token"), PH_NOISY | PH_READONLY, "oauth2/responsetype/accesstoken.zep", 101 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, _16, "setrefreshtoken", NULL, _17, client_id, user_id, expires, scope);
		zephir_check_call_status();
	}
	RETURN_CCTOR(token);

}

/**
 * Generates an unique access token.
 *
 * Implementing classes may want to override this function to implement
 * other access token generation schemes.
 *
 * @return string An unique access token.
 *
 * @ingroup oauth2_section_4
 */
PHP_METHOD(OAuth2_ResponseType_AccessToken, generateAccessToken) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_7 = NULL, *_9 = NULL, *_14 = NULL, *_17 = NULL, *_19 = NULL;
	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *randomData = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init, *_4, _5, _6, *_8 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_15 = NULL, *_16 = NULL, *_18 = NULL;

	ZEPHIR_MM_GROW();

	if ((zephir_function_exists_ex(SS("mcrypt_create_iv") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, 20);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, 1);
		ZEPHIR_CALL_FUNCTION(&randomData, "mcrypt_create_iv", NULL, &_0, &_1);
		zephir_check_call_status();
		_2 = !ZEPHIR_IS_FALSE_IDENTICAL(randomData);
		if (_2) {
			_2 = zephir_fast_strlen_ev(randomData) == 20;
		}
		if (_2) {
			ZEPHIR_RETURN_CALL_FUNCTION("bin2hex", &_3, randomData);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	if ((zephir_function_exists_ex(SS("openssl_random_pseudo_bytes") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, 20);
		ZEPHIR_CALL_FUNCTION(&randomData, "openssl_random_pseudo_bytes", NULL, _4);
		zephir_check_call_status();
		_2 = !ZEPHIR_IS_FALSE_IDENTICAL(randomData);
		if (_2) {
			_2 = zephir_fast_strlen_ev(randomData) == 20;
		}
		if (_2) {
			ZEPHIR_RETURN_CALL_FUNCTION("bin2hex", &_3, randomData);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "/dev/urandom", 0);
	if ((zephir_file_exists(&_0 TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "/dev/urandom", 0);
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_LONG(&_5, 0);
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_LONG(&_6, 20);
		ZEPHIR_CALL_FUNCTION(&randomData, "file_get_contents", &_7, &_1, ZEPHIR_GLOBAL(global_false), ZEPHIR_GLOBAL(global_null), &_5, &_6);
		zephir_check_call_status();
		_2 = !ZEPHIR_IS_FALSE_IDENTICAL(randomData);
		if (_2) {
			_2 = zephir_fast_strlen_ev(randomData) == 20;
		}
		if (_2) {
			ZEPHIR_RETURN_CALL_FUNCTION("bin2hex", &_3, randomData);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_CALL_FUNCTION(&_8, "mt_rand", &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_10, "mt_rand", &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_11, "mt_rand", &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_12, "mt_rand", &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_13, "microtime", &_14, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_15, "mt_rand", &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_16, "uniqid", &_17, _15, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(randomData);
	ZEPHIR_CONCAT_VVVVVV(randomData, _8, _10, _11, _12, _13, _16);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "sha512", 0);
	ZEPHIR_CALL_FUNCTION(&_18, "hash", NULL, &_0, randomData);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 40);
	ZEPHIR_RETURN_CALL_FUNCTION("substr", &_19, _18, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generates an unique refresh token
 *
 * Implementing classes may want to override this function to implement
 * other refresh token generation schemes.
 *
 * @return string An unique refresh.
 *
 * @ingroup oauth2_section_4
 * @see OAuth2::generateAccessToken()
 */
PHP_METHOD(OAuth2_ResponseType_AccessToken, generateRefreshToken) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "generateaccesstoken", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

