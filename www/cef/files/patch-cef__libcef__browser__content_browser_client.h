--- cef/libcef/browser/content_browser_client.h.orig	2014-01-23 15:05:13.203439102 -0600
+++ cef/libcef/browser/content_browser_client.h	2014-01-23 17:50:36.333031274 -0600
@@ -137,7 +137,7 @@
       content::BrowserURLHandler* handler) OVERRIDE;
   virtual std::string GetDefaultDownloadName() OVERRIDE;
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   virtual void GetAdditionalMappedFilesForChildProcess(
       const CommandLine& command_line,
       int child_process_id,
