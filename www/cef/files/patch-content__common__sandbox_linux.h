--- content/common/sandbox_linux/sandbox_linux.h.orig	2014-01-23 17:55:23.143042518 -0600
+++ content/common/sandbox_linux/sandbox_linux.h	2014-01-23 17:55:54.293438345 -0600
@@ -86,7 +86,9 @@
   // Returns true if it can be determined that the current process has open
   // directories that are not managed by the LinuxSandbox class. This would
   // be a vulnerability as it would allow to bypass the setuid sandbox.
+#if defined(OS_LINUX)
   bool HasOpenDirectories();
+#endif
   // The last part of the initialization is to make sure any temporary "hole"
   // in the sandbox is closed. For now, this consists of closing proc_fd_.
   void SealSandbox();
