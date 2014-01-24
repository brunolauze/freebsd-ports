--- cef/libcef/browser/browser_context_proxy.h.orig	2014-01-23 15:10:56.633504044 -0600
+++ cef/libcef/browser/browser_context_proxy.h	2014-01-23 15:11:57.473230333 -0600
@@ -53,6 +53,15 @@
       int bridge_id,
       const GURL& requesting_frame,
       const MIDISysExPermissionCallback& callback) OVERRIDE;
+  virtual void RequestProtectedMediaIdentifierPermission(
+      int render_process_id,
+      int render_view_id,
+      int bridge_id,
+      int group_id,
+      const GURL& requesting_frame,
+      const ProtectedMediaIdentifierPermissionCallback& callback) OVERRIDE;
+  virtual void CancelProtectedMediaIdentifierPermissionRequests(
+      int group_id) OVERRIDE;
   virtual void CancelMIDISysExPermissionRequest(
       int render_process_id,
       int render_view_id,
