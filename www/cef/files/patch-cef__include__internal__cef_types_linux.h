--- cef/include/internal/cef_types_linux.h.orig	2014-01-23 13:45:25.103378859 -0600
+++ cef/include/internal/cef_types_linux.h	2014-01-23 13:45:44.433377391 -0600
@@ -34,7 +34,7 @@
 
 #include "include/internal/cef_build.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <gtk/gtk.h>
 #include "include/internal/cef_string.h"
 
