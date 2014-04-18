--- connectivity/source/inc/dbase/dindexnode.hxx.orig	2013-10-11 13:22:47.100129006 -0500
+++ connectivity/source/inc/dbase/dindexnode.hxx	2013-10-11 13:23:22.461127143 -0500
@@ -26,7 +26,13 @@
 #include <tools/ref.hxx>
 
 #define NODE_NOTFOUND 0xFFFF
-#define DINDEX_PAGE_SIZE 512
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#else
+ #define PAGE_SIZE 512
+#endif
+
+#define DINDEX_PAGE_SIZE PAGE_SIZE
 
 namespace connectivity
 {
