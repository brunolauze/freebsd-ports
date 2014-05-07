--- src/Pegasus/ProviderManager2/CMPIR/native/broker_os.c.orig	2014-02-25 16:47:33.216996344 -0600
+++ src/Pegasus/ProviderManager2/CMPIR/native/broker_os.c	2014-02-25 16:53:56.494421791 -0600
@@ -115,7 +115,7 @@
     CMPI_THREAD_RETURN (CMPI_THREAD_CDECL *start )(void *),
     void *parm, int detached)
 {
-#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU)
+#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU) || defined(CMPI_PLATFORM_FREEBSD_GENERIC_GNU)
     pthread_t t;
     pthread_attr_t tattr;
     startWrapperArg *wparm =
@@ -227,7 +227,7 @@
 #else
 static int threadOnce (int *once, void (*init)(void))
 {
-# if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU)
+# if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU) || defined(CMPI_PLATFORM_FREEBSD_GENERIC_GNU)
     return pthread_once ( once, init );
 # elif defined PEGASUS_OS_TYPE_WINDOWS
     if (*once==0)
@@ -249,7 +249,7 @@
 
 static int createThreadKey(CMPI_THREAD_KEY_TYPE *key, void (*cleanup)(void*))
 {
-#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU)
+#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU) || defined(CMPI_PLATFORM_FREEBSD_GENERIC_GNU)
     return pthread_key_create ((pthread_key_t*)key , cleanup );
 #elif defined(CMPI_PLATFORM_ZOS_ZSERIES_IBM)
     return pthread_key_create (key , cleanup );
@@ -275,7 +275,7 @@
 
 static void *getThreadSpecific(CMPI_THREAD_KEY_TYPE key)
 {
-#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU)
+#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU) || defined(CMPI_PLATFORM_FREEBSD_GENERIC_GNU)
     return pthread_getspecific(key);
 #elif defined(CMPI_PLATFORM_ZOS_ZSERIES_IBM)
     return(void*) pthread_getspecific_d8_np(key);
@@ -288,7 +288,7 @@
 
 static int setThreadSpecific(CMPI_THREAD_KEY_TYPE key, void * value)
 {
-#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU)
+#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU) || defined(CMPI_PLATFORM_FREEBSD_GENERIC_GNU)
     return pthread_setspecific(key,value);
 #elif defined(CMPI_PLATFORM_ZOS_ZSERIES_IBM)
     return pthread_setspecific(key,value);
@@ -301,7 +301,7 @@
 
 static CMPI_MUTEX_TYPE newMutex (int opt)
 {
-#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU)
+#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU) || defined(CMPI_PLATFORM_FREEBSD_GENERIC_GNU)
     static pthread_mutex_t tmpl=PTHREAD_MUTEX_INITIALIZER;
     pthread_mutex_t *m=calloc(1,sizeof(pthread_mutex_t));
     *m=tmpl;
@@ -336,7 +336,7 @@
 
 static void destroyMutex (CMPI_MUTEX_TYPE m)
 {
-#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU)
+#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU) || defined(CMPI_PLATFORM_FREEBSD_GENERIC_GNU)
     free(m);
 #elif defined(CMPI_PLATFORM_ZOS_ZSERIES_IBM)
     if (pthread_mutex_destroy((pthread_mutex_t *) m)!=0)
@@ -354,7 +354,7 @@
 
 static void lockMutex (CMPI_MUTEX_TYPE m)
 {
-#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU)
+#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU) || defined(CMPI_PLATFORM_FREEBSD_GENERIC_GNU)
     pthread_mutex_lock ((pthread_mutex_t *)m );
 #elif defined(CMPI_PLATFORM_ZOS_ZSERIES_IBM)
     pthread_mutex_lock ((pthread_mutex_t *)m );
@@ -367,7 +367,7 @@
 
 static void unlockMutex (CMPI_MUTEX_TYPE m)
 {
-#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU)
+#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU) || defined(CMPI_PLATFORM_FREEBSD_GENERIC_GNU)
     pthread_mutex_unlock ((pthread_mutex_t *)m );
 #elif defined(CMPI_PLATFORM_ZOS_ZSERIES_IBM)
     pthread_mutex_unlock ((pthread_mutex_t *)m );
@@ -380,7 +380,7 @@
 
 static CMPI_COND_TYPE newCondition (int opt)
 {
-#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU)
+#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU) || defined(CMPI_PLATFORM_FREEBSD_GENERIC_GNU)
     pthread_cond_t tmpl=PTHREAD_COND_INITIALIZER;
     pthread_cond_t *c=calloc(1,sizeof(pthread_cond_t));
     *c=tmpl;
@@ -408,7 +408,7 @@
 
 static void destroyCondition (CMPI_COND_TYPE c)
 {
-#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU)
+#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU) || defined(CMPI_PLATFORM_FREEBSD_GENERIC_GNU)
     free(c);
 #elif defined(CMPI_PLATFORM_ZOS_ZSERIES_IBM)
     if (pthread_cond_destroy((pthread_cond_t*) c) != 0)
@@ -428,7 +428,7 @@
     CMPI_MUTEX_TYPE m,
     struct timespec *wait)
 {
-#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU)
+#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU) || defined(CMPI_PLATFORM_FREEBSD_GENERIC_GNU)
     return pthread_cond_timedwait(
         (pthread_cond_t*)c,
         (pthread_mutex_t*)m,
@@ -479,7 +479,7 @@
 
 static int condWait(CMPI_COND_TYPE c, CMPI_MUTEX_TYPE m)
 {
-#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU)
+#if defined(CMPI_PLATFORM_LINUX_GENERIC_GNU) || defined(CMPI_PLATFORM_FREEBSD_GENERIC_GNU)
     return pthread_cond_wait((pthread_cond_t*)c, (pthread_mutex_t*)m);
 #elif defined(CMPI_PLATFORM_ZOS_ZSERIES_IBM)
     return pthread_cond_wait((pthread_cond_t*)c, (pthread_mutex_t*)m);
