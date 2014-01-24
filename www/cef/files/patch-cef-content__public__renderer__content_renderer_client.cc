--- content/public/renderer/content_renderer_client.cc.org	2014-01-23 10:48:41.313623441 -0600
+++ content/public/renderer/content_renderer_client.cc	2014-01-23 10:49:10.924194457 -0600
@@ -92,7 +92,6 @@
   return false;
 }
 
-#ifdef OS_ANDROID
 bool ContentRendererClient::HandleNavigation(
     RenderFrame* render_frame,
     DocumentState* document_state,
@@ -104,7 +103,6 @@
     bool is_redirect) {
   return false;
 }
-#endif
 
 bool ContentRendererClient::ShouldFork(blink::WebFrame* frame,
                                        const GURL& url,
