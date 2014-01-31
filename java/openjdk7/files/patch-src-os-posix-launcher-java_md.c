--- hotspot/src/os/posix/launcher/java_md.c.orig	2013-09-06 14:22:03.000000000 -0400
+++ hotspot/src/os/posix/launcher/java_md.c	2014-01-24 20:43:26.000000000 -0500
@@ -992,9 +992,13 @@
             }
         }
     }
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     {
+#ifdef __FreeBSD__
+        const char* self = "/proc/curproc/file";
+#else
         const char* self = "/proc/self/exe";
+#endif
         char buf[PATH_MAX+1];
         int len = readlink(self, buf, PATH_MAX);
         if (len >= 0) {
@@ -1002,7 +1006,7 @@
             exec_path = JLI_StringDup(buf);
         }
     }
-#else /* !__sun && !__linux */
+#else /* !__sun && !__linux__ && !__FreeBSD__ */
     {
         /* Not implemented */
     }
