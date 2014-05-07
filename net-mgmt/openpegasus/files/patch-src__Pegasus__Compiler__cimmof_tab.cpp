--- src/Pegasus/Compiler/cimmof_tab.cpp.orig	2014-02-28 21:01:10.213309635 -0600
+++ src/Pegasus/Compiler/cimmof_tab.cpp	2014-02-28 21:01:37.600750144 -0600
@@ -256,7 +256,7 @@
 
 #include <cstdlib>
 #if !defined(PEGASUS_OS_ZOS) && !defined(PEGASUS_OS_VMS)
-#if defined(PEGASUS_OS_DARWIN)
+#if defined(PEGASUS_OS_DARWIN) || defined(PEGASUS_OS_FREEBSD)
 #include <sys/malloc.h>
 #else
 #include <malloc.h>
