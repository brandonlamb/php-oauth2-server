
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * The JWT bearer authorization grant implements JWT (JSON Web Tokens) as a grant type per the IETF draft.
 *
 * @see http://tools.ietf.org/html/draft-ietf-oauth-jwt-bearer-04#section-4
 *
 * @author F21
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
ZEPHIR_INIT_CLASS(OAuth2_GrantType_JwtBearer) {

	ZEPHIR_REGISTER_CLASS(OAuth2\\GrantType, JwtBearer, oauth2, granttype_jwtbearer, oauth2_granttype_jwtbearer_method_entry, 0);

	zend_declare_property_null(oauth2_granttype_jwtbearer_ce, SL("jwt"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(oauth2_granttype_jwtbearer_ce, SL("storage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_granttype_jwtbearer_ce, SL("audience"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_granttype_jwtbearer_ce, SL("jwtUtil"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(oauth2_granttype_jwtbearer_ce TSRMLS_CC, 1, oauth2_granttype_granttypeinterface_ce);
	zend_class_implements(oauth2_granttype_jwtbearer_ce TSRMLS_CC, 1, oauth2_clientassertiontype_clientassertiontypeinterface_ce);
	return SUCCESS;

}

/**
 * Creates an instance of the JWT bearer grant type.
 *
 * @param OAuth2\Storage\JWTBearerInterface storage A valid storage interface that implements storage hooks for the JWT bearer grant type.
 * @param string audience The audience to validate the token against. This is usually the full URI of the OAuth token requests endpoint.
 * @param OAuth2\Encryption\Jwt jwtUtil OPTONAL The class used to decode, encode and verify JWTs.
 */
PHP_METHOD(OAuth2_GrantType_JwtBearer, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zend_class_entry *_1 = NULL;
	zend_bool _0;
	zval *audience = NULL;
	zval *storage, *audience_param = NULL, *jwtUtil = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &storage, &audience_param, &jwtUtil);

	if (unlikely(Z_TYPE_P(audience_param) != IS_STRING && Z_TYPE_P(audience_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'audience' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(audience_param) == IS_STRING)) {
		zephir_get_strval(audience, audience_param);
	} else {
		ZEPHIR_INIT_VAR(audience);
		ZVAL_EMPTY_STRING(audience);
	}
	if (!jwtUtil) {
		ZEPHIR_CPY_WRT(jwtUtil, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(jwtUtil);
	}


	if (!(zephir_instance_of_ev(storage, oauth2_storage_jwtbearerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'storage' must be an instance of 'OAuth2\\Storage\\JwtBearerInterface'", "", 0);
		return;
	}
	_0 = Z_TYPE_P(jwtUtil) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(jwtUtil, oauth2_encryption_encryptioninterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'jwtUtil' must be an instance of 'OAuth2\\Encryption\\EncryptionInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("storage"), storage TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("audience"), audience TSRMLS_CC);
	if (Z_TYPE_P(jwtUtil) == IS_NULL) {
		ZEPHIR_INIT_NVAR(jwtUtil);
		if (!_1) {
			_1 = zend_fetch_class(SL("OAuth2\\Encryption\\Jwt"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(jwtUtil, _1);
		if (zephir_has_constructor(jwtUtil TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, jwtUtil, "__construct", NULL);
			zephir_check_call_status();
		}
	}
	zephir_update_property_this(this_ptr, SL("jwtUtil"), jwtUtil TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the grant_type get parameter to identify the grant type request as JWT bearer authorization grant.
 *
 * @return string The string identifier for grant_type.
 *
 * @see OAuth2\GrantType\GrantTypeInterface::getQuerystringIdentifier()
 */
PHP_METHOD(OAuth2_GrantType_JwtBearer, getQuerystringIdentifier) {


	RETURN_STRING("urn:ietf:params:oauth:grant-type:jwt-bearer", 1);

}

/**
 * Validates the data from the decoded JWT.
 *
 * @return boolean  TRUE if the JWT request is valid and can be decoded. Otherwise, FALSE is returned.
 *
 * @see OAuth2\GrantType\GrantTypeInterface::getTokenData()
 */
PHP_METHOD(OAuth2_GrantType_JwtBearer, validateRequest) {

	zend_bool _14, _21;
	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL;
	zval *_6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *response, *undecodedJWT = NULL, *jwt = NULL, *notBefore, *jti = NULL, *key = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL, *_7, *_8 = NULL, *_10, *_11 = NULL, *_13 = NULL, *_15, *_16, *_17, *_18, *_19, *_20, *_22, *_23, *_24, *_25, *_26, *_27, *_28;

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
	ZVAL_STRING(_1, "assertion", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, request, "request", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "invalid_request", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "Missing parameters: \"assertion\" required", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "assertion", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&undecodedJWT, request, "request", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("jwtUtil"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "assertion", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_5, request, "request", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_NULL(_1);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_BOOL(_2, 0);
	ZEPHIR_CALL_METHOD(&jwt, _4, "decode", NULL, _5, _1, _2);
	zephir_check_call_status();
	if (!(zephir_is_true(jwt))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "invalid_request", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "JWT is malformed", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZEPHIR_INIT_VAR(_6);
	array_init_size(_6, 12);
	zephir_array_update_string(&_6, SL("scope"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("iss"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("sub"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("aud"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("exp"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("nbf"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("iat"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("jti"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("typ"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_fast_array_merge(_1, &(_6), &(jwt) TSRMLS_CC);
	ZEPHIR_CPY_WRT(jwt, _1);
	if (!(zephir_array_isset_string(jwt, SS("iss")))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "Invalid issuer (iss) provided", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_array_isset_string(jwt, SS("sub")))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "Invalid subject (sub) provided", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_array_isset_string(jwt, SS("exp")))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "Expiration (exp) time must be present", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_string(&_7, jwt, SL("exp"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 115 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_8, "ctype_digit", &_9, _7);
	zephir_check_call_status();
	if (zephir_is_true(_8)) {
		zephir_array_fetch_string(&_10, jwt, SL("exp"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 116 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "time", &_12);
		zephir_check_call_status();
		if (ZEPHIR_LE(_10, _11)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_LONG(_1, 400);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "JWT has expired", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
			zephir_check_temp_parameter(_2);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "Expiration (exp) time must be a unix time stamp", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(notBefore);
	zephir_array_fetch_string(&notBefore, jwt, SL("nbf"), PH_NOISY, "oauth2/granttype/jwtbearer.zep", 126 TSRMLS_CC);
	if (zephir_is_true(notBefore)) {
		ZEPHIR_CALL_FUNCTION(&_11, "ctype_digit", &_9, notBefore);
		zephir_check_call_status();
		if (zephir_is_true(_11)) {
			ZEPHIR_CALL_FUNCTION(&_13, "time", &_12);
			zephir_check_call_status();
			if (ZEPHIR_GT(notBefore, _13)) {
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_LONG(_1, 400);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_STRING(_3, "JWT cannot be used before the Not Before (nbf) time", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
				zephir_check_temp_parameter(_2);
				zephir_check_temp_parameter(_3);
				zephir_check_call_status();
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_LONG(_1, 400);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "Not Before (nbf) time must be a unix time stamp", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
			zephir_check_temp_parameter(_2);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	_14 = !zephir_array_isset_string(jwt, SS("aud"));
	if (!(_14)) {
		zephir_array_fetch_string(&_10, jwt, SL("aud"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 140 TSRMLS_CC);
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("audience"), PH_NOISY_CC);
		_14 = !ZEPHIR_IS_EQUAL(_10, _15);
	}
	if (_14) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "Invalid audience (aud)", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	if (zephir_array_isset_string(jwt, SS("jti"))) {
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
		zephir_array_fetch_string(&_10, jwt, SL("iss"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 148 TSRMLS_CC);
		zephir_array_fetch_string(&_17, jwt, SL("sub"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 148 TSRMLS_CC);
		zephir_array_fetch_string(&_18, jwt, SL("aud"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 148 TSRMLS_CC);
		zephir_array_fetch_string(&_19, jwt, SL("exp"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 148 TSRMLS_CC);
		zephir_array_fetch_string(&_20, jwt, SL("jti"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 148 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&jti, _16, "getjti", NULL, _10, _17, _18, _19, _20);
		zephir_check_call_status();
		_21 = zephir_is_true(jti);
		if (_21) {
			zephir_array_fetch_string(&_22, jti, SL("expires"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 151 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_11, "time", &_12);
			zephir_check_call_status();
			_21 = ZEPHIR_GT(_22, _11);
		}
		if (_21) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_LONG(_1, 400);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "JSON Token Identifier (jti) has already been used", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
			zephir_check_temp_parameter(_2);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		} else {
			_23 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
			zephir_array_fetch_string(&_24, jwt, SL("iss"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 155 TSRMLS_CC);
			zephir_array_fetch_string(&_25, jwt, SL("sub"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 155 TSRMLS_CC);
			zephir_array_fetch_string(&_26, jwt, SL("aud"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 155 TSRMLS_CC);
			zephir_array_fetch_string(&_27, jwt, SL("exp"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 155 TSRMLS_CC);
			zephir_array_fetch_string(&_28, jwt, SL("jti"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 155 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, _23, "setjti", NULL, _24, _25, _26, _27, _28);
			zephir_check_call_status();
		}
	}
	_16 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	zephir_array_fetch_string(&_10, jwt, SL("iss"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 161 TSRMLS_CC);
	zephir_array_fetch_string(&_17, jwt, SL("sub"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 161 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&key, _16, "getclientkey", NULL, _10, _17);
	zephir_check_call_status();
	if (!(zephir_is_true(key))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "Invalid issuer (iss) or subject (sub) provided", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_16 = zephir_fetch_nproperty_this(this_ptr, SL("jwtUtil"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_METHOD(&_11, _16, "decode", NULL, undecodedJWT, key, _1);
	zephir_check_call_status();
	if (!(zephir_is_true(_11))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "JWT failed signature verification", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_this(this_ptr, SL("jwt"), jwt TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

PHP_METHOD(OAuth2_GrantType_JwtBearer, getClientId) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("jwt"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("iss"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 180 TSRMLS_CC);
	RETURN_CTORW(_1);

}

PHP_METHOD(OAuth2_GrantType_JwtBearer, getUserId) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("jwt"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("sub"), PH_NOISY | PH_READONLY, "oauth2/granttype/jwtbearer.zep", 185 TSRMLS_CC);
	RETURN_CTORW(_1);

}

PHP_METHOD(OAuth2_GrantType_JwtBearer, getScope) {


	RETURN_NULL();

}

/**
 * Creates an access token that is NOT associated with a refresh token.
 * If a subject (sub) the name of the user/account we are accessing data on behalf of.
 *
 * @see OAuth2\GrantType\GrantTypeInterface::createAccessToken()
 */
PHP_METHOD(OAuth2_GrantType_JwtBearer, createAccessToken) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *client_id = NULL, *user_id = NULL, *scope = NULL;
	zval *accessToken, *client_id_param = NULL, *user_id_param = NULL, *scope_param = NULL, *_0;

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
	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 0);
	ZEPHIR_RETURN_CALL_METHOD(accessToken, "createaccesstoken", NULL, client_id, user_id, scope, _0);
	zephir_check_call_status();
	RETURN_MM();

}

