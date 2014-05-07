--- /dev/null	2014-04-30 08:11:00.000000000 -0500
+++ src/Pegasus/Config/FixedPropertyTableFreeBSD.h	2014-04-30 08:19:50.732580299 -0500
@@ -0,0 +1,96 @@
+//%LICENSE////////////////////////////////////////////////////////////////
+//
+// Licensed to The Open Group (TOG) under one or more contributor license
+// agreements.  Refer to the OpenPegasusNOTICE.txt file distributed with
+// this work for additional information regarding copyright ownership.
+// Each contributor licenses this file to you under the OpenPegasus Open
+// Source License; you may not use this file except in compliance with the
+// License.
+//
+// Permission is hereby granted, free of charge, to any person obtaining a
+// copy of this software and associated documentation files (the "Software"),
+// to deal in the Software without restriction, including without limitation
+// the rights to use, copy, modify, merge, publish, distribute, sublicense,
+// and/or sell copies of the Software, and to permit persons to whom the
+// Software is furnished to do so, subject to the following conditions:
+//
+// The above copyright notice and this permission notice shall be included
+// in all copies or substantial portions of the Software.
+//
+// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
+// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
+// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
+// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
+// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
+// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
+// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
+//
+//////////////////////////////////////////////////////////////////////////
+/*
+//
+//%/////////////////////////////////////////////////////////////////////////////
+*/
+
+#if defined(PEGASUS_USE_RELEASE_DIRS) && \
+    defined(PEGASUS_OVERRIDE_DEFAULT_RELEASE_DIRS)
+# include <Pegasus/Config/ProductDirectoryStructure.h>
+#endif
+
+#ifdef PEGASUS_USE_RELEASE_CONFIG_OPTIONS
+#ifndef PEGASUS_FLAVOR
+    {"httpPort",            "5988"},
+    {"httpsPort",           "5989"},
+#endif
+    {"enableAuthentication", "false"},
+    {"httpAuthType",        "Basic"},
+    {"enableBinaryRepository", "false"},
+#endif
+#if defined(PEGASUS_USE_RELEASE_DIRS)
+# if defined(PEGASUS_OVERRIDE_DEFAULT_RELEASE_DIRS)
+    {"traceFilePath",       PEGASUS_TRACE_FILE_PATH},
+#  if !defined(PEGASUS_USE_SYSLOGS)
+    {"logdir",              PEGASUS_LOG_DIR},
+    {"maxLogFileSizeKBytes",      "32768"},/* 32768 * 1024 = 33554432 (32MB)*/
+#  endif
+    {"passwordFilePath",     PEGASUS_CONFIG_DIR"/cimserver.passwd"},
+    {"sslCertificateFilePath", PEGASUS_SSL_CERT_FILE_PATH},
+    {"sslKeyFilePath",       PEGASUS_SSL_KEY_FILE_PATH},
+    {"sslTrustStore",        PEGASUS_SSL_SERVER_TRUSTSTORE},
+#  ifdef PEGASUS_ENABLE_SSL_CRL_VERIFICATION
+    {"crlStore",             PEGASUS_SSL_SERVER_CRL},
+#  endif
+    {"repositoryDir",        PEGASUS_REPOSITORY_DIR},
+    {"providerDir", PEGASUS_EXTRA_PROVIDER_LIB_DIR PEGASUS_PROVIDER_LIB_DIR
+                    ":/usr/" PEGASUS_ARCH_LIB "/cmpi"},
+    {"providerManagerDir",   PEGASUS_PROVIDER_MANAGER_LIB_DIR},
+# else /* PEGASUS_OVERRIDE_DEFAULT_RELEASE_DIRS */
+    {"traceFilePath",       "/var/log/cimserver.trc"},
+#  if !defined(PEGASUS_USE_SYSLOGS)
+    {"logdir",              "/var/log"},
+#  endif
+    {"passwordFilePath",    "/usr/local/etc/pegasus/cimserver.passwd"},
+    {"sslCertificateFilePath", "/usr/local/etc/pegasus/server.pem"},
+    {"sslKeyFilePath",      "/usr/local/etc/pegasus/file.pem"},
+    {"sslTrustStore",       "/usr/local/etc/pegasus/cimserver_trust"},
+    {"crlStore",            "/usr/local/etc/pegasus/crl"},
+    {"repositoryDir",       PEGASUS_REPOSITORY_DIR},
+#ifdef PEGASUS_ENABLE_PROTOCOL_WEB
+    {"webRoot",             "/usr/local/www/pegasus"},
+    {"indexFile",           "index.html"},
+    {"mimeTypesFile",       "/usr/local/www/pegasus/mimeType.txt"},
+#endif
+
+#  if defined(PEGASUS_ENABLE_CMPI_PROVIDER_MANAGER)
+    {"providerDir",         "/usr/local/lib/pegasus/:/usr/local/lib/pegasus/providers/:/usr/local/"
+                                PEGASUS_ARCH_LIB "/cmpi"},
+#  else
+    {"providerDir",         "/usr/local/lib/pegasus"},
+#  endif
+    {"providerManagerDir",  "/usr/local/lib/pegasus/providermanagers"},
+    {"messageDir",          "/usr/local/share/locale/ICU_Messages"},
+# endif /* PEGASUS_OVERRIDE_DEFAULT_RELEASE_DIRS */
+#endif /* defined(PEGASUS_USE_RELEASE_DIRS) */
+#if !defined(PEGASUS_USE_RELEASE_CONFIG_OPTIONS) && \
+    !defined(PEGASUS_USE_RELEASE_DIRS)
+    {"bogus", "MyBogusValue"} /* Remove this line if others are added */
+#endif
