/*
 *  dde.h       Dynamic Data Exchange (DDE) definitions
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

#ifndef _INC_DDE
#define _INC_DDE

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifndef _INC_WINDOWS
    #include <windows.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack( __push, 1 )

/* DDE messages */
#define WM_DDE_FIRST        0x03E0
#define WM_DDE_INITIATE     (WM_DDE_FIRST + 0)
#define WM_DDE_TERMINATE    (WM_DDE_FIRST + 1)
#define WM_DDE_ADVISE       (WM_DDE_FIRST + 2)
#define WM_DDE_UNADVISE     (WM_DDE_FIRST + 3)
#define WM_DDE_ACK          (WM_DDE_FIRST + 4)
#define WM_DDE_DATA         (WM_DDE_FIRST + 5)
#define WM_DDE_REQUEST      (WM_DDE_FIRST + 6)
#define WM_DDE_POKE         (WM_DDE_FIRST + 7)
#define WM_DDE_EXECUTE      (WM_DDE_FIRST + 8)
#define WM_DDE_LAST         (WM_DDE_FIRST + 8)

#ifndef RC_INVOKED

/* Structure used with WM_DDE_ACK */
typedef struct tagDDEACK {
    unsigned short  bAppReturnCode  : 8;
    unsigned short  reserved        : 6;
    unsigned short  fBusy           : 1;
    unsigned short  fAck            : 1;
} DDEACK;

/* Structure used with WM_DDE_ADVISE */
typedef struct tagDDEADVISE {
    unsigned short  reserved    : 14;
    unsigned short  fDeferUpd   : 1;
    unsigned short  fAckReq     : 1;
    short           cfFormat;
} DDEADVISE;

/* Structure used with WM_DDE_DATA */
typedef struct tagDDEDATA {
    unsigned short  unused      : 12;
    unsigned short  fResponse   : 1;
    unsigned short  fRelease    : 1;
    unsigned short  reserved    : 1;
    unsigned short  fAckReq     : 1;
    short           cfFormat;
    BYTE            Value[1];
} DDEDATA;

/* Structure used with WM_DDE_POKE */
typedef struct tagDDEPOKE {
    unsigned short  unused      : 13;
    unsigned short  fRelease    : 1;
    unsigned short  fReserved   : 2;
    short           cfFormat;
    BYTE            Value[1];
} DDEPOKE;

/* Structure retained for compatibility */
typedef struct tagDDELN {
    unsigned short  unused      : 13;
    unsigned short  fRelease    : 1;
    unsigned short  fDeferUpd   : 1;
    unsigned short  fAckReq     : 1;
    short           cfFormat;
} DDELN;

/* Another structure retained for compatibility */
typedef struct tagDDEUP {
    unsigned short  unused      : 12;
    unsigned short  fAck        : 1;
    unsigned short  fRelease    : 1;
    unsigned short  fReserved   : 1;
    unsigned short  fAckReq     : 1;
    short           cfFormat;
    BYTE            rgb[1];
} DDEUP;

#endif /* RC_INVOKED */

#pragma pack( __pop )

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _INC_DDE */
