--- src/Pegasus/Config/RepositoryPropertyOwner.cpp.orig	2014-04-30 08:33:34.141523778 -0500
+++ src/Pegasus/Config/RepositoryPropertyOwner.cpp	2014-04-30 08:33:50.057522399 -0500
@@ -52,7 +52,7 @@
 {
 #if defined(PEGASUS_OS_LINUX) || defined(PEGASUS_OS_FREEBSD)
 # ifdef PEGASUS_USE_RELEASE_CONFIG_OPTIONS
-    {"repositoryIsDefaultInstanceProvider", "false", IS_STATIC, IS_HIDDEN},
+    {"repositoryIsDefaultInstanceProvider", "true", IS_STATIC, IS_HIDDEN},
 # else
     {"repositoryIsDefaultInstanceProvider", "true", IS_STATIC, IS_VISIBLE},
 # endif
