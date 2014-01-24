--- cef/include/internal/cef_types.h.orig	2014-01-23 13:47:35.713374441 -0600
+++ cef/include/internal/cef_types.h	2014-01-23 13:48:19.414319363 -0600
@@ -42,7 +42,7 @@
 #include "include/internal/cef_types_win.h"
 #elif defined(OS_MACOSX)
 #include "include/internal/cef_types_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "include/internal/cef_types_linux.h"
 #endif
 
