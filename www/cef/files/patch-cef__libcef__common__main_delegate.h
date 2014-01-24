--- cef/libcef/common/main_delegate.h.orig	2014-01-23 17:32:25.333049879 -0600
+++ cef/libcef/common/main_delegate.h	2014-01-23 17:32:45.133045785 -0600
@@ -39,7 +39,7 @@
       const std::string& process_type,
       const content::MainFunctionParams& main_function_params) OVERRIDE;
   virtual void ProcessExiting(const std::string& process_type) OVERRIDE;
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
   virtual void ZygoteForked() OVERRIDE;
 #endif
   virtual content::ContentBrowserClient* CreateContentBrowserClient() OVERRIDE;
