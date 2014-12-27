
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
#include "kernel/file.h"
#include "kernel/concat.h"


/**
 * @package \OAuth2\ResponseType
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
ZEPHIR_INIT_CLASS(OAuth2_ResponseType_AuthorizationCode) {

	ZEPHIR_REGISTER_CLASS(OAuth2\\ResponseType, AuthorizationCode, oauth2, responsetype_authorizationcode, oauth2_responsetype_authorizationcode_method_entry, 0);

	zend_declare_property_null(oauth2_responsetype_authorizationcode_ce, SL("storage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_responsetype_authorizationcode_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(oauth2_responsetype_authorizationcode_ce TSRMLS_CC, 1, oauth2_responsetype_authorizationcodeinterface_ce);
	return SUCCESS;

}

PHP_METHOD(OAuth2_ResponseType_AuthorizationCode, __construct) {

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


	if (!(zephir_instance_of_ev(storage, oauth2_storage_authorizationcodeinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'storage' must be an instance of 'OAuth2\\Storage\\AuthorizationCodeInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("storage"), storage TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 3);
	zephir_array_update_string(&_1, SL("enforce_redirect"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(_1, SS("auth_code_lifetime"), 30);
	zephir_fast_array_merge(_0, &(_1), &(config) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("config"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(OAuth2_ResponseType_AuthorizationCode, getAuthorizeResponse) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *user_id = NULL;
	zval *params = NULL, *user_id_param = NULL, *result, *_0 = NULL, *_2 = NULL, *_3, *_4, *_5, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params, &user_id_param);

	ZEPHIR_SEPARATE_PARAM(params);
	if (!user_id_param) {
		ZEPHIR_INIT_VAR(user_id);
		ZVAL_EMPTY_STRING(user_id);
	} else {
		zephir_get_strval(user_id, user_id_param);
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
	zephir_array_fetch_string(&_3, params, SL("client_id"), PH_NOISY | PH_READONLY, "oauth2/responsetype/authorizationcode.zep", 37 TSRMLS_CC);
	zephir_array_fetch_string(&_4, params, SL("redirect_uri"), PH_NOISY | PH_READONLY, "oauth2/responsetype/authorizationcode.zep", 37 TSRMLS_CC);
	zephir_array_fetch_string(&_5, params, SL("scope"), PH_NOISY | PH_READONLY, "oauth2/responsetype/authorizationcode.zep", 37 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "createauthorizationcode", NULL, _3, user_id, _4, _5);
	zephir_check_call_status();
	zephir_array_update_multi(&result, &_2 TSRMLS_CC, SL("ss"), 4, SL("query"), SL("code"));
	if (zephir_array_isset_string(params, SS("state"))) {
		zephir_array_fetch_string(&_6, params, SL("state"), PH_NOISY | PH_READONLY, "oauth2/responsetype/authorizationcode.zep", 40 TSRMLS_CC);
		zephir_array_update_multi(&result, &_6 TSRMLS_CC, SL("ss"), 4, SL("query"), SL("state"));
	}
	array_init_size(return_value, 3);
	ZEPHIR_OBS_VAR(_7);
	zephir_array_fetch_string(&_7, params, SL("redirect_uri"), PH_NOISY, "oauth2/responsetype/authorizationcode.zep", 43 TSRMLS_CC);
	zephir_array_fast_append(return_value, _7);
	zephir_array_fast_append(return_value, result);
	RETURN_MM();

}

/**
 * Handle the creation of the authorization code.
 *
 * @param string client_id Client identifier related to the authorization code
 * @param string user_id User ID associated with the authorization code
 * @param string redirect_uri An absolute URI to which the authorization server will redirect the
 * user-agent to when the end-user authorization step is completed.
 * @param string scope (optional) Scopes to be stored in space-separated string.
 * @return strin
 *
 * @see http://tools.ietf.org/html/rfc6749#section-4
 * @ingroup oauth2_section_4
 */
PHP_METHOD(OAuth2_ResponseType_AuthorizationCode, createAuthorizationCode) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *client_id_param = NULL, *user_id_param = NULL, *redirect_uri_param = NULL, *scope_param = NULL, *code = NULL, *_0, *_1 = NULL, *_2, *_3, *_4;
	zval *client_id = NULL, *user_id = NULL, *redirect_uri = NULL, *scope = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &client_id_param, &user_id_param, &redirect_uri_param, &scope_param);

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
	if (unlikely(Z_TYPE_P(redirect_uri_param) != IS_STRING && Z_TYPE_P(redirect_uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'redirect_uri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(redirect_uri_param) == IS_STRING)) {
		zephir_get_strval(redirect_uri, redirect_uri_param);
	} else {
		ZEPHIR_INIT_VAR(redirect_uri);
		ZVAL_EMPTY_STRING(redirect_uri);
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


	ZEPHIR_CALL_METHOD(&code, this_ptr, "generateauthorizationcode", NULL);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "time", NULL);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_3, _2, SL("auth_code_lifetime"), PH_NOISY | PH_READONLY, "oauth2/responsetype/authorizationcode.zep", 64 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_add_function(_4, _1, _3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setauthorizationcode", NULL, code, client_id, user_id, redirect_uri, _4, scope);
	zephir_check_call_status();
	RETURN_CCTOR(code);

}

/**
 * @return boolean  TRUE if the grant type requires a redirect_uri, FALSE if not
 */
PHP_METHOD(OAuth2_ResponseType_AuthorizationCode, enforceRedirect) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("enforce_redirect"), PH_NOISY | PH_READONLY, "oauth2/responsetype/authorizationcode.zep", 74 TSRMLS_CC);
	RETURN_CTORW(_1);

}

/**
 * Generates an unique auth code.
 *
 * Implementing classes may want to override this function to implement
 * other auth code generation schemes.
 *
 * @return string An unique auth code.
 *
 * @ingroup oauth2_section_4
 */
PHP_METHOD(OAuth2_ResponseType_AuthorizationCode, generateAuthorizationCode) {

	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_10 = NULL, *_13 = NULL, *_16 = NULL;
	int tokenLen, ZEPHIR_LAST_CALL_STATUS;
	zval *randomData = NULL, _0, _1 = zval_used_for_init, _2 = zval_used_for_init, *_3, _4, *_5 = NULL, *_7 = NULL, *_9 = NULL, *_11 = NULL, *_12 = NULL, *_14 = NULL, *_15 = NULL;

	ZEPHIR_MM_GROW();

	tokenLen = 40;
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "/dev/urandom", 0);
	if ((zephir_function_exists_ex(SS("mcrypt_create_iv") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, 100);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, 1);
		ZEPHIR_CALL_FUNCTION(&randomData, "mcrypt_create_iv", NULL, &_1, &_2);
		zephir_check_call_status();
	} else if ((zephir_function_exists_ex(SS("openssl_random_pseudo_bytes") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, 100);
		ZEPHIR_CALL_FUNCTION(&randomData, "openssl_random_pseudo_bytes", NULL, _3);
		zephir_check_call_status();
	} else if ((zephir_file_exists(&_0 TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "/dev/urandom", 0);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, 0);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_LONG(&_4, 100);
		ZEPHIR_CALL_FUNCTION(&_5, "file_get_contents", &_6, &_1, ZEPHIR_GLOBAL(global_false), ZEPHIR_GLOBAL(global_null), &_2, &_4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_7, "mt_rand", &_8);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_9, "uniqid", &_10, _7, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(randomData);
		ZEPHIR_CONCAT_VV(randomData, _5, _9);
	} else {
		ZEPHIR_CALL_FUNCTION(&_5, "mt_rand", &_8);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_7, "mt_rand", &_8);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_9, "mt_rand", &_8);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_11, "mt_rand", &_8);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_12, "microtime", &_13, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_14, "mt_rand", &_8);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_15, "uniqid", &_10, _14, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(randomData);
		ZEPHIR_CONCAT_VVVVVV(randomData, _5, _7, _9, _11, _12, _15);
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "sha512", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "hash", NULL, &_1, randomData);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, tokenLen);
	ZEPHIR_RETURN_CALL_FUNCTION("substr", &_16, _5, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

