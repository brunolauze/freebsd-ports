--- cef/libcef/browser/browser_context_proxy.cc.orig	2014-01-23 15:11:05.753889431 -0600
+++ cef/libcef/browser/browser_context_proxy.cc	2014-01-23 15:13:20.686561553 -0600
@@ -129,6 +129,21 @@
     const GURL& requesting_frame) {
 }
 
+void CefBrowserContextProxy::RequestProtectedMediaIdentifierPermission(
+    int render_process_id,
+    int render_view_id,
+    int bridge_id,
+    int group_id,
+    const GURL& requesting_frame,
+    const ProtectedMediaIdentifierPermissionCallback& callback) {
+  // TODO(CEF): Implement Protected Media Identifier API permission handling.
+  callback.Run(true);
+}
+
+void CefBrowserContextProxy::CancelProtectedMediaIdentifierPermissionRequests(
+    int group_id) {
+}
+
 content::ResourceContext* CefBrowserContextProxy::GetResourceContext() {
   return resource_context_.get();
 }
