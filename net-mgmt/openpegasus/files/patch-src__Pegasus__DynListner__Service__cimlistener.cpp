--- src/Pegasus/DynListener/Service/cimlistener.cpp.orig	2014-04-23 15:11:17.393223511 -0500
+++ src/Pegasus/DynListener/Service/cimlistener.cpp	2014-04-23 15:11:29.123222760 -0500
@@ -210,7 +210,7 @@
 
 static const char OPTION_HELP        = 'h';
 
-static const char OPTION_HOME        = 'D';
+static const char __unused OPTION_HOME        = 'D';
 
 static const char OPTION_SHUTDOWN    = 's';
 
