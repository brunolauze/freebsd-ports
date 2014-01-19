--- cmake/modules/PopplerMacros.cmake.orig	2014-01-18 18:23:21.753793280 -0600
+++ cmake/modules/PopplerMacros.cmake	2014-01-18 18:23:49.876678213 -0600
@@ -101,8 +101,8 @@
 if(CMAKE_COMPILER_IS_GNUCXX)
   # set the default compile warnings
   set(DEFAULT_COMPILE_WARNINGS_NO)
-  set(DEFAULT_COMPILE_WARNINGS_YES "-Wall -Wcast-align -fno-exceptions -fno-check-new -fno-common")
-  set(DEFAULT_COMPILE_WARNINGS_KDE "-Wno-long-long -Wundef -D_XOPEN_SOURCE=600 -D_BSD_SOURCE -Wcast-align -Wconversion -Wall -W -Wpointer-arith -Wwrite-strings -Wformat-security -Wmissing-format-attribute -fno-exceptions -fno-check-new -fno-common")
+  set(DEFAULT_COMPILE_WARNINGS_YES "-Wall -Wcast-align -fno-exceptions -fno-common")
+  set(DEFAULT_COMPILE_WARNINGS_KDE "-Wno-long-long -Wundef -D_XOPEN_SOURCE=600 -D_BSD_SOURCE -Wcast-align -Wconversion -Wall -W -Wpointer-arith -Wwrite-strings -Wformat-security -Wmissing-format-attribute -fno-exceptions -fno-common")
 
   set(CMAKE_CXX_FLAGS                "-Wnon-virtual-dtor -Woverloaded-virtual ${CMAKE_CXX_FLAGS}")
   set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
