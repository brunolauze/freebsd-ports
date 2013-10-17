--- qtbase/config.tests/unix/gstreamer/gstreamer.cpp.orig	2013-10-13 21:10:16.161544653 -0500
+++ qtbase/config.tests/unix/gstreamer/gstreamer.cpp	2013-10-13 21:10:42.313727928 -0500
@@ -40,15 +40,6 @@
 ****************************************************************************/
 
 #include <gst/gst.h>
-#include <gst/interfaces/propertyprobe.h>
-#include <gst/interfaces/xoverlay.h>
-
-#if !defined(GST_VERSION_MAJOR) \
-    || !defined(GST_VERSION_MINOR)
-#  error "No GST_VERSION_* macros"
-#elif GST_VERION_MAJOR != 0 && GST_VERSION_MINOR != 10
-#  error "Incompatible version of GStreamer found (Version 0.10.x is required)."
-#endif
 
 int main(int argc, char **argv)
 {
