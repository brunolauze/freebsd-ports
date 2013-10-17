--- sw/Module_sw.mk.orig	2013-10-11 14:18:18.766899211 -0500
+++ sw/Module_sw.mk	2013-10-11 14:18:52.363897112 -0500
@@ -46,9 +46,6 @@
 ))
 
 $(eval $(call gb_Module_add_slowcheck_targets,sw,\
-    CppunitTest_sw_htmlexport \
-    CppunitTest_sw_macros_test \
-    CppunitTest_sw_ooxmlexport \
     CppunitTest_sw_ooxmlimport \
     CppunitTest_sw_ww8export \
     CppunitTest_sw_ww8import \
