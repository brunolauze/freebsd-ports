--- src/Pegasus/ProviderManager2/CMPIR/ip.c.orig	2014-02-25 16:42:55.621527222 -0600
+++ src/Pegasus/ProviderManager2/CMPIR/ip.c	2014-02-25 16:45:13.333207877 -0600
@@ -93,7 +93,7 @@
     extern int h_errno;
 #endif
 
-#if defined(PEGASUS_OS_LINUX)
+#if defined(PEGASUS_OS_LINUX) || defined(PEGASUS_OS_FREEBSD)
     rc = gethostbyname_r (hname,hbuf,tmphbuf,hbuflen,&hptr,&herr);
 #elif defined(PEGASUS_OS_SOLARIS)
     hptr = gethostbyname_r(hname,hbuf,tmphbuf,hbuflen,&herr);
