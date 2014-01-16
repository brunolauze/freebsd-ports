--- eglib/src/glib.h.orig	2014-01-16 06:34:34.903531341 -0600
+++ eglib/src/glib.h	2014-01-16 06:35:39.062717322 -0600
@@ -49,9 +49,9 @@
 
 G_BEGIN_DECLS
 
-#ifdef G_OS_WIN32
+#if defined(G_OS_WIN32) || defined(__FreeBSD__)
 /* MSC and Cross-compilatin will use this */
-int vasprintf (char **strp, const char *fmt, va_list ap);
+int eglib_vasprintf (char **strp, const char *fmt, va_list ap);
 #endif
 
 
@@ -250,7 +250,7 @@
 #define g_vfprintf vfprintf
 #define g_vsprintf vsprintf
 #define g_vsnprintf vsnprintf
-#define g_vasprintf vasprintf
+#define g_vasprintf eglib_vasprintf
 
 gsize   g_strlcpy            (gchar *dest, const gchar *src, gsize dest_size);
 gchar  *g_stpcpy             (gchar *dest, const char *src);
