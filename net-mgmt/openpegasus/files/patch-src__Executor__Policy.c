--- src/Executor/Policy.c.orig	2014-04-23 13:59:25.205520799 -0500
+++ src/Executor/Policy.c	2014-04-23 13:59:55.054518838 -0500
@@ -33,6 +33,9 @@
 #include <unistd.h>
 #include <ctype.h>
 #include <fcntl.h>
+#if defined(PEGASUS_OS_FREEBSD)
+#include <sys/stat.h>
+#endif
 #include "Policy.h"
 #include "Defines.h"
 #include "Macro.h"
