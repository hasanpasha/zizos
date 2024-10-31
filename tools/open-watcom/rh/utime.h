/*
 *  utime.h utimbuf structure and prototypes
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
 */
#if !defined( _UTIME_H_INCLUDED ) && !defined( _SYS_UTIME_H_INCLUDED )
#define _UTIME_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifndef __COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack( __push, 1 )

/* 
 *  ISO C types
 */
#ifdef __cplusplus
 #ifndef _STDTIME_T_DEFINED
 #define _STDTIME_T_DEFINED
  namespace std {
    typedef unsigned long time_t;
  }
  typedef std::time_t __w_time_t;
 #endif
 #ifndef _TIME_T_DEFINED
 #define _TIME_T_DEFINED
  #define _TIME_T_DEFINED_
  using std::time_t;
 #endif
#else  /* __cplusplus not defined */
 #ifndef _TIME_T_DEFINED
 #define _TIME_T_DEFINED
  #define _TIME_T_DEFINED_
  typedef unsigned long time_t;
  typedef time_t __w_time_t;
 #endif
#endif /* __cplusplus not defined */
#ifndef __cplusplus
 #ifndef _WCHAR_T_DEFINED
 #define _WCHAR_T_DEFINED
  #define _WCHAR_T_DEFINED_
  typedef unsigned short wchar_t;
 #endif
#endif

struct utimbuf {
    time_t      actime;         /* access time */
    time_t      modtime;        /* modification time */
};
#define _utimbuf    utimbuf

/*
 *  POSIX 1003.1 Prototype
 */
_WCRTLINK extern int utime( const char *__path, const struct utimbuf *__times );
_WCRTLINK extern int _utime( const char *__path, const struct utimbuf *__times );
_WCRTLINK extern int _wutime( const wchar_t *__path, const struct utimbuf *__times );

#pragma pack( __pop )

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
