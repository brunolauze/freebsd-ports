--- content/browser/frame_host/render_widget_host_view_guest.cc.orig	2014-01-19 21:35:31.439446959 -0600
+++ content/browser/frame_host/render_widget_host_view_guest.cc	2014-01-19 21:36:50.019887461 -0600
@@ -240,7 +240,7 @@
 gfx::NativeViewId RenderWidgetHostViewGuest::GetNativeViewId() const {
   if (guest_->GetEmbedderRenderWidgetHostView())
     return guest_->GetEmbedderRenderWidgetHostView()->GetNativeViewId();
-  return static_cast<gfx::NativeViewId>(NULL);
+  return reinterpret_cast<gfx::NativeViewId>(NULL);
 }
 
 gfx::NativeViewAccessible RenderWidgetHostViewGuest::GetNativeViewAccessible() {
