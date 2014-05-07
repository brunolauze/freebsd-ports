--- src/Executor/Defines.h.orig	2014-02-28 16:24:48.892950370 -0600
+++ src/Executor/Defines.h	2014-02-28 16:26:40.409891422 -0600
@@ -202,7 +202,7 @@
 **==============================================================================
 */
 
-#if defined(PEGASUS_OS_LINUX)
+#if defined(PEGASUS_OS_LINUX) || defined(PEGASUS_OS_FREEBSD)
 # define HAVE_MSG_CONTROL
 #endif
 
