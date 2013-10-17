--- bridges/source/cpp_uno/gcc3_linux_x86-64/except.cxx.orig	2013-10-15 10:37:01.843256757 -0500
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/except.cxx	2013-10-15 10:38:41.909390861 -0500
@@ -22,10 +22,6 @@
 #include <string.h>
 #include <dlfcn.h>
 
-#include <cxxabi.h>
-#ifndef _GLIBCXX_CDTOR_CALLABI // new in GCC 4.7 cxxabi.h
-#define _GLIBCXX_CDTOR_CALLABI
-#endif
 
 #include <boost/unordered_map.hpp>
 
@@ -254,8 +250,11 @@
             *reinterpret_cast< OUString const * >( &pUnoExc->pType->pTypeName ),
             Reference< XInterface >() );
     }
-
+    #ifdef _LIBCPP_VERSION
+    pCppExc = __cxxabiv1::__cxa_allocate_exception( pTypeDescr->nSize );
+    #else
     pCppExc = __cxa_allocate_exception( pTypeDescr->nSize );
+    #endif
     ::uno_copyAndConvertData( pCppExc, pUnoExc->pData, pTypeDescr, pUno2Cpp );
 
     // destruct uno exception
@@ -273,8 +272,11 @@
             Reference< XInterface >() );
     }
     }
-
+    #ifdef _LIBCPP_VERSION
+    __cxxabiv1::__cxa_throw( pCppExc, rtti, deleteException );
+    #else
     __cxa_throw( pCppExc, rtti, deleteException );
+    #endif
 }
 
 //==================================================================================================
