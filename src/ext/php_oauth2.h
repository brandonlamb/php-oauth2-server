
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_OAUTH2_H
#define PHP_OAUTH2_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_OAUTH2_NAME        "oauth2"
#define PHP_OAUTH2_VERSION     "0.0.1"
#define PHP_OAUTH2_EXTNAME     "oauth2"
#define PHP_OAUTH2_AUTHOR      ""
#define PHP_OAUTH2_ZEPVERSION  "0.5.9a"
#define PHP_OAUTH2_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(oauth2)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(oauth2)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(oauth2)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(oauth2_globals_id, zend_oauth2_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (oauth2_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_oauth2_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(oauth2_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(oauth2_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def oauth2_globals
#define zend_zephir_globals_def zend_oauth2_globals

extern zend_module_entry oauth2_module_entry;
#define phpext_oauth2_ptr &oauth2_module_entry

#endif
