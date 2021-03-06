--- ./devtools/M4/UNIX/sharedlib.m4.orig	2006-09-06 07:56:53.000000000 +0900
+++ ./devtools/M4/UNIX/sharedlib.m4	2008-01-20 07:37:08.000000000 +0900
@@ -55,8 +55,9 @@
 install-`'bldCURRENT_PRODUCT: ${SHAREDLIB}
 	ifdef(`confMKDIR', `if [ ! -d ${DESTDIR}${SHAREDLIBDIR} ]; then confMKDIR -p ${DESTDIR}${SHAREDLIBDIR}; else :; fi ')
 	${INSTALL} -c -o ${LIBOWN} -g ${LIBGRP} -m ${LIBMODE} ${SHAREDLIB} ${DESTDIR}${SHAREDLIBDIR}
+	${INSTALL} -c -o ${LIBOWN} -g ${LIBGRP} -m ${LIBMODE} bldCURRENT_PRODUCT.a ${DESTDIR}${LIBDIR}
 	ifelse(bldOS, `AIX', `${AR} ${AROPTS} ${DESTDIR}${SHAREDLIBDIR}bldCURRENT_PRODUCT.a ${SHAREDLIB}', `rm -f ${DESTDIR}${SHAREDLIBDIR}${SHAREDLIB_LINK}
-	${LN} ${LNOPTS} ${DESTDIR}${SHAREDLIBDIR}${SHAREDLIB} ${DESTDIR}${SHAREDLIBDIR}${SHAREDLIB_LINK}')
+	${LN} ${LNOPTS} ${DESTDIR}${SHAREDLIBDIR}/${SHAREDLIB} ${DESTDIR}${SHAREDLIBDIR}/${SHAREDLIB_LINK}')
 
 bldCURRENT_PRODUCT-clean:
 	rm -f ${OBJS} ${SHAREDLIB} bldCURRENT_PRODUCT.a ${MANPAGES} ifelse(bldOS, `AIX', `shr.o', `bldCURRENT_PRODUCT${SHAREDLIB_EXT}')
