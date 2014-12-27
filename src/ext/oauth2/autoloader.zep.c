
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
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"


/**
 * Autoloads OAuth2 classes
 *
 * @author    Brent Shaffer <bshafs at gmail dot com>
 * @license   MIT License
 */
ZEPHIR_INIT_CLASS(OAuth2_Autoloader) {

	ZEPHIR_REGISTER_CLASS(OAuth2, Autoloader, oauth2, autoloader, oauth2_autoloader_method_entry, 0);

	zend_declare_property_null(oauth2_autoloader_ce, SL("dir"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param string dir
 */
PHP_METHOD(OAuth2_Autoloader, __construct) {

	zval *dir_param = NULL, *_0;
	zval *dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dir_param);

	if (!dir_param) {
		ZEPHIR_INIT_VAR(dir);
		ZVAL_EMPTY_STRING(dir);
	} else {
	if (unlikely(Z_TYPE_P(dir_param) != IS_STRING && Z_TYPE_P(dir_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dir' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(dir_param) == IS_STRING)) {
		zephir_get_strval(dir, dir_param);
	} else {
		ZEPHIR_INIT_VAR(dir);
		ZVAL_EMPTY_STRING(dir);
	}
	}


	if (1 == 0) {
		ZEPHIR_INIT_ZVAL_NREF(_0);
		ZVAL_STRING(_0, "./", 1);
		zephir_update_property_this(this_ptr, SL("dir"), _0 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("dir"), dir TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Registers OAuth2\Autoloader as an SPL autoloader.
 *
 * @param string dir
 */
PHP_METHOD(OAuth2_Autoloader, register) {

	zval *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *dir_param = NULL, _0, _1, *_4 = NULL;
	zval *dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dir_param);

	if (!dir_param) {
		ZEPHIR_INIT_VAR(dir);
		ZVAL_EMPTY_STRING(dir);
	} else {
	if (unlikely(Z_TYPE_P(dir_param) != IS_STRING && Z_TYPE_P(dir_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dir' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(dir_param) == IS_STRING)) {
		zephir_get_strval(dir, dir_param);
	} else {
		ZEPHIR_INIT_VAR(dir);
		ZVAL_EMPTY_STRING(dir);
	}
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "unserialize_callback_func", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "spl_autoload_call", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_2, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 3);
	ZEPHIR_INIT_VAR(_4);
	object_init_ex(_4, oauth2_autoloader_ce);
	ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, dir);
	zephir_check_call_status();
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "autoload", 1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Handles autoloading of classes.
 *
 * @param string className A class name.
 * @return boolean Returns true if the class has been loaded
 */
PHP_METHOD(OAuth2_Autoloader, autoload) {

	zval *className_param = NULL, *file, _0, *_1, *_2, *_3, _4, _5;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	if (unlikely(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(className_param) == IS_STRING)) {
		zephir_get_strval(className, className_param);
	} else {
		ZEPHIR_INIT_VAR(className);
		ZVAL_EMPTY_STRING(className);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "OAuth2", 0);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strpos(_1, className, &_0, 0 );
	if (!ZEPHIR_IS_LONG_IDENTICAL(_1, 0)) {
		RETURN_MM_BOOL(0);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("dir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "\\", 0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "/", 0);
	zephir_fast_str_replace(_3, &_4, &_5, className TSRMLS_CC);
	ZEPHIR_INIT_VAR(file);
	ZEPHIR_CONCAT_VSVS(file, _2, "/", _3, ".php");
	if ((zephir_file_exists(file TSRMLS_CC) == SUCCESS)) {
		if (zephir_require_zval(file TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

