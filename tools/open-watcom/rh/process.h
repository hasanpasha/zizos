/*
 *  process.h   Process spawning and related routines
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
#ifndef _PROCESS_H_INCLUDED
#define _PROCESS_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifndef __COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  POSIX 1003.1 types
 */
#ifndef _PID_T_DEFINED_
 #define _PID_T_DEFINED_
 typedef int            pid_t;  /* Used for process IDs & group IDs */
#endif

#if !defined( _NO_EXT_KEYS ) /* extensions enabled */

/* mode flags for spawnxxx routines */
#define _P_WAIT             0
#define _P_NOWAIT           1
#define _P_OVERLAY          2
#define _P_NOWAITO          3
#define _OLD_P_OVERLAY      2

#define P_WAIT              _P_WAIT
#define P_NOWAIT            _P_NOWAIT
#define P_OVERLAY           _P_OVERLAY
#define P_NOWAITO           _P_NOWAITO
#define OLD_P_OVERLAY       _OLD_P_OVERLAY

/* values for __action_code used with cwait() */

#define WAIT_CHILD          0
#define WAIT_GRANDCHILD     1

#endif /* extensions enabled */

/*
 *  POSIX 1003.1 Prototypes
 */
_WCRTLINK extern int        execl( const char *__path, const char *__arg0, ... );
_WCRTLINK extern int        execle( const char *__path, const char *__arg0, ... );
_WCRTLINK extern int        execlp( const char *__file, const char *__arg0, ... );
_WCRTLINK extern int        execv( const char *__path, const char *const __argv[] );
_WCRTLINK extern int        execve( const char *__path, const char *const __argv[], const char *const __envp[] );
_WCRTLINK extern int        execvp( const char *__file, const char *const __argv[] );

#ifdef __cplusplus
namespace std {
#endif
_WCRTLINK _WCNORETURN extern void abort( void );
_WCRTLINK _WCNORETURN extern void exit( int __status );
_WCRTLINK extern char       *getenv( const char *__name );
_WCRTLINK extern int        system( const char *__cmd );
#ifdef __cplusplus
} // namespace std
using std::abort;
using std::exit;
using std::getenv;
using std::system;
#endif /* __cplusplus not defined */

_WCRTLINK _WCNORETURN extern void _Exit( int __status );
_WCRTLINK _WCNORETURN extern void _exit( int __status );

_WCRTLINK extern int        setenv( const char *__name, const char *__newvalue, int __overwrite );
_WCRTLINK extern int        putenv( const char *__string );

_WCRTLINK extern pid_t      getpid( void );

_WCRTLINK extern pid_t      wait( int *__stat_loc );

#if !defined( _NO_EXT_KEYS ) /* extensions enabled */

_WCRTLINK extern int        execlpe( const char *__file, const char *__arg0, ... );
_WCRTLINK extern int        execvpe( const char *__file, const char *const __argv[], const char *const __envp[] );

_WCRTLINK extern int        _execl( const char *__path, const char *__arg0, ... );
_WCRTLINK extern int        _execle( const char *__path, const char *__arg0, ... );
_WCRTLINK extern int        _execlp( const char *__file, const char *__arg0, ... );
_WCRTLINK extern int        _execv( const char *__path, const char *const __argv[] );
_WCRTLINK extern int        _execve( const char *__path, const char *const __argv[], const char *const __envp[] );
_WCRTLINK extern int        _execvp( const char *__file, const char *const __argv[] );
_WCRTLINK extern int        _execlpe( const char *__file, const char *__arg0, ... );
_WCRTLINK extern int        _execvpe( const char *__file, const char *const __argv[], const char *const __envp[] );

 _WCRTLINK extern int  _beginthread(
                void (_WCCALLBACK *__start_address)(void *), int __prio,
                const char *__thread_name,
                unsigned __stack_size, void *__arglist );
 #pragma intrinsic(_beginthread)
 _WCRTLINK extern void  _endthread( void );

_WCRTLINK extern int        cwait( int *__status, int __process_id, int __action_code );
_WCRTLINK extern int        _cwait( int *__status, int __process_id, int __action_code );

_WCRTLINK extern char       *getcmd( char *__buffer );
_WCRTLINK extern int        _bgetcmd( char *__buffer, int __len );
_WCRTLINK extern char       *_cmdname( char *__name );

_WCRTLINK extern int        spawnl( int __mode, const char *__path, const char *__arg0, ... );
_WCRTLINK extern int        spawnle( int __mode, const char *__path, const char *__arg0, ... );
_WCRTLINK extern int        spawnlp( int __mode, const char *__path, const char *__arg0, ... );
_WCRTLINK extern int        spawnlpe( int __mode, const char *__path, const char *__arg0, ... );
_WCRTLINK extern int        spawnv( int __mode, const char *__path, const char * const *__argv );
_WCRTLINK extern int        spawnve( int __mode, const char *__path, const char * const *__argv, const char * const *__envp );
_WCRTLINK extern int        spawnvp( int __mode, const char *__path, const char * const *__argv );
_WCRTLINK extern int        spawnvpe( int __mode, const char *__path, const char * const *__argv, const char * const *__envp );

_WCRTLINK extern int        _spawnl( int __mode, const char *__path, const char *__arg0, ... );
_WCRTLINK extern int        _spawnle( int __mode, const char *__path, const char *__arg0, ... );
_WCRTLINK extern int        _spawnlp( int __mode, const char *__path, const char *__arg0, ... );
_WCRTLINK extern int        _spawnlpe( int __mode, const char *__path, const char *__arg0, ... );
_WCRTLINK extern int        _spawnv( int __mode, const char *__path, const char * const *__argv );
_WCRTLINK extern int        _spawnve( int __mode, const char *__path, const char * const *__argv, const char * const *__envp );
_WCRTLINK extern int        _spawnvp( int __mode, const char *__path, const char * const *__argv );
_WCRTLINK extern int        _spawnvpe( int __mode, const char *__path, const char * const *__argv, const char * const *__envp );

_WCRTLINK extern int        _putenv( const char *__string );

_WCRTLINK extern pid_t      _getpid( void );

  extern int (__stdcall *_pRawDllMain)( void *, unsigned, void * );

#endif /* extensions enabled */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
