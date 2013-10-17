--- include/sal/log.hxx.orig	2013-10-15 10:48:39.364206347 -0500
+++ include/sal/log.hxx	2013-10-15 10:51:38.658417206 -0500
@@ -157,10 +157,13 @@
 
     @since LibreOffice 3.5
 */
+#ifdef _LIBCPP_VERSION
 #define SAL_STREAM(stream) \
-    (dynamic_cast< ::std::ostringstream & >(::std::ostringstream() << stream). \
-     str())
-
+    (::std::ostringstream() << stream).str()
+#else
+#define SAL_STREAM(stream) \
+    (dynamic_cast< ::std::ostringstream & >(::std::ostringstream() << stream).str())
+#endif
 /**
     @page sal_log Basic logging functionality.
 
