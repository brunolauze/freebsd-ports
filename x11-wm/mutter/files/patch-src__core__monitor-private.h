--- src/core/monitor-private.h.orig	2014-01-19 17:50:46.419776306 -0600
+++ src/core/monitor-private.h	2014-01-19 17:59:08.169773773 -0600
@@ -38,7 +38,6 @@
 #define META_MONITOR_PRIVATE_H
 
 #include <cogl/cogl.h>
-#include <libgnome-desktop/gnome-pnp-ids.h>
 
 #include "display-private.h"
 #include <meta/screen.h>
@@ -252,7 +251,6 @@
   int persistent_timeout_id;
   MetaMonitorConfig *config;
 
-  GnomePnpIds *pnp_ids;
 };
 
 struct _MetaMonitorManagerClass
