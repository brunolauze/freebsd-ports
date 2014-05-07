--- src/Pegasus/Repository/NameSpaceManager.h.orig	2014-04-24 15:23:01.518423528 -0500
+++ src/Pegasus/Repository/NameSpaceManager.h	2014-04-24 15:23:24.485404402 -0500
@@ -307,9 +307,13 @@
 {
 public:
     NonEmptyNameSpace(const String& nameSpaceName)
+#if defined(PEGASUS_INTERNALONLY)
     : Exception(MessageLoaderParms(
           "Repository.NameSpaceManager.ATTEMPT_DELETE_NONEMPTY_NAMESPACE",
           "Attempt to delete a non-empty namespace: $0", nameSpaceName))
+#else
+    : Exception("Repository.NameSpaceManager.ATTEMPT_DELETE_NONEMPTY_NAMESPACE")
+#endif
     {
     }
 };
