--- mcs/build/profiles/basic.make.orig	2014-01-18 20:27:36.163864389 -0600
+++ mcs/build/profiles/basic.make	2014-01-18 20:30:27.829891944 -0600
@@ -8,13 +8,13 @@
 
 MONOLITE_MCS = $(topdir)/class/lib/monolite/basic.exe
 
-ifdef use_monolite
+#ifdef use_monolite
 PROFILE_RUNTIME = $(with_mono_path_monolite) $(RUNTIME)
 BOOTSTRAP_MCS = $(PROFILE_RUNTIME) $(RUNTIME_FLAGS) $(MONOLITE_MCS) -sdk:2
-else
-PROFILE_RUNTIME = $(EXTERNAL_RUNTIME)
-BOOTSTRAP_MCS = $(EXTERNAL_MCS)
-endif
+#else
+#PROFILE_RUNTIME = $(EXTERNAL_RUNTIME)
+#BOOTSTRAP_MCS = $(EXTERNAL_MCS)
+#endif
 
 MCS = $(with_mono_path) $(INTERNAL_GMCS)
 
@@ -28,7 +28,7 @@
 LIBRARY_COMPILE = $(BOOT_COMPILE)
 
 # Verbose basic only
-# V = 1
+V = 1
 
 #
 # Copy from rules.make because I don't know how to unset MCS_FLAGS
@@ -89,7 +89,8 @@
 endif
 
 $(PROFILE_EXE): $(topdir)/build/common/basic-profile-check.cs
-	$(BOOTSTRAP_MCS) /warn:0 /out:$@ $<
+	echo "Trying to compile basic-profile-check.exe..."
+	$(BOOTSTRAP_MCS) /out:$@ $<
 	echo -n "Bootstrap compiler: " 1>&2
 	$(BOOTSTRAP_MCS) --version 1>&2
 
