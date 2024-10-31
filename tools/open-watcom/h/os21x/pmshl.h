/*
 *  pmshl.h     OS/2 Presentation Manager Shell include file
 *              for 16-bit development.
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

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define MAXNAMEL 60

#define XYF_NOAUTOCLOSE  0x0008
#define XYF_MINIMIZED    0x0004
#define XYF_MAXIMIZED    0x0002
#define XYF_INVISIBLE    0x0001
#define XYF_NORMAL       0x0000

#define HINI_PROFILE       (HINI) NULL
#define HINI_USERPROFILE   ((HINI)-1L)
#define HINI_SYSTEMPROFILE ((HINI)-2L)
#define HINI_USER          HINI_USERPROFILE
#define HINI_SYSTEM        HINI_SYSTEMPROFILE

#define SAF_VALIDFLAGS       0x001F
#define SAF_INSTALLEDCMDLINE 0x0001
#define SAF_STARTCHILDAPP    0x0002
#define SAF_MAXIMIZED        0x0004
#define SAF_MINIMIZED        0x0008
#define SAF_BACKGROUND       0x0010

typedef LHANDLE HAPP;
typedef LHANDLE HPROGRAM, FAR *PHPROGRAM;
typedef LHANDLE HINI, FAR *PHINI;

typedef struct _XYWINSIZE {
    SHORT  x;
    SHORT  y;
    SHORT  cx;
    SHORT  cy;
    USHORT fsWindow;
} XYWINSIZE, FAR *PXYWINSIZE;

typedef struct _PRFPROFILE {
    ULONG cchUserName;
    PSZ   pszUserName;
    ULONG cchSysName;
    PSZ   pszSysName;
} PRFPROFILE, FAR *PPRFPROFILE;

HAPP EXPENTRY WinInstStartApp(HINI,HWND,USHORT,PSZ FAR*,PSZ,PVOID,USHORT);
BOOL EXPENTRY WinTerminateApp(HAPP);

#ifdef INCL_WINPROGRAMLIST

#define MAXPATHL 128

#define SGH_ROOT ((HPROGRAM)-1L)

#define PROG_DEFAULT       (PROGCATEGORY)0
#define PROG_FULLSCREEN    (PROGCATEGORY)1
#define PROG_WINDOWABLEVIO (PROGCATEGORY)2
#define PROG_PM            (PROGCATEGORY)3
#define PROG_GROUP         (PROGCATEGORY)5
#define PROG_REAL          (PROGCATEGORY)4
#define PROG_DLL           (PROGCATEGORY)6
#define PROG_RESERVED      (PROGCATEGORY)255

#define SHE_VISIBLE   (BYTE)0x00
#define SHE_INVISIBLE (BYTE)0x01
#define SHE_RESERVED  (BYTE)0xFF

#define SHE_UNPROTECTED (BYTE)0x00
#define SHE_PROTECTED   (BYTE)0x02

typedef struct _HPROGARRAY {
    HPROGRAM ahprog[1];
} HPROGARRAY, FAR *PHPROGARRAY;

typedef CHAR PROGCATEGORY, FAR *PPROGCATEGORY;
typedef struct _PROGTYPE {
    PROGCATEGORY progc;
    UCHAR        fbVisible;
} PROGTYPE, FAR *PPROGTYPE;

typedef struct _PROGRAMENTRY {
    HPROGRAM hprog;
    PROGTYPE progt;
    CHAR     szTitle[MAXNAMEL+1];
} PROGRAMENTRY, FAR *PPROGRAMENTRY;

typedef struct _PIBSTRUCT {
    PROGTYPE  progt;
    CHAR      szTitle[MAXNAMEL+1];
    CHAR      szIconFileName[MAXPATHL+1];
    CHAR      szExecutable[MAXPATHL+1];
    CHAR      szStartupDir[MAXPATHL+1];
    XYWINSIZE xywinInitial;
    USHORT    res1;
    LHANDLE   res2;
    USHORT    cchEnvironmentVars;
    PCH       pchEnvironmentVars;
    USHORT    cchProgramParameter;
    PCH       pchProgramParameter;
} PIBSTRUCT, FAR *PPIBSTRUCT;

typedef struct _PROGDETAILS {
    ULONG     Length;
    PROGTYPE  progt;
    USHORT    pad1[3];
    PSZ       pszTitle;
    PSZ       pszExecutable;
    PSZ       pszParameters;
    PSZ       pszStartupDir;
    PSZ       pszIcon;
    PSZ       pszEnvironment;
    SWP       swpInitial;
    USHORT    pad2[5];
} PROGDETAILS, FAR *PPROGDETAILS;

typedef struct _PROGTITLE {
    HPROGRAM hprog;
    PROGTYPE progt;
    USHORT   pad1[3];
    PSZ      pszTitle;
} PROGTITLE, FAR *PPROGTITLE;

typedef struct _QFEOUTBLK {
    USHORT   Total;
    USHORT   Count;
    HPROGRAM ProgramArr[1];
} QFEOUTBLK, FAR *PQFEOUTBLK;

HPROGRAM APIENTRY WinAddProgram(HAB,PPIBSTRUCT,HPROGRAM);
HPROGRAM APIENTRY WinCreateGroup(HAB,PSZ,UCHAR,ULONG,ULONG);
USHORT   APIENTRY WinQueryDefinition(HAB,HPROGRAM,PPIBSTRUCT,USHORT);
BOOL     APIENTRY WinQueryProgramTitles(HAB,HPROGRAM,PPROGRAMENTRY,USHORT,PUSHORT);

HPROGRAM     APIENTRY PrfAddProgram(HINI,PPROGDETAILS,HPROGRAM);
BOOL         APIENTRY PrfChangeProgram(HINI,HPROGRAM,PPROGDETAILS);
HPROGRAM     APIENTRY PrfCreateGroup(HINI,PSZ,UCHAR);
BOOL         APIENTRY PrfDestroyGroup(HINI,HPROGRAM);
ULONG        APIENTRY PrfQueryDefinition(HINI,HPROGRAM,PPROGDETAILS,ULONG);
PROGCATEGORY APIENTRY PrfQueryProgramCategory(HINI,PSZ);
ULONG        APIENTRY PrfQueryProgramHandle(HINI,PSZ,PHPROGARRAY,ULONG,PULONG);
ULONG        APIENTRY PrfQueryProgramTitles(HINI,HPROGRAM,PPROGTITLE,ULONG,PULONG);
BOOL         APIENTRY PrfRemoveProgram(HINI,HPROGRAM);

#endif

#if defined(INCL_WINSWITCHLIST) || !defined(INCL_NOCOMMON)

typedef LHANDLE HSWITCH, FAR *PHSWITCH;

#define SWL_VISIBLE     (BYTE)0x04
#define SWL_INVISIBLE   (BYTE)0x01
#define SWL_GRAYED      (BYTE)0x02
#define SWL_JUMPABLE    (BYTE)0x02
#define SWL_NOTJUMPABLE (BYTE)0x01

typedef struct _SWCNTRL {
    HWND     hwnd;
    HWND     hwndIcon;
    HPROGRAM hprog;
    USHORT   idProcess;
    USHORT   idSession;
    UCHAR    uchVisibility;
    UCHAR    fbJump;
    CHAR     szSwtitle[MAXNAMEL+1];
    BYTE     fReserved;
} SWCNTRL, FAR *PSWCNTRL;

HSWITCH EXPENTRY WinAddSwitchEntry(PSWCNTRL);
USHORT  EXPENTRY WinRemoveSwitchEntry(HSWITCH);

#endif

#ifdef INCL_WINSWITCHLIST

typedef struct _SWENTRY {
    HSWITCH hswitch;
    SWCNTRL swctl;
} SWENTRY, FAR *PSWENTRY;

typedef struct _SWBLOCK {
    USHORT  cswentry;
    SWENTRY aswentry[1];
} SWBLOCK, FAR *PSWBLOCK;

USHORT   EXPENTRY WinChangeSwitchEntry(HSWITCH,PSWCNTRL);
HSWITCH  EXPENTRY WinCreateSwitchEntry(HAB,PSWCNTRL);
USHORT   EXPENTRY WinQuerySessionTitle(HAB,USHORT,PSZ,USHORT);
USHORT   EXPENTRY WinQuerySwitchEntry(HSWITCH,PSWCNTRL);
HSWITCH  EXPENTRY WinQuerySwitchHandle(HWND,PID);
USHORT   EXPENTRY WinQuerySwitchList(HAB,PSWBLOCK,USHORT);
USHORT   EXPENTRY WinQueryTaskSizePos(HAB,USHORT,PSWP);
USHORT   EXPENTRY WinQueryTaskTitle(USHORT,PSZ,USHORT);
USHORT   EXPENTRY WinSwitchToProgram(HSWITCH);

#endif

#ifdef INCL_ERRORS
    #define INCL_SHLERRORS
#endif

#ifdef INCL_WINSHELLDATA

#define PL_ALTERED 0x008E

BOOL   APIENTRY WinQueryProfileData(HAB,PSZ,PSZ,PVOID,PUSHORT);
SHORT  APIENTRY WinQueryProfileInt(HAB,PSZ,PSZ,SHORT);
USHORT APIENTRY WinQueryProfileSize(HAB,PSZ,PSZ,PUSHORT);
USHORT APIENTRY WinQueryProfileString(HAB,PSZ,PSZ,PSZ,PVOID,USHORT);
BOOL   APIENTRY WinWriteProfileData(HAB,PSZ,PSZ,PVOID,USHORT);
BOOL   APIENTRY WinWriteProfileString(HAB,PSZ,PSZ,PSZ);

BOOL   APIENTRY PrfCloseProfile(HINI);
HINI   APIENTRY PrfOpenProfile(HAB,PSZ);
BOOL   APIENTRY PrfQueryProfile(HAB,PPRFPROFILE);
BOOL   APIENTRY PrfQueryProfileData(HINI,PSZ,PSZ,PVOID,PULONG);
SHORT  APIENTRY PrfQueryProfileInt(HINI,PSZ,PSZ,SHORT);
BOOL   APIENTRY PrfQueryProfileSize(HINI,PSZ,PSZ,PULONG);
ULONG  APIENTRY PrfQueryProfileString(HINI,PSZ,PSZ,PSZ,PVOID,ULONG);
BOOL   APIENTRY PrfReset(HAB,PPRFPROFILE);
BOOL   APIENTRY PrfWriteProfileData(HINI,PSZ,PSZ,PVOID,ULONG);
BOOL   APIENTRY PrfWriteProfileString(HINI,PSZ,PSZ,PSZ);

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#ifdef INCL_SHLERRORS
    #include <pmerr.h>
#endif
