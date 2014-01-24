--- content/public/renderer/content_renderer_client.h.orig	2014-01-23 10:50:58.263626602 -0600
+++ content/public/renderer/content_renderer_client.h	2014-01-23 10:51:15.074212759 -0600
@@ -173,7 +173,6 @@
   // Returns true if a popup window should be allowed.
   virtual bool AllowPopup();
 
-#ifdef OS_ANDROID
   // TODO(sgurun) This callback is deprecated and will be removed as soon
   // as android webview completes implementation of a resource throttle based
   // shouldoverrideurl implementation. See crbug.com/325351
@@ -188,7 +187,6 @@
                                 blink::WebNavigationType type,
                                 blink::WebNavigationPolicy default_policy,
                                 bool is_redirect);
-#endif
 
   // Returns true if we should fork a new process for the given navigation.
   // If |send_referrer| is set to false (which is the default), no referrer
