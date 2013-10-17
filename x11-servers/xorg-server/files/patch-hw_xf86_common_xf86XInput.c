--- hw/xfree86/common/xf86Xinput.c.orig	2013-10-09 19:55:45.133529545 -0500
+++ hw/xfree86/common/xf86Xinput.c	2013-10-09 19:56:13.638638253 -0500
@@ -524,7 +524,7 @@
 MatchAttrToken(const char *attr, struct xorg_list *patterns,
                int (*compare) (const char *attr, const char *pattern))
 {
-    const xf86MatchGroup *group;
+    const xf86MatchGroup *group = NULL;
 
     /* If there are no patterns, accept the match */
     if (xorg_list_is_empty(patterns))
