--- mak/commands.mak.orig	2014-02-28 21:31:33.349074427 -0600
+++ mak/commands.mak	2014-02-28 21:31:36.586175987 -0600
@@ -250,6 +250,92 @@
 
 endif
 
+
+ifeq ($(OS),freebsd)
+    STRIPCRS =
+    DIFF = diff
+    SORT = sort
+    REDIRECTERROR = 2>&1
+    CIMSERVER_START_SERVICE = $(CIMSERVER_PATH)cimserver $(CIMSERVER_CONFIG_OPTIONS)
+    CIMSERVER_STOP_SERVICE = $(CIMSERVER_PATH)cimserver -s
+    SLEEP = sleep
+    TIME_CMD = time
+    REMOVE_PEGASUS_DIRECTORY = rm -Rf pegasus.old; mv pegasus pegasus.old
+    MUEXE = mu
+    MKDIRHIER = mkdir -p
+    RMDIRHIER = rm -rf
+    CPDIRHIER = cp -R
+    ECHO = echo
+    ECHO-E = echo -e
+    COPY = cp
+    TOUCH = touch
+    CAT = cat
+    DOCXX = doc++
+    DOXYGEN = doxygen
+
+    GET_HOSTNAME = `host \`hostname\`|cut -d" " -f1`
+
+    LIB_LINK_SUFFIX = .so
+
+    Prwxrwxrwx = 777
+    Prwxrwxrwt = 1777
+    Prwxr_xr_x = 755
+    Prwxr_x___ = 750
+    Prwxr__r__ = 744
+    Prwx______ = 700
+    Pr__r__r__ = 444
+    Pr________ = 400
+    Pr_xr_xr_x = 555
+    Pr_x______ = 500
+    Prw_______ = 600
+    Prw_r__r__ = 644
+    Prw_r_____ = 640
+    CHMODDIRHIER = chmod -R
+
+    INSTALL_USR = root
+    INSTALL_GRP = pegasus
+    CIMSERVER_USR = root
+    CIMSERVER_GRP = root
+    CHMOD = chmod
+    CHOWN = chown
+    CHGRP = chgrp
+    CHOWNDIRHIER = chown -R
+    CHGRPDIRHIER = chgrp -R
+
+    SYMBOLIC_LINK_CMD = ln -f -s
+
+    CURRENT_USER=`whoami`
+
+#
+# Since the Privilege Separation splits the cimserver process into two
+# processes (cimservermain process - a non privileged process; cimserver
+# process - a privileged process), the pegasus files need to be split into
+# two sets. The files which can be updated by cimservermain process are owned
+# by user "CIMSERVERMAIN_USR" and group "CIMSERVERMAIN_GRP". Other files
+# owned by user "CIMSERVER_USR" and group "CIMSERVER_GRP" can be updated
+# by cimserver process.
+# If the Privilege Separation is not enabled, a single privileged process
+# (cimserver process) is created. All the pegasus files can be updated by
+# the cimserver process. The CIMSERVERMAIN_USR variable will be set
+# equal to CIMSERVER_USR, and the CIMSERVERMAIN_GRP variable will be set
+# equal to CIMSERVER_GRP.
+#
+# To further restrict the privileges assigned to the cimservermain
+# process, we recommend creating a new group for the cimservermain
+# process.  By default, the name of this group will be the same as
+# the cimservermain user.  Note: the CIMSERVERMAIN_GRP should be
+# the primary group for the CIMSERVERMAIN_USER.
+
+ifdef PEGASUS_ENABLE_PRIVILEGE_SEPARATION
+    CIMSERVERMAIN_USR = $(PEGASUS_CIMSERVERMAIN_USER)
+    CIMSERVERMAIN_GRP = $(PEGASUS_CIMSERVERMAIN_USER)
+else
+    CIMSERVERMAIN_USR = $(CIMSERVER_USR)
+    CIMSERVERMAIN_GRP = $(CIMSERVER_GRP)
+endif
+
+endif
+
 ifeq ($(OS),zos)
     STRIPCRS =
     DIFF = diff
