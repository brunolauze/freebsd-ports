--- hotspot/make/bsd/makefiles/gcc.make.orig	2013-09-06 13:22:00.000000000 -0500
+++ hotspot/make/bsd/makefiles/gcc.make	2014-01-31 11:01:43.339432688 -0600
@@ -32,13 +32,13 @@
   # When cross-compiling the ALT_COMPILER_PATH points
   # to the cross-compilation toolset
   ifdef CROSS_COMPILE_ARCH
-    CXX = $(ALT_COMPILER_PATH)/g++
-    CC  = $(ALT_COMPILER_PATH)/gcc
-    HOSTCXX = g++
-    HOSTCC  = gcc
+    CXX = $(ALT_COMPILER_PATH)/c++
+    CC  = $(ALT_COMPILER_PATH)/cc
+    HOSTCXX = c++
+    HOSTCC  = cc
   else ifneq ($(OS_VENDOR), Darwin)
-    CXX = g++
-    CC  = gcc
+    CXX = c++
+    CC  = cc
     HOSTCXX = $(CXX)
     HOSTCC  = $(CC)
   endif
@@ -116,7 +116,10 @@
 CFLAGS += -fno-rtti
 CFLAGS += -fno-exceptions
 CFLAGS += -pthread
+# Clang does not support -fcheck-new.
+ifeq (,$(findstring clang,$(shell $(CC) -v 2>&1)))
 CFLAGS += -fcheck-new
+endif
 # version 4 and above support fvisibility=hidden (matches jni_x86.h file)
 # except 4.1.2 gives pointless warnings that can't be disabled (afaik)
 ifneq "$(shell expr \( $(CC_VER_MAJOR) \> 4 \) \| \( \( $(CC_VER_MAJOR) = 4 \) \& \( $(CC_VER_MINOR) \>= 3 \) \))" "0"
@@ -187,7 +190,7 @@
 endif
 
 
-# The flags to use for an Optimized g++ build
+# The flags to use for an Optimized c++ build
 ifeq ($(OS_VENDOR), Darwin)
   # use -Os by default, unless -O3 can be proved to be worth the cost, as per policy
   # <http://wikis.sun.com/display/OpenJDK/Mac+OS+X+Port+Compilers>
@@ -214,7 +217,7 @@
 
 # Flags for generating make dependency flags.
 ifneq ("${CC_VER_MAJOR}", "2")
-DEPFLAGS = -fpch-deps -MMD -MP -MF $(DEP_DIR)/$(@:%=%.d)
+DEPFLAGS = -MMD -MP -MF $(DEP_DIR)/$(@:%=%.d)
 endif
 
 # -DDONT_USE_PRECOMPILED_HEADER will exclude all includes in precompiled.hpp.
@@ -225,8 +228,8 @@
 #------------------------------------------------------------------------
 # Linker flags
 
-# statically link libstdc++.so, work with gcc but ignored by g++
-STATIC_STDCXX = -Wl,-Bstatic -lstdc++ -Wl,-Bdynamic
+# statically link libc++.so, work with gcc but ignored by c++
+STATIC_STDCXX = -Wl,-Bstatic -lc++ -Wl,-Bdynamic
 
 # statically link libgcc and/or libgcc_s, libgcc does not exist before gcc-3.x.
 ifneq ("${CC_VER_MAJOR}", "2")
