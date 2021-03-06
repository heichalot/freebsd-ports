--- ia32/include/yvals.h.orig	Sat Sep  6 11:58:50 2003
+++ ia32/include/yvals.h	Sat Sep  6 12:03:22 2003
@@ -1,93 +1,17 @@
-/* static char cvs_id[] = "$Id: yvals.h,v 1.35.2.3 2003/08/22 00:21:06 dlmoore2 Exp $"; */
+/* static char cvs_id[] = "$Id: yvals.h,v 1.35.2.1 2002/12/26 08:38:02 grigory Exp $"; */
 /* yvals.h values header for EDG/gcc on various Unix systems */
 #ifndef _YVALS
 #define _YVALS
 
-#define __need___va_list
-#include <stdarg.h>
-
-#include <features.h>	/* Get glibc version __GLIBC__ and __GLIBC_MINOR__*/
-#define __GLIBC_2_2     ((__GLIBC__ > 2) || ((__GLIBC__ >= 2) && (__GLIBC_MINOR__ >= 2)))
-			/* true if glibc-2.2 and older is used */
-
-#define _CPPLIB_VER	310
-
- #if defined(ia64) || defined(__ia64) || defined(__ia64__)	/* assume Itanium */
-  #define _D0		3	/* 0: big endian, 3: little endian floating-point */
-  #define _DLONG	1	/* 0: 64, 1: 80, 2: 128 long double bits */
-  #define _LBIAS	0x3ffe	/* 80/128 long double bits */
-  #define _LOFF		15	/* 80/128 long double bits */
-/*  #define _FPP_TYPE	1 */	/* 80287/Pentium FPP */
-
- #elif defined(i386) || defined(__i386) || defined(__i386__)	/* assume PC */
-  #define _D0		3	/* 0: big endian, 3: little endian floating-point */
-  #define _DLONG	1	/* 0: 64, 1: 80, 2: 128 long double bits */
-  #define _LBIAS	0x3ffe	/* 80/128 long double bits */
-  #define _LOFF		15	/* 80/128 long double bits */
-  #define _FPP_TYPE	1	/* 80287/Pentium FPP */
-
- #elif defined(sparc) || defined (__sparc)	/* assume SPARC */
-  #define _D0		0	/* 0: big endian, 3: little endian floating-point */
-  #define _DLONG	2	/* 0: 64, 1: 80, 2: 128 long double bits */
-  #define _LBIAS	0x3ffe	/* 80/128 long double bits */
-  #define _LOFF		15	/* 80/128 long double bits */
-  #define _FPP_TYPE	2	/* SPARC FPP */
-
- #elif defined(_POWER)		/* assume PowerPC */
-  #define _D0		0	/* 0: big endian, 3: little endian floating-point */
-  #define _DLONG	0	/* 0: 64, 1: 80, 2: 128 long double bits */
-  #define _LBIAS	0x3ffe	/* 80/128 long double bits */
-  #define _LOFF		15	/* 80/128 long double bits */
-  #define _FPP_TYPE	3	/* MIPS FPP */
-
-  #define _PDT	long
-  #define _SZT	unsigned long
-
- #elif defined(__hppa)	/* assume HP PA-RISC */
-  #define _D0		0	/* 0: big endian, 3: little endian floating-point */
-  #define _DLONG	2	/* 0: 64, 1: 80, 2: 128 long double bits */
-  #define _LBIAS	0x3ffe	/* 80/128 long double bits */
-  #define _LOFF		15	/* 80/128 long double bits */
-  #define _FPP_TYPE	4	/* HP PA-RISC FPP */
-
- #else /* system detector */
-  #error /* unknown compilation environment */
- #endif /* system detector */
-
- #ifdef __linux
-  #define _LINUX_C_LIB	1	/* assume Linux-specific conventions */
- #endif /* __linux */
-
 		/* NAMING PROPERTIES */
-/* #define _STD_LINKAGE	defines C names as extern "C++" */
- #ifdef __SUNPRO_CC
-  #define _STD_USING	/* exports C names from std to global, else reversed */
- #endif /* __SUNPRO_CC */
-
-#define _USE_EXISTING_SYSTEM_NAMES	1 /* _Open => open etc. */
 #define _POSIX_C_LIB	1	/* use common Unix/Linux conventions */
-#define _SOLARIS_C_LIB	1	/* add declarations for C extensions */
-
- #if __EDG__
-  #define _HAS_STRICT_LINKAGE	1	/* extern "C" in function type */
- #else /* __EDG__ */
-  #define _HAS_STRICT_LINKAGE	0	/* extern "C" in function type */
- #endif /* __EDG__ */
 
 		/* THREAD AND LOCALE CONTROL */
  #ifndef _MULTI_THREAD
   #define _MULTI_THREAD	1	/* 0 for no locks, 1 for multithreaded library */
  #endif /* _MULTI_THREAD */
- #ifndef _IOSTREAM_OP_LOCKS
-  #define _IOSTREAM_OP_LOCKS	1
- #endif /* _MULTI_THREAD */
-#define _GLOBAL_LOCALE	0	/* 0 for per-thread locales, 1 for shared */
-#define _FILE_OP_LOCKS	0	/* 0 for no file atomic locks, 1 for atomic */
 
 		/* THREAD-LOCAL STORAGE */
-#define _COMPILER_TLS	0	/* 1 if compiler supports TLS directly */
-#define _TLS_QUAL	/* TLS qualifier, such as __declspec(thread), if any */
-
  #define _HAS_TRADITIONAL_IOSTREAMS	1
  #define _HAS_TRADITIONAL_ITERATORS	1
  #define _HAS_TRADITIONAL_POS_TYPE	1
@@ -134,211 +58,8 @@
 
  #define _Restrict
 
- #ifdef __cplusplus
-_STD_BEGIN
-typedef bool _Bool;
-_STD_END
- #endif /* __cplusplus */
-
-		/* VC++ COMPILER PARAMETERS */
-#define _CRTIMP
-#define _CDECL
-
-#define _LONGLONG	long long
-#define _ULONGLONG	unsigned long long
-#define _LLONG_MAX	0x7fffffffffffffffLL
-#define _ULLONG_MAX	0xffffffffffffffffULL
-
-_C_STD_BEGIN
-		/* errno PROPERTIES */
-#define _EDOM	33
-#define _ERANGE	34
-#define _EFPOS	152
-#define _EILSEQ	99
-#define _ERRMAX	152
-
-		/* FLOATING-POINT PROPERTIES */
-#define _DBIAS	0x3fe	/* IEEE format double and float */
-#define _DOFF	4
-#define _FBIAS	0x7e
-#define _FOFF	7
-#define _FRND	1
-
-		/* INTEGER PROPERTIES */
-#define _BITS_BYTE	8
-#define _C2			1	/* 0 if not 2's complement */
-#define _CSIGN		1	/* 0 if char is not signed */
-#define _MBMAX		8	/* MB_LEN_MAX */
-
-#define _MAX_EXP_DIG	8	/* for parsing numerics */
-#define _MAX_INT_DIG	32
-#define _MAX_SIG_DIG	36
-
- #ifdef _LONGLONG
-typedef _LONGLONG _Longlong;
-typedef _ULONGLONG _ULonglong;
- #else /* _LONGLONG */
-typedef long _Longlong;
-typedef unsigned long _ULonglong;
-#ifndef _M_IA64
- #define _LLONG_MAX	0x7fffffffL
- #define _ULLONG_MAX	0xffffffffUL
-#else
- #define _LLONG_MAX	0x7fffffffffffffffLL
- #define _ULLONG_MAX	0xffffffffffffffffULL
-#endif
- #endif /* _LONGLONG */
-
- #ifdef __CYGWIN__
-  #define _WCMAX	0x7fff
-  #ifdef __cplusplus
-    #ifdef _HAS_WCHAR_TYPE
-      #define _WCHART
-typedef wchar_t _Wchart;
-typedef wchar_t _Wintt;
-    #else /* _HAS_WCHAR_TYPE */
-typedef short _Wchart;
-typedef short _Wintt;
-    #endif /* _HAS_WCHAR_TYPE */
-  #else /* __cplusplus */
-typedef short _Wchart;
-typedef short _Wintt;
-  #endif /* __cplusplus */
-
- #else /* __CYGWIN__ */
-  #define _WCMAX	0x7fffffff
-  #ifdef __cplusplus
-    #ifdef _HAS_WCHAR_TYPE
-      #define _WCHART
-typedef wchar_t _Wchart;
-typedef wchar_t _Wintt;
-    #else /* _HAS_WCHAR_TYPE */
-typedef __WCHAR_TYPE__ _Wchart;
-typedef int _Wintt;
-    #endif /* _HAS_WCHAR_TYPE */
-  #else /* __cplusplus */
-typedef __WCHAR_TYPE__ _Wchart;
-typedef int _Wintt;
-  #endif /* __cplusplus */
- #endif /* __CYGWIN__ */
-
-#define _WCMIN		0
-#define _ILONG		1	/* 0 if 16-bit int */
-
-		/* POINTER PROPERTIES */
-
- #ifdef _PDT
-typedef _PDT _Ptrdifft;
- #else /* _PDT */
-typedef __PTRDIFF_TYPE__ _Ptrdifft;
- #endif /* _PDT */
-
- #ifdef _SZT
-typedef _SZT _Sizet;
- #else /* _SZT */
-typedef __SIZE_TYPE__	 _Sizet;
- #endif /* _SZT */
-
-		/* signal PROPERTIES */
-#define _SIGABRT	6
-#define _SIGMAX		44
-
-		/* stdarg PROPERTIES */
-typedef va_list _Va_list;
- #if __EDG__
-  #undef va_copy
- #endif /* __EDG__ */
-#ifndef va_copy
- #define va_copy(dest, src)	((dest) = (src))
-#endif /* va_copy */
-
-		/* stdlib PROPERTIES */
-#define _EXFAIL	1	/* EXIT_FAILURE */
-
-_EXTERN_C
-void _Atexit(void (*)(void));
-_END_EXTERN_C
-
-typedef struct _Mbstatet
-	{	/* state of a multibyte translation */
-	unsigned long _Wchar;
-	unsigned short _Byte, _State;
-	} _Mbstatet;
-
-		/* stdio PROPERTIES */
-#define _FNAMAX	64
-#define _FOPMAX	16
-#define _TNAMAX	16
-
-#define _Filet FILE
-
-typedef struct _Fpost
-	{	/* file position */
-	long _Off;	/* can be system dependent */
-	_Mbstatet _Wstate;
-	} _Fpost;
-
-#ifndef _FPOSOFF
- #ifdef __sun
-  #define _FPOSOFF(fp)	((long)(fp))
- #else /* __sun */
-  #if __GLIBC_2_2
-   #define _FPOSOFF(fp)	((long)(fp.__pos))
-  #else
-   #define _FPOSOFF(fp)	((long)(fp))
-  #endif
- #endif /* __sun */
-#endif
-
-#define _FD_VALID(fd)	(0 <= (fd))	/* fd is signed integer */
-#define _FD_INVALID		(-1)
-
-		/* STORAGE ALIGNMENT PROPERTIES */
-#define _MEMBND	3U /* eight-byte boundaries (2^^3) */
-
-		/* time PROPERTIES */
-#define _TBIAS	((70 * 365LU + 17) * 86400)
-_C_STD_END
-
-		/* MULTITHREAD PROPERTIES */
- #if _MULTI_THREAD
-_EXTERN_C
-void _Locksyslock(unsigned int);
-void _Unlocksyslock(unsigned int);
-_END_EXTERN_C
-
- #else /* _MULTI_THREAD */
-  #define _Locksyslock(x)	(void)0
-  #define _Unlocksyslock(x)	(void)0
- #endif /* _MULTI_THREAD */
-
-		/* LOCK MACROS */
- #define _LOCK_LOCALE	0
- #define _LOCK_MALLOC	1
- #define _LOCK_STREAM	2
- #define _LOCK_DEBUG	3
- #define _MAX_LOCK		4	/* one more than highest lock number */
-
-
-
-		/* MISCELLANEOUS MACROS */
-#define _ATEXIT_T	void
-#define _Mbstinit(x)	mbstate_t x = {0, 0}
-
-#define _MAX	(max)
-#define _MIN	(min)
-
 #define _TEMPLATE_STAT
 
- #ifdef __SUNPRO_CC
-  #define __EDG__	1	/* close enough for Sun compiler, hereafter */
- #endif /* __SUNPRO_CC */
-
- #if __EDG__
-  #define _NO_RETURN
- #else /* __EDG__ */
-  #define _NO_RETURN	__attribute__((__noreturn__))
- #endif /* __EDG__ */
 #endif /* _YVALS */
 
 /*
