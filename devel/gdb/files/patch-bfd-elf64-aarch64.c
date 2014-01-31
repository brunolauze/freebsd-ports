--- bfd/elf64-aarch64.c.orig	2014-01-31 08:30:24.679323864 -0600
+++ bfd/elf64-aarch64.c	2014-01-31 08:32:58.709326555 -0600
@@ -3217,49 +3217,49 @@
 #define MASK(n) ((1u << (n)) - 1)
 
 /* Decode the 26-bit offset of unconditional branch.  */
-static inline uint32_t
+static inline __unused uint32_t
 decode_branch_ofs_26 (uint32_t insn)
 {
   return insn & MASK (26);
 }
 
 /* Decode the 19-bit offset of conditional branch and compare & branch.  */
-static inline uint32_t
+static inline __unused uint32_t
 decode_cond_branch_ofs_19 (uint32_t insn)
 {
   return (insn >> 5) & MASK (19);
 }
 
 /* Decode the 19-bit offset of load literal.  */
-static inline uint32_t
+static inline __unused uint32_t
 decode_ld_lit_ofs_19 (uint32_t insn)
 {
   return (insn >> 5) & MASK (19);
 }
 
 /* Decode the 14-bit offset of test & branch.  */
-static inline uint32_t
+static inline __unused uint32_t
 decode_tst_branch_ofs_14 (uint32_t insn)
 {
   return (insn >> 5) & MASK (14);
 }
 
 /* Decode the 16-bit imm of move wide.  */
-static inline uint32_t
+static inline __unused uint32_t
 decode_movw_imm (uint32_t insn)
 {
   return (insn >> 5) & MASK (16);
 }
 
 /* Decode the 21-bit imm of adr.  */
-static inline uint32_t
+static inline __unused uint32_t
 decode_adr_imm (uint32_t insn)
 {
   return ((insn >> 29) & MASK (2)) | ((insn >> 3) & (MASK (19) << 2));
 }
 
 /* Decode the 12-bit imm of add immediate.  */
-static inline uint32_t
+static inline __unused uint32_t
 decode_add_imm (uint32_t insn)
 {
   return (insn >> 10) & MASK (12);
