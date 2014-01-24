--- cef/include/cef_base.h.orig	2014-01-23 13:42:56.183379772 -0600
+++ cef/include/cef_base.h	2014-01-23 13:43:16.464249494 -0600
@@ -48,7 +48,7 @@
 #include "include/internal/cef_win.h"
 #elif defined(OS_MACOSX)
 #include "include/internal/cef_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "include/internal/cef_linux.h"
 #endif
 
