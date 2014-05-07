--- src/Service/ServerProcessUnix.cpp.orig	2014-02-26 06:18:56.523208262 -0600
+++ src/Service/ServerProcessUnix.cpp	2014-02-26 06:19:27.747361271 -0600
@@ -80,7 +80,7 @@
     {
 #if defined(PEGASUS_OS_ZOS)
         sig = sigwait(&set);
-#else // else for platforms = LINUX, HPUX, AIX
+#else // else for platforms = LINUX, HPUX, AIX, FREEBSD
         sigwait(&set, &sig);
 #endif
     } while (errno == EINTR);
