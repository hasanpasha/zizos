/***************************************************************************
 * FILE: string.h/cstring (String functions)
 *
 * =========================================================================
 *
 *                          Open Watcom Project
 *
 * Copyright (c) 2004-2024 The Open Watcom Contributors. All Rights Reserved.
 * Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
 *
 *    This file is automatically generated. Do not edit directly.
 *
 * =========================================================================
 *
 * Description: This header is part of the C/C++ standard library. It
 *              declares functions for manipulating null terminated arrays
 *              of characters.
 ***************************************************************************/
#ifndef _STRING_H_INCLUDED
#define _STRING_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus

#include <cstring>

// C99 types in string.h.
#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
 #define _SIZE_T_DEFINED_
 using std::size_t;
#endif
#ifndef _WINT_T_DEFINED
#define _WINT_T_DEFINED
 #define _WINT_T_DEFINED_
 using std::wint_t;
#endif

// C99 functions in string.h
using std::memchr;
using std::memcmp;
using std::memcpy;
using std::memmove;
using std::memset;
using std::strcat;
using std::strchr;
using std::strcmp;
using std::strcoll;
using std::strcpy;
using std::strcspn;
using std::strerror;
using std::strlen;
using std::strncat;
using std::strncmp;
using std::strncpy;
using std::strpbrk;
using std::strrchr;
using std::strspn;
using std::strstr;
using std::strtok;
using std::strxfrm;

// C99 functions not officially in string.h
#if !defined( _NO_EXT_KEYS ) /* extensions enabled */
using std::wcscat;
using std::wcschr;
using std::wcscmp;
using std::wcscoll;
using std::wcscpy;
using std::wcscspn;
using std::wcslen;
using std::wcsncat;
using std::wcsncmp;
using std::wcsncpy;
using std::wcspbrk;
using std::wcsrchr;
using std::wcsspn;
using std::wcsstr;
using std::wcstok;
using std::wcsxfrm;
#endif /* extensions enabled */

#else /* __cplusplus not defined */

#ifndef __COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

 #ifndef _WCHAR_T_DEFINED
 #define _WCHAR_T_DEFINED
  #define _WCHAR_T_DEFINED_
  typedef unsigned short wchar_t;
 #endif

 #ifndef _WINT_T_DEFINED
 #define _WINT_T_DEFINED
  #define _WINT_T_DEFINED_
  typedef unsigned short wint_t;
  typedef wint_t __w_wint_t;
 #endif

 #ifndef _SIZE_T_DEFINED
 #define _SIZE_T_DEFINED
  #define _SIZE_T_DEFINED_
  typedef unsigned size_t;
  typedef size_t   __w_size_t;
 #endif

#ifndef NULL
 #ifdef __RDOSDEV__
  #define NULL 0
 #else
  #define NULL ((void *)0)
 #endif
#endif

#ifndef _NLSCMPERROR
 /* For MS compatibility, equal to INT_MAX */
 #define _NLSCMPERROR ((int)((unsigned int)~0 >> 1))
#endif

_WCIRTLINK extern void      *memchr( const void *__s, int __c, size_t __n );
_WCIRTLINK extern int       memcmp( const void *__s1, const void *__s2, size_t __n );
_WCIRTLINK extern void      *memcpy( void *__s1, const void *__s2, size_t __n );
_WCRTLINK  extern void      *memmove( void *__s1, const void *__s2, size_t __n );
#ifdef _M_I86
_WCIRTLINK extern void      *memset( void *__s, int __c, size_t __n );
#else
_WCRTLINK  extern void      *memset( void *__s, int __c, size_t __n );
#endif
_WCIRTLINK extern char      *strcat( char *__s1, const char *__s2 );
_WCIRTLINK extern char      *strchr( const char *__s, int __c );
#ifdef _M_I86
_WCIRTLINK extern int       strcmp( const char *__s1, const char *__s2 );
#else
_WCRTLINK  extern int       strcmp( const char *__s1, const char *__s2 );
#endif
_WCRTLINK  extern int       strcoll( const char *__s1, const char *__s2 );
_WCIRTLINK extern char      *strcpy( char *__s1, const char *__s2 );
_WCRTLINK  extern size_t    strcspn( const char *__s1, const char *__s2 );
_WCIRTLINK extern size_t    strlen( const char *__s );
_WCRTLINK  extern char      *strncat( char *__s1, const char *__s2, size_t __n );
_WCRTLINK  extern int       strncmp( const char *__s1, const char *__s2, size_t __n );
_WCRTLINK  extern char      *strncpy( char *__s1, const char *__s2, size_t __n );
_WCRTLINK  extern char      *strpbrk( const char *__s1, const char *__s2 );
_WCRTLINK  extern char      *strrchr( const char *__s, int __c );
_WCRTLINK  extern size_t    strspn( const char *__s1, const char *__s2 );
_WCRTLINK  extern char      *strstr( const char *__s1, const char *__s2 );
_WCRTLINK  extern char      *strtok( char *__s1, const char *__s2 );
_WCRTLINK  extern size_t    strxfrm( char *__s1, const char *__s2, size_t __n );

_WCRTLINK extern char       *strerror( int __errnum );

#if !defined( _NO_EXT_KEYS ) /* extensions enabled */

/* MS extension functions */

_WCRTLINK extern int        strcmpi( const char *__s1, const char *__s2 );
_WCRTLINK extern char       *strnset( char *__string, int __c, __w_size_t __len );
_WCRTLINK extern int        strnicmp( const char *__s1, const char *__s2, __w_size_t __n );
_WCRTLINK extern char       *strlwr( char *__string );
_WCRTLINK extern char       *strupr( char *__string );
_WCRTLINK extern int        stricmp( const char *__s1, const char *__s2 );
_WCRTLINK extern char       *strrev( char *__string );
_WCRTLINK extern char       *strset( char *__string, int __c );
_WCRTLINK extern int        memicmp( const void *__s1, const void *__s2, __w_size_t __n );
_WCRTLINK extern int        _stricoll( const char *__s1, const char *__s2 );
_WCRTLINK extern int        _strncoll( const char *__s1, const char *__s2, __w_size_t __n );
_WCRTLINK extern int        _strnicoll( const char *__s1, const char *__s2, __w_size_t __n );
_WCRTLINK extern char       *_strnset( char *__string, int __c, __w_size_t __len );
_WCRTLINK extern int        _strnicmp( const char *__s1, const char *__s2, __w_size_t __n );
_WCRTLINK extern char       *_strlwr( char *__string );
_WCRTLINK extern char       *_strupr( char *__string );
_WCRTLINK extern int        _stricmp( const char *__s1, const char *__s2 );
_WCRTLINK extern char       *_strrev( char *__string );
_WCRTLINK extern char       *_strset( char *__string, int __c );
_WCRTLINK extern char       *_strerror( const char *__s );
_WCRTLINK extern char       *_strdup( const char *__string );
_WCRTLINK extern int        _memicmp( const void *__s1, const void *__s2, __w_size_t __n );
_WCRTLINK extern void       *_memccpy( void *__s1, const void *__s2, int __c, __w_size_t __n );

/* POSIX extension functions */

_WCRTLINK extern char       *strdup( const char *__string );
_WCRTLINK extern void       *memccpy( void *__s1, const void *__s2, int __c, __w_size_t __n );

/* WATCOM's Additional Functions (non-ISO, non-POSIX) */

#ifdef __NT__
_WCRTLINK extern char       *_doserror( int __oserrnum );
#endif
_WCRTLINK  extern char      *strspnp( const char *__s1, const char *__s2 );
_WCRTLINK  extern char      *strtok_r( char *__s1, const char *__s2, char **__p1 );

/* Far version of functions */

#ifndef _INC_WINDOWSX
_WCRTLINK extern void _WCFAR *_fmemccpy( void _WCFAR *__s1, const void _WCFAR *__s2, int __c, __w_size_t __n );
_WCIRTLINK extern void _WCFAR *_fmemchr( const void _WCFAR *__s, int __c, __w_size_t __n );
_WCIRTLINK extern int _fmemcmp( const void _WCFAR *__s1, const void _WCFAR *__s2, __w_size_t __n );
_WCIRTLINK extern void _WCFAR *_fmemcpy( void _WCFAR *__s1, const void _WCFAR *__s2, __w_size_t __n );
_WCRTLINK extern int _fmemicmp( const void _WCFAR *__s1, const void _WCFAR *__s2, __w_size_t __n );
_WCRTLINK extern void _WCFAR *_fmemmove( void _WCFAR *__s1, const void _WCFAR *__s2, __w_size_t __n );
_WCIRTLINK extern void _WCFAR *_fmemset( void _WCFAR *__s, int __c, __w_size_t __n );
_WCIRTLINK extern char _WCFAR *_fstrcat( char _WCFAR *__s1, const char _WCFAR *__s2 );
_WCRTLINK extern char _WCFAR *_fstrchr( const char _WCFAR *__s, int __c );
_WCIRTLINK extern int _fstrcmp( const char _WCFAR *__s1, const char _WCFAR *__s2 );
_WCIRTLINK extern char _WCFAR *_fstrcpy( char _WCFAR *__s1, const char _WCFAR *__s2 );
_WCRTLINK extern __w_size_t _fstrcspn( const char _WCFAR *__s1, const char _WCFAR *__s2 );
_WCRTLINK extern char _WCFAR *_fstrdup( const char _WCFAR *__string );
_WCRTLINK extern int _fstricmp( const char _WCFAR *__s1, const char _WCFAR *__s2 );
_WCIRTLINK extern __w_size_t _fstrlen( const char _WCFAR *__s );
_WCRTLINK extern char _WCFAR *_fstrlwr( char _WCFAR *__string );
_WCRTLINK extern char _WCFAR *_fstrncat( char _WCFAR *__s1, const char _WCFAR *__s2, __w_size_t __n );
_WCRTLINK extern int _fstrncmp( const char _WCFAR *__s1, const char _WCFAR *__s2, __w_size_t __n );
_WCRTLINK extern char _WCFAR *_fstrncpy( char _WCFAR *__s1, const char _WCFAR *__s2, __w_size_t __n );
_WCRTLINK extern int _fstrnicmp( const char _WCFAR *__s1, const char _WCFAR *__s2, __w_size_t __n );
_WCRTLINK extern char _WCFAR *_fstrnset( char _WCFAR *__string, int __c, __w_size_t __len );
_WCRTLINK extern char _WCFAR *_fstrpbrk( const char _WCFAR *__s1, const char _WCFAR *__s2 );
_WCRTLINK extern char _WCFAR *_fstrrchr( const char _WCFAR *__s, int __c );
_WCRTLINK extern char _WCFAR *_fstrrev( char _WCFAR *__string );
_WCRTLINK extern char _WCFAR *_fstrset( char _WCFAR *__string, int __c );
_WCRTLINK extern __w_size_t _fstrspn( const char _WCFAR *__s1, const char _WCFAR *__s2 );
_WCRTLINK extern char _WCFAR *_fstrstr( const char _WCFAR *__s1, const char _WCFAR *__s2 );
_WCRTLINK extern char _WCFAR *_fstrtok( char _WCFAR *__s1, const char _WCFAR *__s2 );
_WCRTLINK extern char _WCFAR *_fstrupr( char _WCFAR *__string );
_WCRTLINK extern char _WCFAR *_fstrspnp( const char _WCFAR *__s1, const char _WCFAR *__s2 );
_WCRTLINK extern char _WCFAR *_fstrtok_r( char _WCFAR *__str, const char _WCFAR *__charset, char _WCFAR **__ptr );
#endif

_WCIRTLINK extern void      movedata( unsigned __srcseg, unsigned __srcoff, unsigned __tgtseg, unsigned __tgtoff, unsigned __len );

/* BSD 'safe' string copy functions */

_WCRTLINK extern __w_size_t strlcat( char *__s1, const char *__s2, __w_size_t __n );
_WCRTLINK extern __w_size_t strlcpy( char *__s1, const char *__s2, __w_size_t __n );

/* Wide character handling functions */

// C99 functions not officially in string.h
_WCRTLINK extern wchar_t    *wcscat( wchar_t *, const wchar_t * );
_WCRTLINK extern wchar_t    *wcschr( const wchar_t *, wint_t );
_WCRTLINK extern int        wcscmp( const wchar_t *, const wchar_t * );
_WCRTLINK extern int        wcscoll( const wchar_t *__s1, const wchar_t *__s2 );
_WCRTLINK extern wchar_t    *wcscpy( wchar_t *, const wchar_t * );
_WCRTLINK extern size_t     wcscspn( const wchar_t *, const wchar_t * );
_WCRTLINK extern size_t     wcslen( const wchar_t * );
_WCRTLINK extern wchar_t    *wcsncat( wchar_t *, const wchar_t *, size_t );
_WCRTLINK extern int        wcsncmp( const wchar_t *, const wchar_t *, size_t );
_WCRTLINK extern wchar_t    *wcsncpy( wchar_t *, const wchar_t *, size_t );
_WCRTLINK extern wchar_t    *wcspbrk( const wchar_t *, const wchar_t * );
_WCRTLINK extern wchar_t    *wcsrchr( const wchar_t *, wint_t );
_WCRTLINK extern size_t     wcsspn( const wchar_t *, const wchar_t * );
_WCRTLINK extern wchar_t    *wcsstr( const wchar_t *, const wchar_t * );
_WCRTLINK extern wchar_t    *wcstok( wchar_t *, const wchar_t *, wchar_t ** );
_WCRTLINK extern size_t     wcsxfrm( wchar_t *__s1, const wchar_t *__s2, size_t __n );

/* MS extension functions */

_WCRTLINK extern wchar_t    *_wcserror( int __errnum );
_WCRTLINK extern wchar_t    *__wcserror( const wchar_t * );
_WCRTLINK extern wchar_t    *_wcsnset( wchar_t *, int, __w_size_t );
_WCRTLINK extern int        _wcsnicmp( const wchar_t *, const wchar_t *, __w_size_t );
_WCRTLINK extern wchar_t    *_wcslwr( wchar_t * );
_WCRTLINK extern wchar_t    *_wcsupr( wchar_t * );
_WCRTLINK extern int        _wcsicmp( const wchar_t *, const wchar_t * );
_WCRTLINK extern wchar_t    *_wcsrev( wchar_t * );
_WCRTLINK extern wchar_t    *_wcsset( wchar_t *, wchar_t );

_WCRTLINK extern int        _wcsicoll( const wchar_t *__s1, const wchar_t *__s2 );
_WCRTLINK extern int        _wcsncoll( const wchar_t *__s1, const wchar_t *__s2, __w_size_t __n );
_WCRTLINK extern int        _wcsnicoll( const wchar_t *__s1, const wchar_t *__s2, __w_size_t __n );
_WCRTLINK extern wchar_t    *_wcsdup( const wchar_t * );

/* POSIX extension functions */

_WCRTLINK extern wchar_t    *wcsdup( const wchar_t * );

/* WATCOM's Additional Functions (non-ISO, non-POSIX) */

#ifdef __NT__
_WCRTLINK extern wchar_t    *_wdoserror( int __errnum );
#endif

#endif /* extensions enabled */

#ifdef  __INLINE_FUNCTIONS__

#if !defined( _NO_EXT_KEYS ) /* extensions enabled */
 #pragma intrinsic(movedata,_fmemchr,_fmemcmp,_fmemcpy,_fmemset)
 #pragma intrinsic(_fstrcat,_fstrcmp,_fstrcpy,_fstrlen)
#endif /* extensions enabled */

 #pragma intrinsic(memchr,memcmp,memcpy,strcat,strcpy,strlen,strchr)
 #ifdef _M_I86
  #pragma intrinsic(memset,strcmp)
 #endif

#endif  /* __INLINE_FUNCTIONS__ */

#if defined(__STDC_WANT_LIB_EXT1__) && __STDC_WANT_LIB_EXT1__ == 1

#ifndef _ERRNO_T_DEFINED
 #define _ERRNO_T_DEFINED
 typedef int errno_t;
#endif

#ifndef _RSIZE_T_DEFINED
#define _RSIZE_T_DEFINED
 typedef size_t rsize_t;
#endif

_WCRTLINK extern errno_t    memcpy_s( void * __restrict __s1, rsize_t __s1max, const void * __restrict __s2, rsize_t __n );
_WCRTLINK extern errno_t    memmove_s( void *__s1, rsize_t __s1max, const void *__s2, rsize_t __n );
_WCRTLINK extern errno_t    strcpy_s( char * __restrict __s1, rsize_t __s1max, const char * __restrict __s2 );
_WCRTLINK extern errno_t    strncpy_s( char * __restrict s1, rsize_t __s1max, const char * __restrict __s2, rsize_t __n );
_WCRTLINK extern errno_t    strcat_s( char * __restrict __s1, rsize_t __s1max, const char * __restrict __s2 );
_WCRTLINK extern errno_t    strncat_s( char * __restrict __s1, rsize_t __s1max, const char * __restrict __s2, rsize_t __n );
_WCRTLINK extern char       *strtok_s( char * __restrict __s1, rsize_t * __restrict __s1max, const char * __restrict __s2, char ** __restrict __ptr );
_WCRTLINK extern errno_t    strerror_s( char *__s, rsize_t __maxsize, errno_t __errnum );
_WCRTLINK extern size_t     strerrorlen_s( errno_t __errnum );
_WCRTLINK extern size_t     strnlen_s( const char *__s, size_t __maxsize );

#endif /* __STDC_WANT_LIB_EXT1__ */

#endif /* __cplusplus not defined */

#endif
