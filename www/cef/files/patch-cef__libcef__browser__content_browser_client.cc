--- cef/libcef/browser/content_browser_client.cc.orig	2014-01-23 15:05:02.235429479 -0600
+++ cef/libcef/browser/content_browser_client.cc	2014-01-23 16:12:21.213172097 -0600
@@ -47,8 +47,10 @@
 #if defined(OS_POSIX) && !defined(OS_MACOSX)
 #include "base/debug/leak_annotations.h"
 #include "base/platform_file.h"
+#if !defined(OS_BSD)
 #include "components/breakpad/app/breakpad_linux.h"
 #include "components/breakpad/browser/crash_handler_host_linux.h"
+#endif
 #include "content/public/common/content_descriptors.h"
 #endif
 
@@ -287,7 +289,7 @@
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 breakpad::CrashHandlerHostLinux* CreateCrashHandlerHost(
     const std::string& process_type) {
   base::FilePath dumps_path =
@@ -340,7 +342,7 @@
 
   return -1;
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 }  // namespace
 
@@ -871,7 +873,7 @@
 }
 
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void CefContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const CommandLine& command_line,
     int child_process_id,
@@ -882,7 +884,7 @@
         kCrashDumpSignal, base::FileDescriptor(crash_signal_fd, false)));
   }
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 
 #if defined(OS_WIN)
