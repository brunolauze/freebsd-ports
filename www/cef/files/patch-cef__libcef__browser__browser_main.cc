--- cef/libcef/browser/browser_main.cc.orig	2014-01-23 13:56:21.023342353 -0600
+++ cef/libcef/browser/browser_main.cc	2014-01-23 13:56:33.495579900 -0600
@@ -26,7 +26,7 @@
 #include "ui/base/resource/resource_bundle.h"
 #include "v8/include/v8.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/printing/print_dialog_gtk.h"
 #endif
 
