--- mono/mini/mini-llvm.c.orig	2014-01-16 14:33:08.981307613 -0600
+++ mono/mini/mini-llvm.c	2014-01-16 14:33:27.872288770 -0600
@@ -4772,8 +4772,10 @@
 	 * with it.
 	 */
 	cfg->encoded_unwind_ops = mono_unwind_decode_fde ((guint8*)data, &cfg->encoded_unwind_ops_len, NULL, &ei, &ei_len, &type_info, &this_reg, &this_offset);
+	/*
 	if (cfg->verbose_level > 1)
 		mono_print_unwind_info (cfg->encoded_unwind_ops, cfg->encoded_unwind_ops_len);
+	*/
 
 	/* Count nested clauses */
 	nested_len = 0;
