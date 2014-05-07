--- src/Service/ServerShutdownClient.cpp.orig	2014-02-26 06:21:01.142303866 -0600
+++ src/Service/ServerShutdownClient.cpp	2014-02-28 21:22:56.962023202 -0600
@@ -79,9 +79,9 @@
     {
         Boolean wasKilled = _serverRunStatus->kill();
 
-#if defined(PEGASUS_OS_HPUX) || defined(PEGASUS_PLATFORM_LINUX_GENERIC_GNU) \
-|| defined(PEGASUS_OS_ZOS) || defined(PEGASUS_OS_SOLARIS) \
-|| defined (PEGASUS_OS_VMS)
+#if defined(PEGASUS_OS_HPUX) || defined(PEGASUS_PLATFORM_LINUX_GENERIC_GNU) || \
+defined(PEGASUS_PLATFORM_FREEBSD_GENERIC_GNU) || defined(PEGASUS_OS_ZOS) || \
+defined(PEGASUS_OS_SOLARIS) || defined (PEGASUS_OS_VMS)
         if (wasKilled)
         {
             MessageLoaderParms parms(
