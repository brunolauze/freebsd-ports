--- src/Executor/tests/common.mak.orig	2014-04-23 15:29:29.829148418 -0500
+++ src/Executor/tests/common.mak	2014-04-23 15:30:02.806146336 -0500
@@ -30,3 +30,6 @@
 #ifeq ($(findstring _GNU, $(PEGASUS_PLATFORM)), _GNU)
 #    FLAGS += -pedantic -ansi -Werror -Wunused -Wno-unused-function
 #endif
+
+EXTRA_LIBRARIES = \
+                -lutil
