--- content/renderer/render_process_impl.cc.orig	2014-01-13 09:00:33.000000000 -0600
+++ content/renderer/render_process_impl.cc	2014-01-14 22:31:46.835129415 -0600
@@ -149,7 +149,7 @@
   int width = rect.width();
   int height = rect.height();
   const size_t stride = skia::PlatformCanvasStrideForWidth(rect.width());
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const size_t max_size = base::SysInfo::MaxSharedMemorySize();
 #else
   const size_t max_size = 0;
