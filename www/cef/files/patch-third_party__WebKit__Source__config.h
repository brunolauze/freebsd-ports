--- third_party/WebKit/Source/config.h.orig	2014-01-13 09:05:30.000000000 -0600
+++ third_party/WebKit/Source/config.h	2014-01-14 23:17:00.863573536 -0600
@@ -167,6 +167,6 @@
 #define __STDC_FORMAT_MACROS 1
 #endif
 
-#if OS(LINUX) || OS(ANDROID) || ENABLE(HARFBUZZ_ON_WINDOWS)
+#if OS(LINUX) || OS(ANDROID) || OS(FREEBSD) || ENABLE(HARFBUZZ_ON_WINDOWS)
 #define WTF_USE_HARFBUZZ 1
 #endif
