--- src/racoon/evt.c.orig	2014-01-17 23:56:04.164049359 -0600
+++ src/racoon/evt.c	2014-01-17 23:59:02.864282987 -0600
@@ -97,8 +97,8 @@
 
 static void
 evt_push(src, dst, type, optdata)
-	struct sockaddr *src;
-	struct sockaddr *dst;
+	struct sockaddr_storage *src;
+	struct sockaddr_storage *dst;
 	int type;
 	vchar_t *optdata;
 {
