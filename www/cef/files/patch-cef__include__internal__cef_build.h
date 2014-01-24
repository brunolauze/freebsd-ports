--- cef/include/internal/cef_build.h.orig	2014-01-23 13:40:54.883359524 -0600
+++ cef/include/internal/cef_build.h	2014-01-23 13:41:36.903485558 -0600
@@ -50,6 +50,10 @@
 #ifndef OS_LINUX
 #define OS_LINUX 1
 #endif
+#elif defined(__FreeBSD__)
+#ifndef OS_BSD
+#define OS_BSD 1
+#endif
 #else
 #error Please add support for your platform in cef_build.h
 #endif
