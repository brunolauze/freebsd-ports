--- src/network/udp.c.orig	2013-10-15 13:17:27.099592863 -0500
+++ src/network/udp.c	2013-10-15 13:17:49.294592485 -0500
@@ -379,7 +379,7 @@
 {
 /* MCAST_JOIN_GROUP was introduced to OS X in v10.7, but it doesn't work,
  * so ignore it to use the same code as on 10.5 or 10.6 */
-#if defined (MCAST_JOIN_GROUP) && !defined (__APPLE__)
+#if defined (MCAST_JOIN_GROUP) && !defined (__APPLE__) && !defined (__FreeBSD__)
     /* Agnostic SSM multicast join */
     int level;
     struct group_req gr;
