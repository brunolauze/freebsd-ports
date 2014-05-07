--- src/Executor/tests/Socket/TestExecutorSocket.c.orig	2014-04-23 16:28:46.419903110 -0500
+++ src/Executor/tests/Socket/TestExecutorSocket.c	2014-04-23 16:29:18.372901031 -0500
@@ -40,6 +40,9 @@
 #include <errno.h>
 #include <stdio.h>
 #include <string.h>
+#if defined(PEGASUS_OS_FREEBSD)
+#include <sys/stat.h>
+#endif
 
 static const char token[] = "A65F5382BC3D4F12AE24A1F6110015AF";
 
