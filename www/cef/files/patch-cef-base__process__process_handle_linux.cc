--- base/process/process_handle_linux.cc.orig	2014-01-23 15:21:08.473232286 -0600
+++ base/process/process_handle_linux.cc	2014-01-23 15:21:52.733631798 -0600
@@ -6,7 +6,7 @@
 
 #include "base/file_util.h"
 #include "base/process/internal_linux.h"
-
+#if defined(OS_LINUX)
 namespace base {
 
 ProcessId GetParentProcessId(ProcessHandle process) {
@@ -28,3 +28,5 @@
 }
 
 }  // namespace base
+
+#endif
