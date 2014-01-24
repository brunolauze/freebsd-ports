--- cef/include/internal/cef_linux.h.orig	2014-01-23 13:44:33.903402493 -0600
+++ cef/include/internal/cef_linux.h	2014-01-23 13:45:02.023843759 -0600
@@ -32,7 +32,7 @@
 #define CEF_INCLUDE_INTERNAL_CEF_LINUX_H_
 #pragma once
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <pthread.h>
 #include "include/internal/cef_types_linux.h"
 #include "include/internal/cef_types_wrappers.h"
