--- v8/src/unique.h.orig	2014-01-17 00:43:31.156599559 -0600
+++ v8/src/unique.h	2014-01-17 00:43:55.276080608 -0600
@@ -130,7 +130,7 @@
 
   // TODO(titzer): this is a hack to migrate to Unique<T> incrementally.
   static Unique<T> CreateUninitialized(Handle<T> handle) {
-    return Unique<T>(reinterpret_cast<Address>(NULL), handle);
+    return Unique<T>(static_cast<Address>(NULL), handle);
   }
 
   static Unique<T> CreateImmovable(Handle<T> handle) {
