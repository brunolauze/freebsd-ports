--- src/slp/slp_agent/peg_slp_agent.cpp.orig	2014-04-22 12:36:47.446818044 -0500
+++ src/slp/slp_agent/peg_slp_agent.cpp	2014-04-22 12:39:14.967807821 -0500
@@ -169,7 +169,7 @@
 
     if ((serv = getservbyname_r(
         SLP_SERVICE_NAME, "udp", &serv_result, buf, SERV_BUF_SIZE)) != NULL)
-#elif defined(PEGASUS_OS_LINUX)
+#elif defined(PEGASUS_OS_LINUX) || defined(PEGASUS_OS_FREEBSD)
 
     int ret = getservbyname_r(
         SLP_SERVICE_NAME,
