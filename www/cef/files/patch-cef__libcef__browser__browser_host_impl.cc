--- cef/libcef/browser/browser_host_impl.cc.orig	2014-01-23 13:50:32.594123279 -0600
+++ cef/libcef/browser/browser_host_impl.cc	2014-01-23 13:52:46.063366109 -0600
@@ -54,7 +54,7 @@
 #include "third_party/WebKit/public/web/WebFindOptions.h"
 #include "ui/shell_dialogs/selected_file_info.h"
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_ANDROID)
 #include "ui/gfx/font_render_params_linux.h"
 #endif
 
@@ -426,7 +426,7 @@
     return NULL;
   }
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_ANDROID)
   content::RendererPreferences* prefs = web_contents->GetMutableRendererPrefs();
   const gfx::FontRenderParams& params = gfx::GetDefaultWebKitFontRenderParams();
   prefs->should_antialias_text = params.antialiasing;
@@ -480,7 +480,7 @@
       break;
   }
   web_contents->GetRenderViewHost()->SyncRendererPrefs();
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_BSD) || defined(OS_ANDROID)
 
   if (client.get()) {
     CefRefPtr<CefLifeSpanHandler> handler = client->GetLifeSpanHandler();
