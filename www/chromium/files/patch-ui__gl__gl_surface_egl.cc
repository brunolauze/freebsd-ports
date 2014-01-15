--- ui/gl/gl_surface_egl.cc.orig	2014-01-14 08:03:09.166038645 -0600
+++ ui/gl/gl_surface_egl.cc	2014-01-14 08:08:35.154332722 -0600
@@ -289,7 +289,7 @@
     // Get a config compatible with the window
     DCHECK(window_);
     XWindowAttributes win_attribs;
-    if (!XGetWindowAttributes(GetNativeDisplay(), window_, &win_attribs)) {
+    if (!XGetWindowAttributes(reinterpret_cast<Display>(GetNativeDisplay()), window_, &win_attribs)) {
       return NULL;
     }
 
