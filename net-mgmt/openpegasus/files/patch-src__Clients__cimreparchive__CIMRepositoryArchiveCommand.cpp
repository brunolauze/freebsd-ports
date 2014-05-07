--- src/Clients/cimreparchive/CIMRepositoryArchiveCommand.cpp.orig	2014-02-28 16:22:08.375920845 -0600
+++ src/Clients/cimreparchive/CIMRepositoryArchiveCommand.cpp	2014-02-28 16:22:43.787152245 -0600
@@ -333,7 +333,7 @@
 
     // Define the "tar" command location based on the platform
 #if defined(PEGASUS_OS_HPUX) || defined(PEGASUS_OS_AIX) || \
-  defined(PEGASUS_OS_PASE)
+  defined(PEGASUS_OS_PASE) || defined(PEGASUS_OS_FREEBSD)
     const char TAR_COMMAND[] = "/usr/bin/tar";
 #elif defined(PEGASUS_OS_LINUX)
     const char TAR_COMMAND[] = "/bin/tar";
