--- src/Pegasus/Common/Constants.h.orig	2014-04-23 12:58:45.783772232 -0500
+++ src/Pegasus/Common/Constants.h	2014-04-23 13:03:53.309750375 -0500
@@ -320,6 +320,26 @@
 #  define PEGASUS_PAM_STANDALONE_PROC_NAME  "/opt/tog-pegasus/sbin/cimservera"
 #  define PEGASUS_PROVIDER_AGENT_PROC_NAME  "/opt/tog-pegasus/sbin/cimprovagt"
 #  undef PEGASUS_DEFAULT_MESSAGE_SOURCE     /* Not defined */
+# elif defined(PEGASUS_OS_FREEBSD)
+#  define PEGASUS_CIMSERVER_START_FILE      "/var/run/cimserverd.pid"
+#  define PEGASUS_CIMSERVER_START_LOCK_FILE \
+    "/var/run/tog-pegasus/cimserver_start.lock"
+#  define PEGASUS_REPOSITORY_DIR            "/usr/local/share/pegasus/repository"
+#  define PEGASUS_CURRENT_CONFIG_FILE_PATH  \
+    "/usr/local/etc/pegasus/cimserver_current.conf"
+#  define PEGASUS_PLANNED_CONFIG_FILE_PATH  \
+    "/usr/local/etc/pegasus/cimserver_planned.conf"
+#  define PEGASUS_SSLCLIENT_CERTIFICATEFILE "/usr/local/etc/pegasus/client.pem"
+#  define PEGASUS_SSLCLIENT_RANDOMFILE      "/usr/local/etc/pegasus/ssl.rnd"
+#  define PEGASUS_SSLSERVER_RANDOMFILE      "/usr/local/etc/pegasus/cimserver.rnd"
+#  define PEGASUS_LOCAL_AUTH_DIR            \
+    "/var/cache/localauth"
+#  define PEGASUS_LOCAL_DOMAIN_SOCKET_PATH  \
+    "/var/run/cimxml.socket"
+#  define PEGASUS_CORE_DIR                  "/var/cache"
+#  define PEGASUS_PAM_STANDALONE_PROC_NAME  "/usr/local//bin/cimservera"
+#  define PEGASUS_PROVIDER_AGENT_PROC_NAME  "/usr/local/bin/cimprovagt"
+#  undef PEGASUS_DEFAULT_MESSAGE_SOURCE     /* Not defined */
 # elif defined(PEGASUS_OS_VMS)
 #  define PEGASUS_CIMSERVER_START_FILE      \
     "/wbem_var/opt/wbem/cimserver_start.conf"
@@ -391,12 +411,12 @@
     PEGASUS_CIMSERVER_STARTFILES_DIR "/cimserver_start.lock"
 #endif
 
-# define PEGASUS_REPOSITORY_DIR            "repository"
-# define PEGASUS_CURRENT_CONFIG_FILE_PATH  "cimserver_current.conf"
-# define PEGASUS_PLANNED_CONFIG_FILE_PATH  "cimserver_planned.conf"
-# define PEGASUS_SSLCLIENT_CERTIFICATEFILE "client.pem"
-# define PEGASUS_SSLCLIENT_RANDOMFILE      "ssl.rnd"
-# define PEGASUS_SSLSERVER_RANDOMFILE      "cimserver.rnd"
+# define PEGASUS_REPOSITORY_DIR            "/usr/local/share/pegasus/repository"
+# define PEGASUS_CURRENT_CONFIG_FILE_PATH  "/usr/local/etc/pegasus/cimserver_current.conf"
+# define PEGASUS_PLANNED_CONFIG_FILE_PATH  "/usr/local/etc/pegasus/cimserver_planned.conf"
+# define PEGASUS_SSLCLIENT_CERTIFICATEFILE "/usr/local/etc/pegasus/client.pem"
+# define PEGASUS_SSLCLIENT_RANDOMFILE      "/usr/local/etc/pegasus/ssl.rnd"
+# define PEGASUS_SSLSERVER_RANDOMFILE      "/usr/local/etc/pegasus/cimserver.rnd"
 # define PEGASUS_LOCAL_AUTH_DIR            PEGASUS_CIMSERVER_STARTFILES_DIR
 
 #ifdef PEGASUS_FLAVOR
