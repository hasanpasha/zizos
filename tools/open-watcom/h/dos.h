/*
 *  dos.h       Defines the structs and unions used to handle the input and
 *              output registers for the DOS and 386 DOS Extender interface
 *              routines.
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
#ifndef _DOS_H_INCLUDED
#define _DOS_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifndef __COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

#if !defined(_SYS__LFNDOS_H_INCLUDED) && defined(__WATCOM_LFN__) && defined(__DOS__)
 #include <sys/_lfndos.h>
#endif

#if defined(_M_IX86) && !defined(_I86_H_INCLUDED)
 #include <i86.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __DOS__
 #define _DOSFAR _WCFAR
#else
 #define _DOSFAR _WCI86FAR
#endif

#ifdef _M_IX86
 #pragma pack( __push, 1 )
#else
 #pragma pack( __push, 8 )
#endif

#ifndef __cplusplus
 #ifndef _WCHAR_T_DEFINED
 #define _WCHAR_T_DEFINED
  #define _WCHAR_T_DEFINED_
  typedef unsigned short wchar_t;
 #endif
#endif

#ifndef NAME_MAX
 #if defined(__OS2__)
  #define NAME_MAX      255     /* maximum filename for HPFS          */
 #elif defined(__NT__) || defined(__WATCOM_LFN__) && defined(__DOS__)
  #define NAME_MAX      259     /* maximum filename for NTFS, FAT LFN and DOS LFN */
 #else
#define NAME_MAX        12      /* 8 chars + '.' +  3 chars */
 #endif
#endif

/* dosexterror struct */

struct _DOSERROR {
    int     exterror;
    char    errclass;
    char    action;
    char    locus;
};
#ifndef __cplusplus
struct DOSERROR {
    int     exterror;
    char    class;
    char    action;
    char    locus;
};
#endif

struct dosdate_t {
    unsigned char   day;        /* 1-31 */
    unsigned char   month;      /* 1-12 */
    unsigned short  year;       /* 1980-2099 */
    unsigned char   dayofweek;  /* 0-6 (0=Sunday) */
};
#define _dosdate_t dosdate_t

struct dostime_t {
    unsigned char   hour;       /* 0-23 */
    unsigned char   minute;     /* 0-59 */
    unsigned char   second;     /* 0-59 */
    unsigned char   hsecond;    /* 1/100 second; 0-99 */
};
#define _dostime_t dostime_t

struct find_t {
    char            reserved[21];       /* reserved for use by DOS    */
    char            attrib;             /* attribute byte for file    */
    unsigned short  wr_time;            /* time of last write to file */
    unsigned short  wr_date;            /* date of last write to file */
    unsigned long   size;               /* length of file in bytes    */
    char            name[NAME_MAX+1];   /* null-terminated filename   */
};
struct _wfind_t {
    char            reserved[21];       /* reserved for use by DOS    */
    char            attrib;             /* attribute byte for file    */
    unsigned short  wr_time;            /* time of last write to file */
    unsigned short  wr_date;            /* date of last write to file */
    unsigned long   size;               /* length of file in bytes    */
    wchar_t         name[NAME_MAX+1];   /* null-terminated filename   */
};
#define _find_t find_t

/* Critical error handler equates for _hardresume result parameter */

#define _HARDERR_IGNORE 0       /* Ignore the error */
#define _HARDERR_RETRY  1       /* Retry the operation */
#define _HARDERR_ABORT  2       /* Abort the program */
#define _HARDERR_FAIL   3       /* Fail the system call in progress */

/* File attribute constants for attribute field */

#define _A_NORMAL       0x00    /* Normal file - read/write permitted */
#define _A_RDONLY       0x01    /* Read-only file */
#define _A_HIDDEN       0x02    /* Hidden file */
#define _A_SYSTEM       0x04    /* System file */
#define _A_VOLID        0x08    /* Volume-ID entry */
#define _A_SUBDIR       0x10    /* Subdirectory */
#define _A_ARCH         0x20    /* Archive file */

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

#ifndef _DELAY_DEFINED
#define _DELAY_DEFINED
_WCRTLINK extern void       delay(unsigned int __milliseconds);
#endif
_WCRTLINK extern int      _islfn( const char *__path );
_WCRTLINK extern char     *_lfntosfn( const char *__orgname, char *__shortname );
_WCRTLINK extern int      bdos( int __dosfn, unsigned int __dx, unsigned int __al);
_WCRTLINK _WCNORETURN extern void   _chain_intr( void (_WCINTERRUPT _DOSFAR *__handler)() );
#if defined(__NT__) || ( defined(__OS2__) && !defined(_M_I86) )
_WCRTLINK extern unsigned _dos_allocmem( unsigned __size, void **__storage );
#else
_WCRTLINK extern unsigned _dos_allocmem( unsigned __size, unsigned *__seg );
#endif
_WCRTLINK extern unsigned _dos_close( int __handle );
_WCRTLINK extern unsigned _dos_commit( int __handle );
_WCRTLINK extern unsigned _dos_creat( const char *__path, unsigned __attr, int *__handle );
_WCRTLINK extern unsigned _dos_creatnew( const char *__path, unsigned __attr, int *__handle );
_WCRTLINK extern unsigned _dos_findfirst( const char *__path, unsigned __attr, struct find_t *__buf );
_WCRTLINK extern unsigned _dos_findnext( struct find_t *__buf );
_WCRTLINK extern unsigned _dos_findclose( struct find_t *__buf );
#if defined(__NT__) || ( defined(__OS2__) && !defined(_M_I86) )
_WCRTLINK extern unsigned _dos_freemem( void *__storage );
#else
_WCRTLINK extern unsigned _dos_freemem( unsigned __seg );
#endif
_WCRTLINK extern void     _dos_getdate( struct dosdate_t *__date );
_WCRTLINK extern unsigned _dos_getdiskfree( unsigned __drive, struct _diskfree_t *__diskspace );
_WCRTLINK extern void     _dos_getdrive( unsigned *__drive );
_WCRTLINK extern unsigned _dos_getfileattr( const char *__path, unsigned *__attr );
_WCRTLINK extern unsigned _dos_getftime( int __handle, unsigned *__date, unsigned *__time );
_WCRTLINK extern void     _dos_gettime( struct dostime_t *__time );
_WCRTLINK extern void     (_WCINTERRUPT _DOSFAR *_dos_getvect( unsigned __intnum ))();
_WCRTLINK _WCNORETURN extern void   _dos_keep( unsigned __retcode, unsigned __memsize );

_WCRTLINK extern unsigned _dos_open( const char *__path, unsigned __mode, int *__handle );
_WCRTLINK extern unsigned _dos_read( int __handle, void _DOSFAR *__buf, unsigned __count, unsigned *__bytes );
_WCRTLINK extern unsigned _dos_setblock( unsigned __size, unsigned __seg, unsigned  *__maxsize );
_WCRTLINK extern unsigned _dos_setdate( struct dosdate_t *__date );
_WCRTLINK extern void     _dos_setdrive( unsigned __drivenum, unsigned *__drives );
_WCRTLINK extern unsigned _dos_setfileattr( const char *__path, unsigned __attr );
_WCRTLINK extern unsigned _dos_setftime( int __handle, unsigned __date, unsigned __time );
_WCRTLINK extern unsigned _dos_settime( struct dostime_t *__time );
_WCRTLINK extern void     _dos_setvect( unsigned __intnum, void (_WCINTERRUPT _DOSFAR *__handler)() );
_WCRTLINK extern unsigned _dos_write( int __handle, void const _DOSFAR *__buf, unsigned __count, unsigned *__bytes );
_WCRTLINK extern int      dosexterr( struct _DOSERROR * );
_WCRTLINK extern void     _harderr( int (_DOSFAR *__func)(unsigned __deverr, unsigned __errcode, unsigned _DOSFAR *__devhdr) );
_WCRTLINK extern void     _hardresume( int __result );
_WCRTLINK extern void     _hardretn( int __error );
#ifdef _M_IX86
_WCRTLINK extern int      intdos( union REGS *, union REGS * );
_WCRTLINK extern int      intdosx( union REGS *, union REGS *, struct SREGS * );
#endif
_WCRTLINK extern unsigned sleep( unsigned __seconds );

_WCRTLINK extern unsigned _wdos_findfirst( const wchar_t *__path, unsigned __attr, struct _wfind_t *__buf );
_WCRTLINK extern unsigned _wdos_findnext( struct _wfind_t *__buf );
_WCRTLINK extern unsigned _wdos_findclose( struct _wfind_t *__buf );

#pragma pack( __pop )

#undef _DOSFAR

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
