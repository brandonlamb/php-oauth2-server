
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "oauth2.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *oauth2_storage_storageinterface_ce;
zend_class_entry *oauth2_responsetype_responsetypeinterface_ce;
zend_class_entry *oauth2_granttype_granttypeinterface_ce;
zend_class_entry *oauth2_storage_accesstokeninterface_ce;
zend_class_entry *oauth2_storage_scopeinterface_ce;
zend_class_entry *oauth2_clientassertiontype_clientassertiontypeinterface_ce;
zend_class_entry *oauth2_tokentype_tokentypeinterface_ce;
zend_class_entry *oauth2_controller_resourcecontrollerinterface_ce;
zend_class_entry *oauth2_controller_tokencontrollerinterface_ce;
zend_class_entry *oauth2_responsetype_accesstokeninterface_ce;
zend_class_entry *oauth2_responsetype_authorizationcodeinterface_ce;
zend_class_entry *oauth2_scopeinterface_ce;
zend_class_entry *oauth2_storage_clientinterface_ce;
zend_class_entry *oauth2_storage_jwtaccesstokeninterface_ce;
zend_class_entry *oauth2_controller_authorizecontrollerinterface_ce;
zend_class_entry *oauth2_encryption_encryptioninterface_ce;
zend_class_entry *oauth2_requestinterface_ce;
zend_class_entry *oauth2_responseinterface_ce;
zend_class_entry *oauth2_storage_authorizationcodeinterface_ce;
zend_class_entry *oauth2_storage_clientcredentialsinterface_ce;
zend_class_entry *oauth2_storage_jwtbearerinterface_ce;
zend_class_entry *oauth2_storage_publickeyinterface_ce;
zend_class_entry *oauth2_storage_refreshtokeninterface_ce;
zend_class_entry *oauth2_storage_usercredentialsinterface_ce;
zend_class_entry *oauth2_clientassertiontype_httpbasic_ce;
zend_class_entry *oauth2_autoloader_ce;
zend_class_entry *oauth2_controller_resourcecontroller_ce;
zend_class_entry *oauth2_controller_tokencontroller_ce;
zend_class_entry *oauth2_exception_ce;
zend_class_entry *oauth2_granttype_authorizationcode_ce;
zend_class_entry *oauth2_granttype_clientcredentials_ce;
zend_class_entry *oauth2_granttype_jwtbearer_ce;
zend_class_entry *oauth2_granttype_refreshtoken_ce;
zend_class_entry *oauth2_granttype_usercredentials_ce;
zend_class_entry *oauth2_responsetype_accesstoken_ce;
zend_class_entry *oauth2_responsetype_authorizationcode_ce;
zend_class_entry *oauth2_scope_ce;
zend_class_entry *oauth2_storage_jwtaccesstoken_ce;
zend_class_entry *oauth2_tokentype_bearer_ce;
zend_class_entry *oauth2_tokentype_mac_ce;

ZEND_DECLARE_MODULE_GLOBALS(oauth2)

static PHP_MINIT_FUNCTION(oauth2)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(OAuth2_Storage_StorageInterface);
	ZEPHIR_INIT(OAuth2_ResponseType_ResponseTypeInterface);
	ZEPHIR_INIT(OAuth2_GrantType_GrantTypeInterface);
	ZEPHIR_INIT(OAuth2_Storage_AccessTokenInterface);
	ZEPHIR_INIT(OAuth2_Storage_ScopeInterface);
	ZEPHIR_INIT(OAuth2_ClientAssertionType_ClientAssertionTypeInterface);
	ZEPHIR_INIT(OAuth2_TokenType_TokenTypeInterface);
	ZEPHIR_INIT(OAuth2_Controller_ResourceControllerInterface);
	ZEPHIR_INIT(OAuth2_Controller_TokenControllerInterface);
	ZEPHIR_INIT(OAuth2_ResponseType_AccessTokenInterface);
	ZEPHIR_INIT(OAuth2_ResponseType_AuthorizationCodeInterface);
	ZEPHIR_INIT(OAuth2_ScopeInterface);
	ZEPHIR_INIT(OAuth2_Storage_ClientInterface);
	ZEPHIR_INIT(OAuth2_Storage_JwtAccessTokenInterface);
	ZEPHIR_INIT(OAuth2_Controller_AuthorizeControllerInterface);
	ZEPHIR_INIT(OAuth2_Encryption_EncryptionInterface);
	ZEPHIR_INIT(OAuth2_RequestInterface);
	ZEPHIR_INIT(OAuth2_ResponseInterface);
	ZEPHIR_INIT(OAuth2_Storage_AuthorizationCodeInterface);
	ZEPHIR_INIT(OAuth2_Storage_ClientCredentialsInterface);
	ZEPHIR_INIT(OAuth2_Storage_JwtBearerInterface);
	ZEPHIR_INIT(OAuth2_Storage_PublicKeyInterface);
	ZEPHIR_INIT(OAuth2_Storage_RefreshTokenInterface);
	ZEPHIR_INIT(OAuth2_Storage_UserCredentialsInterface);
	ZEPHIR_INIT(OAuth2_ClientAssertionType_HttpBasic);
	ZEPHIR_INIT(OAuth2_Autoloader);
	ZEPHIR_INIT(OAuth2_Controller_ResourceController);
	ZEPHIR_INIT(OAuth2_Controller_TokenController);
	ZEPHIR_INIT(OAuth2_Exception);
	ZEPHIR_INIT(OAuth2_GrantType_AuthorizationCode);
	ZEPHIR_INIT(OAuth2_GrantType_ClientCredentials);
	ZEPHIR_INIT(OAuth2_GrantType_JwtBearer);
	ZEPHIR_INIT(OAuth2_GrantType_RefreshToken);
	ZEPHIR_INIT(OAuth2_GrantType_UserCredentials);
	ZEPHIR_INIT(OAuth2_ResponseType_AccessToken);
	ZEPHIR_INIT(OAuth2_ResponseType_AuthorizationCode);
	ZEPHIR_INIT(OAuth2_Scope);
	ZEPHIR_INIT(OAuth2_Storage_JwtAccessToken);
	ZEPHIR_INIT(OAuth2_TokenType_Bearer);
	ZEPHIR_INIT(OAuth2_TokenType_Mac);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(oauth2)
{

	zephir_deinitialize_memory(TSRMLS_C);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_oauth2_globals *zephir_globals TSRMLS_DC)
{
	zephir_globals->initialized = 0;

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache Enabled */
#if PHP_VERSION_ID < 50600
	zephir_globals->cache_enabled = 1;
#else
	zephir_globals->cache_enabled = 0;
#endif

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;


}

static PHP_RINIT_FUNCTION(oauth2)
{

	zend_oauth2_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(oauth2)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(oauth2)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_OAUTH2_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_OAUTH2_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_OAUTH2_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_OAUTH2_VERSION);
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_OAUTH2_ZEPVERSION);
	php_info_print_table_end();


}

static PHP_GINIT_FUNCTION(oauth2)
{
	php_zephir_init_globals(oauth2_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(oauth2)
{

}

zend_module_entry oauth2_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_OAUTH2_EXTNAME,
	NULL,
	PHP_MINIT(oauth2),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(oauth2),
#else
	NULL,
#endif
	PHP_RINIT(oauth2),
	PHP_RSHUTDOWN(oauth2),
	PHP_MINFO(oauth2),
	PHP_OAUTH2_VERSION,
	ZEND_MODULE_GLOBALS(oauth2),
	PHP_GINIT(oauth2),
	PHP_GSHUTDOWN(oauth2),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_OAUTH2
ZEND_GET_MODULE(oauth2)
#endif
