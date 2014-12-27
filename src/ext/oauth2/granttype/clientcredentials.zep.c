
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"


/**
 * @author Brent Shaffer <bshafs at gmail dot com>
 *
 * @see OAuth2\ClientAssertionType_HttpBasic
 */
ZEPHIR_INIT_CLASS(OAuth2_GrantType_ClientCredentials) {

	ZEPHIR_REGISTER_CLASS_EX(OAuth2\\GrantType, ClientCredentials, oauth2, granttype_clientcredentials, oauth2_clientassertiontype_httpbasic_ce, oauth2_granttype_clientcredentials_method_entry, 0);

	zend_declare_property_null(oauth2_granttype_clientcredentials_ce, SL("clientData"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(oauth2_granttype_clientcredentials_ce TSRMLS_CC, 1, oauth2_granttype_granttypeinterface_ce);
	return SUCCESS;

}

PHP_METHOD(OAuth2_GrantType_ClientCredentials, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *config = NULL;
	zval *storage, *config_param = NULL;

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
	zephir_array_update_string(&config, SL("allow_public_clients"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_PARENT(NULL, oauth2_granttype_clientcredentials_ce, this_ptr, "__construct", &_0, storage, config);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(OAuth2_GrantType_ClientCredentials, getQuerystringIdentifier) {


	RETURN_STRING("client_credentials", 1);

}

PHP_METHOD(OAuth2_GrantType_ClientCredentials, getScope) {

	zval *_1, *_2, *_3;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadclientdata", &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("clientData"), PH_NOISY_CC);
	if (zephir_array_isset_string(_2, SS("scope"))) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("clientData"), PH_NOISY_CC);
		zephir_array_fetch_string(&_1, _3, SL("scope"), PH_NOISY, "oauth2/granttype/clientcredentials.zep", 35 TSRMLS_CC);
	} else {
		ZVAL_NULL(_1);
	}
	RETURN_CCTOR(_1);

}

PHP_METHOD(OAuth2_GrantType_ClientCredentials, getUserId) {

	zval *_1, *_2, *_3;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadclientdata", &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("clientData"), PH_NOISY_CC);
	if (zephir_array_isset_string(_2, SS("user_id"))) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("clientData"), PH_NOISY_CC);
		zephir_array_fetch_string(&_1, _3, SL("user_id"), PH_NOISY, "oauth2/granttype/clientcredentials.zep", 41 TSRMLS_CC);
	} else {
		ZVAL_NULL(_1);
	}
	RETURN_CCTOR(_1);

}

PHP_METHOD(OAuth2_GrantType_ClientCredentials, createAccessToken) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool includeRefreshToken;
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
	includeRefreshToken = 0;
	ZEPHIR_RETURN_CALL_METHOD(accessToken, "createaccesstoken", NULL, client_id, user_id, scope, (includeRefreshToken ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(OAuth2_GrantType_ClientCredentials, loadClientData) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("clientData"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "getclientid", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2, _1, "getclientdetails", NULL, _3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("clientData"), _2 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

