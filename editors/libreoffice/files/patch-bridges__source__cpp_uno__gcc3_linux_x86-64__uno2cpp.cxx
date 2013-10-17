--- bridges/source/cpp_uno/gcc3_linux_x86-64/uno2cpp.cxx.orig	2013-10-15 10:12:53.959354972 -0500
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/uno2cpp.cxx	2013-10-15 10:13:54.579352510 -0500
@@ -290,7 +290,11 @@
      catch (...)
      {
           // fill uno exception
+	#ifdef _LIBCPP_VERSION
+        CPPU_CURRENT_NAMESPACE::fillUnoException( __cxxabiv1::__cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
+	#else
         fillUnoException( __cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
+	#endif
 
         // temporary params
         for ( ; nTempIndizes--; )
