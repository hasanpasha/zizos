/*
 *  tchar.h     Generic International Text Function Macros
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
#ifndef _TCHAR_H_INCLUDED
#define _TCHAR_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifndef __COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

#ifndef _STRING_H_INCLUDED
 #include <string.h>
#endif

#ifndef _TIME_H_INCLUDED
 #include <time.h>
#endif

#if defined(_UNICODE) || defined(__UNICODE__)

#ifndef _WCHAR_H_INCLUDED
 #include <wchar.h>
#endif

#elif defined(_MBCS)

#ifndef _MBSTRING_H_INCLUDED
 #include <mbstring.h>
#endif

#endif

#ifdef __cplusplus
extern "C" {
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

#if defined(_UNICODE) || defined(__UNICODE__)
// **************************** UNICODE **************************************

#ifndef __TCHAR_DEFINED
typedef wchar_t _TCHAR;
typedef wchar_t _TSCHAR;
typedef wchar_t _TUCHAR;
typedef wchar_t _TXCHAR;
typedef wchar_t _TINT;
#define __TCHAR_DEFINED
#endif

#ifndef _TCHAR_DEFINED

#if !defined( _NO_EXT_KEYS ) /* extensions enabled */
typedef wchar_t TCHAR;
#endif /* extensions enabled */

#define _TCHAR_DEFINED
#endif

#define _TEOF           WEOF

#define __T(__x)        L ## __x

#define _TDIR           WDIR

/* Program */

#define _tmain          wmain
#define _tWinMain       wWinMain
#define _tenviron       _wenviron
#define __targc         __wargc
#define __targv         __wargv

/* Formatted i/o */

#define _tprintf        wprintf
#define _ftprintf       fwprintf
#define _sntprintf      _snwprintf
#define _vtprintf       vwprintf
#define _vftprintf      vfwprintf
#define _tscanf         wscanf
#define _ftscanf        fwscanf
#define _stscanf        swscanf
#define _vsntprintf     _vsnwprintf
#define _vstprintf      _vswprintf
#define _stprintf       _swprintf

/* Unformatted i/o */

#define _fgettc         fgetwc
#define _fgettchar      _fgetwchar
#define _fgetts         fgetws
#define _fputtc         fputwc
#define _fputtchar      _fputwchar
#define _fputts         fputws
#define _gettc          getwc
#define _gettchar       getwchar
#define _getts          _getws
#define _puttc          putwc
#define _puttchar       putwchar
#define _putts          _putws
#define _ungettc        ungetwc

/* String conversion functions */

#define _tcstod         wcstod
#define _tcstol         wcstol
#define _tcstoul        wcstoul

#define _itot           _itow
#define _ltot           _ltow
#define _ultot          _ultow
#define _ttoi           _wtoi
#define _ttol           _wtol

/* String functions */

#define _tcscat         wcscat
#define _tcschr         wcschr
#define _tcscpy         wcscpy
#define _tcscspn        wcscspn
#define _tcslen         wcslen
#define _tcsncat        wcsncat
#define _tcsncpy        wcsncpy
#define _tcspbrk        wcspbrk
#define _tcsrchr        wcsrchr
#define _tcsspn         wcsspn
#define _tcsstr         wcsstr
#if defined(__cplusplus) && defined(__INLINE_FUNCTIONS__)
inline wchar_t *_tcstok( wchar_t *__p1, const wchar_t *__p2 ) {
    return( wcstok( __p1, __p2, NULL ) );
}
#else
#define _tcstok(__p1,__p2)      wcstok((__p1),(__p2),NULL)
#endif

#define _tcserror       _wcserror
#define __tcserror      __wcserror

#define _tcsdup         _wcsdup
#define _tcsnset        _wcsnset
#define _tcsrev         _wcsrev
#define _tcsset         _wcsset

#define _tcscmp         wcscmp
#define _tcsicmp        _wcsicmp
#define _tcsnccmp       wcsncmp
#define _tcsncmp        wcsncmp
#define _tcsncicmp      _wcsnicmp
#define _tcsnicmp       _wcsnicmp

#define _tcscoll        wcscoll
#define _tcsicoll       _wcsicoll
#define _tcsnccoll      _wcsncoll
#define _tcsncoll       _wcsncoll
#define _tcsncicoll     _wcsnicoll
#define _tcsnicoll      _wcsnicoll

/* Execute functions */

#define _texecl         _wexecl
#define _texecle        _wexecle
#define _texeclp        _wexeclp
#define _texeclpe       _wexeclpe
#define _texecv         _wexecv
#define _texecve        _wexecve
#define _texecvp        _wexecvp
#define _texecvpe       _wexecvpe

#define _tspawnl        _wspawnl
#define _tspawnle       _wspawnle
#define _tspawnlp       _wspawnlp
#define _tspawnlpe      _wspawnlpe
#define _tspawnv        _wspawnv
#define _tspawnve       _wspawnve
#define _tspawnvp       _wspawnvp
#define _tspawnvpe      _wspawnvpe

#define _tsystem        _wsystem

/* Time functions */

#define _tasctime       _wasctime
#define _tctime         _wctime
#define _tstrdate       _wstrdate
#define _tstrtime       _wstrtime
#define _tutime         _wutime
#define _tcsftime       wcsftime

/* Directory functions */

#define _tchdir         _wchdir
#define _tclosedir      _wclosedir
#define _tgetcwd        _wgetcwd
#define _tgetdcwd       _wgetdcwd
#define _tmkdir         _wmkdir
#define _topendir       _wopendir
#define _treaddir       _wreaddir
#define _trewinddir     _wrewinddir
#define _trmdir         _wrmdir

/* Directory struct */

#define _tdirent        _wdirent

/* Environment/Path functions */

#define _tfullpath      _wfullpath
#define _tgetenv        _wgetenv
#define _tmakepath      _wmakepath
#define _tputenv        _wputenv
#define _tsearchenv     _wsearchenv
#define _tsplitpath     _wsplitpath

/* Stdio functions */

#define _tfdopen        _wfdopen
#define _tfsopen        _wfsopen
#define _tfopen         _wfopen
#define _tfreopen       _wfreopen
#define _tperror        _wperror
#define _ttmpnam        _wtmpnam
#define _ttempnam       _wtempnam

/* Io functions */

#define _taccess        _waccess
#define _tchmod         _wchmod
#define _tcreat         _wcreat
#define _tfindfirst     _wfindfirst
#define _tfindfirsti64  _wfindfirsti64
#define _tfindnext      _wfindnext
#define _tfindnexti64   _wfindnexti64
#define _topen          _wopen
#define _tremove        _wremove
#define _trename        _wrename
#define _tsopen         _wsopen
#define _tunlink        _wunlink

#define _tfinddata_t    _wfinddata_t
#define _tfinddatai64_t _wfinddatai64_t

/* Stat functions */

#define _tstat          _wstat
#define _tstati64       _wstati64
#define _tfstat         fstat
#define _tfstati64      _fstati64

/* Setlocale functions */

#define _tsetlocale     _wsetlocale

/* Redundant "logical-character" mappings */

#define _tcsclen        wcslen
#define _tcsnccat       wcsncat
#define _tcsnccpy       wcsncpy
#define _tcsncset       _wcsnset

#define _tcsdec         _wcsdec
#define _tcsinc         _wcsinc
#define _tcsnbcnt       _wcsncnt
#define _tcsnccnt       _wcsncnt
#define _tcsnextc       _wcsnextc
#define _tcsninc        _wcsninc
#define _tcsspnp        _wcsspnp

#define _tcslwr         _wcslwr
#define _tcsupr         _wcsupr
#define _tcsxfrm        wcsxfrm

#if defined(__cplusplus) && defined(__INLINE_FUNCTIONS__)
inline size_t _tclen( const wchar_t * ) {
    return( 1 );
}
inline void _tccpy( wchar_t *__p1, const wchar_t *__p2 ) {
    *__p1 = (wchar_t)*__p2;
}
inline int _tccmp( const wchar_t *__p1, const wchar_t *__p2 ) {
    return( (int)((*__p1)-(*__p2)) );
}
#else
#define _tclen(__p)       (1)
#define _tccpy(__p1,__p2) ((*(__p1) = *(__p2)))
#define _tccmp(__p1,__p2) ((*(__p1))-(*(__p2)))
#endif

/* ctype functions */

#define _istalnum       iswalnum
#define _istalpha       iswalpha
#define _istascii       iswascii
#define _istcntrl       iswcntrl
#define _istdigit       iswdigit
#define _istgraph       iswgraph
#define _istlower       iswlower
#define _istprint       iswprint
#define _istpunct       iswpunct
#define _istspace       iswspace
#define _istupper       iswupper
#define _istxdigit      iswxdigit

#define _totupper       towupper
#define _totlower       towlower

#define _istlegal(__c)      (1)
#define _istlead(__c)       (0)
#define _istleadbyte(__c)   (0)

#if defined(__cplusplus) && defined(__INLINE_FUNCTIONS__)
inline wchar_t *_wcsdec( const wchar_t *, const wchar_t *__p ) {
    return( (wchar_t *)(__p-1) );
}
inline wchar_t *_wcsinc( const wchar_t *__p ) {
    return( (wchar_t *)(__p+1) );
}
inline unsigned int _wcsnextc( const wchar_t *__p ) {
    return( (unsigned int)*__p );
}
inline wchar_t *_wcsninc( const wchar_t *__p, size_t __l ) {
    return( (wchar_t *)(__p+__l) );
}
inline size_t _wcsncnt( const wchar_t *__p, size_t __l ) {
    size_t __i;
    __i = wcslen(__p);
    return( (__i>__l) ? __l : __i );
}
inline wchar_t *_wcsspnp( const wchar_t *__p1, const wchar_t *__p2 ) {
    return( (*(__p1 += wcsspn(__p1,__p2))!='\0') ? (wchar_t*)__p1 : NULL );
}
#else
#define _wcsdec(__p1, __p2)     ((__p2)-1)
#define _wcsinc(__p)            ((__p)+1)
#define _wcsnextc(__p)          ((unsigned int) *(__p))
#define _wcsninc(__p, __l)      (((__p)+(__l)))
#define _wcsncnt(__p, __l)      ((wcslen(__p)>__l) ? __l : wcslen(__p))
#define _wcsspnp(__p1, __p2)    ((*((__p1)+wcsspn(__p1,__p2))) ? \
                                  ((__p1)+wcsspn(__p1,__p2)) : NULL)
#endif

#else
// **************************** SBCS and MBCS ********************************

#define _TEOF           EOF

#define __T(__x)        __x

#define _TDIR           DIR

/* Program */

#define _tmain          main
#define _tWinMain       WinMain
#define _tenviron       environ
#define __targc         __argc
#define __targv         __argv

/* Formatted i/o */

#define _tprintf        printf
#define _ftprintf       fprintf
#define _stprintf       sprintf
#define _sntprintf      _snprintf
#define _vtprintf       vprintf
#define _vftprintf      vfprintf
#define _vstprintf      vsprintf
#define _vsntprintf     _vsnprintf
#define _tscanf         scanf
#define _ftscanf        fscanf
#define _stscanf        sscanf

/* Unformatted i/o */

#define _fgettc         fgetc
#define _fgettchar      _fgetchar
#define _fgetts         fgets
#define _fputtc         fputc
#define _fputtchar      _fputchar
#define _fputts         fputs
#define _gettc          getc
#define _gettchar       getchar
#define _getts          gets
#define _puttc          putc
#define _puttchar       putchar
#define _putts          puts
#define _ungettc        ungetc

/* String conversion functions */

#define _tcstod         strtod
#define _tcstol         strtol
#define _tcstoul        strtoul

#define _itot           itoa
#define _ltot           ltoa
#define _ultot          ultoa
#define _ttoi           atoi
#define _ttol           atol

/* String functions */

#define _tcscat         strcat
#define _tcscpy         strcpy
#define _tcslen         strlen
#define _tcsxfrm        strxfrm
#define _tcsdup         _strdup

#define _tcserror       strerror
#define __tcserror      _strerror

/* Execute functions */

#define _texecl         execl
#define _texecle        execle
#define _texeclp        execlp
#define _texeclpe       execlpe
#define _texecv         execv
#define _texecve        execve
#define _texecvp        execvp
#define _texecvpe       execvpe

#define _tspawnl        spawnl
#define _tspawnle       spawnle
#define _tspawnlp       spawnlp
#define _tspawnlpe      spawnlpe
#define _tspawnv        spawnv
#define _tspawnve       spawnve
#define _tspawnvp       spawnvp
#define _tspawnvpe      spawnvpe

#define _tsystem        system

/* Time functions */

#define _tasctime       asctime
#define _tctime         ctime
#define _tstrdate       _strdate
#define _tstrtime       strtime
#define _tutime         utime
#define _tcsftime       strftime

/* Directory functions */

#define _tchdir         chdir
#define _tclosedir      closedir
#define _tgetcwd        getcwd
#define _tgetdcwd       _getdcwd
#define _tmkdir         mkdir
#define _topendir       opendir
#define _treaddir       readdir
#define _trewinddir     rewinddir
#define _trmdir         rmdir

/* Directory struct */

#define _tdirent        dirent

/* Environment/Path functions */

#define _tfullpath      _fullpath
#define _tgetenv        getenv
#define _tmakepath      _makepath
#define _tputenv        putenv
#define _tsearchenv     _searchenv
#define _tsplitpath     _splitpath

/* Stdio functions */

#define _tfdopen        fdopen
#define _tfsopen        _fsopen
#define _tfopen         fopen
#define _tfreopen       freopen
#define _tperror        perror
#define _ttmpnam        tmpnam
#define _ttempnam       tempnam

/* Io functions */

#define _taccess        access
#define _tchmod         chmod
#define _tcreat         creat
#define _tfindfirst     _findfirst
#define _tfindfirsti64  _findfirsti64
#define _tfindnext      _findnext
#define _tfindnexti64   _findnexti64
#define _topen          open
#define _tremove        remove
#define _trename        rename
#define _tsopen         _sopen
#define _tunlink        unlink

#define _tfinddata_t    _finddata_t
#define _tfinddatai64_t _finddatai64_t

/* ctype functions */

#define _istascii       __isascii
#define _istcntrl       iscntrl
#define _istxdigit      isxdigit

/* Stat functions */

#define _tstat          stat
#define _tstati64       _stati64
#define _tfstat         fstat
#define _tfstati64      _fstati64

/* Setlocale functions */

#define _tsetlocale     setlocale


#ifdef _MBCS
// **************************** MBCS *****************************************

#ifndef __TCHAR_DEFINED
typedef char            _TCHAR;
typedef signed char     _TSCHAR;
typedef unsigned char   _TUCHAR;
typedef unsigned char   _TXCHAR;
typedef unsigned int    _TINT;
#define __TCHAR_DEFINED
#endif

#ifndef _TCHAR_DEFINED

#if !defined( _NO_EXT_KEYS ) /* extensions enabled */
typedef char            TCHAR;
#endif /* extensions enabled */

#define _TCHAR_DEFINED
#endif

#ifdef _MB_MAP_DIRECT

/* use mb functions directly - types must match */

/* String functions */

#define _tcschr     _mbschr
#define _tcscspn    _mbscspn
#define _tcsncat    _mbsnbcat
#define _tcsncpy    _mbsnbcpy
#define _tcspbrk    _mbspbrk
#define _tcsrchr    _mbsrchr
#define _tcsspn     _mbsspn
#define _tcsstr     _mbsstr
#define _tcstok     _mbstok

#define _tcsnset    _mbsnbset
#define _tcsrev     _mbsrev
#define _tcsset     _mbsset

#define _tcscmp     _mbscmp
#define _tcsicmp    _mbsicmp
#define _tcsnccmp   _mbsncmp
#define _tcsncmp    _mbsnbcmp
#define _tcsncicmp  _mbsnicmp
#define _tcsnicmp   _mbsnbicmp

#define _tcscoll    _mbscoll
#define _tcsicoll   _mbsicoll
#define _tcsnccoll  _mbsncoll
#define _tcsncoll   _mbsnbcoll
#define _tcsncicoll _mbsnicoll
#define _tcsnicoll  _mbsnbicoll

/* "logical-character" mappings */

#define _tcsclen    _mbslen
#define _tcsnccat   _mbsncat
#define _tcsnccpy   _mbsncpy
#define _tcsncset   _mbsnset

/* MBCS-specific mappings */

#define _tcsdec     _mbsdec
#define _tcsinc     _mbsinc
#define _tcsnbcnt   _mbsnbcnt
#define _tcsnccnt   _mbsnccnt
#define _tcsnextc   _mbsnextc
#define _tcsninc    _mbsninc
#define _tcsspnp    _mbsspnp

#define _tcslwr     _mbslwr
#define _tcsupr     _mbsupr

#define _tclen      _mbclen
#define _tccpy      _mbccpy

#define _tccmp      _mbccmp

#else

#if defined(__cplusplus) && defined(__INLINE_FUNCTIONS__)

/* the default: use type-safe inline function thunks */

/* String functions */

inline char *_tcschr( const char *__p, unsigned int __c ) {
    return( (char *)_mbschr( (const unsigned char *)__p, __c ) );
}
inline size_t _tcscspn( const char *__p1, const char *__p2 ) {
    return( _mbscspn( (const unsigned char *)__p1,
                      (const unsigned char *)__p2 ) );
}
inline char *_tcsncat( char *__p1, const char *__p2, size_t __l ) {
    return( (char *)_mbsnbcat( (unsigned char *)__p1,
                               (const unsigned char *)__p2, __l ) );
}
inline char *_tcsncpy( char *__p1, const char *__p2, size_t __l ) {
    return( (char *)_mbsnbcpy( (unsigned char *)__p1,
                               (const unsigned char *)__p2, __l ) );
}
inline char *_tcspbrk( const char *__p1, const char *__p2 ) {
    return( (char *)_mbspbrk( (const unsigned char *)__p1,
                              (const unsigned char *)__p2 ) );
}
inline char *_tcsrchr( const char *__p, unsigned int __c ) {
    return( (char *)_mbsrchr( (const unsigned char *)__p, __c ) );
}
inline size_t _tcsspn( const char *__p1, const char *__p2 ) {
    return( _mbsspn( (const unsigned char *)__p1,
                     (const unsigned char *)__p2 ) );
}
inline char *_tcsstr( const char *__p1, const char *__p2 ) {
    return( (char *)_mbsstr( (const unsigned char *)__p1,
                             (const unsigned char *)__p2 ) );
}
inline char *_tcstok( char *__p1, const char *__p2 ) {
    return( (char *)_mbstok( (unsigned char *)__p1,
                             (const unsigned char *)__p2 ) );
}

inline char *_tcsnset( char *__p, unsigned int __c, size_t __l ) {
    return( (char *)_mbsnbset( (unsigned char *)__p, __c, __l ) );
}
inline char *_tcsrev( char *__p ) {
    return( (char *)_mbsrev( (unsigned char *)__p ) );
}
inline char *_tcsset(char *__p, unsigned int __c ) {
    return( (char *)_mbsset( (unsigned char *)__p, __c ) );
}

inline int _tcscmp( const char *__p1, const char *__p2 ) {
    return( _mbscmp( (const unsigned char *)__p1,
                     (const unsigned char *)__p2 ) );
}
inline int _tcsicmp( const char *__p1, const char *__p2 ) {
    return( _mbsicmp( (const unsigned char *)__p1,
                      (const unsigned char *)__p2 ) );
}
inline int _tcsnccmp( const char *__p1, const char *__p2, size_t __l ) {
    return( _mbsncmp( (const unsigned char *)__p1,
                      (const unsigned char *)__p2, __l ) );
}
inline int _tcsncmp( const char *__p1, const char *__p2, size_t __l ) {
    return( _mbsnbcmp( (const unsigned char *)__p1,
                       (const unsigned char *)__p2, __l ) );
}
inline int _tcsncicmp( const char *__p1, const char *__p2, size_t __l ) {
    return( _mbsnicmp( (const unsigned char *)__p1,
                       (const unsigned char *)__p2, __l ) );
}
inline int _tcsnicmp( const char *__p1, const char *__p2, size_t __l ) {
    return( _mbsnbicmp( (const unsigned char *)__p1,
                        (const unsigned char *)__p2, __l ) );
}

inline int _tcscoll( const char *__p1, const char *__p2 ) {
    return( _mbscoll( (const unsigned char *)__p1,
                      (const unsigned char *)__p2 ) );
}
inline int _tcsicoll( const char *__p1, const char *__p2 ) {
    return( _mbsicoll( (const unsigned char *)__p1,
                       (const unsigned char *)__p2 ) );
}
inline int _tcsnccoll( const char *__p1, const char *__p2, size_t __l ) {
    return( _mbsncoll( (const unsigned char *)__p1,
                       (const unsigned char *)__p2, __l ) );
}
inline int _tcsncoll( const char *__p1, const char *__p2, size_t __l ) {
    return( _mbsnbcoll( (const unsigned char *)__p1,
                        (const unsigned char *)__p2, __l ) );
}
inline int _tcsncicoll( const char *__p1, const char *__p2, size_t __l ) {
    return( _mbsnicoll( (const unsigned char *)__p1,
                        (const unsigned char *)__p2, __l ) );
}
inline int _tcsnicoll( const char *__p1, const char *__p2, size_t __l ) {
    return( _mbsnbicoll( (const unsigned char *)__p1,
                         (const unsigned char *)__p2, __l ) );
}

/* "logical-character" mappings */

inline size_t _tcsclen( const char *__p ) {
    return( _mbslen( (const unsigned char *)__p ) );
}
inline char *_tcsnccat( char *__p1, const char *__p2, size_t __l ) {
    return( (char *)_mbsncat( (unsigned char *)__p1,
                              (const unsigned char *)__p2, __l ) );
}
inline char *_tcsnccpy( char *__p1, const char *__p2, size_t __l ) {
    return( (char *)_mbsncpy( (unsigned char *)__p1,
                              (const unsigned char *)__p2, __l ) );
}
inline char *_tcsncset( char *__p, unsigned int __c, size_t __l ) {
    return( (char *)_mbsnset( (unsigned char *)__p, __c, __l ) );
}

/* MBCS-specific mappings */

inline char *_tcsdec( const char *__p1, const char *__p2 ) {
    return( (char *)_mbsdec( (const unsigned char *)__p1,
                             (const unsigned char *)__p2 ) );
}
inline char *_tcsinc( const char *__p ) {
    return( (char *)_mbsinc( (const unsigned char *)__p ) );
}
inline size_t _tcsnbcnt( const char *__p, size_t __l ) {
    return( _mbsnbcnt( (const unsigned char *)__p, __l ) );
}
inline size_t _tcsnccnt( const char *__p, size_t __l ) {
    return( _mbsnccnt( (const unsigned char *)__p, __l ) );
}
inline char *_tcsninc( const char *__p, size_t __l ) {
    return( (char *)_mbsninc( (const unsigned char *)__p, __l ) );
}
inline char *_tcsspnp( const char *__p1, const char *__p2 ) {
    return( (char *)_mbsspnp( (const unsigned char *)__p1,
                              (const unsigned char *)__p2 ) );
}
inline char *_tcslwr( char *__p ) {
    return( (char *)_mbslwr( (unsigned char *)__p ) );
}
inline char *_tcsupr( char *__p ) {
    return( (char *)_mbsupr( (unsigned char *)__p ) );
}

inline size_t _tclen( const char *__p ) {
    return( _mbclen( (const unsigned char *)__p ) );
}

inline void _tccpy( char *__p1, const char *__p2 ) {
    _mbccpy( (unsigned char *)__p1, (const unsigned char *)__p2 );
}

inline int _tccmp( const char *__p1, const char *__p2 ) {
    return _mbccmp( (const unsigned char *)__p1, (const unsigned char *)__p2 );
}

inline unsigned int _tcsnextc( const char *__p ) {
    return( _mbsnextc( (const unsigned char *)__p ) );
}

#else

/* use type-safe linked-in function thunks */

/* String functions */

_WCRTLINK extern char *_tcschr(const char *, unsigned int);
_WCRTLINK extern size_t _tcscspn(const char *, const char *);
_WCRTLINK extern char *_tcsncat(char *, const char *, size_t);
_WCRTLINK extern char *_tcsncpy(char *, const char *, size_t);
_WCRTLINK extern char *_tcspbrk(const char *, const char *);
_WCRTLINK extern char *_tcsrchr(const char *, int);
_WCRTLINK extern size_t _tcsspn(const char *, const char *);
_WCRTLINK extern char *_tcsstr(const char *, const char *);
_WCRTLINK extern char *_tcstok(char *, const char *);

_WCRTLINK extern char *_tcsnset(char *, unsigned int, size_t);
_WCRTLINK extern char *_tcsrev(char *);
_WCRTLINK extern char *_tcsset(char *, unsigned int);

_WCRTLINK extern int _tcscmp(const char *, const char *);
_WCRTLINK extern int _tcsicmp(const char *, const char *);
_WCRTLINK extern int _tcsnccmp(const char *, const char *, size_t);
_WCRTLINK extern int _tcsncmp(const char *, const char *, size_t);
_WCRTLINK extern int _tcsncicmp(const char *, const char *, size_t);
_WCRTLINK extern int _tcsnicmp(const char *, const char *, size_t);

_WCRTLINK extern int _tcscoll(const char *, const char *);
_WCRTLINK extern int _tcsicoll(const char *, const char *);
_WCRTLINK extern int _tcsnccoll(const char *, const char *, size_t);
_WCRTLINK extern int _tcsncoll(const char *, const char *, size_t);
_WCRTLINK extern int _tcsncicoll(const char *, const char *, size_t);
_WCRTLINK extern int _tcsnicoll(const char *, const char *, size_t);

/* "logical-character" mappings */

_WCRTLINK extern size_t _tcsclen(const char *);
_WCRTLINK extern char *_tcsnccat(char *, const char *, size_t);
_WCRTLINK extern char *_tcsnccpy(char *, const char *, size_t);
_WCRTLINK extern char *_tcsncset(char *, unsigned int, size_t);

/* MBCS-specific mappings */

_WCRTLINK extern char *_tcsdec(const char *, const char *);
_WCRTLINK extern char *_tcsinc(const char *);
_WCRTLINK extern size_t _tcsnbcnt(const char *, size_t);
_WCRTLINK extern size_t _tcsnccnt(const char *, size_t);
_WCRTLINK extern unsigned int _tcsnextc (const char *);
_WCRTLINK extern char *_tcsninc(const char *, size_t);
_WCRTLINK extern char *_tcsspnp(const char *, const char *);

_WCRTLINK extern char *_tcslwr(char *);
_WCRTLINK extern char *_tcsupr(char *);

_WCRTLINK extern size_t _tclen(const char *);
_WCRTLINK extern void _tccpy(char *, const char *);
_WCRTLINK extern int _tccmp(const char *, const char *);

#endif

#endif

/* ctype functions */

#define _istalnum       _ismbcalnum
#define _istalpha       _ismbcalpha
#define _istdigit       _ismbcdigit
#define _istgraph       _ismbcgraph
#define _istlegal       _ismbclegal
#define _istlower       _ismbclower
#define _istprint       _ismbcprint
#define _istpunct       _ismbcpunct
#define _istspace       _ismbcspace
#define _istupper       _ismbcupper

#define _totupper       _mbctoupper
#define _totlower       _mbctolower

#define _istlead        _ismbblead
#define _istleadbyte    isleadbyte

#else
// **************************** SBCS *****************************************

#ifndef __TCHAR_DEFINED
typedef char            _TCHAR;
typedef signed char     _TSCHAR;
typedef unsigned char   _TUCHAR;
typedef char            _TXCHAR;
typedef int             _TINT;
#define __TCHAR_DEFINED
#endif

#ifndef _TCHAR_DEFINED

#if !defined( _NO_EXT_KEYS ) /* extensions enabled */
typedef char            TCHAR;
#endif /* extensions enabled */

#define _TCHAR_DEFINED
#endif

/* String functions */

#define _tcschr         strchr
#define _tcscspn        strcspn
#define _tcsncat        strncat
#define _tcsncpy        strncpy
#define _tcspbrk        strpbrk
#define _tcsrchr        strrchr
#define _tcsspn         strspn
#define _tcsstr         strstr
#define _tcstok         strtok

#define _tcsnset        _strnset
#define _tcsrev         _strrev
#define _tcsset         _strset

#define _tcscmp         strcmp
#define _tcsicmp        _stricmp
#define _tcsnccmp       strncmp
#define _tcsncmp        strncmp
#define _tcsncicmp      _strnicmp
#define _tcsnicmp       _strnicmp

#define _tcscoll        strcoll
#define _tcsicoll       _stricoll
#define _tcsnccoll      _strncoll
#define _tcsncoll       _strncoll
#define _tcsncicoll     _strnicoll
#define _tcsnicoll      _strnicoll

/* "logical-character" mappings */

#define _tcsclen        strlen
#define _tcsnccat       strncat
#define _tcsnccpy       strncpy
#define _tcsncset       _strnset

#define _tcsdec         _strdec
#define _tcsinc         _strinc
#define _tcsnbcnt       _strncnt
#define _tcsnccnt       _strncnt
#define _tcsnextc       _strnextc
#define _tcsninc        _strninc
#define _tcsspnp        _strspnp

#define _tcslwr         _strlwr
#define _tcsupr         _strupr
#define _tcsxfrm        strxfrm

#if defined(__cplusplus) && defined(__INLINE_FUNCTIONS__)
inline size_t _tclen( const char * ) {
    return( 1 );
}
inline void _tccpy( char *__p1, const char *__p2 ) {
    *__p1 = *__p2;
}
inline int _tccmp( const char *__p1, const char *__p2 ) {
    return( (int) (((unsigned char)*__p1)-((unsigned char)*__p2)) );
}
#else
#define _tclen(__p)       (1)
#define _tccpy(__p1,__p2) ((*(__p1) = *(__p2)))
#define _tccmp(__p1,__p2) (((unsigned char)*(__p1))-((unsigned char)*(__p2)))
#endif

/* ctype functions */

#define _istalnum       isalnum
#define _istalpha       isalpha
#define _istdigit       isdigit
#define _istgraph       isgraph
#define _istlower       islower
#define _istprint       isprint
#define _istpunct       ispunct
#define _istspace       isspace
#define _istupper       isupper

#define _totupper       toupper
#define _totlower       tolower

#define _istlegal(__c)      (1)
#define _istlead(__c)       (0)
#define _istleadbyte(__c)   (0)

#if defined(__cplusplus) && defined(__INLINE_FUNCTIONS__)
inline char *_strdec( const char *, const char *__p ) {
    return( (char *)(__p-1) );
}
inline char *_strinc( const char *__p ) {
    return( (char *)(__p+1) );
}
inline unsigned int _strnextc( const char *__p ) {
    return( (unsigned int)*__p );
}
inline char *_strninc( const char *__p, size_t __l ) {
    return( (char *)(__p+__l) );
}
inline size_t _strncnt( const char *__p, size_t __l ) {
    size_t __i;
    __i = strlen(__p);
    return( (__i>__l) ? __l : __i );
}
inline char *_strspnp( const char *__p1, const char *__p2 ) {
    return( (*(__p1 += strspn(__p1,__p2))!='\0') ? (char*)__p1 : NULL );
}
#else
#define _strdec(__p1, __p2)  ((__p2)-1)
#define _strinc(__p)         ((__p)+1)
#define _strnextc(__p)       ((unsigned int) *(__p))
#define _strninc(__p, __l)   (((__p)+(__l)))
#define _strncnt(__p, __l)   ((strlen(__p)>__l) ? __l : strlen(__p))
#define _strspnp(__p1, __p2) ((*((__p1)+strspn(__p1,__p2))) ? \
                                ((__p1)+strspn(__p1,__p2)) : NULL)
#endif

#endif

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#define _T(__x)         __T(__x)
#define _TEXT(__x)      __T(__x)

#endif
