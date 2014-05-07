--- pyopenchange/mapistore/folder.c.orig	2014-04-20 17:56:09.831788036 -0500
+++ pyopenchange/mapistore/folder.c	2014-04-20 17:57:08.797782670 -0500
@@ -108,7 +108,7 @@
 	value = PyObject_GetAttrString(datetime, "second");
 	tm->tm_sec = PyInt_AS_LONG(value);
 
-#ifdef	__USE_BSD
+#if	defined(__USE_BSD) || defined(__FreeBSD__)
 	value = PyObject_CallMethod(datetime, "utcoffset", NULL);
 	if (value && value != Py_None) {
 		tm->tm_gmtoff = PyInt_AS_LONG(value);
