--- solenv/gbuild/platform/unxgcc.mk.orig	2013-10-11 14:21:25.277887332 -0500
+++ solenv/gbuild/platform/unxgcc.mk	2013-10-11 14:22:34.356881414 -0500
@@ -43,12 +43,12 @@
 	$(gb_CFLAGS_COMMON) \
 	-fPIC \
 	-Wdeclaration-after-statement \
-	-Wshadow \
+	-Wno-unused-parameter
 
 gb_CXXFLAGS := \
 	$(gb_CXXFLAGS_COMMON) \
 	-fPIC \
-	-Wshadow \
+	-Wno-unused-parameter \
 	-Woverloaded-virtual \
 
 ifneq ($(COM_GCC_IS_CLANG),TRUE)
