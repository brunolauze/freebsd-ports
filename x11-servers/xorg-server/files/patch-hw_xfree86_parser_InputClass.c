--- hw/xfree86/parser/InputClass.c.orig	2013-10-09 20:08:12.038482654 -0500
+++ hw/xfree86/parser/InputClass.c	2013-10-09 20:08:51.968474312 -0500
@@ -362,7 +362,8 @@
     XF86ConfInputClassPtr prev;
 
     while (ptr) {
-        xf86MatchGroup *group, *next;
+        xf86MatchGroup *group = NULL;
+	xf86MatchGroup *next;
         char **list;
 
         TestFree(ptr->identifier);
