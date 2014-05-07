--- src/Clients/repupgrade/RepositoryUpgrade.cpp.orig	2014-01-15 07:32:30.000000000 -0600
+++ src/Clients/repupgrade/RepositoryUpgrade.cpp	2014-04-23 14:44:34.063334313 -0500
@@ -151,10 +151,10 @@
 /**
     Display messages.
 */
-static const char REQUIRED_ARGS_MISSING [] =
+static const char __unused REQUIRED_ARGS_MISSING [] =
                 "Required arguments missing.";
 
-static const char REQUIRED_ARGS_MISSING_KEY [] =
+static const char __unused REQUIRED_ARGS_MISSING_KEY [] =
                 "Clients.repupgrade.RepositoryUpgrade.REQUIRED_ARGS_MISSING";
 
 static const char REPOSITORY_UPGRADE_FAILURE []    =
@@ -307,6 +307,11 @@
     const String NEW_REPOSITORY_PATH = "/var/opt/tog-pegasus/repository";
     const String RepositoryUpgrade::_LOG_PATH  =
         "/var/opt/tog-pegasus/log/upgrade";
+# elif defined(PEGASUS_OS_FREEBSD)
+    const String OLD_REPOSITORY_PATH = "/usr/local/share/pegasus/prev_repository";
+    const String NEW_REPOSITORY_PATH = "/usr/local/share/pegasus/repository";
+    const String RepositoryUpgrade::_LOG_PATH  =
+        "/var/log/upgrade";
 # else
 #   undef REPUPGRADE_USE_RELEASE_DIRS
     const String RepositoryUpgrade::_LOG_PATH = "./";
