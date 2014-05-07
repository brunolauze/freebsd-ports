--- src/Executor/tests/Path/TestExecutorPath.c.orig	2014-04-23 16:13:56.425964880 -0500
+++ src/Executor/tests/Path/TestExecutorPath.c	2014-04-23 16:14:09.369964016 -0500
@@ -39,6 +39,9 @@
 #include <string.h>
 #include <stdlib.h>
 #include <unistd.h>
+#if defined(__FreeBSD__)
+extern char **environ;
+#endif
 
 static void UnsetEnvironmentVariable(const char* name)
 {
