--- eglib/src/goutput.c.orig	2014-01-16 05:28:25.697410500 -0600
+++ eglib/src/goutput.c	2014-01-16 05:28:36.976525082 -0600
@@ -145,7 +145,7 @@
 #else
 	char *msg;
 	
-	if (vasprintf (&msg, format, args) < 0)
+	if (eglib_vasprintf (&msg, format, args) < 0)
 		return;
 
 #ifdef G_OS_WIN32
