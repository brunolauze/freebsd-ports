--- shell/Module_shell.mk.orig	2013-10-11 14:10:42.479932573 -0500
+++ shell/Module_shell.mk	2013-10-11 14:11:13.336928554 -0500
@@ -14,7 +14,7 @@
 	Library_localebe \
 ))
 
-ifeq ($(OS),LINUX)
+ifeq ($(GUI),UNX)
 ifeq ($(ENABLE_GIO),TRUE)
 $(eval $(call gb_Module_add_targets,shell,\
 	Library_losessioninstall \
