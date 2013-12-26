--- gsf/gsf-output-iconv.c.orig	2013-12-26 16:34:42.872658942 -0600
+++ gsf/gsf-output-iconv.c	2013-12-26 16:36:21.622537147 -0600
@@ -22,6 +22,7 @@
 #include <gsf-config.h>
 #include <gsf/gsf-output-iconv.h>
 #include <gsf/gsf.h>
+#include <glibconfig.h>
 #include <glib/gi18n-lib.h>
 
 #include <string.h>
