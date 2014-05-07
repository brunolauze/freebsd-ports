--- mak/config.mak.orig	2014-04-22 17:02:42.979750194 -0500
+++ mak/config.mak	2014-04-22 17:24:55.317649146 -0500
@@ -252,11 +252,13 @@
     CIM_SCHEMA_VER=$(patsubst CIM%,%,$(patsubst CIMPrelim%,%,$(PEGASUS_CIM_SCHEMA)))
 endif
 
+ifndef ALLOW_EXPERIMENTAL
 ifneq (, $(findstring Prelim, $(CIM_SCHEMA_DIR)))
     ALLOW_EXPERIMENTAL = -aE
 else
     ALLOW_EXPERIMENTAL =
 endif
+endif
 
 LEX = flex
 
