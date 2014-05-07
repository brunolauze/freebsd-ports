--- src/Pegasus/Repository/InheritanceTree.h.orig	2014-04-24 15:24:28.219400153 -0500
+++ src/Pegasus/Repository/InheritanceTree.h	2014-04-24 15:24:50.767406698 -0500
@@ -221,9 +221,13 @@
 {
 public:
     InvalidInheritanceTree(const String& className)
+#if defined(PEGASUS_INTERNALONLY)
     : Exception(MessageLoaderParms(
           "Repository.InheritanceTree.INVALID_INHERITANCE_TREE",
           "Invalid inheritance tree: unknown class: $0", className))
+#else
+    : Exception("Repository.InheritanceTree.INVALID_INHERITANCE_TREE")
+#endif
     {
     }
 };
