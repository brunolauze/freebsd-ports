--- src/core/monitor.c.orig	2014-01-19 17:52:35.180140689 -0600
+++ src/core/monitor.c	2014-01-19 17:57:21.010087818 -0600
@@ -705,11 +705,146 @@
 
       if (g_strcmp0 (output->vendor, "unknown") != 0)
         {
-          if (!manager->pnp_ids)
-            manager->pnp_ids = gnome_pnp_ids_new ();
 
-          vendor_name = gnome_pnp_ids_get_pnp_id (manager->pnp_ids,
-                                                  output->vendor);
+
+
+	if (output->vendor == "AIC") vendor_name = "AG Neovo";
+	if (output->vendor == "ACR") vendor_name = "Acer";
+	if (output->vendor == "DEL") vendor_name = "DELL";
+	if (output->vendor == "SAM") vendor_name = "SAMSUNG";
+	if (output->vendor == "SNY") vendor_name = "SONY";
+	if (output->vendor == "SEC") vendor_name = "Epson";
+	if (output->vendor == "WAC") vendor_name = "Wacom";
+	if (output->vendor == "NEC") vendor_name = "NEC";
+	if (output->vendor == "CMO") vendor_name = "CMO";		/* Chi Mei */
+	if (output->vendor == "BNQ") vendor_name = "BenQ";
+
+	if (output->vendor == "ABP") vendor_name = "Advansys";
+	if (output->vendor == "ACC") vendor_name = "Accton";
+	if (output->vendor == "ACE") vendor_name = "Accton";
+	if (output->vendor == "ADP") vendor_name = "Adaptec";
+	if (output->vendor == "ADV") vendor_name = "AMD";
+	if (output->vendor == "AIR") vendor_name = "AIR";
+	if (output->vendor == "AMI") vendor_name = "AMI";
+	if (output->vendor == "ASU") vendor_name = "ASUS";
+	if (output->vendor == "ATI") vendor_name = "ATI";
+	if (output->vendor == "ATK") vendor_name = "Allied Telesyn";
+	if (output->vendor == "AZT") vendor_name = "Aztech";
+	if (output->vendor == "BAN") vendor_name = "Banya";
+	if (output->vendor == "BRI") vendor_name = "Boca Research";
+	if (output->vendor == "BUS") vendor_name = "Buslogic";
+	if (output->vendor == "CCI") vendor_name = "Cache Computers Inc.";
+	if (output->vendor == "CHA") vendor_name = "Chase";
+	if (output->vendor == "CMD") vendor_name = "CMD Technology, Inc.";
+	if (output->vendor == "COG") vendor_name = "Cogent";
+	if (output->vendor == "CPQ") vendor_name = "Compaq";
+	if (output->vendor == "CRS") vendor_name = "Crescendo";
+	if (output->vendor == "CSC") vendor_name = "Crystal";
+	if (output->vendor == "CSI") vendor_name = "CSI";
+	if (output->vendor == "CTL") vendor_name = "Creative Labs";
+	if (output->vendor == "DBI") vendor_name = "Digi";
+	if (output->vendor == "DEC") vendor_name = "Digital Equipment";
+	if (output->vendor == "DBK") vendor_name = "Databook";
+	if (output->vendor == "EGL") vendor_name = "Eagle Technology";
+	if (output->vendor == "ELS") vendor_name = "ELSA";
+	if (output->vendor == "ESS") vendor_name = "ESS";
+	if (output->vendor == "FAR") vendor_name = "Farallon";
+	if (output->vendor == "FDC") vendor_name = "Future Domain";
+	if (output->vendor == "HWP") vendor_name = "Hewlett-Packard";
+	if (output->vendor == "IBM") vendor_name = "IBM";
+	if (output->vendor == "INT") vendor_name = "Intel";
+	if (output->vendor == "ISA") vendor_name = "Iomega";
+	if (output->vendor == "LEN") vendor_name = "Lenovo";
+	if (output->vendor == "MDG") vendor_name = "Madge";
+	if (output->vendor == "MDY") vendor_name = "Microdyne";
+	if (output->vendor == "MET") vendor_name = "Metheus";
+	if (output->vendor == "MIC") vendor_name = "Micronics";
+	if (output->vendor == "MLX") vendor_name = "Mylex";
+	if (output->vendor == "NVL") vendor_name = "Novell";
+	if (output->vendor == "OLC") vendor_name = "Olicom";
+	if (output->vendor == "PRO") vendor_name = "Proteon";
+	if (output->vendor == "RII") vendor_name = "Racal";
+	if (output->vendor == "RTL") vendor_name = "Realtek";
+	if (output->vendor == "SCM") vendor_name = "SCM";
+	if (output->vendor == "SKD") vendor_name = "SysKonnect";
+	if (output->vendor == "SGI") vendor_name = "SGI";
+	if (output->vendor == "SMC") vendor_name = "SMC";
+	if (output->vendor == "SNI") vendor_name = "Siemens Nixdorf";
+	if (output->vendor == "STL") vendor_name = "Stallion Technologies";
+	if (output->vendor == "SUN") vendor_name = "Sun";
+	if (output->vendor == "SUP") vendor_name = "SupraExpress";
+	if (output->vendor == "SVE") vendor_name = "SVEC";
+	if (output->vendor == "TCC") vendor_name = "Thomas-Conrad";
+	if (output->vendor == "TCI") vendor_name = "Tulip";
+	if (output->vendor == "TCM") vendor_name = "3Com";
+	if (output->vendor == "TCO") vendor_name = "Thomas-Conrad";
+	if (output->vendor == "TEC") vendor_name = "Tecmar";
+	if (output->vendor == "TRU") vendor_name = "Truevision";
+	if (output->vendor == "TOS") vendor_name = "Toshiba";
+	if (output->vendor == "TYN") vendor_name = "Tyan";
+	if (output->vendor == "UBI") vendor_name = "Ungermann-Bass";
+	if (output->vendor == "USC") vendor_name = "UltraStor";
+	if (output->vendor == "VDM") vendor_name = "Vadem";
+	if (output->vendor == "VMI") vendor_name = "Vermont";
+	if (output->vendor == "WDC") vendor_name = "Western Digital";
+	if (output->vendor == "ZDS") vendor_name = "Zeos";
+
+	/* From http://faydoc.tripod.com/structures/01/0136.htm */
+	if (output->vendor == "ACT") vendor_name = "Targa";
+	if (output->vendor == "ADI") vendor_name = "ADI";
+	if (output->vendor == "AOC") vendor_name = "AOC Intl";
+	if (output->vendor == "API") vendor_name = "Acer America";
+	if (output->vendor == "APP") vendor_name = "Apple Computer";
+	if (output->vendor == "ART") vendor_name = "ArtMedia";
+	if (output->vendor == "AST") vendor_name = "AST Research";
+	if (output->vendor == "CPL") vendor_name = "Compal";
+	if (output->vendor == "CTX") vendor_name = "Chuntex Electronic Co.";
+	if (output->vendor == "DPC") vendor_name = "Delta Electronics";
+	if (output->vendor == "DWE") vendor_name = "Daewoo";
+	if (output->vendor == "ECS") vendor_name = "ELITEGROUP";
+	if (output->vendor == "EIZ") vendor_name = "EIZO";
+	if (output->vendor == "FCM") vendor_name = "Funai";
+	if (output->vendor == "GSM") vendor_name = "LG Electronics";
+	if (output->vendor == "GWY") vendor_name = "Gateway 2000";
+	if (output->vendor == "HEI") vendor_name = "Hyundai";
+	if (output->vendor == "HIT") vendor_name = "Hitachi";
+	if (output->vendor == "HSL") vendor_name = "Hansol";
+	if (output->vendor == "HTC") vendor_name = "Hitachi";
+	if (output->vendor == "ICL") vendor_name = "Fujitsu ICL";
+	if (output->vendor == "IVM") vendor_name = "Idek Iiyama";
+	if (output->vendor == "KFC") vendor_name = "KFC Computek";
+	if (output->vendor == "LKM") vendor_name = "ADLAS";
+	if (output->vendor == "LNK") vendor_name = "LINK Tech";
+	if (output->vendor == "LTN") vendor_name = "Lite-On";
+	if (output->vendor == "MAG") vendor_name = "MAG InnoVision";
+	if (output->vendor == "MAX") vendor_name = "Maxdata";
+	if (output->vendor == "MEI") vendor_name = "Panasonic";
+	if (output->vendor == "MEL") vendor_name = "Mitsubishi";
+	if (output->vendor == "MIR") vendor_name = "miro";
+	if (output->vendor == "MTC") vendor_name = "MITAC";
+	if (output->vendor == "NAN") vendor_name = "NANAO";
+	if (output->vendor == "NEC") vendor_name = "NEC Tech";
+	if (output->vendor == "NOK") vendor_name = "Nokia";
+	if (output->vendor == "OQI") vendor_name = "OPTIQUEST";
+	if (output->vendor == "PBN") vendor_name = "Packard Bell";
+	if (output->vendor == "PGS") vendor_name = "Princeton";
+	if (output->vendor == "PHL") vendor_name = "Philips";
+	if (output->vendor == "REL") vendor_name = "Relisys";
+	if (output->vendor == "SDI") vendor_name = "Samtron";
+	if (output->vendor == "SMI") vendor_name = "Smile";
+	if (output->vendor == "SPT") vendor_name = "Sceptre";
+	if (output->vendor == "SRC") vendor_name = "Shamrock Technology";
+	if (output->vendor == "STP") vendor_name = "Sceptre";
+	if (output->vendor == "TAT") vendor_name = "Tatung";
+	if (output->vendor == "TRL") vendor_name = "Royal Information Company";
+	if (output->vendor == "TSB") vendor_name = "Toshiba, Inc.";
+	if (output->vendor == "UNM") vendor_name = "Unisys";
+	if (output->vendor == "VSC") vendor_name = "ViewSonic";
+	if (output->vendor == "WTC") vendor_name = "Wen Tech";
+	if (output->vendor == "ZCM") vendor_name = "Zenith Data Systems";
+
+	if (output->vendor == "???") vendor_name = "Unknown";
+
 
           ret = g_strdup_printf ("%s %s", vendor_name, inches);
 
