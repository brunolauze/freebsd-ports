--- src/slp/slp_client/src/cmd-utils/slp_client/lslp.cpp.orig	2014-02-26 06:13:08.855144149 -0600
+++ src/slp/slp_client/src/cmd-utils/slp_client/lslp.cpp	2014-02-26 06:13:51.557428444 -0600
@@ -38,6 +38,8 @@
 # include "lslp-linux.cpp"
 #elif defined(PEGASUS_OS_AIX) || defined(PEGASUS_OS_PASE)
 # include "lslp-aix.cpp"
+#elif defined(PEGASUS_OS_FREEBSD)
+#  include "lslp-freebsd.cpp"
 #elif defined(PEGASUS_OS_HPUX)
 # include "lslp-hpux.cpp"
 #else
