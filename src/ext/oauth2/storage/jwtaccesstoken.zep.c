
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
#include "kernel/hash.h"


/**
 * JWT Access token
 * @author Brent Shaffer <bshafs at gmail dot com>
 */
ZEPHIR_INIT_CLASS(OAuth2_Storage_JwtAccessToken) {

	ZEPHIR_REGISTER_CLASS(OAuth2\\Storage, JwtAccessToken, oauth2, storage_jwtaccesstoken, oauth2_storage_jwtaccesstoken_method_entry, 0);

	zend_declare_property_null(oauth2_storage_jwtaccesstoken_ce, SL("publicKeyStorage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_storage_jwtaccesstoken_ce, SL("tokenStorage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_storage_jwtaccesstoken_ce, SL("encryptionUtil"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(oauth2_storage_jwtaccesstoken_ce TSRMLS_CC, 1, oauth2_storage_jwtaccesstokeninterface_ce);
	return SUCCESS;

}

/**
 * @param OAuth2\Encryption\PublicKeyInterface publicKeyStorage the public key encryption to use
 * @param OAuth2\Storage\AccessTokenInterfacetokenStorage OPTIONAL persist the access token to another storage. This is useful if
 * you want to retain access token grant information somewhere, but
 * is not necessary when using this grant type.
 * @param OAuth2\Encryption\EncryptionInterface encryptionUtil   OPTIONAL class to use for "encode" and "decode" functions.
 */
PHP_METHOD(OAuth2_Storage_JwtAccessToken, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zend_class_entry *_2 = NULL;
	zend_bool _0, _1;
	zval *publicKeyStorage, *tokenStorage = NULL, *encryptionUtil = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &publicKeyStorage, &tokenStorage, &encryptionUtil);

	if (!tokenStorage) {
		tokenStorage = ZEPHIR_GLOBAL(global_null);
	}
	if (!encryptionUtil) {
		ZEPHIR_CPY_WRT(encryptionUtil, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(encryptionUtil);
	}


	if (!(zephir_instance_of_ev(publicKeyStorage, oauth2_storage_publickeyinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'publicKeyStorage' must be an instance of 'OAuth2\\Storage\\PublicKeyInterface'", "", 0);
		return;
	}
	_0 = Z_TYPE_P(tokenStorage) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(tokenStorage, oauth2_storage_accesstokeninterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'tokenStorage' must be an instance of 'OAuth2\\Storage\\AccessTokenInterface'", "", 0);
		return;
	}
	_1 = Z_TYPE_P(encryptionUtil) != IS_NULL;
	if (_1) {
		_1 = !zephir_instance_of_ev(encryptionUtil, oauth2_encryption_encryptioninterface_ce TSRMLS_CC);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'encryptionUtil' must be an instance of 'OAuth2\\Encryption\\EncryptionInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("publicKeyStorage"), publicKeyStorage TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("tokenStorage"), tokenStorage TSRMLS_CC);
	if (Z_TYPE_P(encryptionUtil) == IS_NULL) {
		ZEPHIR_INIT_NVAR(encryptionUtil);
		if (!_2) {
			_2 = zend_fetch_class(SL("OAuth2\\Encryption\\Jwt"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(encryptionUtil, _2);
		if (zephir_has_constructor(encryptionUtil TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, encryptionUtil, "__construct", NULL);
			zephir_check_call_status();
		}
	}
	zephir_update_property_this(this_ptr, SL("encryptionUtil"), encryptionUtil TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(OAuth2_Storage_JwtAccessToken, getAccessToken) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *oauth_token_param = NULL, *tokenData = NULL, *client_id = NULL, *public_key = NULL, *algorithm = NULL, *_0, *_1 = NULL, *_2, *_3, *_4, *_5, *_6 = NULL;
	zval *oauth_token = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &oauth_token_param);

	if (unlikely(Z_TYPE_P(oauth_token_param) != IS_STRING && Z_TYPE_P(oauth_token_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'oauth_token' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(oauth_token_param) == IS_STRING)) {
		zephir_get_strval(oauth_token, oauth_token_param);
	} else {
		ZEPHIR_INIT_VAR(oauth_token);
		ZVAL_EMPTY_STRING(oauth_token);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("encryptionUtil"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_NULL(_1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 0);
	ZEPHIR_CALL_METHOD(&tokenData, _0, "decode", NULL, oauth_token, _1, _2);
	zephir_check_call_status();
	if (!(zephir_is_true(tokenData))) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_array_isset_string(tokenData, SS("aud"))) {
		ZEPHIR_OBS_VAR(client_id);
		zephir_array_fetch_string(&client_id, tokenData, SL("aud"), PH_NOISY, "oauth2/storage/jwtaccesstoken.zep", 46 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(client_id);
		ZVAL_NULL(client_id);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("publicKeyStorage"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&public_key, _3, "getpublickey", NULL, client_id);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("publicKeyStorage"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&algorithm, _4, "getencryptionalgorithm", NULL, client_id);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("encryptionUtil"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_METHOD(&_6, _5, "decode", NULL, oauth_token, public_key, _1);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_6)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "convertjwttooauth2", NULL, tokenData);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(OAuth2_Storage_JwtAccessToken, setAccessToken) {

	int expires, ZEPHIR_LAST_CALL_STATUS;
	zval *oauth_token_param = NULL, *client_id_param = NULL, *user_id_param = NULL, *expires_param = NULL, *scope_param = NULL, *_0, *_1, *_2;
	zval *oauth_token = NULL, *client_id = NULL, *user_id = NULL, *scope = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &oauth_token_param, &client_id_param, &user_id_param, &expires_param, &scope_param);

	if (unlikely(Z_TYPE_P(oauth_token_param) != IS_STRING && Z_TYPE_P(oauth_token_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'oauth_token' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(oauth_token_param) == IS_STRING)) {
		zephir_get_strval(oauth_token, oauth_token_param);
	} else {
		ZEPHIR_INIT_VAR(oauth_token);
		ZVAL_EMPTY_STRING(oauth_token);
	}
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
	expires = zephir_get_intval(expires_param);
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("tokenStorage"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("tokenStorage"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, expires);
		ZEPHIR_CALL_METHOD(NULL, _1, "setaccesstoken", NULL, oauth_token, client_id, user_id, _2, scope);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(OAuth2_Storage_JwtAccessToken, convertJwtToOAuth2) {

	HashTable *_1;
	HashPosition _0;
	zval *tokenData_param = NULL, *keyMapping, *jwtKey = NULL, *oauth2Key = NULL, **_2, *_3;
	zval *tokenData = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tokenData_param);

	zephir_get_arrval(tokenData, tokenData_param);


	ZEPHIR_INIT_VAR(keyMapping);
	array_init_size(keyMapping, 4);
	add_assoc_stringl_ex(keyMapping, SS("aud"), SL("client_id"), 1);
	add_assoc_stringl_ex(keyMapping, SS("exp"), SL("expires"), 1);
	add_assoc_stringl_ex(keyMapping, SS("sub"), SL("user_id"), 1);
	zephir_is_iterable(keyMapping, &_1, &_0, 0, 0, "oauth2/storage/jwtaccesstoken.zep", 84);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HKEY(jwtKey, _1, _0);
		ZEPHIR_GET_HVALUE(oauth2Key, _2);
		if (zephir_array_isset(tokenData, jwtKey)) {
			zephir_array_fetch(&_3, tokenData, jwtKey, PH_NOISY | PH_READONLY, "oauth2/storage/jwtaccesstoken.zep", 79 TSRMLS_CC);
			zephir_array_update_zval(&tokenData, oauth2Key, &_3, PH_COPY | PH_SEPARATE);
			zephir_array_unset(&tokenData, jwtKey, PH_SEPARATE);
		}
	}
	RETURN_CTOR(tokenData);

}

