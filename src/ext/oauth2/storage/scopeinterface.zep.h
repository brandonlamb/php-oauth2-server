
extern zend_class_entry *oauth2_storage_scopeinterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_Storage_ScopeInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_scopeinterface_scopeexists, 0, 0, 1)
	ZEND_ARG_INFO(0, scope)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_scopeinterface_getdefaultscope, 0, 0, 0)
	ZEND_ARG_INFO(0, client_id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_storage_scopeinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_Storage_ScopeInterface, scopeExists, arginfo_oauth2_storage_scopeinterface_scopeexists)
	PHP_ABSTRACT_ME(OAuth2_Storage_ScopeInterface, getDefaultScope, arginfo_oauth2_storage_scopeinterface_getdefaultscope)
  PHP_FE_END
};
