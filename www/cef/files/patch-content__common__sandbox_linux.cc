--- content/common/sandbox_linux/sandbox_linux.cc.orig	2014-01-23 17:54:29.783057998 -0600
+++ content/common/sandbox_linux/sandbox_linux.cc	2014-01-23 17:58:20.113024263 -0600
@@ -244,10 +244,6 @@
   if (!pre_initialized_)
     PreinitializeSandbox();
 
-  DCHECK(!HasOpenDirectories()) <<
-      "InitializeSandbox() called after unexpected directories have been " <<
-      "opened. This breaks the security of the setuid sandbox.";
-
   // Attempt to limit the future size of the address space of the process.
   LimitAddressSpace(process_type);
 
@@ -303,9 +299,11 @@
 #endif  // !defined(ADDRESS_SANITIZER)
 }
 
+#if defined(OS_LINUX)
 bool LinuxSandbox::HasOpenDirectories() {
   return sandbox::Credentials().HasOpenDirectory(proc_fd_);
 }
+#endif
 
 void LinuxSandbox::SealSandbox() {
   if (proc_fd_ >= 0) {
