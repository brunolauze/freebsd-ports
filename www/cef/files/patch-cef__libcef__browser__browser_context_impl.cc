--- cef/libcef/browser/browser_context_impl.cc.orig	2014-01-23 14:57:01.123608359 -0600
+++ cef/libcef/browser/browser_context_impl.cc	2014-01-23 14:59:03.663802561 -0600
@@ -267,6 +267,21 @@
     const GURL& requesting_frame) {
 }
 
+void CefBrowserContextImpl::RequestProtectedMediaIdentifierPermission(
+    int render_process_id,
+    int render_view_id,
+    int bridge_id,
+    int group_id,
+    const GURL& requesting_frame,
+    const ProtectedMediaIdentifierPermissionCallback& callback) {
+  // Always accept requests for the moment. TODO(CEF): Implement Permission Request dialog
+  callback.Run(true);
+}
+
+void CefBrowserContextImpl::CancelProtectedMediaIdentifierPermissionRequests(
+    int group_id) {
+}
+
 content::ResourceContext* CefBrowserContextImpl::GetResourceContext() {
   return resource_context_.get();
 }
