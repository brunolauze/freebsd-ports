--- src/Pegasus/Common/AuditLoggerToLog.cpp.orig	2014-02-28 20:42:14.140225569 -0600
+++ src/Pegasus/Common/AuditLoggerToLog.cpp	2014-02-28 20:43:23.903404000 -0600
@@ -46,7 +46,7 @@
 # include <unixlib.h>
 #endif
 
-#ifdef PEGASUS_OS_SOLARIS
+#if defined(PEGASUS_OS_SOLARIS) || defined(PEGASUS_OS_FREEBSD)
 extern char** environ;
 #endif
 
@@ -54,7 +54,7 @@
 
 #ifdef PEGASUS_ENABLE_AUDIT_LOGGER
 
-#if defined(PEGASUS_OS_SOLARIS)
+#if defined(PEGASUS_OS_SOLARIS) || defined(PEGASUS_OS_FREEBSD)
 extern char** environ;
 #endif
 
