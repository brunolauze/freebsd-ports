--- src/Executor/tests/Macro/TestExecutorMacro.c.orig	2014-04-23 15:58:09.065029968 -0500
+++ src/Executor/tests/Macro/TestExecutorMacro.c	2014-04-23 16:00:22.151020804 -0500
@@ -38,6 +38,9 @@
 #include <string.h>
 #include <stdlib.h>
 #include <unistd.h>
+#if defined(__FreeBSD__)
+extern char **environ;
+#endif
 
 #define TEST_DUMP_FILE "dumpfile"
 #define MAX_DUMP_SIZE 1024
