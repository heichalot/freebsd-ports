--- ./setup.py.orig	2010-01-05 11:40:22.000000000 +0100
+++ ./setup.py	2010-01-05 11:40:57.000000000 +0100
@@ -42,7 +42,7 @@
 setup(
     name = 'scapy',
     version = '2.1.0', 
-    packages=['scapy','scapy/arch', 'scapy/arch/windows', 'scapy/layers','scapy/asn1','scapy/tools','scapy/modules', 'scapy/crypto'],
+    packages=['scapy','scapy/arch','scapy/layers','scapy/asn1','scapy/tools','scapy/modules', 'scapy/crypto'],
     scripts = SCRIPTS,
     data_files = [('share/man/man1', ["doc/scapy.1.gz"])],
 
