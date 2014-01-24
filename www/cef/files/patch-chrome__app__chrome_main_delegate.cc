--- chrome/app/chrome_main_delegate.cc.orig	2014-01-21 06:25:44.277301962 -0600
+++ chrome/app/chrome_main_delegate.cc	2014-01-21 06:25:18.287555692 -0600
@@ -97,7 +97,7 @@
 #include "ui/base/x/x11_util.h"
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "components/breakpad/app/breakpad_linux.h"
 #endif
 
@@ -115,7 +115,7 @@
     g_chrome_content_plugin_client = LAZY_INSTANCE_INITIALIZER;
 #endif
 
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
 base::LazyInstance<chrome::ChromeBreakpadClient>::Leaky
     g_chrome_breakpad_client = LAZY_INSTANCE_INITIALIZER;
 #endif
@@ -235,7 +235,7 @@
       // Mac needs them for the plugin process name.
       process_type == switches::kPluginProcess ||
 #endif
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
       // The zygote process opens the resources for the renderers.
       process_type == switches::kZygoteProcess ||
 #endif
@@ -392,7 +392,7 @@
       std::string format_str =
           command_line.GetSwitchValueASCII(switches::kDiagnosticsFormat);
       if (format_str == "machine") {
-        format = diagnostics::DiagnosticsWriter::MACHINE;
+        format = diagnostics::DiagnosticsWriter::THEMACHINE;
       } else if (format_str == "log") {
         format = diagnostics::DiagnosticsWriter::LOG;
       } else {
@@ -433,7 +433,7 @@
       std::string format_str =
           command_line.GetSwitchValueASCII(switches::kDiagnosticsFormat);
       if (format_str == "machine") {
-        format = diagnostics::DiagnosticsWriter::MACHINE;
+        format = diagnostics::DiagnosticsWriter::THEMACHINE;
       } else if (format_str == "human") {
         format = diagnostics::DiagnosticsWriter::HUMAN;
       } else {
@@ -564,7 +564,7 @@
   std::string process_type =
       command_line.GetSwitchValueASCII(switches::kProcessType);
 
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
   breakpad::SetBreakpadClient(g_chrome_breakpad_client.Pointer());
 #endif
 
@@ -704,7 +704,7 @@
 #endif
   }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   // Zygote needs to call InitCrashReporter() in RunZygote().
   if (process_type != switches::kZygoteProcess) {
 #if defined(OS_ANDROID)
@@ -822,8 +822,9 @@
   const CommandLine* command_line = CommandLine::ForCurrentProcess();
   std::string process_type =
       command_line->GetSwitchValueASCII(switches::kProcessType);
+#if !defined(OS_BSD)
   breakpad::InitCrashReporter(process_type);
-
+#endif
   // Reset the command line for the newly spawned process.
   crash_keys::SetSwitchesFromCommandLine(command_line);
 }
