--- src/Pegasus/Config/SecurityPropertyOwner.cpp	2014-04-30 09:12:08.068364118 -0500
+++ src/Pegasus/Config/SecurityPropertyOwner.cpp.orig	2014-04-30 09:08:32.494378811 -0500
@@ -78,8 +78,8 @@
 //   authorizedUserGroups
 ///////////////////////////////////////////////////////////////////////////////
 #ifdef PEGASUS_OS_PASE
-    {"enableAuthentication", "true", IS_DYNAMIC, IS_VISIBLE},
-    {"httpAuthType", "Basic", IS_DYNAMIC, IS_VISIBLE},
+    {"enableAuthentication", "true", IS_STATIC, IS_VISIBLE},
+    {"httpAuthType", "Basic", IS_STATIC, IS_VISIBLE},
     {"passwordFilePath", "cimserver.passwd", IS_STATIC, IS_VISIBLE},
     {"sslCertificateFilePath", "ssl/keystore/servercert.pem", IS_STATIC,
         IS_VISIBLE},
@@ -97,8 +97,8 @@
     {"enableRemotePrivilegedUserAccess", "true", IS_STATIC, IS_VISIBLE},
     {"authorizedUserGroups", "", IS_STATIC, IS_VISIBLE},
 #else // PEGASUS_OS_PASE
-    {"enableAuthentication", "false", IS_DYNAMIC, IS_VISIBLE},
-    {"httpAuthType", "Basic", IS_DYNAMIC, IS_VISIBLE},
+    {"enableAuthentication", "false", IS_STATIC, IS_VISIBLE},
+    {"httpAuthType", "Basic", IS_STATIC, IS_VISIBLE},
     {"passwordFilePath", "cimserver.passwd", IS_STATIC, IS_VISIBLE},
 #ifdef PEGASUS_OS_HPUX
     {"sslCertificateFilePath", "cert.pem", IS_STATIC, IS_VISIBLE},
@@ -117,7 +117,7 @@
 #if defined(PEGASUS_OS_HPUX) || defined(PEGASUS_OS_LINUX) || defined(PEGASUS_OS_FREEBSD)
 # ifdef PEGASUS_USE_RELEASE_CONFIG_OPTIONS
     {"enableSubscriptionsForNonprivilegedUsers",
-         "true", IS_STATIC, IS_VISIBLE},
+         "false", IS_STATIC, IS_VISIBLE},
 # else
     {"enableSubscriptionsForNonprivilegedUsers", "true", IS_STATIC, IS_VISIBLE},
 # endif
