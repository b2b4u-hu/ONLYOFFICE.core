/* create opj_config_private.h for CMake */
#define OPJ_HAVE_INTTYPES_H 1

#define OPJ_PACKAGE_VERSION "2.4.0"

/* find whether or not have <malloc.h> */
#ifndef _MAC
#define OPJ_HAVE_MALLOC_H
#endif
/* check if function `aligned_alloc` exists */
#define OPJ_HAVE_ALIGNED_ALLOC
/* check if function `_aligned_malloc` exists */
#define OPJ_HAVE__ALIGNED_MALLOC
/* check if function `memalign` exists */
#ifndef _WIN32
#define OPJ_HAVE_MEMALIGN
#endif
/* check if function `posix_memalign` exists */
#ifdef _LINUX
#define OPJ_HAVE_POSIX_MEMALIGN
#endif

#if !defined(_POSIX_C_SOURCE)
#if defined(OPJ_HAVE_FSEEKO) || defined(OPJ_HAVE_POSIX_MEMALIGN)
/* Get declarations of fseeko, ftello, posix_memalign. */
#define _POSIX_C_SOURCE 200112L
#endif
#endif

/* Byte order.  */
/* All compilers that support Mac OS X define either __BIG_ENDIAN__ or
__LITTLE_ENDIAN__ to match the endianness of the architecture being
compiled for. This is not necessarily the same as the architecture of the
machine doing the building. In order to support Universal Binaries on
Mac OS X, we prefer those defines to decide the endianness.
On other platforms we use the result of the TRY_RUN. */
#if !defined(__APPLE__)
//#define OPJ_BIG_ENDIAN
#elif defined(__BIG_ENDIAN__)
# define OPJ_BIG_ENDIAN
#endif
