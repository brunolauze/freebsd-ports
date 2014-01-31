--- opcodes/mips-dis.c.orig	2014-01-31 08:41:34.348931797 -0600
+++ opcodes/mips-dis.c	2014-01-31 08:42:01.879853308 -0600
@@ -245,7 +245,7 @@
   "c0_taglo",     "c0_taghi",     "c0_errorepc",  "$31"
 };
 
-static const struct mips_cp0sel_name mips_cp0sel_names_mipsr5900[] =
+static const __unused struct mips_cp0sel_name mips_cp0sel_names_mipsr5900[] =
 {
   { 24, 2, "c0_iab"			},
   { 24, 3, "c0_iabm"		},
