
extern zend_class_entry *oauth2_requestinterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_RequestInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_requestinterface_query, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_requestinterface_request, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_requestinterface_server, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_requestinterface_headers, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, default)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_requestinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_RequestInterface, query, arginfo_oauth2_requestinterface_query)
	PHP_ABSTRACT_ME(OAuth2_RequestInterface, request, arginfo_oauth2_requestinterface_request)
	PHP_ABSTRACT_ME(OAuth2_RequestInterface, server, arginfo_oauth2_requestinterface_server)
	PHP_ABSTRACT_ME(OAuth2_RequestInterface, headers, arginfo_oauth2_requestinterface_headers)
	PHP_ABSTRACT_ME(OAuth2_RequestInterface, getAllQueryParameters, NULL)
  PHP_FE_END
};
