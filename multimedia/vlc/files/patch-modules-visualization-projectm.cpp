--- modules/visualization/projectm.cpp.orig	2013-10-15 13:05:29.307650381 -0500
+++ modules/visualization/projectm.cpp	2013-10-15 13:06:32.942648811 -0500
@@ -25,10 +25,12 @@
 #ifdef HAVE_CONFIG_H
 # include "config.h"
 #endif
+#ifdef HAVE_XLOCALE_H
+# include <xlocale.h>
+#endif
 #ifndef __STDC_CONSTANT_MACROS
 # define __STDC_CONSTANT_MACROS
 #endif
-
 #include <vlc_common.h>
 #include <vlc_plugin.h>
 #include <vlc_aout.h>
