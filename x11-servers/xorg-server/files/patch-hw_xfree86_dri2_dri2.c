--- hw/xfree86/dri2/dri2.c.orig	2013-10-09 19:57:23.226521376 -0500
+++ hw/xfree86/dri2/dri2.c	2013-10-09 19:58:59.045952270 -0500
@@ -277,7 +277,7 @@
 static DRI2DrawableRefPtr
 DRI2LookupDrawableRef(DRI2DrawablePtr pPriv, XID id)
 {
-    DRI2DrawableRefPtr ref;
+    DRI2DrawableRefPtr ref = NULL;
 
     xorg_list_for_each_entry(ref, &pPriv->reference_list, link) {
         if (ref->id == id)
@@ -357,7 +357,8 @@
 DRI2DrawableGone(pointer p, XID id)
 {
     DRI2DrawablePtr pPriv = p;
-    DRI2DrawableRefPtr ref, next;
+    DRI2DrawableRefPtr ref = NULL;
+    DRI2DrawableRefPtr next;
     WindowPtr pWin;
     PixmapPtr pPixmap;
     DrawablePtr pDraw;
