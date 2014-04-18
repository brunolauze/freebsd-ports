--- bridges/Library_cpp_uno.mk.orig	2013-10-12 22:35:19.987969252 -0500
+++ bridges/Library_cpp_uno.mk	2013-10-12 22:35:54.903965398 -0500
@@ -188,11 +188,6 @@
 	$(if $(filter TRUE,$(HAVE_GCC_AVX)),-mno-avx) \
 ))
 
-ifeq ($(filter ANDROID WNT,$(OS)),)
-$(eval $(call gb_Library_add_libs,gcc3_uno,\
-	-ldl \
-))
-endif
 endif
 
 $(eval $(call gb_Library_use_libraries,$(gb_CPPU_ENV)_uno,\
