--- src/glsl/ir_constant_expression.cpp.orig	2013-10-07 13:05:40.203896803 -0500
+++ src/glsl/ir_constant_expression.cpp	2013-10-07 13:06:05.040191535 -0500
@@ -40,6 +40,13 @@
 #include "glsl_types.h"
 #include "program/hash_table.h"
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2(x) (log(x) / log(2))
+#endif
+
+
+
 static float
 dot(ir_constant *op0, ir_constant *op1)
 {
