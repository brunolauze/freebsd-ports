--- src/mapi/glapi/gen/gl_gentable.py.orig	2013-10-07 13:31:19.349787378 -0500
+++ src/mapi/glapi/gen/gl_gentable.py	2013-10-07 13:31:51.358931991 -0500
@@ -42,7 +42,7 @@
 #endif
 
 #if (defined(GLXEXT) && defined(HAVE_BACKTRACE)) \\
-	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(_WIN32_WCE) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__))
+	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(_WIN32_WCE) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__) && !defined(__FreeBSD__))
 #define USE_BACKTRACE
 #endif
 
