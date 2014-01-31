--- bfd/elfxx-mips.c.orig	2013-12-07 22:33:13.000000000 -0600
+++ bfd/elfxx-mips.c	2014-01-31 08:38:28.619143293 -0600
@@ -975,7 +975,7 @@
    all the subsequent PLT entries are microMIPS code too.
 
    The trailing NOP is for alignment and correct disassembly only.  */
-static const bfd_vma micromips_o32_exec_plt0_entry[] =
+static const __unused bfd_vma micromips_o32_exec_plt0_entry[] =
 {
   0x7980, 0x0000,	/* addiupc $3, (&GOTPLT[0]) - .			*/
   0xff23, 0x0000,	/* lw $25, 0($3)				*/
@@ -990,7 +990,7 @@
 
 /* The format of the microMIPS first PLT entry in an O32 executable
    in the insn32 mode.  */
-static const bfd_vma micromips_insn32_o32_exec_plt0_entry[] =
+static const __unused bfd_vma micromips_insn32_o32_exec_plt0_entry[] =
 {
   0x41bc, 0x0000,	/* lui $28, %hi(&GOTPLT[0])			*/
   0xff3c, 0x0000,	/* lw $25, %lo(&GOTPLT[0])($28)			*/
@@ -1014,7 +1014,7 @@
 /* The format of subsequent MIPS16 o32 PLT entries.  We use v0 ($2)
    and v1 ($3) as temporaries because t8 ($24) and t9 ($25) are not
    directly addressable.  */
-static const bfd_vma mips16_o32_exec_plt_entry[] =
+static const __unused bfd_vma mips16_o32_exec_plt_entry[] =
 {
   0xb203,		/* lw $2, 12($pc)			*/
   0x9a60,		/* lw $3, 0($2)				*/
@@ -1027,7 +1027,7 @@
 
 /* The format of subsequent microMIPS o32 PLT entries.  We use v0 ($2)
    as a temporary because t8 ($24) is not addressable with ADDIUPC.  */
-static const bfd_vma micromips_o32_exec_plt_entry[] =
+static const __unused bfd_vma micromips_o32_exec_plt_entry[] =
 {
   0x7900, 0x0000,	/* addiupc $2, (.got.plt entry) - .	*/
   0xff22, 0x0000,	/* lw $25, 0($2)			*/
@@ -1036,7 +1036,7 @@
 };
 
 /* The format of subsequent microMIPS o32 PLT entries in the insn32 mode.  */
-static const bfd_vma micromips_insn32_o32_exec_plt_entry[] =
+static const __unused bfd_vma micromips_insn32_o32_exec_plt_entry[] =
 {
   0x41af, 0x0000,	/* lui $15, %hi(.got.plt entry)		*/
   0xff2f, 0x0000,	/* lw $25, %lo(.got.plt entry)($15)	*/
@@ -2055,13 +2055,13 @@
   return r_type == R_MIPS_GOT_PAGE || r_type == R_MICROMIPS_GOT_PAGE;
 }
 
-static inline bfd_boolean
+static inline __unused bfd_boolean
 got_ofst_reloc_p (unsigned int r_type)
 {
   return r_type == R_MIPS_GOT_OFST || r_type == R_MICROMIPS_GOT_OFST;
 }
 
-static inline bfd_boolean
+static inline __unused bfd_boolean
 got_hi16_reloc_p (unsigned int r_type)
 {
   return r_type == R_MIPS_GOT_HI16 || r_type == R_MICROMIPS_GOT_HI16;
@@ -7331,20 +7331,20 @@
       /* Change alignments of some sections.  */
       s = bfd_get_linker_section (abfd, ".hash");
       if (s != NULL)
-	bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
+	(void)bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
       s = bfd_get_linker_section (abfd, ".dynsym");
       if (s != NULL)
-	bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
+	(void)bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
       s = bfd_get_linker_section (abfd, ".dynstr");
       if (s != NULL)
-	bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
+	(void)bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
       /* ??? */
       s = bfd_get_section_by_name (abfd, ".reginfo");
       if (s != NULL)
-	bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
+	(void)bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
       s = bfd_get_linker_section (abfd, ".dynamic");
       if (s != NULL)
-	bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
+	(void)bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
     }
 
   if (!info->shared)
