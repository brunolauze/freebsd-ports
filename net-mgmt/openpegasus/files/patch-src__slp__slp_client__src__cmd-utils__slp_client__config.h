--- src/slp/slp_client/src/cmd-utils/slp_client/config.h.orig	2014-02-26 06:03:01.276231860 -0600
+++ src/slp/slp_client/src/cmd-utils/slp_client/config.h	2014-02-26 06:12:15.204135816 -0600
@@ -73,6 +73,8 @@
     defined(PEGASUS_PLATFORM_WIN64_X86_64_MSVC) || \
     defined(PEGASUS_PLATFORM_WIN32_IX86_MSVC)
 #    define HOST_OS "Windows"
+#elif defined(PEGASUS_OS_FREEBSD)
+#    define HOST_OS "FreeBSD"
 #else
 #    define HOST_OS "Linux"
 #endif
@@ -82,6 +84,8 @@
     defined(PEGASUS_PLATFORM_WIN64_X86_64_MSVC) || \
     defined(PEGASUS_PLATFORM_WIN32_IX86_MSVC)
 #    define OS_PORT_INCLUDE "lslp-windows.h"
+#elif defined(PEGASUS_OS_FREEBSD)
+#    define OS_PORT_INCLUDE "lslp-freebsd.h"
 #else
 #    define OS_PORT_INCLUDE "lslp-linux.h"
 #endif
