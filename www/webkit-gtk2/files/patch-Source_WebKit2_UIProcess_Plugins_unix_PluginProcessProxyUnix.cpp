--- Source/WebKit2/UIProcess/Plugins/unix/PluginProcessProxyUnix.cpp.orig	2013-09-09 03:29:14.000000000 -0500
+++ Source/WebKit2/UIProcess/Plugins/unix/PluginProcessProxyUnix.cpp	2014-01-23 14:48:55.233289329 -0600
@@ -27,7 +27,8 @@
 
 #include "config.h"
 #include "PluginProcessProxy.h"
-
+#include <sys/signal.h>
+#include <sys/wait.h>
 #if ENABLE(PLUGIN_PROCESS)
 
 #include "PluginProcessCreationParameters.h"
@@ -74,16 +75,16 @@
     int status;
     GOwnPtr<char> stdOut;
 
-    // If the disposition of SIGCLD signal is set to SIG_IGN (default)
+    // If the disposition of SIGCHLD signal is set to SIG_IGN (default)
     // then the signal will be ignored and g_spawn_sync() will not be
     // able to return the status.
     // As a consequence, we make sure that the disposition is set to
     // SIG_DFL before calling g_spawn_sync().
     struct sigaction action;
-    sigaction(SIGCLD, 0, &action);
+    sigaction(SIGCHLD, 0, &action);
     if (action.sa_handler == SIG_IGN) {
         action.sa_handler = SIG_DFL;
-        sigaction(SIGCLD, &action, 0);
+        sigaction(SIGCHLD, &action, 0);
     }
 
     if (!g_spawn_sync(0, argv, 0, G_SPAWN_STDERR_TO_DEV_NULL, 0, 0, &stdOut.outPtr(), 0, &status, 0))
