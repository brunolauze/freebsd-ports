--- tools/grit/grit/node/base.py.orig	2014-01-13 09:02:35.000000000 -0600
+++ tools/grit/grit/node/base.py	2014-01-15 00:09:21.200012745 -0600
@@ -478,9 +478,10 @@
         'is_win': platform_assertion == 'is_win',
         'is_android': platform_assertion == 'is_android',
         'is_ios': platform_assertion == 'is_ios',
+	'is_bsd': 'bsd' in target_platform,
         # is_posix is not mutually exclusive of the others
-        'is_posix': (target_platform in ('darwin', 'linux2', 'linux3', 'sunos5')
-                     or 'bsd' in sys.platform),
+        'is_posix': (target_platform in ('darwin', 'linux2', 'linux3', 'sunos5', 'bsd')
+                     or 'bsd' in sys.platform or 'freebsd' in sys.platform),
         'pp_ifdef' : pp_ifdef,
         'pp_if' : pp_if,
     }
