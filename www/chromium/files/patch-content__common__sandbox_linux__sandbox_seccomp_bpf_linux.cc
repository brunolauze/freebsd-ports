--- content/common/sandbox_linux/sandbox_seccomp_bpf_linux.cc.orig	2014-01-19 21:28:59.209464575 -0600
+++ content/common/sandbox_linux/sandbox_seccomp_bpf_linux.cc	2014-01-19 21:30:47.749777126 -0600
@@ -42,7 +42,7 @@
 
 // Make sure that seccomp-bpf does not get disabled by mistake. Also make sure
 // that we think twice about this when adding a new architecture.
-#if !defined(ARCH_CPU_MIPS_FAMILY)
+#if !defined(ARCH_CPU_MIPS_FAMILY) && !defined(__FreeBSD__)
 #error "Seccomp-bpf disabled on supported architecture!"
 #endif  // !defined(ARCH_CPU_MIPS_FAMILY)
 
