#ifndef _PLATFORM_H
#define _PLATFORM_H

#ifdef U_EXPORT
/* Use the predefined value. */
#elif defined(U_STATIC_IMPLEMENTATION)
#   define U_EXPORT
#elif defined(__GNUC__)
#   define U_EXPORT __attribute__((visibility("default")))
#elif (defined(__SUNPRO_CC) && __SUNPRO_CC >= 0x550) \
   || (defined(__SUNPRO_C) && __SUNPRO_C >= 0x550)
#   define U_EXPORT __global
/*#elif defined(__HP_aCC) || defined(__HP_cc)
#   define U_EXPORT __declspec(dllexport)*/
#elif defined(_MSC_VER)
#   define U_EXPORT __declspec(dllexport)
#else
#   define U_EXPORT
#endif

/* U_CALLCONV is releated to U_EXPORT2 */
#ifdef U_EXPORT2
/* Use the predefined value. */
#elif defined(_MSC_VER)
#   define U_EXPORT2 __cdecl
#else
#   define U_EXPORT2
#endif

#ifdef U_IMPORT
/* Use the predefined value. */
#elif defined(_MSC_VER)
/* Windows needs to export/import data. */
#   define U_IMPORT __declspec(dllimport)
#else
#   define U_IMPORT
#endif


/**
 * \def U_PLATFORM
 * The U_PLATFORM macro defines the platform we're on.
 *
 * We used to define one different, value-less macro per platform.
 * That made it hard to know the set of relevant platforms and macros,
 * and hard to deal with variants of platforms.
 *
 * Starting with ICU 49, we define platforms as numeric macros,
 * with ranges of values for related platforms and their variants.
 * The U_PLATFORM macro is set to one of these values.
 *
 * Historical note from the Solaris Wikipedia article:
 * AT&T and Sun collaborated on a project to merge the most popular Unix variants
 * on the market at that time: BSD, System V, and Xenix.
 * This became Unix System V Release 4 (SVR4).
 *
 * @internal
 */

/** Unknown platform. @internal */
#define U_PF_UNKNOWN 0
/** Windows @internal */
#define U_PF_WINDOWS 1000
/** MinGW. Windows, calls to Win32 API, but using GNU gcc and binutils. @internal */
#define U_PF_MINGW 1800
/**
 * Cygwin. Windows, calls to cygwin1.dll for Posix functions,
 * using MSVC or GNU gcc and binutils.
 * @internal
 */
#define U_PF_CYGWIN 1900
/* Reserve 2000 for U_PF_UNIX? */
/** HP-UX is based on UNIX System V. @internal */
#define U_PF_HPUX 2100
/** Solaris is a Unix operating system based on SVR4. @internal */
#define U_PF_SOLARIS 2600
/** BSD is a UNIX operating system derivative. @internal */
#define U_PF_BSD 3000
/** AIX is based on UNIX System V Releases and 4.3 BSD. @internal */
#define U_PF_AIX 3100
/** IRIX is based on UNIX System V with BSD extensions. @internal */
#define U_PF_IRIX 3200
/**
 * Darwin is a POSIX-compliant operating system, composed of code developed by Apple,
 * as well as code derived from NeXTSTEP, BSD, and other projects,
 * built around the Mach kernel.
 * Darwin forms the core set of components upon which Mac OS X, Apple TV, and iOS are based.
 * (Original description modified from WikiPedia.)
 * @internal
 */
#define U_PF_DARWIN 3500
/** iPhone OS (iOS) is a derivative of Mac OS X. @internal */
#define U_PF_IPHONE 3550
/** QNX is a commercial Unix-like real-time operating system related to BSD. @internal */
#define U_PF_QNX 3700
/** Linux is a Unix-like operating system. @internal */
#define U_PF_LINUX 4000
/**
 * Native Client is pretty close to Linux.
 * See https://developer.chrome.com/native-client and
 *  http://www.chromium.org/nativeclient
 *  @internal
 */
#define U_PF_BROWSER_NATIVE_CLIENT 4020
/** Android is based on Linux. @internal */
#define U_PF_ANDROID 4050
/* Maximum value for Linux-based platform is 4499 */
/** z/OS is the successor to OS/390 which was the successor to MVS. @internal */
#define U_PF_OS390 9000
/** "IBM i" is the current name of what used to be i5/OS and earlier OS/400. @internal */
#define U_PF_OS400 9400

#ifdef U_PLATFORM
/* Use the predefined value. */
#elif defined(__MINGW32__)
#   define U_PLATFORM U_PF_MINGW
#elif defined(__CYGWIN__)
#   define U_PLATFORM U_PF_CYGWIN
#elif defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#   define U_PLATFORM U_PF_WINDOWS
#elif defined(__ANDROID__)
#   define U_PLATFORM U_PF_ANDROID
/* Android wchar_t support depends on the API level. */
#   include <android/api-level.h>
#elif defined(__pnacl__) || defined(__native_client__)
#   define U_PLATFORM U_PF_BROWSER_NATIVE_CLIENT
#elif defined(linux) || defined(__linux__) || defined(__linux)
#   define U_PLATFORM U_PF_LINUX
#elif defined(__APPLE__) && defined(__MACH__)
#   include <TargetConditionals.h>
#   if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE  /* variant of TARGET_OS_MAC */
#       define U_PLATFORM U_PF_IPHONE
#   else
#       define U_PLATFORM U_PF_DARWIN
#   endif
#elif defined(BSD) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__MirBSD__)
#   if defined(__FreeBSD__)
#       include <sys/endian.h>
#   endif
#   define U_PLATFORM U_PF_BSD
#elif defined(sun) || defined(__sun)
/* Check defined(__SVR4) || defined(__svr4__) to distinguish Solaris from SunOS? */
#   define U_PLATFORM U_PF_SOLARIS
#   if defined(__GNUC__)
/* Solaris/GCC needs this header file to get the proper endianness. Normally, this
 * header file is included with stddef.h but on Solairs/GCC, the GCC version of stddef.h
 *  is included which does not include this header file.
 */
#       include <sys/isa_defs.h>
#   endif
#elif defined(_AIX) || defined(__TOS_AIX__)
#   define U_PLATFORM U_PF_AIX
#elif defined(_hpux) || defined(hpux) || defined(__hpux)
#   define U_PLATFORM U_PF_HPUX
#elif defined(sgi) || defined(__sgi)
#   define U_PLATFORM U_PF_IRIX
#elif defined(__QNX__) || defined(__QNXNTO__)
#   define U_PLATFORM U_PF_QNX
#elif defined(__TOS_MVS__)
#   define U_PLATFORM U_PF_OS390
#elif defined(__OS400__) || defined(__TOS_OS400__)
#   define U_PLATFORM U_PF_OS400
#else
#   define U_PLATFORM U_PF_UNKNOWN
#endif

/**
* \def U_CALLCONV
* Similar to U_CDECL_BEGIN/U_CDECL_END, this qualifier is necessary
* in callback function typedefs to make sure that the calling convention
* is compatible.
*
* This is only used for non-ICU-API functions.
* When a function is a public ICU API,
* you must use the U_CAPI and U_EXPORT2 qualifiers.
*
* Please note, you need to use U_CALLCONV after the *.
*
* NO : "static const char U_CALLCONV *func( . . . )"
* YES: "static const char* U_CALLCONV func( . . . )"
*
* @stable ICU 2.0
*/
#if U_PLATFORM == U_PF_OS390 && defined(__cplusplus)
#    define U_CALLCONV __cdecl
#else
#    define U_CALLCONV U_EXPORT2
#endif

#endif