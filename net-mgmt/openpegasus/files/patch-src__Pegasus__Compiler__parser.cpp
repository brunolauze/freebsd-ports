--- src/Pegasus/Compiler/parser.cpp.orig	2014-04-23 14:11:42.202469930 -0500
+++ src/Pegasus/Compiler/parser.cpp	2014-04-23 14:12:27.500466882 -0500
@@ -72,7 +72,7 @@
    "Null","Integer", "Real", "String", "Boolean,", "Char"
 };
 
-static const Uint32 _NUM_TYPES = sizeof(_parserTypeStrings) /
+static const Uint32 __unused _NUM_TYPES = sizeof(_parserTypeStrings) /
                                 sizeof(_parserTypeStrings[0]);
 
 const char* strValTypeEnumToString(strValTypeNS::strValTypeEnum type)
