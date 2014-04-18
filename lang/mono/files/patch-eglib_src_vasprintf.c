--- eglib/src/vasprintf.c.orig	2014-01-16 05:23:44.597122329 -0600
+++ eglib/src/vasprintf.c	2014-01-16 05:23:54.892632120 -0600
@@ -2,7 +2,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 
-int vasprintf(char **ret, const char *fmt, va_list ap)
+int eglib_vasprintf(char **ret, const char *fmt, va_list ap)
 {
 	char *buf;
 	int len;
