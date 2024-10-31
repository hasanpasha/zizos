/*
 *  sqltypes.h  Open Database Connectivity (ODBC) data types
 *
 * =========================================================================
 *
 *                          Open Watcom Project
 *
 * Copyright (c) 2004-2024 The Open Watcom Contributors. All Rights Reserved.
 *
 *    This file is automatically generated. Do not edit directly.
 *
 * =========================================================================
 */

#ifndef __SQLTYPES
#define __SQLTYPES

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Define default ODBC version number. */
#ifndef ODBCVER
    #define ODBCVER 0x0380
#endif

/* ODBC calling convention */
#define SQL_API __stdcall

/* ODBC primitive data types */
typedef unsigned char       SQLCHAR;
#if (ODBCVER >= 0x0300)
typedef signed char         SQLSCHAR;
typedef unsigned char       SQLDATE;
typedef unsigned char       SQLDECIMAL;
typedef double              SQLDOUBLE;
typedef double              SQLFLOAT;
#endif
typedef long                SQLINTEGER;
typedef unsigned long       SQLUINTEGER;
#if (ODBCVER >= 0x0300)
typedef unsigned char       SQLNUMERIC;
#endif
typedef void                *SQLPOINTER;
#if (ODBCVER >= 0x0300)
typedef float               SQLREAL;
#endif
typedef short               SQLSMALLINT;
typedef unsigned short      SQLUSMALLINT;
#if (ODBCVER >= 0x0300)
typedef unsigned char       SQLTIME;
typedef unsigned char       SQLTIMESTAMP;
typedef unsigned char       SQLVARCHAR;
#endif
typedef SQLINTEGER          SQLLEN;
typedef SQLUINTEGER         SQLULEN;
typedef SQLUSMALLINT        SQLSETPOSIROW;
typedef SQLULEN             SQLROWCOUNT;
typedef SQLULEN             SQLROWSETSIZE;
typedef SQLULEN             SQLTRANSID;
typedef SQLLEN              SQLROWOFFSET;
typedef SQLSMALLINT         SQLRETURN;

/* ODBC handle data types */
#if (ODBCVER >= 0x0300)
typedef void        *SQLHANDLE;
typedef SQLHANDLE   SQLHENV;
typedef SQLHANDLE   SQLHDBC;
typedef SQLHANDLE   SQLHSTMT;
typedef SQLHANDLE   SQLHDESC;
#else
typedef void        *SQLHENV;
typedef void        *SQLHDBC;
typedef void        *SQLHSTMT;
#endif

/* Portable primitive data types */
typedef unsigned char       UCHAR;
typedef signed char         SCHAR;
typedef SCHAR               SQLSCHAR;
typedef long                SDWORD;
typedef short               SWORD;
typedef unsigned long       UDWORD;
typedef unsigned short      UWORD;
typedef UDWORD              SQLUINTEGER;
typedef signed long         SLONG;
typedef signed short        SSHORT;
typedef unsigned long       ULONG;
typedef unsigned short      USHORT;
typedef double              SDOUBLE;
typedef double              LDOUBLE;
typedef float               SFLOAT;
typedef void                *PTR;
typedef void                *HENV;
typedef void                *HDBC;
typedef void                *HSTMT;
typedef signed short        RETCODE;
typedef HWND                SQLHWND;

/* ODBC large integer data types */
#define ODBCINT64           __int64
typedef ODBCINT64           SQLBIGINT;
typedef unsigned ODBCINT64  SQLUBIGINT;

/* ODBC GUID */
#if (ODBCVER >= 0x0350)
typedef GUID    SQLGUID;
#endif

/* Bookmark primitive data type */
typedef SQLULEN BOOKMARK;

/* ODBC string data types */
typedef wchar_t     SQLWCHAR;
#ifdef UNICODE
typedef SQLWCHAR    SQLTCHAR;
#else
typedef SQLCHAR     SQLTCHAR;
#endif

/* ODBC maximum numeric length */
#if (ODBCVER >= 0x0300)
    #define SQL_MAX_NUMERIC_LEN 16
#endif

/* Date structure */
typedef struct tagDATE_STRUCT {
    SQLSMALLINT     year;
    SQLUSMALLINT    month;
    SQLUSMALLINT    day;
} DATE_STRUCT;
#if (ODBCVER >= 0x0300)
typedef DATE_STRUCT SQL_DATE_STRUCT;
#endif

/* Time structure */
typedef struct tagTIME_STRUCT {
    SQLUSMALLINT    hour;
    SQLUSMALLINT    minute;
    SQLUSMALLINT    second;
} TIME_STRUCT;
#if (ODBCVER >= 0x0300)
typedef TIME_STRUCT SQL_TIME_STRUCT;
#endif

/* Timestamp structure */
typedef struct tagTIMESTAMP_STRUCT {
    SQLSMALLINT     year;
    SQLUSMALLINT    month;
    SQLUSMALLINT    day;
    SQLUSMALLINT    hour;
    SQLUSMALLINT    minute;
    SQLUSMALLINT    second;
    SQLUINTEGER     fraction;
} TIMESTAMP_STRUCT;
#if (ODBCVER >= 0x0300)
typedef TIMESTAMP_STRUCT    SQL_TIMESTAMP_STRUCT;
#endif

/* ODBC interval codes */
#if (ODBCVER >= 0x0300)
typedef enum {
    SQL_IS_YEAR             = 1,
    SQL_IS_MONTH            = 2,
    SQL_IS_DAY              = 3,
    SQL_IS_HOUR             = 4,
    SQL_IS_MINUTE           = 5,
    SQL_IS_SECOND           = 6,
    SQL_IS_YEAR_TO_MONTH    = 7,
    SQL_IS_DAY_TO_MONTH     = 8,
    SQL_IS_DAY_TO_MINUTE    = 9,
    SQL_IS_DAY_TO_SECOND    = 10,
    SQL_IS_HOUR_TO_MINUTE   = 11,
    SQL_IS_HOUR_TO_SECOND   = 12,
    SQL_IS_MINUTE_TO_SECOND = 13
} SQLINTERVAL;
#endif

/* ODBC year and month structure */
#if (ODBCVER >= 0x0300)
typedef struct tagSQL_YEAR_MONTH {
    SQLUINTEGER year;
    SQLUINTEGER month;
} SQL_YEAR_MONTH_STRUCT;
#endif

/* ODBC day and second structure */
#if (ODBCVER >= 0x0300)
typedef struct tagSQL_DAY_SECOND {
    SQLUINTEGER day;
    SQLUINTEGER hour;
    SQLUINTEGER minute;
    SQLUINTEGER second;
    SQLUINTEGER fraction;
} SQL_DAY_SECOND_STRUCT;
#endif

/* ODBC interval structure */
#if (ODBCVER >= 0x0300)
typedef struct tagSQL_INTERVAL_STRUCT {
    SQLINTERVAL interval_type;
    SQLSMALLINT interval_sign;
    union {
        SQL_YEAR_MONTH_STRUCT   year_month;
        SQL_DAY_SECOND_STRUCT   day_second;
    } intval;
} SQL_INTERVAL_STRUCT;
#endif

/* ODBC numeric structure */
#if (ODBCVER >= 0x0300)
typedef struct tagSQL_NUMERIC_STRUCT {
    SQLCHAR     precision;
    SQLSCHAR    scale;
    SQLCHAR     sign;
    SQLCHAR     val[SQL_MAX_NUMERIC_LEN];
} SQL_NUMERIC_STRUCT;
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __SQLTYPES */
