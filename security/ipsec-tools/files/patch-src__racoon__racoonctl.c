--- src/racoon/racoonctl.c.orig	2014-01-19 12:15:56.941161586 -0600
+++ src/racoon/racoonctl.c	2014-01-19 12:16:37.731519308 -0600
@@ -1454,7 +1454,7 @@
 		else if (evt_quit_event == ec->ec_type) {
 			switch (ec->ec_type) {
 			case EVT_PHASE1_MODE_CFG:
-				print_cfg(ec, len);
+				print_cfg((char*)ec, len);
 				break;
 			default:
 				print_evt(ec);
