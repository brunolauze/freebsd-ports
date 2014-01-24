--- cef/libcef/common/main_delegate.cc.orig	2014-01-23 16:15:27.333183138 -0600
+++ cef/libcef/common/main_delegate.cc	2014-01-23 16:18:11.433185264 -0600
@@ -42,7 +42,7 @@
 #include "content/public/common/content_paths.h"
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "components/breakpad/app/breakpad_linux.h"
 #endif
 
@@ -361,12 +361,14 @@
   if (command_line.HasSwitch(switches::kEnableCrashReporter)) {
     const std::string& process_type = command_line.GetSwitchValueASCII(
         switches::kProcessType);
+#if !defined(OS_BSD)
     breakpad::SetBreakpadClient(g_shell_breakpad_client.Pointer());
+#endif
 #if defined(OS_MACOSX)
     base::mac::DisableOSCrashDumps();
     breakpad::InitCrashReporter(process_type);
     breakpad::InitCrashProcessInfo(process_type);
-#elif defined(OS_POSIX) && !defined(OS_MACOSX)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
     if (process_type != switches::kZygoteProcess)
       breakpad::InitCrashReporter(process_type);
 #elif defined(OS_WIN)
@@ -429,7 +431,7 @@
   ResourceBundle::CleanupSharedInstance();
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void CefMainDelegate::ZygoteForked() {
   const CommandLine& command_line = *CommandLine::ForCurrentProcess();
   if (command_line.HasSwitch(switches::kEnableCrashReporter)) {
