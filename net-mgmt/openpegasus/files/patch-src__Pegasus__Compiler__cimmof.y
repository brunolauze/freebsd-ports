--- src/Pegasus/Compiler/cimmof.y.orig	2014-02-28 20:49:57.617222206 -0600
+++ src/Pegasus/Compiler/cimmof.y	2014-02-28 20:51:15.345160620 -0600
@@ -68,7 +68,7 @@
 
 #include <cstdlib>
 #if !defined(PEGASUS_OS_ZOS) && !defined(PEGASUS_OS_VMS)
-#if defined(PEGASUS_OS_DARWIN)
+#if defined(PEGASUS_OS_DARWIN) || defined(PEGASUS_OS_FREEBSD)
 #include <sys/malloc.h>
 #else
 #include <malloc.h>
