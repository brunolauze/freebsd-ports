--- buildtools/scripts/abi_gen.sh.orig	2013-12-27 10:43:00.857605732 -0600
+++ buildtools/scripts/abi_gen.sh	2013-12-27 10:44:04.753140039 -0600
@@ -9,6 +9,7 @@
 cat <<EOF
 set height 0
 set width 0
+set print sevenbit-strings on
 EOF
 nm "$SHAREDLIB" | cut -d' ' -f2- | egrep '^[BDGTRVWS]' | grep -v @ | egrep -v ' (__bss_start|_edata|_init|_fini|_end)' | cut -c3- | sort | while read s; do
     echo "echo $s: "
@@ -17,5 +18,5 @@
 ) > $GDBSCRIPT
 
 # forcing the terminal avoids a problem on Fedora12
-TERM=none gdb -batch -x $GDBSCRIPT "$SHAREDLIB" < /dev/null
+TERM=none %GDB_CMD%% -batch -x $GDBSCRIPT "$SHAREDLIB" < /dev/null
 rm -f $GDBSCRIPT
