
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
ZEPHIR_INIT_CLASS(OAuth2_GrantType_UserCredentials) {

	ZEPHIR_REGISTER_CLASS(OAuth2\\GrantType, UserCredentials, oauth2, granttype_usercredentials, oauth2_granttype_usercredentials_method_entry, 0);

	zend_declare_property_null(oauth2_granttype_usercredentials_ce, SL("userInfo"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(oauth2_granttype_usercredentials_ce, SL("storage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(oauth2_granttype_usercredentials_ce TSRMLS_CC, 1, oauth2_granttype_granttypeinterface_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * @param OAuth2\Storage\UserCredentialsInterface $storage REQUIRED Storage class for retrieving user credentials information
 */
PHP_METHOD(OAuth2_GrantType_UserCredentials, __construct) {

	zval *storage;

	zephir_fetch_params(0, 1, 0, &storage);



	if (!(zephir_instance_of_ev(storage, oauth2_storage_usercredentialsinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'storage' must be an instance of 'OAuth2\\Storage\\UserCredentialsInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("storage"), storage TSRMLS_CC);

}

PHP_METHOD(OAuth2_GrantType_UserCredentials, getQuerystringIdentifier) {


	RETURN_STRING("password", 1);

}

PHP_METHOD(OAuth2_GrantType_UserCredentials, validateRequest) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *response, *userInfo = NULL, *_0 = NULL, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10, *_11 = NULL;

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
	ZVAL_STRING(_1, "password", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, request, "request", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_2 = !zephir_is_true(_0);
	if (!(_2)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "username", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, request, "request", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		_2 = !zephir_is_true(_3);
	}
	if (_2) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "invalid_request", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "Missing parameters: \"username\" and \"password\" required", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _4, _5);
		zephir_check_temp_parameter(_4);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "username", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, request, "request", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "password", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, request, "request", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, _6, "checkusercredentials", NULL, _8, _9);
	zephir_check_call_status();
	if (!(zephir_is_true(_7))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 401);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "Invalid username and password combination", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _4, _5);
		zephir_check_temp_parameter(_4);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "username", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_11, request, "request", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&userInfo, _10, "getuserdetails", NULL, _11);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(userInfo)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 400);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "invalid_grant", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "Unable to retrieve user information", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "seterror", NULL, _1, _4, _5);
		zephir_check_temp_parameter(_4);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_array_isset_string(userInfo, SS("user_id")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_LogicException, "you must set the user_id on the array returned by getUserDetails", "oauth2/granttype/usercredentials.zep", 56);
		return;
	}
	zephir_update_property_this(this_ptr, SL("userInfo"), userInfo TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

PHP_METHOD(OAuth2_GrantType_UserCredentials, getClientId) {


	RETURN_NULL();

}

PHP_METHOD(OAuth2_GrantType_UserCredentials, getUserId) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("userInfo"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("user_id"), PH_NOISY | PH_READONLY, "oauth2/granttype/usercredentials.zep", 71 TSRMLS_CC);
	RETURN_CTORW(_1);

}

PHP_METHOD(OAuth2_GrantType_UserCredentials, getScope) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("userInfo"), PH_NOISY_CC);
	if (zephir_array_isset_string(_1, SS("scope"))) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("userInfo"), PH_NOISY_CC);
		zephir_array_fetch_string(&_0, _2, SL("scope"), PH_NOISY, "oauth2/granttype/usercredentials.zep", 76 TSRMLS_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(OAuth2_GrantType_UserCredentials, createAccessToken) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *client_id = NULL, *user_id = NULL, *scope = NULL;
	zval *accessToken, *client_id_param = NULL, *user_id_param = NULL, *scope_param = NULL;

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
	ZEPHIR_RETURN_CALL_METHOD(accessToken, "createaccesstoken", NULL, client_id, user_id, scope);
	zephir_check_call_status();
	RETURN_MM();

}

