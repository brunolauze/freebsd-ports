--- test/list.c.orig	2013-10-09 20:00:38.810514310 -0500
+++ test/list.c	2013-10-09 20:01:08.315667649 -0500
@@ -68,7 +68,7 @@
 {
     struct parent parent = { 0 };
     struct child child[3];
-    struct child *c;
+    struct child *c = NULL;
 
     xorg_list_init(&parent.children);
 
@@ -96,7 +96,7 @@
 {
     struct parent parent = { 0 };
     struct child child[3];
-    struct child *c;
+    struct child *c = NULL;
     int i;
 
     xorg_list_init(&parent.children);
@@ -138,7 +138,7 @@
 {
     struct parent parent = { 0 };
     struct child child[2];
-    struct child *c;
+    struct child *c = NULL;
 
     xorg_list_init(&parent.children);
 
@@ -187,7 +187,7 @@
 {
     struct parent parent = { 0 };
     struct child child[3];
-    struct child *c;
+    struct child *c = NULL;
     int i = 0;
 
     xorg_list_init(&parent.children);
