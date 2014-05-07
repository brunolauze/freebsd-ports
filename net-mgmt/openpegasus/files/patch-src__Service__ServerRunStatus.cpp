--- src/Service/ServerRunStatus.cpp.orig	2014-02-26 06:22:51.344370520 -0600
+++ src/Service/ServerRunStatus.cpp	2014-02-28 21:24:27.084014105 -0600
@@ -62,6 +62,12 @@
 # endif
 #endif
 
+#if defined(PEGASUS_PLATFORM_FREEBSD_GENERIC_GNU)
+# include <sys/user.h>
+# include <libutil.h>
+#endif
+
+
 PEGASUS_NAMESPACE_BEGIN
 
 #ifdef PEGASUS_OS_TYPE_WINDOWS
@@ -207,6 +213,7 @@
 
 #if defined(PEGASUS_OS_HPUX) || \
     defined(PEGASUS_PLATFORM_LINUX_GENERIC_GNU) || \
+    defined(PEGASUS_PLATFORM_FREEBSD_GENERIC_GNU) || \
     defined(PEGASUS_OS_SOLARIS) || \
     defined(PEGASUS_OS_ZOS) || \
     defined(PEGASUS_OS_AIX) || defined(PEGASUS_OS_PASE)
@@ -460,6 +467,22 @@
     return false;
 }
 
+#elif defined(PEGASUS_PLATFORM_FREEBSD_GENERIC_GNU)
+Boolean ServerRunStatus::_isServerProcess(PEGASUS_PID_T pid)
+{
+    struct kinfo_proc *kp;
+
+    kp = kinfo_getproc(pid);
+
+    if (kp != NULL)
+    {
+	if (strcmp(kp->ki_comm, _serverName) == 0)
+	{
+	    return true;
+	}	
+    }
+    return false;
+}
 # else
 
 ///////////////////////////////////////////////////////
