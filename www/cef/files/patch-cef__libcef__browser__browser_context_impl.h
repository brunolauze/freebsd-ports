--- cef/libcef/browser/browser_context_impl.h.orig	2014-01-23 14:55:28.943418200 -0600
+++ cef/libcef/browser/browser_context_impl.h	2014-01-23 14:56:16.293583266 -0600
@@ -50,6 +50,15 @@
       int render_view_id,
       int bridge_id,
       const GURL& requesting_frame) OVERRIDE;
+  virtual void RequestProtectedMediaIdentifierPermission(
+      int render_process_id,
+      int render_view_id,
+      int bridge_id,
+      int group_id,
+      const GURL& requesting_frame,
+      const ProtectedMediaIdentifierPermissionCallback& callback) OVERRIDE;
+  virtual void CancelProtectedMediaIdentifierPermissionRequests(
+      int group_id) OVERRIDE;
   virtual content::ResourceContext* GetResourceContext() OVERRIDE;
   virtual content::GeolocationPermissionContext*
       GetGeolocationPermissionContext() OVERRIDE;
