
extern zend_class_entry *oauth2_granttype_granttypeinterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_GrantType_GrantTypeInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_granttype_granttypeinterface_validaterequest, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, OAuth2\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, OAuth2\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_granttype_granttypeinterface_createaccesstoken, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, accessToken, OAuth2\\ResponseType\\AccessTokenInterface, 0)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, user_id)
	ZEND_ARG_INFO(0, scope)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_granttype_granttypeinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_GrantType_GrantTypeInterface, getQuerystringIdentifier, NULL)
	PHP_ABSTRACT_ME(OAuth2_GrantType_GrantTypeInterface, validateRequest, arginfo_oauth2_granttype_granttypeinterface_validaterequest)
	PHP_ABSTRACT_ME(OAuth2_GrantType_GrantTypeInterface, getClientId, NULL)
	PHP_ABSTRACT_ME(OAuth2_GrantType_GrantTypeInterface, getUserId, NULL)
	PHP_ABSTRACT_ME(OAuth2_GrantType_GrantTypeInterface, getScope, NULL)
	PHP_ABSTRACT_ME(OAuth2_GrantType_GrantTypeInterface, createAccessToken, arginfo_oauth2_granttype_granttypeinterface_createaccesstoken)
  PHP_FE_END
};
