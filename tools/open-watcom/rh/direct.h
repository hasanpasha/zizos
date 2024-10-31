/*
 *  direct.h    Defines the types and structures used by the directory routines
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
#ifndef _DIRECT_H_INCLUDED
#define _DIRECT_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifndef _DIRENT_H_INCLUDED
 #include <dirent.h>
#endif

#ifndef _SYS_TYPES_H_INCLUDED
 #include <sys/types.h>
#endif

#ifndef __COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack( __push, 1 )

#ifndef _DISKFREE_T_DEFINED
#define _DISKFREE_T_DEFINED
 #define _DISKFREE_T_DEFINED_
 struct _diskfree_t {
     unsigned    total_clusters;
     unsigned    avail_clusters;
     unsigned    sectors_per_cluster;
     unsigned    bytes_per_sector;
 };
 #define diskfree_t _diskfree_t
#endif

_WCRTLINK extern int        _chdrive( int __drive );
_WCRTLINK extern int        _getdrive( void );
_WCRTLINK extern unsigned   _getdiskfree( unsigned __drive, struct _diskfree_t *__diskspace );

_WCRTLINK extern char       *getcwd( char *__buf, __w_size_t __size );
_WCRTLINK extern int        chdir( const char *__path );
_WCRTLINK extern int        mkdir( const char *__path );
_WCRTLINK extern int        rmdir( const char *__path );

_WCRTLINK extern char       *_getdcwd( int __drive, char *__buffer, __w_size_t __maxlen );
_WCRTLINK extern char       *_getcwd( char *__buf, __w_size_t __size );
_WCRTLINK extern int        _chdir( const char *__path );
_WCRTLINK extern int        _mkdir( const char *__path );
_WCRTLINK extern int        _rmdir( const char *__path );

#pragma pack( __pop )

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
