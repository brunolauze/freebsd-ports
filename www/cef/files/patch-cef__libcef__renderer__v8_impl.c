--- cef/libcef/renderer/v8_impl.cc.orig	2014-01-23 14:44:59.614210942 -0600
+++ cef/libcef/renderer/v8_impl.cc	2014-01-23 14:45:42.285254186 -0600
@@ -1154,7 +1154,7 @@
   }
 
   // Create the new V8 object.
-  v8::Local<v8::Object> obj = v8::Object::New();
+  v8::Local<v8::Object> obj = v8::Object::New(isolate);
 
   // Create a tracker object that will cause the user data and/or accessor
   // reference to be released when the V8 object is destroyed.
