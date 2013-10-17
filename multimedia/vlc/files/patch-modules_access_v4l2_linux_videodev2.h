--- modules/access/v4l2/linux/videodev2.h.orig	2013-10-15 14:21:59.720323557 -0500
+++ modules/access/v4l2/linux/videodev2.h	2013-10-15 14:24:50.189385758 -0500
@@ -57,11 +57,44 @@
 #define _UAPI__LINUX_VIDEODEV2_H
 
 #include <sys/time.h>
-#include <linux/ioctl.h>
-#include <linux/types.h>
+#include <sys/types.h>
+#include <sys/ioctl.h>
 #include <linux/v4l2-common.h>
 #include <linux/v4l2-controls.h>
 
+
+#ifndef HAVE_LINUX_INTEGER_TYPES
+/* XXX remove when depending software has been updated */
+#ifndef __u64
+typedef uint64_t __u64;
+#endif
+#ifndef __u32
+typedef uint32_t __u32;
+#endif
+#ifndef __u16
+typedef uint16_t __u16;
+#endif
+#ifndef __u8
+typedef uint8_t __u8;
+#endif
+
+#ifndef __s64
+typedef int64_t __s64;
+#endif
+#ifndef __s32
+typedef int32_t __s32;
+#endif
+#ifndef __s16
+typedef int16_t __s16;
+#endif
+#ifndef __s8
+typedef int8_t __s8;
+#endif
+#ifndef __le32
+typedef __u32 __le32;
+#endif
+#endif
+
 /*
  * Common stuff for both V4L1 and V4L2
  * Moved from videodev.h
