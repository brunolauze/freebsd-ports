--- bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx.orig	2013-10-15 10:32:21.051274382 -0500
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx	2013-10-15 10:34:49.973265163 -0500
@@ -23,6 +23,37 @@
 #include <exception>
 #include <cstddef>
 
+#include <cxxabi.h>
+#ifndef _GLIBCXX_CDTOR_CALLABI // new in GCC 4.7 cxxabi.h
+#define _GLIBCXX_CDTOR_CALLABI
+#endif
+
+#ifdef _LIBCPP_VERSION
+
+namespace __cxxabiv1
+{
+    struct __class_type_info : public std::type_info
+    {
+        explicit __class_type_info( const char *__n ) : type_info( __n ) { }
+        virtual ~__class_type_info();
+    };
+
+    struct __si_class_type_info : public __class_type_info
+    {
+        explicit __si_class_type_info( const char *__n, const __class_type_info *__b ) :
+            __class_type_info( __n ), __base_type( __b ) { }
+        virtual ~__si_class_type_info();
+        const __class_type_info *__base_type;
+    };
+
+extern "C" void *__cxa_allocate_exception( std::size_t thrown_size ) _NOEXCEPT;
+
+extern "C" _LIBCPP_NORETURN void __cxa_throw(
+    void *thrown_exception, std::type_info *tinfo, void (*dest) (void *) );
+}
+
+#else
+
 namespace CPPU_CURRENT_NAMESPACE
 {
 
@@ -82,6 +113,14 @@
     void *thrown_exception, void *tinfo, void (*dest) (void *) ) __attribute__((noreturn));
 #endif
 
+}
+
+#endif
+
+namespace CPPU_CURRENT_NAMESPACE
+{
+
+
 // -----
 
 //==================================================================================================
@@ -89,7 +128,11 @@
     uno_Any * pUnoExc, uno_Mapping * pUno2Cpp );
 //==================================================================================================
 void fillUnoException(
-    __cxa_exception * header, uno_Any *, uno_Mapping * pCpp2Uno );
+#ifdef _LIBCPP_VERSION
+    __cxxabiv1::__cxa_exception * header, uno_Any *, uno_Mapping * pCpp2Uno );
+#else
+     __cxa_exception * header, uno_Any *, uno_Mapping * pCpp2Uno );
+#endif
 }
 
 /* vim:set shiftwidth=4 softtabstop=4 expandtab: */
