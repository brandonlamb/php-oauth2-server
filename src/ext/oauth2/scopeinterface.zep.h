
extern zend_class_entry *oauth2_scopeinterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_ScopeInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_scopeinterface_checkscope, 0, 0, 2)
	ZEND_ARG_INFO(0, required_scope)
	ZEND_ARG_INFO(0, available_scope)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_scopeinterface_getscopefromrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_scopeinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_ScopeInterface, checkScope, arginfo_oauth2_scopeinterface_checkscope)
	PHP_ABSTRACT_ME(OAuth2_ScopeInterface, getScopeFromRequest, arginfo_oauth2_scopeinterface_getscopefromrequest)
  PHP_FE_END
};
