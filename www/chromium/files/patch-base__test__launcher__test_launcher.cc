--- base/test/launcher/test_launcher.cc.orig	2014-01-14 21:16:07.149747075 -0600
+++ base/test/launcher/test_launcher.cc	2014-01-14 21:16:53.955613479 -0600
@@ -8,6 +8,10 @@
 #include <fcntl.h>
 #endif
 
+#if defined(OS_BSD)
+#include <signal.h>
+#endif
+
 #include "base/at_exit.h"
 #include "base/bind.h"
 #include "base/command_line.h"
