--- dix/events.c.orig	2013-10-09 19:53:51.152534783 -0500
+++ dix/events.c	2013-10-09 19:54:27.786532906 -0500
@@ -1171,7 +1171,7 @@
 PlayReleasedEvents(void)
 {
     QdEventPtr tmp;
-    QdEventPtr qe;
+    QdEventPtr qe = NULL;
     DeviceIntPtr dev;
     DeviceIntPtr pDev;
 
@@ -5269,7 +5269,8 @@
 InitEvents(void)
 {
     int i;
-    QdEventPtr qe, tmp;
+    QdEventPtr qe = NULL;
+    QdEventPtr tmp;
 
     inputInfo.numDevices = 0;
     inputInfo.devices = (DeviceIntPtr) NULL;
