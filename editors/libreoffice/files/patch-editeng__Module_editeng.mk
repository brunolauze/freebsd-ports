--- editeng/Module_editeng.mk.orig	2013-10-11 13:24:26.746121127 -0500
+++ editeng/Module_editeng.mk	2013-10-11 13:24:37.235122335 -0500
@@ -27,7 +27,6 @@
 # add any runtime tests (unit tests) here
 # remove if no tests
 $(eval $(call gb_Module_add_check_targets,editeng,\
-    CppunitTest_editeng_core \
     CppunitTest_editeng_borderline \
     CppunitTest_editeng_lookuptree \
 ))
