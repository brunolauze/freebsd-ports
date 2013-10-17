--- sysui/CustomTarget_slackware.mk.orig	2013-10-12 12:30:49.099390585 -0500
+++ sysui/CustomTarget_slackware.mk	2013-10-12 12:31:24.018388245 -0500
@@ -25,7 +25,7 @@
 
 $(slack_WORKDIR)/empty.tar:
 	mkdir $(slack_WORKDIR)/empty
-	$(GNUTAR) -C $(slack_WORKDIR)/empty --owner=root $(if $(filter-out MACOSX,$(OS_FOR_BUILD)),--group=root) --same-owner -cf $@ .
+	$(GNUTAR) -C $(slack_WORKDIR)/empty -cf $@ .
 
 $(slack_WORKDIR)/%/install/doinst.sh: $(slack_SRCDIR)/update-script $(call gb_CustomTarget_get_workdir,sysui/share)/%/launcherlist
 	echo "( cd etc; rm -rf $(UNIXFILENAME.$*) )" > $@
@@ -54,7 +54,7 @@
            GNOMEDIR="" \
            ./create_tree.sh
 	cp $(slack_WORKDIR)/empty.tar $@.tmp
-	$(GNUTAR) -C $(slack_WORKDIR)/$* --owner=root $(if $(filter-out MACOSX,$(OS_FOR_BUILD)),--group=root) --same-owner \
+	$(GNUTAR) -C $(slack_WORKDIR)/$* \
 		-rf $@.tmp install usr opt
 	gzip < $@.tmp > $@
 
