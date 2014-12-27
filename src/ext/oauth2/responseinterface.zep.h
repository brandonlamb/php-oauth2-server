
extern zend_class_entry *oauth2_responseinterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_ResponseInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_responseinterface_addparameters, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_responseinterface_addhttpheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, httpHeaders, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_responseinterface_setstatuscode, 0, 0, 1)
	ZEND_ARG_INFO(0, statusCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_responseinterface_seterror, 0, 0, 2)
	ZEND_ARG_INFO(0, statusCode)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, description)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_responseinterface_setredirect, 0, 0, 2)
	ZEND_ARG_INFO(0, statusCode)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, state)
	ZEND_ARG_INFO(0, error)
	ZEND_ARG_INFO(0, errorDescription)
	ZEND_ARG_INFO(0, errorUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_responseinterface_getparameter, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, default)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_responseinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_ResponseInterface, addParameters, arginfo_oauth2_responseinterface_addparameters)
	PHP_ABSTRACT_ME(OAuth2_ResponseInterface, addHttpHeaders, arginfo_oauth2_responseinterface_addhttpheaders)
	PHP_ABSTRACT_ME(OAuth2_ResponseInterface, setStatusCode, arginfo_oauth2_responseinterface_setstatuscode)
	PHP_ABSTRACT_ME(OAuth2_ResponseInterface, setError, arginfo_oauth2_responseinterface_seterror)
	PHP_ABSTRACT_ME(OAuth2_ResponseInterface, setRedirect, arginfo_oauth2_responseinterface_setredirect)
	PHP_ABSTRACT_ME(OAuth2_ResponseInterface, getParameter, arginfo_oauth2_responseinterface_getparameter)
  PHP_FE_END
};
