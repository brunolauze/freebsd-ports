--- qtjsbackend/src/3rdparty/v8/src/stub-cache.cc.orig	2013-10-14 13:43:57.813436588 -0500
+++ qtjsbackend/src/3rdparty/v8/src/stub-cache.cc	2013-10-14 13:44:23.686435283 -0500
@@ -1362,7 +1362,7 @@
                                             Handle<String> name) {
   return (FLAG_print_code_stubs && !name.is_null())
       ? GetCodeWithFlags(flags, *name->ToCString())
-      : GetCodeWithFlags(flags, reinterpret_cast<char*>(NULL));
+      : GetCodeWithFlags(flags, static_cast<char*>(NULL));
 }
 
 
