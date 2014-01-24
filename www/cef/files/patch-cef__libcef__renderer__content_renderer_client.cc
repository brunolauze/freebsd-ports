--- cef/libcef/renderer/content_renderer_client.cc.orig	2014-01-23 14:21:02.423619630 -0600
+++ cef/libcef/renderer/content_renderer_client.cc	2014-01-23 14:22:50.253575808 -0600
@@ -517,7 +517,7 @@
 }
 
 bool CefContentRendererClient::HandleNavigation(
-    content::RenderView* view,
+    content::RenderFrame* render_frame,
     content::DocumentState* document_state,
     int opener_id,
     blink::WebFrame* frame,
