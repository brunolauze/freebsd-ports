--- mak/shared-library-unix.mak.orig	2014-02-25 17:49:00.590195126 -0600
+++ mak/shared-library-unix.mak	2014-02-28 20:04:24.145395307 -0600
@@ -251,6 +251,10 @@
 	$(MAKE) --directory=$(LIB_DIR) -f $(PEGASUS_ROOT)/mak/library-unix.mak \
             ln LIBRARY=lib$(LIBRARY) SUFFIX=$(LIB_SUFFIX) PLATFORM_SUFFIX=so
     endif
+    ifdef PEGASUS_PLATFORM_FREEBSD_GENERIC_GNU
+	$(MAKE) --directory=$(LIB_DIR) -f $(PEGASUS_ROOT)/mak/library-unix.mak \
+	    ln LIBRARY=lib$(LIBRARY) SUFFIX=$(LIB_SUFFIX) PLATFORM_SUFFIX=so
+    endif
 	$(TOUCH) $(FULL_LIB)
 	@ $(ECHO)
 
