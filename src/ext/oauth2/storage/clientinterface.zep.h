
extern zend_class_entry *oauth2_storage_clientinterface_ce;

ZEPHIR_INIT_CLASS(OAuth2_Storage_ClientInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_clientinterface_getclientdetails, 0, 0, 1)
	ZEND_ARG_INFO(0, client_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_clientinterface_getclientscope, 0, 0, 1)
	ZEND_ARG_INFO(0, client_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_storage_clientinterface_checkrestrictedgranttype, 0, 0, 2)
	ZEND_ARG_INFO(0, client_id)
	ZEND_ARG_INFO(0, grant_type)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_storage_clientinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth2_Storage_ClientInterface, getClientDetails, arginfo_oauth2_storage_clientinterface_getclientdetails)
	PHP_ABSTRACT_ME(OAuth2_Storage_ClientInterface, getClientScope, arginfo_oauth2_storage_clientinterface_getclientscope)
	PHP_ABSTRACT_ME(OAuth2_Storage_ClientInterface, checkRestrictedGrantType, arginfo_oauth2_storage_clientinterface_checkrestrictedgranttype)
  PHP_FE_END
};
