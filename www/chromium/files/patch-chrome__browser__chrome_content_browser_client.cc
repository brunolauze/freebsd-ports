--- chrome/browser/chrome_content_browser_client.cc.orig	2014-01-13 09:01:01.000000000 -0600
+++ chrome/browser/chrome_content_browser_client.cc	2014-01-14 21:52:50.427622529 -0600
@@ -487,7 +487,7 @@
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 breakpad::CrashHandlerHostLinux* CreateCrashHandlerHost(
     const std::string& process_type) {
   base::FilePath dumps_path;
@@ -1399,7 +1399,7 @@
   if (breakpad::IsCrashReporterEnabled()) {
     std::string enable_crash_reporter;
     GoogleUpdateSettings::GetMetricsId(&enable_crash_reporter);
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     enable_crash_reporter += "," + base::GetLinuxDistro();
 #endif
     command_line->AppendSwitchASCII(switches::kEnableCrashReporter,
@@ -2530,7 +2530,7 @@
           Profile::FromBrowserContext(browser_context)));
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const CommandLine& command_line,
     int child_process_id,
@@ -2585,7 +2585,7 @@
   }
 #endif  // defined(OS_ANDROID)
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 const wchar_t* ChromeContentBrowserClient::GetResourceDllName() {
