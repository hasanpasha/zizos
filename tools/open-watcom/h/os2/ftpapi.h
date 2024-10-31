/*
 *  ftpapi.h    OS/2 FTPAPI include file for 32-bit development.
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

#ifndef __FTPAPI_H__
#define __FTPAPI_H__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if (defined(__IBMC__) || defined(__WATCOMC__)) && !defined(TCP_NODEFLIB)
#pragma library("ftpapi.lib")
#endif

#define T_ASCII   1
#define T_EBCDIC  2
#define T_BINARY  3

#define M_OVERLAY 1
#define M_APPEND  2

#define TRCMODE   1
#define TRCOPEN   2

#define FTPSERVICE    1
#define FTPHOST       2
#define FTPSOCKET     3
#define FTPCONNECT    4
#define FTPLOGIN      5
#define FTPABORT      6
#define FTPLOCALFILE  7
#define FTPDATACONN   8
#define FTPCOMMAND    9
#define FTPPROXYTHIRD 10
#define FTPNOPRIMARY  11
#define FTPNOXLATETBL 12

#define PINGREPLY  (-1)
#define PINGSOCKET (-3)
#define PINGPROTO  (-4)
#define PINGSEND   (-5)
#define PINGRECV   (-6)
#define PINGHOST   (-7)

#define REST_GET 1
#define REST_PUT 2

#if defined(__WATCOMC__)
#pragma aux ftperrno "*"
#endif

extern int ftperrno;

int  _System ftp_errno(void);
int  _System ftpappend(char *, char *, char *, char *, char *, char *, int);
int  _System ftpcd(char *, char *, char *, char *, char *);
int  _System ftpdelete(char *, char *, char *, char *, char *);
int  _System ftpdir(char *, char *, char *, char *, char *, char *);
int  _System ftpget(char *, char *, char *, char *, char *, char *, char *, int);
int  _System ftpmkd(char *, char *, char *, char *, char *);
void _System ftplogoff(void);
int  _System ftpls(char *, char *, char *, char *, char *, char *);
int  _System ftpping(char *, int, unsigned long *);
int  _System ftpproxy(char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, int);
int  _System ftpput(char *, char *, char *, char *, char *, char *, int);
int  _System ftpputunique(char *, char *, char *, char *, char *, char *, int);
int  _System ftppwd(char *, char *, char *, char *, char *, int);
int  _System ftpquote(char *, char *, char *, char *, char *);
int  _System ftprmd(char *, char *, char *, char *, char *);
int  _System ftprename(char *, char *, char *, char *, char *, char *);
long _System ftpremsize(char *, char *, char *, char *, char *, char *, char *, int);
long _System ftprestart(char *, char *, char *, char *, char *, char *, char *, int, int);
int  _System ftpsite(char *, char *, char *, char *, char *);
int  _System ftpsys(char *, char *, char *, char *, char *, int);
int  _System ftptrcoff(void);
int  _System ftptrcon(char *, int);
int  _System ftpver(char *, int);
int  _System ftpxlate(unsigned long, char *);
int  _System keep_file_date (char*, char*);
int  _System ping(unsigned long, int);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
