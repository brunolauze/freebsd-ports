--- src/Server/cimserver.cpp.orig	2014-04-23 14:58:10.727278081 -0500
+++ src/Server/cimserver.cpp	2014-04-23 14:58:46.399275057 -0500
@@ -234,7 +234,7 @@
 
 static const char OPTION_HELP        = 'h';
 
-static const char OPTION_HOME        = 'D';
+static const char __unused OPTION_HOME        = 'D';
 
 static const char OPTION_SHUTDOWN    = 's';
 
