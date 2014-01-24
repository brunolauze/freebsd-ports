--- cef/tools/make_version_header.py.orig	2014-01-23 13:33:52.113504771 -0600
+++ cef/tools/make_version_header.py	2014-01-23 13:34:50.333734651 -0600
@@ -131,7 +131,7 @@
                   '#define CEF_API_HASH_PLATFORM "' + api_hashes['windows'] + '"\n'+\
                   '#elif defined(OS_MACOSX)\n'+\
                   '#define CEF_API_HASH_PLATFORM "' + api_hashes['macosx'] + '"\n'+\
-                  '#elif defined(OS_LINUX)\n'+\
+                  '#elif defined(OS_LINUX) || defined(OS_BSD)\n'+\
                   '#define CEF_API_HASH_PLATFORM "' + api_hashes['linux'] + '"\n'+\
                   '#endif\n\n'+\
                   '///\n'+\
