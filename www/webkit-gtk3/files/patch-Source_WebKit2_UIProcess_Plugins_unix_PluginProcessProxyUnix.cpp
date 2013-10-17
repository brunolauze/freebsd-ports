--- Source/WebKit2/UIProcess/Plugins/unix/PluginProcessProxyUnix.cpp.orig	2013-10-08 16:50:34.683185182 -0500
+++ Source/WebKit2/UIProcess/Plugins/unix/PluginProcessProxyUnix.cpp	2013-10-08 16:50:53.592723054 -0500
@@ -27,7 +27,8 @@
 
 #include "config.h"
 #include "PluginProcessProxy.h"
-
+#include <sys/signal.h>
+#include <sys/wait.h>
 #if ENABLE(PLUGIN_PROCESS)
 
 #include "PluginProcessCreationParameters.h"
