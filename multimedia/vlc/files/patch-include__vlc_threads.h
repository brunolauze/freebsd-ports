--- include/vlc_threads.h.orig	2013-10-15 18:01:38.684435644 -0500
+++ include/vlc_threads.h	2013-10-15 18:02:22.744414611 -0500
@@ -175,8 +175,6 @@
 # include <pthread.h>
 # include <semaphore.h>
 # define LIBVLC_USE_PTHREAD           1
-# define LIBVLC_USE_PTHREAD_CLEANUP   1
-# define LIBVLC_USE_PTHREAD_CANCEL    1
 
 typedef pthread_t       vlc_thread_t;
 typedef pthread_mutex_t vlc_mutex_t;
@@ -324,7 +322,7 @@
 VLC_API void vlc_restorecancel(int state);
 VLC_API void vlc_testcancel(void);
 
-#if defined (LIBVLC_USE_PTHREAD_CLEANUP)
+#if defined (LIBVLC_USE_PTHREAD_CLEANUP) && !defined(__FreeBSD__)
 /**
  * Registers a new procedure to run if the thread is cancelled (or otherwise
  * exits prematurely). Any call to vlc_cleanup_push() <b>must</b> paired with a
