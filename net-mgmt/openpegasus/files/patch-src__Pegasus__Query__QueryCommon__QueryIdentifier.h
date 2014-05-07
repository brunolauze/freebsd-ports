--- src/Pegasus/Query/QueryCommon/QueryIdentifier.h.orig	2014-02-28 21:16:07.472313078 -0600
+++ src/Pegasus/Query/QueryCommon/QueryIdentifier.h	2014-02-28 21:16:28.301203751 -0600
@@ -38,7 +38,9 @@
 #include <Pegasus/Common/ArrayInternal.h>
 #include <Pegasus/Common/CIMName.h>
 #include <Pegasus/Query/QueryCommon/SubRange.h>
+#ifdef PEGASUS_INTERNALONLY
 #include <Pegasus/Query/QueryCommon/QueryException.h>
+#endif
 
 #ifdef PEGASUS_USE_EXPERIMENTAL_INTERFACES
 
