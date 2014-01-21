--- bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx.orig	2014-01-20 00:56:33.607572988 -0600
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx	2014-01-20 01:00:25.020536167 -0600
@@ -85,9 +85,12 @@
 // additional problem of an incompletely declared return type:
 
 #if !HAVE_GCC_CXXABI_H_CXA_GET_GLOBALS
+#if defined(__FreeBSD__)
+/*namespace __cxxabiv1 { extern "C" void * __cxa_get_globals() throw(); } */
+#else
 namespace __cxxabiv1 { extern "C" void * __cxa_get_globals() throw(); }
 #endif
-
+#endif
 #if !HAVE_GCC_CXXABI_H_CXA_ALLOCATE_EXCEPTION
 namespace __cxxabiv1 {
 extern "C" void * __cxa_allocate_exception(std::size_t thrown_size) throw();
