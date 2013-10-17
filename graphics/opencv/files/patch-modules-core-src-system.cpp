--- modules/core/src/system.cpp.orig	2013-10-07 22:22:20.403708650 -0500
+++ modules/core/src/system.cpp	2013-10-07 22:22:45.594970168 -0500
@@ -79,7 +79,7 @@
 #include <pthread.h>
 #include <sys/time.h>
 #include <time.h>
-
+#include <unistd.h>
 #if defined __MACH__ && defined __APPLE__
 #include <mach/mach.h>
 #include <mach/mach_time.h>
@@ -904,4 +904,4 @@
 
 }
 
-/* End of file. */
\ No newline at end of file
+/* End of file. */
