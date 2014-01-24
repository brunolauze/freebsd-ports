--- cef/tests/cefclient/osrenderer.cpp.orig	2014-01-23 13:58:10.074184640 -0600
+++ cef/tests/cefclient/osrenderer.cpp	2014-01-23 13:58:36.533486840 -0600
@@ -9,7 +9,7 @@
 #include <gl/glu.h>
 #elif defined(OS_MACOSX)
 #include <OpenGL/gl.h>
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include <GL/gl.h>
 #include <GL/glu.h>
 #else
