--- extensions/Library_npsoplugin.mk.orig	2013-10-11 13:28:18.737107247 -0500
+++ extensions/Library_npsoplugin.mk	2013-10-11 13:28:40.061105087 -0500
@@ -23,9 +23,11 @@
 
 ifneq ($(OS),WNT)
 
+ifeq ($(filter DRAGONFLY FREEBSD NETBSD OPENBSD MACOSX,$(OS)),)
 $(eval $(call gb_Library_add_libs,npsoplugin,\
 	-ldl \
 ))
+endif
 
 $(eval $(call gb_Library_use_external,npsoplugin,gtk))
 
