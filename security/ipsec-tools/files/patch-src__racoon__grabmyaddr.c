--- src/racoon/grabmyaddr.c.orig	2014-01-19 02:13:19.642326215 -0600
+++ src/racoon/grabmyaddr.c	2014-01-19 02:13:31.982420909 -0600
@@ -741,12 +741,12 @@
 
 	switch (rtm->rtm_type) {
 	case RTM_NEWADDR:
-		parse_addresses(ifa + 1, msg + ifa->ifam_msglen,
+		parse_addresses((char *)ifa + 1, msg + ifa->ifam_msglen,
 				ifa->ifam_addrs, &addr);
 		myaddr_open_all_configured((struct sockaddr *) &addr);
 		break;
 	case RTM_DELADDR:
-		parse_addresses(ifa + 1, msg + ifa->ifam_msglen,
+		parse_addresses((char *)ifa + 1, msg + ifa->ifam_msglen,
 				ifa->ifam_addrs, &addr);
 		myaddr_close_all_open((struct sockaddr *) &addr);
 		break;
