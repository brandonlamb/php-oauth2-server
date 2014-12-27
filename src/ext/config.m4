PHP_ARG_ENABLE(oauth2, whether to enable oauth2, [ --enable-oauth2   Enable Oauth2])

if test "$PHP_OAUTH2" = "yes"; then

	AC_DEFINE(HAVE_OAUTH2, 1, [Whether you have Oauth2])
	oauth2_sources="oauth2.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/exit.c oauth2/autoloader.zep.c
	oauth2/clientassertiontype/clientassertiontypeinterface.zep.c
	oauth2/clientassertiontype/httpbasic.zep.c
	oauth2/controller/authorizecontrollerinterface.zep.c
	oauth2/controller/resourcecontroller.zep.c
	oauth2/controller/resourcecontrollerinterface.zep.c
	oauth2/controller/tokencontroller.zep.c
	oauth2/controller/tokencontrollerinterface.zep.c
	oauth2/encryption/encryptioninterface.zep.c
	oauth2/exception.zep.c
	oauth2/granttype/authorizationcode.zep.c
	oauth2/granttype/clientcredentials.zep.c
	oauth2/granttype/granttypeinterface.zep.c
	oauth2/granttype/jwtbearer.zep.c
	oauth2/granttype/refreshtoken.zep.c
	oauth2/granttype/usercredentials.zep.c
	oauth2/requestinterface.zep.c
	oauth2/responseinterface.zep.c
	oauth2/responsetype/accesstoken.zep.c
	oauth2/responsetype/accesstokeninterface.zep.c
	oauth2/responsetype/authorizationcode.zep.c
	oauth2/responsetype/authorizationcodeinterface.zep.c
	oauth2/responsetype/responsetypeinterface.zep.c
	oauth2/scope.zep.c
	oauth2/scopeinterface.zep.c
	oauth2/storage/accesstokeninterface.zep.c
	oauth2/storage/authorizationcodeinterface.zep.c
	oauth2/storage/clientcredentialsinterface.zep.c
	oauth2/storage/clientinterface.zep.c
	oauth2/storage/jwtaccesstoken.zep.c
	oauth2/storage/jwtaccesstokeninterface.zep.c
	oauth2/storage/jwtbearerinterface.zep.c
	oauth2/storage/publickeyinterface.zep.c
	oauth2/storage/refreshtokeninterface.zep.c
	oauth2/storage/scopeinterface.zep.c
	oauth2/storage/storageinterface.zep.c
	oauth2/storage/usercredentialsinterface.zep.c
	oauth2/tokentype/bearer.zep.c
	oauth2/tokentype/mac.zep.c
	oauth2/tokentype/tokentypeinterface.zep.c "
	PHP_NEW_EXTENSION(oauth2, $oauth2_sources, $ext_shared)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([oauth2], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([oauth2], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/oauth2], [php_OAUTH2.h])
fi
