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

#ifndef _SYS_TYPES_H_INCLUDED
 #include <sys/types.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NULL
#ifdef __cplusplus
  #define NULL 0
#else
 #ifdef __RDOSDEV__
  #define NULL 0
 #else
  #define NULL ((void *)0)
 #endif
#endif
#endif

/* Symbolic constants for the access() function */

#define R_OK    4       /*  Test for read permission    */
#define W_OK    2       /*  Test for write permission   */
#define X_OK    1       /*  Test for execute permission */
#define F_OK    0       /*  Test for existence of file  */

/* Symbolic constants for the lseek() function */

#define SEEK_SET    0           /* Seek relative to the start of file   */
#define SEEK_CUR    1           /* Seek relative to current position    */
#define SEEK_END    2           /* Seek relative to the end of the file */

/* Symbolic constants for stream I/O */

#define STDIN_FILENO    0
#define STDOUT_FILENO   1
#define STDERR_FILENO   2

/* Compile-time Symbolic Constants for Portability Specifications */

#undef  _POSIX_JOB_CONTROL              /* no job control                   */
#define _POSIX_SAVED_IDS    1           /* no saved-set user-ID & group-ID  */
#define _POSIX_VERSION      198808L     /* YYYYmm of POSIX std approval     */
#define _POSIX_PROCESS_SCHEDULING   1
#define _POSIX_TIMERS   1

/* Open Watcom supports pthreads and semaphores on Linux now.
 * QNX might not conform to the POSIX standards, though.
 */
#ifdef __LINUX__
#define _POSIX_SEMAPHORES   200809L
#define _POSIX_THREADS      200809L

#define _POSIX_BARRIERS     200809L
#define _POSIX_SPIN_LOCKS   200809L
#define _POSIX_READER_WRITER_LOCKS  200809L
#endif

/* Symbolic constants for sysconf */

#define _SC_ARG_MAX                         1
#define _SC_CHILD_MAX                       2
#define _SC_CLK_TCK                         3
#define _SC_NGROUPS_MAX                     4
#define _SC_OPEN_MAX                        5
#define _SC_JOB_CONTROL                     6
#define _SC_SAVED_IDS                       7
#define _SC_VERSION                         8
#define _SC_STREAM_MAX                      9
#define _SC_TZNAME_MAX                      10
#define _SC_PAGE_SIZE                       11
#define _SC_PAGESIZE                        11
#define _SC_NPROCESSORS_CONF                12
#define _SC_NPROCESSORS_ONLN                13
#define _SC_PHYS_PAGES                      14
#define _SC_AVPHYS_PAGES                    15
#define _SC_REALTIME_SIGNALS                16
#define _SC_SOMAXCONN                       17
#define _SC_THREAD_ATTR_STACKADDR           18
#define _SC_THREAD_ATTR_STACKSIZE           19
#define _SC_THREAD_PRIORITY_SCHEDULING      20
#define _SC_THREAD_PROCESS_SHARED           21
#define _SC_MONOTONIC_CLOCK                 22
#define _SC_THREAD_STACK_MIN                23

/* Execution-time Symbolic Constants for Portability Specifications */

#define _POSIX_CHOWN_RESTRICTED 0       /* restricted use of chown() */
#define _POSIX_NO_TRUNC         0       /* pathname components > NAME_MAX */
#define _POSIX_VDISABLE         0x00    /* terminal special chars can be disabled */

/* Symbolic constants for pathconf, fpathconf */

#define _PC_LINK_MAX            1
#define _PC_MAX_CANON           2
#define _PC_MAX_INPUT           3
#define _PC_NAME_MAX            4
#define _PC_PATH_MAX            5
#define _PC_PIPE_BUF            6
#define _PC_CHOWN_RESTRICTED    7
#define _PC_NO_TRUNC            8
#define _PC_VDISABLE            9
#define _PC_DOS_SHARE           10  /* test for dos share support   */
#define _PC_DOS_LOCKS           11  /* test for dos locking support */

/* Symbolic constants for confstr */

#define _CS_PATH            1

_WCRTLINK extern ssize_t    read( int fildes, void *buf, __w_size_t nbyte );
_WCRTLINK extern ssize_t    write( int fildes, const void *buf, __w_size_t nbyte );
_WCRTLINK extern int        access( const char *__path, int __mode );
_WCRTLINK extern int        dup( int __handle );
_WCRTLINK extern int        dup2( int __handle1, int __handle2 );
_WCRTLINK extern int        close( int __fildes );
_WCRTLINK extern off_t      lseek( int __handle, off_t __offset, int __origin );
_WCRTLINK extern int        unlink( const char *__path );
_WCRTLINK extern int        isatty( int __handle );
_WCRTLINK extern int        fsync( int __handle );
_WCRTLINK extern int        pipe( int __fildes[2] );
_WCRTLINK extern unsigned   alarm( unsigned int __seconds );
_WCRTLINK extern int        chown( const char *__path, uid_t __owner, gid_t __group );
_WCRTLINK extern int        fchown( int __fildes, uid_t __owner, gid_t __group );
_WCRTLINK extern int        fdatasync( int __fildes );
_WCRTLINK extern pid_t      fork( void );
_WCRTLINK extern long       fpathconf( int __fildes, int __name );
_WCRTLINK extern gid_t      getegid( void );
_WCRTLINK extern uid_t      geteuid( void );
_WCRTLINK extern gid_t      getgid( void );
_WCRTLINK extern int        getgroups( int __gidsetsize, gid_t __grouplist[] );
_WCRTLINK extern int        gethostname( char *__name, size_t __len );
_WCRTLINK extern char       *getlogin( void );
_WCRTLINK extern pid_t      getpgrp( void );
_WCRTLINK extern pid_t      getppid( void );
_WCRTLINK extern pid_t      getsid( pid_t __pid );
_WCRTLINK extern uid_t      getuid( void );
_WCRTLINK extern int        link( const char *__path1, const char *__path2 );
_WCRTLINK extern long       pathconf( const char *__path, int __name );
_WCRTLINK extern int        pause( void );
_WCRTLINK extern ssize_t    readlink( const char *__path, char *__buf, size_t __bufsiz );
_WCRTLINK extern int        setegid( gid_t __newegroup );
_WCRTLINK extern int        seteuid( uid_t __newuserid );
_WCRTLINK extern int        setgid( gid_t __newgroup );
_WCRTLINK extern int        setpgid( pid_t __pid, pid_t __pgroupid );
_WCRTLINK extern int        setregid( gid_t __real, uid_t __effective );
_WCRTLINK extern int        setreuid( uid_t __real, uid_t __effective );
_WCRTLINK extern pid_t      setsid( void );
_WCRTLINK extern int        setuid( uid_t __newuserid );
_WCRTLINK extern int        symlink( const char *__pname, const char *__slink );
_WCRTLINK extern void       sync( void );
_WCRTLINK extern long       sysconf( int __name );
_WCRTLINK extern pid_t      tcgetpgrp( int __fildes );
_WCRTLINK extern int        tcsetpgrp( int __fildes, pid_t __pgrp_id );
_WCRTLINK extern char       *ttyname( int __fildes );
_WCRTLINK extern int        ttyname_r( int __fildes, char *__buf, size_t __buflen );
_WCRTLINK extern int        chroot( const char *__path );
_WCRTLINK extern int        lchown( const char *__path, uid_t __owner, gid_t __group );
_WCRTLINK extern int        nice( int __val );
_WCRTLINK extern int        usleep( unsigned long __usec );
#ifdef __386__
_WCRTLINK extern pid_t      vfork( void );
#pragma aux vfork \
    __parm [] \
    __value [__eax] \
    __modify __exact [__eax __edx]
#endif
_WCRTLINK extern int        truncate( const char *__path, off_t __length );
_WCRTLINK extern int        ftruncate( int __fd, off_t __length );

#if defined( _LINUX_SOURCE ) || !defined( _NO_EXT_KEYS ) /* extensions enabled */

_WCRTLINK extern int        eof( int __handle );
_WCRTLINK extern long       filelength( int __handle );
_WCRTLINK extern off_t      tell( int __handle );
_WCRTLINK extern int        chsize( int __handle, long __size );
_WCRTLINK extern int        setmode( int __handle, int __mode );
_WCRTLINK extern int        _read( int fildes, void *buf, unsigned nbyte );
_WCRTLINK extern int        _write( int fildes, const void *buf, unsigned nbyte );
_WCRTLINK extern int        _access( const char *__path, int __mode );
_WCRTLINK extern int        _dup( int __handle );
_WCRTLINK extern int        _dup2( int __handle1, int __handle2 );
_WCRTLINK extern int        _close( int __handle );
_WCRTLINK extern off_t      _lseek( int __handle, off_t __offset, int __origin );
_WCRTLINK extern long long  _lseeki64( int __fildes, long long __offset, int __whence );
_WCRTLINK extern int        _unlink( const char *__path );
_WCRTLINK extern int        _isatty( int __handle );
_WCRTLINK extern long       _get_osfhandle( int __posixhandle );
_WCRTLINK extern int        _hdopen( int __handle,int __mode );
_WCRTLINK extern int        _open_osfhandle( long __osfhandle, int __flags );
_WCRTLINK extern int        _os_handle( int __handle );
_WCRTLINK extern int        _eof( int __handle );
_WCRTLINK extern long       _filelength( int __handle );
_WCRTLINK extern long long  _filelengthi64( int __handle );
_WCRTLINK extern off_t      _tell( int __handle );
_WCRTLINK extern long long  _telli64( int __handle );
_WCRTLINK extern int        _chsize( int __handle, long __size );
_WCRTLINK extern int        _setmode( int __handle, int __mode );
_WCRTLINK extern int        ioperm( unsigned long __from, unsigned long __num, int __turn_on );
_WCRTLINK extern int        iopl( int __level );
_WCRTLINK extern int        _llseek( unsigned int __fildes, unsigned long __hi, unsigned long __lo, loff_t *__res, unsigned int __whence );
_WCRTLINK extern int        truncate64( const char *__path, off64_t __length );
_WCRTLINK extern int        ftruncate64( int __fd, off64_t __length );

#endif /* extensions enabled */

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

_WCRTLINK extern int          brk( void _WCNEAR *__endds );
_WCRTLINK extern void _WCNEAR *__brk( unsigned __new_brk_value );
_WCRTLINK extern void _WCNEAR *sbrk( int __increment );

/* Globals used and set by getopt() */
_WCRTDATA extern char       *optarg;
_WCRTDATA extern int        optind;
_WCRTDATA extern int        opterr;
_WCRTDATA extern int        optopt;

_WCRTLINK extern int        getopt( int __argc, char * const __argv[], const char *__optstring );

#if defined( _LINUX_SOURCE ) || !defined( _NO_EXT_KEYS ) /* extensions enabled */
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
_WCRTLINK extern unsigned   delay(unsigned int __milliseconds);
#endif

#endif /* extensions enabled */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
