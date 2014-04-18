--- eglib/src/gerror.c.orig	2014-01-16 05:26:17.587270731 -0600
+++ eglib/src/gerror.c	2014-01-16 05:26:35.826482522 -0600
@@ -40,7 +40,7 @@
 	err->code = code;
 
 	va_start (args, format);
-	if (vasprintf (&err->message, format, args) == -1)
+	if (eglib_vasprintf (&err->message, format, args) == -1)
 		err->message = g_strdup_printf ("internal: invalid format string %s", format); 
 	va_end (args);
 
@@ -55,7 +55,7 @@
 	err->domain = domain;
 	err->code = code;
 
-	if (vasprintf (&err->message, format, ap) == -1)
+	if (eglib_vasprintf (&err->message, format, ap) == -1)
 		err->message = g_strdup_printf ("internal: invalid format string %s", format); 
 
 	return err;
