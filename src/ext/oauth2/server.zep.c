
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
* Server class for OAuth2
* This class serves as a convience class which wraps the other Controller classes
*
* @see OAuth2\Controller\ResourceController
* @see OAuth2\Controller\AuthorizeController
* @see OAuth2\Controller\TokenController
*/
ZEPHIR_INIT_CLASS(OAuth2_Server) {

	ZEPHIR_REGISTER_CLASS(OAuth2, Server, oauth2, server, oauth2_server_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(oauth2_server_ce, SL("response"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_server_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_server_ce, SL("storages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_server_ce, SL("authorizeController"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_server_ce, SL("tokenController"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_server_ce, SL("resourceController"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_server_ce, SL("userInfoController"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_server_ce, SL("grantTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_server_ce, SL("responseTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_server_ce, SL("tokenType"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_server_ce, SL("scopeUtil"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_server_ce, SL("clientAssertionType"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(oauth2_server_ce, SL("storageMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(oauth2_server_ce, SL("responseTypeMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(oauth2_server_ce TSRMLS_CC, 1, oauth2_controller_resourcecontrollerinterface_ce);
	zend_class_implements(oauth2_server_ce TSRMLS_CC, 1, oauth2_controller_authorizecontrollerinterface_ce);
	zend_class_implements(oauth2_server_ce TSRMLS_CC, 1, oauth2_controller_tokencontrollerinterface_ce);
	return SUCCESS;

}

/**
 * @param mixed storage       (array or OAuth2\Storage) - single object or array of objects implementing the
 *                             required storage types (ClientCredentialsInterface and AccessTokenInterface as a minimum)
 * @param array $config        specify a different token lifetime, token header name, etc
 * @param array $grantTypes    An array of OAuth2\GrantType\GrantTypeInterface to use for granting access tokens
 * @param array $responseTypes Response types to use.  array keys should be "code" and and "token" for
 *                             Access Token and Authorization Code response types
 * @param OAuth2\TokenType\TokenTypeInterface                     $tokenType           The token type object to use. Valid token types are "bearer" and "mac"
 * @param OAuth2\ScopeInterface                                   $scopeUtil           The scope utility class to use to validate scope
 * @param OAuth2\ClientAssertionType\ClientAssertionTypeInterface $clientAssertionType The method in which to verify the client identity.  Default is HttpBasic
 *
 * @ingroup oauth2_section_7
 */
PHP_METHOD(OAuth2_Server, __construct) {

	zephir_fcall_cache_entry *_9 = NULL, *_15 = NULL, *_19 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_7, *_13, *_17;
	HashPosition _6, _12, _16;
	zend_bool _0, _1, _2;
	zval *storage_param = NULL, *config_param = NULL, *grantTypes_param = NULL, *responseTypes_param = NULL, *tokenType = NULL, *scopeUtil = NULL, *clientAssertionType = NULL, *key = NULL, *service = NULL, *type = NULL, *_5, **_8, *_10, **_14, **_18;
	zval *storage = NULL, *config = NULL, *grantTypes = NULL, *responseTypes = NULL, *_3, *_4, *_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 7, &storage_param, &config_param, &grantTypes_param, &responseTypes_param, &tokenType, &scopeUtil, &clientAssertionType);

	if (!storage_param) {
		ZEPHIR_INIT_VAR(storage);
		array_init(storage);
	} else {
		zephir_get_arrval(storage, storage_param);
	}
	if (!config_param) {
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	} else {
		zephir_get_arrval(config, config_param);
	}
	if (!grantTypes_param) {
		ZEPHIR_INIT_VAR(grantTypes);
		array_init(grantTypes);
	} else {
		zephir_get_arrval(grantTypes, grantTypes_param);
	}
	if (!responseTypes_param) {
		ZEPHIR_INIT_VAR(responseTypes);
		array_init(responseTypes);
	} else {
		zephir_get_arrval(responseTypes, responseTypes_param);
	}
	if (!tokenType) {
		tokenType = ZEPHIR_GLOBAL(global_null);
	}
	if (!scopeUtil) {
		scopeUtil = ZEPHIR_GLOBAL(global_null);
	}
	if (!clientAssertionType) {
		clientAssertionType = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(tokenType) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(tokenType, oauth2_tokentype_tokentypeinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'tokenType' must be an instance of 'OAuth2\\TokenType\\TokenTypeInterface'", "", 0);
		return;
	}
	_1 = Z_TYPE_P(scopeUtil) != IS_NULL;
	if (_1) {
		_1 = !zephir_instance_of_ev(scopeUtil, oauth2_scopeinterface_ce TSRMLS_CC);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'scopeUtil' must be an instance of 'OAuth2\\ScopeInterface'", "", 0);
		return;
	}
	_2 = Z_TYPE_P(clientAssertionType) != IS_NULL;
	if (_2) {
		_2 = !zephir_instance_of_ev(clientAssertionType, oauth2_clientassertiontype_clientassertiontypeinterface_ce TSRMLS_CC);
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'clientAssertionType' must be an instance of 'OAuth2\\ClientAssertionType\\ClientAssertionTypeInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 13);
	add_assoc_stringl_ex(_3, SS("access_token"), SL("OAuth2\\Storage\\AccessTokenInterface"), 1);
	add_assoc_stringl_ex(_3, SS("authorization_code"), SL("OAuth2\\Storage\\AuthorizationCodeInterface"), 1);
	add_assoc_stringl_ex(_3, SS("client_credentials"), SL("OAuth2\\Storage\\ClientCredentialsInterface"), 1);
	add_assoc_stringl_ex(_3, SS("client"), SL("OAuth2\\Storage\\ClientInterface"), 1);
	add_assoc_stringl_ex(_3, SS("refresh_token"), SL("OAuth2\\Storage\\RefreshTokenInterface"), 1);
	add_assoc_stringl_ex(_3, SS("user_credentials"), SL("OAuth2\\Storage\\UserCredentialsInterface"), 1);
	add_assoc_stringl_ex(_3, SS("user_claims"), SL("OAuth2\\OpenID\\Storage\UserClaimsInterface"), 1);
	add_assoc_stringl_ex(_3, SS("public_key"), SL("OAuth2\\Storage\\PublicKeyInterface"), 1);
	add_assoc_stringl_ex(_3, SS("jwt_bearer"), SL("OAuth2\\Storage\\JWTBearerInterface"), 1);
	add_assoc_stringl_ex(_3, SS("scope"), SL("OAuth2\\Storage\\ScopeInterface"), 1);
	zephir_update_property_this(this_ptr, SL("storageMap"), _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	array_init_size(_4, 6);
	add_assoc_stringl_ex(_4, SS("token"), SL("OAuth2\\ResponseType\\AccessTokenInterface"), 1);
	add_assoc_stringl_ex(_4, SS("code"), SL("OAuth2\\ResponseType\\AuthorizationCodeInterface"), 1);
	add_assoc_stringl_ex(_4, SS("id_token"), SL("OAuth2\\OpenID\\ResponseType\\IdTokenInterface"), 1);
	add_assoc_stringl_ex(_4, SS("id_token token"), SL("OAuth2\\OpenID\\ResponseType\\IdTokenTokenInterface"), 1);
	zephir_update_property_this(this_ptr, SL("responseTypeMap"), _4 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	array_init(_5);
	zephir_update_property_this(this_ptr, SL("storages"), _5 TSRMLS_CC);
	if (1 != 1) {
		ZEPHIR_INIT_NVAR(storage);
		array_init_size(storage, 2);
		zephir_array_fast_append(storage, storage);
	}
	zephir_is_iterable(storage, &_7, &_6, 0, 0, "oauth2/server.zep", 123);
	for (
	  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
	  ; zephir_hash_move_forward_ex(_7, &_6)
	) {
		ZEPHIR_GET_HMKEY(key, _7, _6);
		ZEPHIR_GET_HVALUE(service, _8);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addstorage", &_9, service, key);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_INIT_VAR(_11);
	array_init_size(_11, 18);
	zephir_array_update_string(&_11, SL("use_jwt_access_tokens"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_11, SL("store_encrypted_token_string"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_11, SL("use_openid_connect"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(_11, SS("id_lifetime"), 3600);
	add_assoc_long_ex(_11, SS("access_lifetime"), 3600);
	add_assoc_stringl_ex(_11, SS("www_realm"), SL("Service"), 1);
	add_assoc_stringl_ex(_11, SS("token_param_name"), SL("access_token"), 1);
	add_assoc_stringl_ex(_11, SS("token_bearer_header_name"), SL("Bearer"), 1);
	zephir_array_update_string(&_11, SL("enforce_state"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_11, SL("require_exact_redirect_uri"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_11, SL("allow_implicit"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_11, SL("allow_credentials_in_request_body"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_11, SL("allow_public_clients"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_11, SL("always_issue_new_refresh_token"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_fast_array_merge(_10, &(_11), &(config) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("config"), _10 TSRMLS_CC);
	zephir_is_iterable(grantTypes, &_13, &_12, 0, 0, "oauth2/server.zep", 144);
	for (
	  ; zephir_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
	  ; zephir_hash_move_forward_ex(_13, &_12)
	) {
		ZEPHIR_GET_HMKEY(key, _13, _12);
		ZEPHIR_GET_HVALUE(type, _14);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addgranttype", &_15, type, key);
		zephir_check_call_status();
	}
	zephir_is_iterable(responseTypes, &_17, &_16, 0, 0, "oauth2/server.zep", 148);
	for (
	  ; zephir_hash_get_current_data_ex(_17, (void**) &_18, &_16) == SUCCESS
	  ; zephir_hash_move_forward_ex(_17, &_16)
	) {
		ZEPHIR_GET_HMKEY(key, _17, _16);
		ZEPHIR_GET_HVALUE(type, _18);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addresponsetype", &_19, type, key);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("tokenType"), tokenType TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("scopeUtil"), scopeUtil TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("clientAssertionType"), clientAssertionType TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set a storage object for the server
 *
 * @param OAuth\Storage\StorageInterface storage An object implementing one of the Storage interfaces
 * @param string key If null, the storage is set to the key of each storage interface it implements
 *
 * @see storageMap
 */
PHP_METHOD(OAuth2_Server, addStorage) {

	HashTable *_17;
	HashPosition _16;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_10 = NULL;
	zend_bool setStorage, _1, _2, _11, _12;
	zval *key = NULL;
	zval *storage, *key_param = NULL, *type = NULL, *interfaceClass = NULL, *_0, *_3, *_4, *_5 = NULL, *_6, *_7, _8 = zval_used_for_init, *_9 = NULL, *_13, *_14 = NULL, *_15 = NULL, **_18;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &storage, &key_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	} else {
	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}
	}


	if (!(zephir_instance_of_ev(storage, oauth2_storage_storageinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'storage' must be an instance of 'OAuth2\\Storage\\StorageInterface'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("storageMap"), PH_NOISY_CC);
	_1 = 1 != 0;
	if (_1) {
		_1 = !zephir_is_numeric(key);
	}
	if (zephir_array_isset(_0, key)) {
		_2 = Z_TYPE_P(storage) != IS_NULL;
		if (_2) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("storageMap"), PH_NOISY_CC);
			ZEPHIR_OBS_VAR(_4);
			zephir_array_fetch(&_4, _3, key, PH_NOISY, "oauth2/server.zep", 168 TSRMLS_CC);
			_2 = !zephir_is_instance_of(storage, Z_STRVAL_P(_4), Z_STRLEN_P(_4) TSRMLS_CC);
		}
		if (_2) {
			ZEPHIR_INIT_VAR(_5);
			object_init_ex(_5, spl_ce_InvalidArgumentException);
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("storageMap"), PH_NOISY_CC);
			zephir_array_fetch(&_7, _6, key, PH_NOISY | PH_READONLY, "oauth2/server.zep", 169 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_8);
			ZVAL_STRING(&_8, "storage of type \"%s\" must implement interface \"%s\"", 0);
			ZEPHIR_CALL_FUNCTION(&_9, "sprintf", &_10, &_8, key, _7);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, _9);
			zephir_check_call_status();
			zephir_throw_exception_debug(_5, "oauth2/server.zep", 169 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_array(this_ptr, SL("storages"), key, storage TSRMLS_CC);
		_11 = ZEPHIR_IS_STRING_IDENTICAL(key, "client");
		if (_11) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("storages"), PH_NOISY_CC);
			_11 = !zephir_array_isset_string(_6, SS("client_credentials"));
		}
		_12 = ZEPHIR_IS_STRING_IDENTICAL(key, "client_credentials");
		if (_12) {
			_13 = zephir_fetch_nproperty_this(this_ptr, SL("storages"), PH_NOISY_CC);
			_12 = !zephir_array_isset_string(_13, SS("client"));
		}
		if (_11) {
			if (zephir_instance_of_ev(storage, oauth2_storage_clientcredentialsinterface_ce TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_STRING(_5, "client_credentials", 1);
				zephir_update_property_array(this_ptr, SL("storages"), _5, storage TSRMLS_CC);
			}
		} else if (_12) {
			if (zephir_instance_of_ev(storage, oauth2_storage_clientinterface_ce TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_STRING(_5, "client", 1);
				zephir_update_property_array(this_ptr, SL("storages"), _5, storage TSRMLS_CC);
			}
		}
	} else if (_1) {
		ZEPHIR_INIT_NVAR(_5);
		object_init_ex(_5, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(_14);
		ZEPHIR_INIT_VAR(_15);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("storageMap"), PH_NOISY_CC);
		zephir_array_keys(_15, _3 TSRMLS_CC);
		zephir_fast_join_str(_14, SL(", "), _15 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_STRING(&_8, "unknown storage key \"%s\", must be one of [%s]", 0);
		ZEPHIR_CALL_FUNCTION(&_9, "sprintf", &_10, &_8, key, _14);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, _9);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5, "oauth2/server.zep", 184 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else {
		setStorage = 0;
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("storageMap"), PH_NOISY_CC);
		zephir_is_iterable(_3, &_17, &_16, 0, 0, "oauth2/server.zep", 194);
		for (
		  ; zephir_hash_get_current_data_ex(_17, (void**) &_18, &_16) == SUCCESS
		  ; zephir_hash_move_forward_ex(_17, &_16)
		) {
			ZEPHIR_GET_HKEY(type, _17, _16);
			ZEPHIR_GET_HVALUE(interfaceClass, _18);
			if (zephir_is_instance_of(storage, Z_STRVAL_P(interfaceClass), Z_STRLEN_P(interfaceClass) TSRMLS_CC)) {
				zephir_update_property_array(this_ptr, SL("storages"), type, storage TSRMLS_CC);
				setStorage = 1;
			}
		}
		if (!(setStorage)) {
			ZEPHIR_INIT_NVAR(_5);
			object_init_ex(_5, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_NVAR(_14);
			zephir_get_class(_14, storage, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_15);
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("storageMap"), PH_NOISY_CC);
			zephir_fast_join_str(_15, SL(", "), _6 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_8);
			ZVAL_STRING(&_8, "storage of class \"%s\" must implement one of [%s]", 0);
			ZEPHIR_CALL_FUNCTION(&_9, "sprintf", &_10, &_8, _14, _15);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, _9);
			zephir_check_call_status();
			zephir_throw_exception_debug(_5, "oauth2/server.zep", 195 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(OAuth2_Server, addGrantType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL;
	zval *grantType, *key_param = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &grantType, &key_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	} else {
	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}
	}


	if (!(zephir_instance_of_ev(grantType, oauth2_granttype_granttypeinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'grantType' must be an instance of 'OAuth2\\GrantType\\GrantTypeInterface'", "", 0);
		return;
	}
	if (1 == 1) {
		zephir_update_property_array(this_ptr, SL("grantTypes"), key, grantType TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&_0, grantType, "getquerystringidentifier", NULL);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("grantTypes"), _0, grantType TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("tokenController"), PH_NOISY_CC);
	if (Z_TYPE_P(_1) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettokencontroller", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0, "addgranttype", NULL, grantType);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(OAuth2_Server, addResponseType) {

	HashTable *_14;
	HashPosition _13;
	zephir_nts_static zephir_fcall_cache_entry *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool setResponse, _2;
	zval *key = NULL;
	zval *responseType, *key_param = NULL, *type = NULL, *interfaceClass = NULL, *_0 = NULL, *_1, *_3, *_4, *_5 = NULL, *_6, *_7, _8 = zval_used_for_init, *_9 = NULL, *_11 = NULL, *_12 = NULL, **_15;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &responseType, &key_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	} else {
	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}
	}


	if (!(zephir_instance_of_ev(responseType, oauth2_responsetype_responsetypeinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'responseType' must be an instance of 'OAuth2\\ResponseType\\ResponseTypeInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeresponsetype", NULL, key);
	zephir_check_call_status();
	zephir_get_strval(key, _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("responseTypeMap"), PH_NOISY_CC);
	_2 = 1 != 0;
	if (_2) {
		_2 = !zephir_is_numeric(key);
	}
	if (zephir_array_isset(_1, key)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("responseTypeMap"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_4);
		zephir_array_fetch(&_4, _3, key, PH_NOISY, "oauth2/server.zep", 222 TSRMLS_CC);
		if (!(zephir_is_instance_of(responseType, Z_STRVAL_P(_4), Z_STRLEN_P(_4) TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_5);
			object_init_ex(_5, spl_ce_InvalidArgumentException);
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("responseTypeMap"), PH_NOISY_CC);
			zephir_array_fetch(&_7, _6, key, PH_NOISY | PH_READONLY, "oauth2/server.zep", 223 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_8);
			ZVAL_STRING(&_8, "responseType of type \"%s\" must implement interface \"%s\"", 0);
			ZEPHIR_CALL_FUNCTION(&_9, "sprintf", &_10, &_8, key, _7);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, _9);
			zephir_check_call_status();
			zephir_throw_exception_debug(_5, "oauth2/server.zep", 223 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_array(this_ptr, SL("responseTypes"), key, responseType TSRMLS_CC);
	} else if (_2) {
		ZEPHIR_INIT_NVAR(_5);
		object_init_ex(_5, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(_11);
		ZEPHIR_INIT_VAR(_12);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("responseTypeMap"), PH_NOISY_CC);
		zephir_array_keys(_12, _3 TSRMLS_CC);
		zephir_fast_join_str(_11, SL(", "), _12 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_STRING(&_8, "unknown responseType key \"%s\", must be one of [%s]", 0);
		ZEPHIR_CALL_FUNCTION(&_9, "sprintf", &_10, &_8, key, _11);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, _9);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5, "oauth2/server.zep", 227 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else {
		setResponse = 0;
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("responseTypeMap"), PH_NOISY_CC);
		zephir_is_iterable(_3, &_14, &_13, 0, 0, "oauth2/server.zep", 237);
		for (
		  ; zephir_hash_get_current_data_ex(_14, (void**) &_15, &_13) == SUCCESS
		  ; zephir_hash_move_forward_ex(_14, &_13)
		) {
			ZEPHIR_GET_HKEY(type, _14, _13);
			ZEPHIR_GET_HVALUE(interfaceClass, _15);
			if (zephir_is_instance_of(responseType, Z_STRVAL_P(interfaceClass), Z_STRLEN_P(interfaceClass) TSRMLS_CC)) {
				zephir_update_property_array(this_ptr, SL("responseTypes"), type, responseType TSRMLS_CC);
				setResponse = 1;
			}
		}
		if (!(setResponse)) {
			ZEPHIR_INIT_NVAR(_5);
			object_init_ex(_5, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_NVAR(_11);
			zephir_get_class(_11, responseType, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_12);
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("responseTypeMap"), PH_NOISY_CC);
			zephir_fast_join_str(_12, SL(", "), _6 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_8);
			ZVAL_STRING(&_8, "Unknown response type %s.  Please implement one of [%s]", 0);
			ZEPHIR_CALL_FUNCTION(&_9, "sprintf", &_10, &_8, _11, _12);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, _9);
			zephir_check_call_status();
			zephir_throw_exception_debug(_5, "oauth2/server.zep", 238 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(OAuth2_Server, setAuthorizeController) {

	zval *authorizeController;

	zephir_fetch_params(0, 1, 0, &authorizeController);



	if (!(zephir_instance_of_ev(authorizeController, oauth2_controller_authorizecontrollerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'authorizeController' must be an instance of 'OAuth2\\Controller\\AuthorizeControllerInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("authorizeController"), authorizeController TSRMLS_CC);

}

PHP_METHOD(OAuth2_Server, getAuthorizeController) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("authorizeController"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "createdefaultauthorizecontroller", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("authorizeController"), _1 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "authorizeController");

}

PHP_METHOD(OAuth2_Server, setTokenController) {

	zval *tokenController;

	zephir_fetch_params(0, 1, 0, &tokenController);



	if (!(zephir_instance_of_ev(tokenController, oauth2_controller_tokencontrollerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'tokenController' must be an instance of 'OAuth2\\Controller\\TokenControllerInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("tokenController"), tokenController TSRMLS_CC);

}

PHP_METHOD(OAuth2_Server, getTokenController) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("tokenController"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "createdefaulttokencontroller", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("tokenController"), _1 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "tokenController");

}

PHP_METHOD(OAuth2_Server, setResourceController) {

	zval *resourceController;

	zephir_fetch_params(0, 1, 0, &resourceController);



	if (!(zephir_instance_of_ev(resourceController, oauth2_controller_resourcecontrollerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'resourceController' must be an instance of 'OAuth2\\Controller\\ResourceControllerInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("resourceController"), resourceController TSRMLS_CC);

}

PHP_METHOD(OAuth2_Server, getResourceController) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("resourceController"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "createdefaultresourcecontroller", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("resourceController"), _1 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "resourceController");

}

PHP_METHOD(OAuth2_Server, normalizeResponseType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zend_bool _0;
	zval *name_param = NULL, *types, _1, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = !ZEPHIR_IS_EMPTY(name);
	if (_0) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, " ", 0);
		ZEPHIR_INIT_VAR(_2);
		zephir_fast_strpos(_2, name, &_1, 0 );
		_0 = !ZEPHIR_IS_FALSE_IDENTICAL(_2);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(types);
		zephir_fast_explode_str(types, SL(" "), name, LONG_MAX TSRMLS_CC);
		Z_SET_ISREF_P(types);
		ZEPHIR_CALL_FUNCTION(NULL, "sort", &_3, types);
		Z_UNSET_ISREF_P(types);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(name);
		zephir_fast_join_str(name, SL(" "), types TSRMLS_CC);
	}
	RETURN_CTOR(name);

}

