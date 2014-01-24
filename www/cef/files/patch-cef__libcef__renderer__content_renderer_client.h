--- cef/libcef/renderer/content_renderer_client.h.orig	2014-01-23 14:20:24.433345192 -0600
+++ cef/libcef/renderer/content_renderer_client.h	2014-01-23 14:22:33.333564132 -0600
@@ -82,7 +82,7 @@
       blink::WebFrame* frame,
       const blink::WebPluginParams& params,
       blink::WebPlugin** plugin) OVERRIDE;
-  virtual bool HandleNavigation(content::RenderView* view,
+  virtual bool HandleNavigation(content::RenderFrame* render_frame,
                                 content::DocumentState* document_state,
                                 int opener_id,
                                 blink::WebFrame* frame,
