--- src/racoon/isakmp.c.orig	2014-01-17 23:44:46.344156200 -0600
+++ src/racoon/isakmp.c	2014-01-17 23:48:00.550186077 -0600
@@ -181,7 +181,7 @@
 static int ph1_main __P((struct ph1handle *, vchar_t *));
 static int quick_main __P((struct ph2handle *, vchar_t *));
 static int isakmp_ph1begin_r __P((vchar_t *,
-	struct sockaddr *, struct sockaddr *, u_int8_t));
+	struct sockaddr *, struct sockaddr *, int));
 static int isakmp_ph2begin_i __P((struct ph1handle *, struct ph2handle *));
 static int isakmp_ph2begin_r __P((struct ph1handle *, vchar_t *));
 static int etypesw1 __P((int));
@@ -1131,7 +1131,7 @@
 isakmp_ph1begin_r(msg, remote, local, etype)
 	vchar_t *msg;
 	struct sockaddr *remote, *local;
-	u_int8_t etype;
+	int etype;
 {
 	struct isakmp *isakmp = (struct isakmp *)msg->v;
 	struct ph1handle *iph1;
@@ -2141,7 +2141,7 @@
 	return;
 }
 
-/* %%%
+/* %%%
  * Interface between PF_KEYv2 and ISAKMP
  */
 /*
@@ -3696,3 +3696,4 @@
 	return 0;
 }
 #endif
+
