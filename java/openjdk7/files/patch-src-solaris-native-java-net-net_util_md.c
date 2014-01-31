--- jdk/src/solaris/native/java/net/net_util_md.c
+++ jdk/src/solaris/native/java/net/net_util_md.c
@@ -118,9 +118,9 @@
     static jfieldID ni_defaultIndexID;
     if (ni_class == NULL) {
         jclass c = (*env)->FindClass(env, "java/net/NetworkInterface");
-        CHECK_NULL(c);
+        CHECK_NULL_RETURN(c, 0);
         c = (*env)->NewGlobalRef(env, c);
-        CHECK_NULL(c);
+        CHECK_NULL_RETURN(c, 0);
         ni_defaultIndexID = (*env)->GetStaticFieldID(
             env, c, "defaultIndex", "I");
         ni_class = c;
