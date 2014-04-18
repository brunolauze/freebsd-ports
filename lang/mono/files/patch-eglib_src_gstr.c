--- eglib/src/gstr.c.orig	2014-01-16 05:26:03.717147822 -0600
+++ eglib/src/gstr.c	2014-01-16 05:26:52.427127730 -0600
@@ -131,7 +131,7 @@
 	int n;
 	char *ret;
 	
-	n = vasprintf (&ret, format, args);
+	n = eglib_vasprintf (&ret, format, args);
 	if (n == -1)
 		return NULL;
 
@@ -146,7 +146,7 @@
 	int n;
 
 	va_start (args, format);
-	n = vasprintf (&ret, format, args);
+	n = eglib_vasprintf (&ret, format, args);
 	va_end (args);
 	if (n == -1)
 		return NULL;
