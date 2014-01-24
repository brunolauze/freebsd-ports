--- content/renderer/render_view_impl.cc.orig	2014-01-23 10:52:31.103907421 -0600
+++ content/renderer/render_view_impl.cc	2014-01-23 10:55:45.783660312 -0600
@@ -3143,7 +3143,7 @@
     WebDataSource::ExtraData* extraData, const WebURLRequest& request,
     WebNavigationType type, WebNavigationPolicy default_policy,
     bool is_redirect) {
-#ifdef OS_ANDROID
+
   // The handlenavigation API is deprecated and will be removed once
   // crbug.com/325351 is resolved.
   if (request.url() != GURL(kSwappedOutURL) &&
@@ -3158,7 +3158,6 @@
           is_redirect)) {
     return blink::WebNavigationPolicyIgnore;
   }
-#endif
 
   Referrer referrer(GetReferrerFromRequest(frame, request));
 
