--- src/Executor/Process.c.orig	2008-12-02 03:00:13.000000000 -0600
+++ src/Executor/Process.c	2014-04-23 14:02:28.380508256 -0500
@@ -38,6 +38,11 @@
 # include <sys/pstat.h>
 #endif
 
+#if defined(PEGASUS_OS_FREEBSD)
+# include <sys/user.h>
+# include <libutil.h>
+#endif
+
 /*
 **==============================================================================
 **
@@ -60,6 +65,18 @@
     return 0;
 }
 
+#elif defined(PEGASUS_OS_FREEBSD)
+
+int GetProcessName(int pid, char name[EXECUTOR_BUFFER_SIZE])
+{
+    struct kinfo_proc *pr = kinfo_getproc(pid);
+    if (pr == NULL) return -1;
+
+    Strlcpy(name, pr->ki_comm, EXECUTOR_BUFFER_SIZE);
+
+    return 0;
+}
+
 #elif defined(PEGASUS_PLATFORM_LINUX_GENERIC_GNU)
 
 int GetProcessName(int pid, char name[EXECUTOR_BUFFER_SIZE])
