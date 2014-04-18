--- bridges/source/cpp_uno/gcc3_linux_x86-64/uno2cpp.cxx.orig	2013-12-24 12:19:12.919113849 -0600
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/uno2cpp.cxx	2013-12-24 12:19:48.720589745 -0600
@@ -289,11 +289,12 @@
     }
      catch (...)
      {
-         // fill uno exception
-         fillUnoException(
-             reinterpret_cast< CPPU_CURRENT_NAMESPACE::__cxa_eh_globals * >(
-                 __cxxabiv1::__cxa_get_globals())->caughtExceptions,
-             *ppUnoExc, pThis->getBridge()->getCpp2Uno());
+
+        #ifdef _LIBCPP_VERSION
+         CPPU_CURRENT_NAMESPACE::fillUnoException( __cxxabiv1::__cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
+        #else
+          fillUnoException( __cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
+        #endif
 
         // temporary params
         for ( ; nTempIndices--; )
