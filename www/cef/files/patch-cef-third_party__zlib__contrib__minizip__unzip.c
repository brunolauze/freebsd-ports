--- third_party/zlib/contrib/minizip/unzip.c.orig	2014-01-23 10:15:54.403709764 -0600
+++ third_party/zlib/contrib/minizip/unzip.c	2014-01-23 10:16:10.473736036 -0600
@@ -68,10 +68,6 @@
 #include <stdlib.h>
 #include <string.h>
 
-#ifndef NOUNCRYPT
-        #define NOUNCRYPT
-#endif
-
 #include "third_party/zlib/zlib.h"
 #include "unzip.h"
 
