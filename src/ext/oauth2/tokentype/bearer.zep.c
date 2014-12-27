
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * Bearer token
 * @package \OAuth2\TokenType
 */
ZEPHIR_INIT_CLASS(OAuth2_TokenType_Bearer) {

	ZEPHIR_REGISTER_CLASS(OAuth2\\TokenType, Bearer, oauth2, tokentype_bearer, oauth2_tokentype_bearer_method_entry, 0);

	zend_declare_property_null(oauth2_tokentype_bearer_ce, SL("config"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(oauth2_tokentype_bearer_ce TSRMLS_CC, 1, oauth2_tokentype_tokentypeinterface_ce);
	return SUCCESS;

}

PHP_METHOD(OAuth2_TokenType_Bearer, __construct) {

	zval *config_param = NULL, *_0;
	zval *config = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config_param);

	if (!config_param) {
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	} else {
		zephir_get_arrval(config, config_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 3);
	add_assoc_stringl_ex(_1, SS("token_param_name"), SL("access_token"), 1);
	add_assoc_stringl_ex(_1, SS("token_bearer_header_name"), SL("Bearer"), 1);
	zephir_fast_array_merge(_0, &(_1), &(config) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("config"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(OAuth2_TokenType_Bearer, getTokenType) {


	RETURN_STRING("Bearer", 1);

}

/**
 * Check if the request has supplied token
 *
 * @param \OAuth2\RequestInterface request
 * @return boolean
 * @see https://github.com/bshaffer/oauth2-server-php/issues/349#issuecomment-37993588
 */
PHP_METHOD(OAuth2_TokenType_Bearer, requestHasToken) {

	zend_bool _1, _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *headers = NULL, *_0, *_2 = NULL, *_3, *_4, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	if (!(zephir_instance_of_ev(request, oauth2_requestinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'request' must be an instance of 'OAuth2\\RequestInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "AUTHORIZATION", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&headers, request, "headers", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_1 = !ZEPHIR_IS_EMPTY(headers);
	if (!(_1)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_4, _3, SL("token_param_name"), PH_NOISY | PH_READONLY, "oauth2/tokentype/bearer.zep", 43 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_2, request, "request", NULL, _4);
		zephir_check_call_status();
		_1 = zephir_get_boolval(_2);
	}
	_5 = _1;
	if (!(_5)) {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_7, _6, SL("token_param_name"), PH_NOISY | PH_READONLY, "oauth2/tokentype/bearer.zep", 44 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_2, request, "query", NULL, _7);
		zephir_check_call_status();
		_5 = zephir_get_boolval(_2);
	}
	RETURN_MM_BOOL(_5);

}

/**
 * This is a convenience function that can be used to get the token, which can then
 * be passed to getAccessTokenData(). The constraints specified by the draft are
 * attempted to be adheared to in this method.
 *
 * As per the Bearer spec (draft 8, section 2) - there are three ways for a client
 * to specify the bearer token, in order of preference: Authorization Header,
 * POST and GET.
 *
 * NB: Resource servers MUST accept tokens via the Authorization scheme
 * (http://tools.ietf.org/html/rfc6750#section-2).
 *
 * @param \OAuth2\RequestInterface request
 * @param \OAuth2\ResponseInterface request
 * @return string
 * @todo Should we enforce TLS/SSL in this function?
 *
 * @see http://tools.ietf.org/html/rfc6750#section-2.1
 * @see http://tools.ietf.org/html/rfc6750#section-2.2
 * @see http://tools.ietf.org/html/rfc6750#section-2.3
 *
 * Old Android version bug (at least with version 2.2)
 * @see http://code.google.com/p/android/issues/detail?id=6684
 *
 */
PHP_METHOD(OAuth2_TokenType_Bearer, getAccessTokenParameter) {

	zval *_15;
	zephir_nts_static zephir_fcall_cache_entry *_11 = NULL, *_21 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool methodsUsed, _22;
	zval *request, *response, *headers = NULL, *matches, *contentType = NULL, *pos, *_0 = NULL, *_1 = NULL, *_2, *_3, *_4, *_5, *_6 = NULL, *_7 = NULL, *_8, *_9, *_10, *_12, *_13 = NULL, *_14 = NULL, *_16 = NULL, *_17, _18, _19, *_20 = NULL, *_23;

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
	ZVAL_STRING(_0, "AUTHORIZATION", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&headers, request, "headers", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_3, _2, SL("token_param_name"), PH_NOISY | PH_READONLY, "oauth2/tokentype/bearer.zep", 80 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, request, "query", NULL, _3);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_5, _4, SL("token_param_name"), PH_NOISY | PH_READONLY, "oauth2/tokentype/bearer.zep", 80 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, request, "request", NULL, _5);
	zephir_check_call_status();
	methodsUsed = ((!ZEPHIR_IS_EMPTY(headers) | zephir_get_boolval(_1)) | zephir_get_boolval(_1));
	if (methodsUsed > 1) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, 400);
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "invalid_request", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_7);
		ZVAL_STRING(_7, "Only one method may be used to authenticate at a time (Auth header, GET or POST)", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _0, _6, _7);
		zephir_check_temp_parameter(_6);
		zephir_check_temp_parameter(_7);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	if (methodsUsed == 0) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, 401);
		ZEPHIR_CALL_METHOD(NULL, response, "setstatuscode", NULL, _0);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	if (!(ZEPHIR_IS_EMPTY(headers))) {
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_9, _8, SL("token_bearer_header_name"), PH_NOISY | PH_READONLY, "oauth2/tokentype/bearer.zep", 96 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_10);
		ZEPHIR_CONCAT_SVS(_10, "/", _9, "\\s(\\S+)/");
		Z_SET_ISREF_P(matches);
		ZEPHIR_CALL_FUNCTION(&_1, "preg_match", &_11, _10, headers, matches);
		Z_UNSET_ISREF_P(matches);
		zephir_check_call_status();
		if (!(zephir_is_true(_1))) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, 400);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "invalid_request", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_STRING(_7, "Malformed auth header", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _0, _6, _7);
			zephir_check_temp_parameter(_6);
			zephir_check_temp_parameter(_7);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
		zephir_array_fetch_long(&_12, matches, 1, PH_NOISY | PH_READONLY, "oauth2/tokentype/bearer.zep", 101 TSRMLS_CC);
		RETURN_CTOR(_12);
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_9, _8, SL("token_param_name"), PH_NOISY | PH_READONLY, "oauth2/tokentype/bearer.zep", 104 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_13, request, "request", NULL, _9);
	zephir_check_call_status();
	if (zephir_is_true(_13)) {
		ZEPHIR_INIT_NVAR(_0);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "REQUEST_METHOD", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_14, request, "server", NULL, _6);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		zephir_fast_strtolower(_0, _14);
		ZEPHIR_INIT_VAR(_15);
		array_init_size(_15, 3);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "post", 1);
		zephir_array_fast_append(_15, _6);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "put", 1);
		zephir_array_fast_append(_15, _6);
		if (!(zephir_fast_in_array(_0, _15 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_LONG(_6, 400);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_STRING(_7, "invalid_request", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_16);
			ZVAL_STRING(_16, "When putting the token in the body, the method must be POST or PUT", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_17);
			ZVAL_STRING(_17, "#section-2.2", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _6, _7, _16, _17);
			zephir_check_temp_parameter(_7);
			zephir_check_temp_parameter(_16);
			zephir_check_temp_parameter(_17);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "CONTENT_TYPE", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&contentType, request, "server", NULL, _6);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_18);
		ZVAL_STRING(&_18, ";", 0);
		ZEPHIR_INIT_VAR(pos);
		zephir_fast_strpos(pos, contentType, &_18, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(pos)) {
			ZEPHIR_SINIT_VAR(_19);
			ZVAL_LONG(&_19, 0);
			ZEPHIR_CALL_FUNCTION(&_20, "substr", &_21, contentType, &_19, pos);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(contentType, _20);
		}
		_22 = Z_TYPE_P(contentType) != IS_NULL;
		if (_22) {
			_22 = !ZEPHIR_IS_STRING(contentType, "application/x-www-form-urlencoded");
		}
		if (_22) {
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_LONG(_6, 400);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_STRING(_7, "invalid_request", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_16);
			ZVAL_STRING(_16, "The content type for POST requests must be \"application/x-www-form-urlencoded\"", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _6, _7, _16);
			zephir_check_temp_parameter(_7);
			zephir_check_temp_parameter(_16);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
		_23 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_12, _23, SL("token_param_name"), PH_NOISY | PH_READONLY, "oauth2/tokentype/bearer.zep", 124 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(request, "request", NULL, _12);
		zephir_check_call_status();
		RETURN_MM();
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_9, _8, SL("token_param_name"), PH_NOISY | PH_READONLY, "oauth2/tokentype/bearer.zep", 128 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(request, "query", NULL, _9);
	zephir_check_call_status();
	RETURN_MM();

}

