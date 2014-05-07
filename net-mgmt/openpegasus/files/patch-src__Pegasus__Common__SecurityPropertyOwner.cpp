--- src/Pegasus/Config/SecurityPropertyOwner.cpp.orig	2014-04-22 11:34:58.394074836 -0500
+++ src/Pegasus/Config/SecurityPropertyOwner.cpp	2014-04-22 11:11:22.144214203 -0500
@@ -114,7 +114,7 @@
     {"sslClientVerificationMode", "disabled", IS_STATIC, IS_VISIBLE},
     {"sslTrustStoreUserName", "", IS_STATIC, IS_VISIBLE},
     {"enableNamespaceAuthorization", "false", IS_STATIC, IS_VISIBLE},
-#if defined(PEGASUS_OS_HPUX) || defined(PEGASUS_OS_LINUX)
+#if defined(PEGASUS_OS_HPUX) || defined(PEGASUS_OS_LINUX) || defined(PEGASUS_OS_FREEBSD)
 # ifdef PEGASUS_USE_RELEASE_CONFIG_OPTIONS
     {"enableSubscriptionsForNonprivilegedUsers",
          "false", IS_STATIC, IS_VISIBLE},
