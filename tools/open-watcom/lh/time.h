/***************************************************************************
 * FILE: time.h/ctime (Time functions)
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
 *              declares facilities for manipulating calendar dates and
 *              times.
 ***************************************************************************/
#ifndef _TIME_H_INCLUDED
#define _TIME_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus

#include <ctime>

// C99 types in time.h
#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
 using std::clock_t;
#endif
#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
 #define _SIZE_T_DEFINED_
 using std::size_t;
#endif
#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
 #define _TIME_T_DEFINED_
 using std::time_t;
#endif
#ifndef _TM_DEFINED
#define _TM_DEFINED
 #define _TM_DEFINED_
 using std::tm;
#endif

// C99 functions in time.h
using std::asctime;
using std::clock;
using std::ctime;
using std::difftime;
using std::gmtime;
using std::localtime;
using std::mktime;
using std::strftime;
using std::time;

#else /* __cplusplus not defined */

#ifndef __COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

#ifndef _SYS_TYPES_H_INCLUDED
 #include <sys/types.h>
#endif

#pragma pack( __push, 8 )

#ifndef NULL
 #ifdef __RDOSDEV__
  #define NULL 0
 #else
  #define NULL ((void *)0)
 #endif
#endif

#define CLOCKS_PER_SEC   1000

#if defined( _POSIX_SOURCE ) || defined( _LINUX_SOURCE ) || !defined( _NO_EXT_KEYS ) /* extensions enabled */

#define CLK_TCK          1000

/*  Clock types */
#define CLOCK_REALTIME              0
#define CLOCK_MONOTONIC             1
#define CLOCK_PROCESS_CPUTIME_ID    2
#define CLOCK_THREAD_CPUTIME_ID     3
#define CLOCK_MONOTONIC_RAW         4

/* Timer settime flags */
#define TIMER_ABSTIME           0x0001
#define TIMER_ADDREL            0x0100
#define TIMER_PRESERVE_EXEC     0x0200
#define TIMER_AUTO_RELEASE      0x0400

#endif /* extensions enabled */

 #ifndef _WCHAR_T_DEFINED
 #define _WCHAR_T_DEFINED
  #define _WCHAR_T_DEFINED_
  typedef unsigned short wchar_t;
 #endif

 #ifndef _SIZE_T_DEFINED
 #define _SIZE_T_DEFINED
  #define _SIZE_T_DEFINED_
  typedef unsigned size_t;
  typedef size_t   __w_size_t;
 #endif

 #ifndef _TIME_T_DEFINED
 #define _TIME_T_DEFINED
  #define _TIME_T_DEFINED_
  typedef signed long time_t;
  typedef time_t __w_time_t;
 #endif

 #ifndef _CLOCK_T_DEFINED
 #define _CLOCK_T_DEFINED
  typedef unsigned long clock_t;
 #endif

struct tm {
    int  tm_sec;    /* seconds after the minute -- [0,61] */
    int  tm_min;    /* minutes after the hour   -- [0,59] */
    int  tm_hour;   /* hours after midnight     -- [0,23] */
    int  tm_mday;   /* day of the month         -- [1,31] */
    int  tm_mon;    /* months since January     -- [0,11] */
    int  tm_year;   /* years since 1900                   */
    int  tm_wday;   /* days since Sunday        -- [0,6]  */
    int  tm_yday;   /* days since January 1     -- [0,365]*/
    int  tm_isdst;  /* Daylight Savings Time flag */
};

#ifndef _TM_DEFINED
#define _TM_DEFINED
 #define _TM_DEFINED_
 typedef struct tm __w_tm;
#endif

#if defined( _POSIX_SOURCE ) || defined( _LINUX_SOURCE ) || !defined( _NO_EXT_KEYS ) || __STDC_VERSION__ >= 199901L /* extensions enabled or C99 */
#ifndef _TIMESPEC_DEFINED
 #define _TIMESPEC_DEFINED
 struct timespec {
     __w_time_t tv_sec;
     long       tv_nsec;
 };
#endif /* _TIMESPEC_DEFINED */
#endif /* extensions enabled */

#if defined( _POSIX_SOURCE ) || defined( _LINUX_SOURCE ) || !defined( _NO_EXT_KEYS ) /* extensions enabled */

#ifndef _TIMER_T_DEFINED_
 #define _TIMER_T_DEFINED_
 typedef int            timer_t;
#endif
#ifndef _CLOCKID_T_DEFINED_
 #define _CLOCKID_T_DEFINED_
 typedef int            clockid_t;
#endif

/* 1003.4/D12 Clocks and Timers */
#ifndef __POSIX_TIMERS
#define __POSIX_TIMERS

struct itimerspec {
    struct timespec it_interval;
    struct timespec it_value;
    int             notify_type;            /* Uses native int size */
    int             timer_type;
    long            data;                   /* Used by gettimer only */
};

struct itimercb {
    struct /*event*/ {
        long  evt_value;              /* Will hold a proxy or a signal */
    }    itcb_event;
    int  itcb_count;
};

#endif /* __POSIX_TIMERS */

struct sigevent;               /* for C++ */

#endif /* extensions enabled */

_WCRTLINK extern char       *asctime( const struct tm *__timeptr );
_WCRTLINK extern clock_t    clock( void );
_WCRTLINK extern char       *ctime( const time_t *__timer );
_WMRTLINK extern double     difftime( time_t __t1, time_t __t0 );
_WCRTLINK extern struct tm  *gmtime( const time_t *__timer );
_WCRTLINK extern struct tm  *localtime( const time_t *__timer );
_WCRTLINK extern time_t     mktime( struct tm *__timeptr );
_WCRTLINK extern size_t     strftime( char *__s, size_t __maxsiz, const char *__fmt, const struct tm *__tp );
_WCRTLINK extern time_t     time( time_t *__timer );
#if defined( _LINUX_SOURCE ) || !defined( _NO_EXT_KEYS ) /* extensions enabled */
_WCRTLINK extern size_t     wcsftime( wchar_t *, size_t, const wchar_t *, const struct tm * );
#endif /* extensions enabled */

#define difftime(__t1,__t0)  ((double)( __t1 ) - (double)( __t0 ))

#if defined( _LINUX_SOURCE ) || !defined( _NO_EXT_KEYS ) /* extensions enabled */
_WCRTLINK extern wchar_t    *_wasctime( const __w_tm * );
_WCRTLINK extern wchar_t    *_wctime( const __w_time_t * );
_WCRTLINK extern wchar_t    *_wstrdate( wchar_t *__buf );
_WCRTLINK extern wchar_t    *_wstrtime( wchar_t *__buf );
_WCRTLINK extern __w_size_t _wstrftime_ms( wchar_t *, __w_size_t, const char *, const __w_tm * );

_WCRTLINK extern char       *_asctime( const __w_tm *__timeptr, char *__buf );
_WCRTLINK extern char       *_ctime( const __w_time_t *__timer, char *__buf );
_WCRTLINK extern __w_tm     *_gmtime( const __w_time_t *__timer, __w_tm *__tmbuf );
_WCRTLINK extern __w_tm     *_localtime( const __w_time_t *__timer, __w_tm *__tmbuf );
_WCRTLINK extern char       *asctime_r( const __w_tm *__timeptr, char *__buf );
_WCRTLINK extern char       *ctime_r( const __w_time_t *__timer, char *__buf );
_WCRTLINK extern __w_tm     *gmtime_r( const __w_time_t *__timer, __w_tm *__tmbuf );
_WCRTLINK extern __w_tm     *localtime_r( const __w_time_t *__timer, __w_tm *__tmbuf );
_WCRTLINK extern char       *_strdate( char *__buf );
_WCRTLINK extern char       *_strtime( char *__buf );
_WCRTLINK extern wchar_t    *__wctime( const __w_time_t *, wchar_t * );
_WCRTLINK extern wchar_t    *__wasctime( const __w_tm *, wchar_t * );
#endif /* extensions enabled */

#if defined( _POSIX_SOURCE ) || defined( _LINUX_SOURCE ) || !defined( _NO_EXT_KEYS ) /* extensions enabled */

_WCRTLINK extern int    nanosleep( const struct timespec *__rqtp, struct timespec *__rmtp );

_WCRTLINK extern int    timer_create( clockid_t __clock_id, struct sigevent *__evp, timer_t *__tmr );
_WCRTLINK extern int    timer_delete( timer_t __timerid );
_WCRTLINK extern int    timer_getoverrun( timer_t __timerid );
_WCRTLINK extern int    timer_gettime( timer_t __timerid, struct itimerspec *__value );
_WCRTLINK extern int    timer_settime( timer_t __timerid, int __flags, struct itimerspec *__value, struct itimerspec *__ovalue );

_WCRTLINK extern int    clock_gettime( clockid_t __clock_id, struct timespec *__tp );
_WCRTLINK extern int    clock_getres( clockid_t __clock_id, struct timespec *__res );
_WCRTLINK extern int    clock_settime( clockid_t __clock_id, const struct timespec *__tp );
_WCRTLINK extern int    clock_nanosleep( clockid_t __clock_id, int __flags, const struct timespec *__req, struct timespec *__rmdr );

#endif /* extensions enabled */

#if defined( _POSIX_SOURCE ) || defined( _LINUX_SOURCE ) || !defined( _NO_EXT_KEYS ) /* extensions enabled */

_WCRTLINK extern void   tzset( void );
_WCRTLINK extern char   **__get_tzname_ptr( void );
#ifdef __FUNCTION_DATA_ACCESS
 #define tzname         (*__get_tzname_ptr())
#elif defined(__SW_BR) || defined(_RTDLL)
 #define tzname  tzname_br
#endif
_WCRTDATA extern char * _WCDATA tzname[2];  /*  time zone names */

#endif /* extensions enabled */

#if defined( _LINUX_SOURCE ) || !defined( _NO_EXT_KEYS ) /* extensions enabled */

_WCRTLINK extern long   *__get_timezone_ptr( void );
_WCRTLINK extern int    *__get_daylight_ptr( void );
#ifdef __FUNCTION_DATA_ACCESS
 #define timezone       (*__get_timezone_ptr())
 #define daylight       (*__get_daylight_ptr())
#elif defined(__SW_BR) || defined(_RTDLL)
 #define timezone       timezone_br
 #define daylight       daylight_br
#endif
_WCRTDATA extern long   _WCDATA timezone;   /* # of seconds from GMT */
_WCRTDATA extern int    _WCDATA daylight;   /* d.s.t. indicator */

#endif /* extensions enabled */

#if defined(__STDC_WANT_LIB_EXT1__) && __STDC_WANT_LIB_EXT1__ == 1

#ifndef _ERRNO_T_DEFINED
 #define _ERRNO_T_DEFINED
 typedef int errno_t;
#endif

#ifndef _RSIZE_T_DEFINED
#define _RSIZE_T_DEFINED
 typedef size_t rsize_t;
#endif

_WCRTLINK extern errno_t    asctime_s( char *__s, rsize_t __maxsize, const struct tm *__timeptr );
_WCRTLINK extern errno_t    ctime_s( char *__s, rsize_t __maxsize, const time_t *__timer );
_WCRTLINK extern struct tm  *gmtime_s( const time_t * __restrict __timer, struct tm * __restrict __result );
_WCRTLINK extern struct tm  *localtime_s( const time_t * __restrict __timer, struct tm * __restrict __t );

_WCRTLINK extern errno_t    _wasctime_s( wchar_t *__s, rsize_t __maxsize, const struct tm *__timeptr );
_WCRTLINK extern errno_t    _wctime_s( wchar_t *__s, rsize_t __maxsize, const time_t *__timer );

#endif /* __STDC_WANT_LIB_EXT1__ */

#pragma pack( __pop )

#endif /* __cplusplus not defined */

#endif
