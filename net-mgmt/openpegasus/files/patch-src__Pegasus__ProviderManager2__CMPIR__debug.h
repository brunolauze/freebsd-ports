--- src/Pegasus/ProviderManager2/CMPIR/debug.h.orig	2014-02-25 15:59:44.862685935 -0600
+++ src/Pegasus/ProviderManager2/CMPIR/debug.h	2014-02-25 16:37:46.299508498 -0600
@@ -125,7 +125,7 @@
 
 #endif /* PEGASUS_DEBUG */
 
-#ifndef PEGASUS_PLATFORM_LINUX_GENERIC_GNU
+#if defined(PEGASUS_PLATFORM_LINUX_GENERIC_GNU) || defined(PEGASUS_PLATFORM_FREEBSD_GENERIC_GNU)
 PEGASUS_RCMPI_DEBUG_VISIBILITY void error_at_line(int a_num, int error,
     char* filename, int line, char* message, ...);
 #endif
