--- cef/libcef/browser/browser_host_impl.cc.orig	2014-01-23 13:50:32.594123279 -0600
+++ cef/libcef/browser/browser_host_impl.cc	2014-01-23 14:53:11.293582157 -0600
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
@@ -715,8 +715,8 @@
 
 void CefBrowserHostImpl::SetZoomLevel(double zoomLevel) {
   if (CEF_CURRENTLY_ON_UIT()) {
-    if (web_contents_.get() && web_contents_->GetRenderViewHost())
-      web_contents_->GetRenderViewHost()->SetZoomLevel(zoomLevel);
+    if (web_contents_.get())
+      web_contents_->SetZoomLevel(zoomLevel);
   } else {
     CEF_POST_TASK(CEF_UIT,
         base::Bind(&CefBrowserHostImpl::SetZoomLevel, this, zoomLevel));
@@ -812,7 +812,7 @@
     options.forward = forward;
     options.matchCase = matchCase;
     options.findNext = findNext;
-    web_contents()->GetRenderViewHost()->Find(identifier, searchText, options);
+    web_contents()->Find(identifier, searchText, options);
   } else {
     CEF_POST_TASK(CEF_UIT,
         base::Bind(&CefBrowserHostImpl::Find, this, identifier, searchText,
@@ -828,7 +828,7 @@
     content::StopFindAction action = clearSelection ?
         content::STOP_FIND_ACTION_CLEAR_SELECTION :
         content::STOP_FIND_ACTION_KEEP_SELECTION;
-    web_contents()->GetRenderViewHost()->StopFinding(action);
+    web_contents()->StopFinding(action);
   } else {
     CEF_POST_TASK(CEF_UIT,
         base::Bind(&CefBrowserHostImpl::StopFinding, this, clearSelection));
