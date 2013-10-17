--- sd/Module_sd.mk.orig	2013-10-11 14:09:30.259936862 -0500
+++ sd/Module_sd.mk	2013-10-11 14:09:44.014935230 -0500
@@ -24,7 +24,6 @@
 
 ifneq ($(OS),DRAGONFLY)
 $(eval $(call gb_Module_add_check_targets,sd,\
-    CppunitTest_sd_uimpress \
     CppunitTest_sd_import_tests \
     CppunitTest_sd_filters_test \
 ))
