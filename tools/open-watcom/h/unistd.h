/*
 *  unistd.h
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
#ifndef _UNISTD_H_INCLUDED
#define _UNISTD_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifndef __COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

#ifndef _IO_H_INCLUDED
 #include <io.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__OS2__) && !defined(_M_I86) && defined(__TCPIP_HEADERS)
 #include <tcpustd.h>  /* unistd.h conflicts with OS/2 TCP/IP headers */
#endif

#ifndef NULL
#ifdef __cplusplus
 #if !defined(_M_I86) || defined(__SMALL__) || defined(__MEDIUM__)
  #define NULL 0
 #else
  #define NULL 0L
 #endif
#else
 #ifdef __RDOSDEV__
  #define NULL 0
 #else
  #define NULL ((void *)0)
 #endif
#endif
#endif

_WCRTLINK _WCNORETURN extern void _exit( int __status );

_WCRTLINK extern unsigned   sleep( unsigned int __seconds );

_WCRTLINK extern pid_t      getpid( void );
_WCRTLINK extern char       *getcwd( char *__buf, __w_size_t __size );
_WCRTLINK extern int        chdir( const char *__path );
_WCRTLINK extern int        rmdir( const char *__path );

_WCRTLINK extern int        execl( const char *__path, const char *__arg0, ... );
_WCRTLINK extern int        execle( const char *__path, const char *__arg0, ... );
_WCRTLINK extern int        execlp( const char *__file, const char *__arg0, ... );
_WCRTLINK extern int        execv( const char *__path, const char *const __argv[] );
_WCRTLINK extern int        execve( const char *__path, const char *const __argv[], const char *const __envp[] );
_WCRTLINK extern int        execvp( const char *__file, const char *const __argv[] );

_WCRTLINK extern void _WCNEAR *__brk( unsigned __new_brk_value );
_WCRTLINK extern void _WCNEAR *sbrk( int __increment );

/* Globals used and set by getopt() */
_WCRTDATA extern char       *optarg;
_WCRTDATA extern int        optind;
_WCRTDATA extern int        opterr;
_WCRTDATA extern int        optopt;

_WCRTLINK extern int        getopt( int __argc, char * const __argv[], const char *__optstring );

#if !defined( _NO_EXT_KEYS ) /* extensions enabled */
_WCRTLINK extern pid_t      _getpid( void );
_WCRTLINK extern char       *_getcwd( char *__buf, __w_size_t __size );
_WCRTLINK extern int        _chdir( const char *__path );
_WCRTLINK extern int        _rmdir( const char *__path );

_WCRTLINK extern int        _execl( const char *__path, const char *__arg0, ... );
_WCRTLINK extern int        _execle( const char *__path, const char *__arg0, ... );
_WCRTLINK extern int        _execlp( const char *__file, const char *__arg0, ... );
_WCRTLINK extern int        _execv( const char *__path, const char *const __argv[] );
_WCRTLINK extern int        _execve( const char *__path, const char *const __argv[], const char *const __envp[] );
_WCRTLINK extern int        _execvp( const char *__file, const char *const __argv[] );

#ifndef _DELAY_DEFINED
#define _DELAY_DEFINED
_WCRTLINK extern void       delay(unsigned int __milliseconds);
#endif

_WCRTLINK extern wchar_t    *_wgetcwd( wchar_t *__buf, __w_size_t __size );
_WCRTLINK extern int        _wchdir( const wchar_t *__path );
_WCRTLINK extern int        _wrmdir( const wchar_t *__path );

_WCRTLINK extern int        _wexecl( const wchar_t *__path, const wchar_t *__arg0, ... );
_WCRTLINK extern int        _wexecle( const wchar_t *__path, const wchar_t *__arg0, ... );
_WCRTLINK extern int        _wexeclp( const wchar_t *__file, const wchar_t *__arg0, ... );
_WCRTLINK extern int        _wexecv( const wchar_t *__path, const wchar_t *const __argv[] );
_WCRTLINK extern int        _wexecve( const wchar_t *__path, const wchar_t *const __argv[], const wchar_t *const __envp[] );
_WCRTLINK extern int        _wexecvp( const wchar_t *__file, const wchar_t *const __argv[] );
#endif /* extensions enabled */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif