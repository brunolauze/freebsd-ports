--- modules/ts/include/opencv2/ts/ts_gtest.h.orig	2013-10-07 21:53:06.132828166 -0500
+++ modules/ts/include/opencv2/ts/ts_gtest.h	2013-10-07 21:59:26.029801498 -0500
@@ -54,6 +54,7 @@
 #include <limits>
 #include <ostream>
 #include <vector>
+#include <unistd.h>
 
 // Copyright 2005, Google Inc.
 // All rights reserved.
@@ -723,6 +724,7 @@
 
 // Implements a subset of TR1 tuple needed by Google Test and Google Mock.
 
+#define GTEST_INCLUDE_GTEST_INTERNAL_GTEST_TUPLE_H_ 1
 #ifndef GTEST_INCLUDE_GTEST_INTERNAL_GTEST_TUPLE_H_
 #define GTEST_INCLUDE_GTEST_INTERNAL_GTEST_TUPLE_H_
 
@@ -1741,17 +1743,53 @@
 // <tr1/functional>.  Hence the following #define is a hack to prevent
 // <tr1/functional> from being included.
 #   define _TR1_FUNCTIONAL 1
-#   include <tr1/tuple>
+#ifdef __clang__
+#if __has_include(<tuple>)
+#include <tuple>
+namespace gtest {
+       using ::std::tuple;
+}
+#endif
+#else
+ #include <tr1/tuple>
+namespace gtest {
+       using ::std::tr1::tuple;
+}
+#endif
 #   undef _TR1_FUNCTIONAL  // Allows the user to #include
                         // <tr1/functional> if he chooses to.
 #  else
-#   include <tr1/tuple>  // NOLINT
+#if defined(__clang__)
+#if __has_include(<tuple>)
+#include <tuple>
+namespace gtest {
+       using ::std::tuple;
+}
+#endif
+#else
+#include <tr1/tuple>
+namespace gtest {
+       using ::std::tr1::tuple;
+}
+#endif
 #  endif  // !GTEST_HAS_RTTI && GTEST_GCC_VER_ < 40302
 
 # else
 // If the compiler is not GCC 4.0+, we assume the user is using a
 // spec-conforming TR1 implementation.
-#  include <tuple>  // NOLINT
+#if defined(__clang__)
+#if __has_include(<tuple>)
+#include <tuple>
+namespace gtest {
+       using ::std::tuple;
+}
+#endif
+#else
+#include <tr1/tuple>
+namespace gtest {
+       using ::std::tr1::tuple;
+}
+#endif
 # endif  // GTEST_USE_OWN_TR1_TUPLE
 
 #endif  // GTEST_HAS_TR1_TUPLE
