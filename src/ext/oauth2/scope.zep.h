
extern zend_class_entry *oauth2_scope_ce;

ZEPHIR_INIT_CLASS(OAuth2_Scope);

PHP_METHOD(OAuth2_Scope, __construct);
PHP_METHOD(OAuth2_Scope, checkScope);
PHP_METHOD(OAuth2_Scope, scopeExists);
PHP_METHOD(OAuth2_Scope, getScopeFromRequest);
PHP_METHOD(OAuth2_Scope, getDefaultScope);
PHP_METHOD(OAuth2_Scope, getReservedScopes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_scope___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, storage, OAuth2\\Storage\\ScopeInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_scope_checkscope, 0, 0, 2)
	ZEND_ARG_INFO(0, required_scope)
	ZEND_ARG_INFO(0, available_scope)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_scope_scopeexists, 0, 0, 1)
	ZEND_ARG_INFO(0, scope)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_scope_getscopefromrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_scope_getdefaultscope, 0, 0, 0)
	ZEND_ARG_INFO(0, client_id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_scope_method_entry) {
	PHP_ME(OAuth2_Scope, __construct, arginfo_oauth2_scope___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth2_Scope, checkScope, arginfo_oauth2_scope_checkscope, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_Scope, scopeExists, arginfo_oauth2_scope_scopeexists, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_Scope, getScopeFromRequest, arginfo_oauth2_scope_getscopefromrequest, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_Scope, getDefaultScope, arginfo_oauth2_scope_getdefaultscope, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth2_Scope, getReservedScopes, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
