--- gdk/broadway/broadway-server.c.orig	2013-11-23 17:40:13.948080996 -0600
+++ gdk/broadway/broadway-server.c	2013-11-23 17:41:14.328111372 -0600
@@ -18,7 +18,6 @@
 #elif defined (G_OS_WIN32)
 #include <io.h>
 #endif
-#include <crypt.h>
 #ifdef HAVE_SYS_MMAN_H
 #include <sys/mman.h>
 #endif
