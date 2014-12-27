
extern zend_class_entry *oauth2_autoloader_ce;

ZEPHIR_INIT_CLASS(OAuth2_Autoloader);

PHP_METHOD(OAuth2_Autoloader, __construct);
PHP_METHOD(OAuth2_Autoloader, register);
PHP_METHOD(OAuth2_Autoloader, autoload);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_autoloader___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_autoloader_register, 0, 0, 0)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth2_autoloader_autoload, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth2_autoloader_method_entry) {
	PHP_ME(OAuth2_Autoloader, __construct, arginfo_oauth2_autoloader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth2_Autoloader, register, arginfo_oauth2_autoloader_register, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OAuth2_Autoloader, autoload, arginfo_oauth2_autoloader_autoload, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
