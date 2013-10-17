--- include/vlc_common.h.orig	2013-10-15 14:42:23.383239549 -0500
+++ include/vlc_common.h	2013-10-15 14:42:49.972240846 -0500
@@ -568,7 +568,7 @@
 #endif
 }
 
-#ifdef __OS2__
+#if defined(__OS2__) || defined(__FreeBSD__)
 #   undef bswap16
 #   undef bswap32
 #   undef bswap64
