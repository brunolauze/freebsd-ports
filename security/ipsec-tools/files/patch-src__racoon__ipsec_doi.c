--- src/racoon/ipsec_doi.c.orig	2014-01-18 00:00:12.474469207 -0600
+++ src/racoon/ipsec_doi.c	2014-01-18 00:01:11.804181168 -0600
@@ -79,6 +79,7 @@
 #include "crypto_openssl.h"
 #include "strnames.h"
 #include "gcmalloc.h"
+#include "vendorid.h"
 
 #ifdef ENABLE_NATT
 #include "nattraversal.h"
@@ -1183,7 +1184,7 @@
 			"failed to get buffer.\n");
 		goto bad;
 	}
-	memset(pair, 0, sizeof(pair));
+	memset(pair, 0, sizeof(*pair));
 
 	bp = (caddr_t)(sab + 1);
 	tlen = sa->l - sizeof(*sab);
@@ -4795,3 +4796,4 @@
 	}
 	/*NOTREACHED*/
 }
+
