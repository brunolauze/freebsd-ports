--- jdk/src/solaris/bin/java_md_solinux.c
+++ jdk/src/solaris/bin/java_md_solinux.c
@@ -927,9 +927,13 @@
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
@@ -937,7 +941,7 @@
             exec_path = JLI_StringDup(buf);
         }
     }
-#else /* !__solaris__ && !__linux__ */
+#else /* !__solaris__ && !__linux__ && !__FreeBSD__ */
     {
         /* Not implemented */
     }
