--- src/racoon/gssapi.h.orig	2014-01-17 23:50:46.424229206 -0600
+++ src/racoon/gssapi.h	2014-01-17 23:51:00.377684045 -0600
@@ -34,11 +34,7 @@
  * POSSIBILITY OF SUCH DAMAGE.
  */
 
-#ifdef __FreeBSD__
-#include "/usr/include/gssapi.h"
-#else
 #include <gssapi/gssapi.h>
-#endif
 
 #define GSSAPI_DEF_NAME         "host"
 
