/*
 *  amvideo.h   ActiveMovie video interfaces
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

#ifndef __AMVIDEO__
#define __AMVIDEO__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#include <ddraw.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Reference time data type */
typedef LONGLONG    REFERENCE_TIME;

/* ActiveMovie DirectDraw switches */
#define AMDDS_NONE      0x00
#define AMDDS_DCIPS     0x01
#define AMDDS_PS        0x02
#define AMDDS_RGBOVR    0x04
#define AMDDS_YUVOVR    0x08
#define AMDDS_RGBOFF    0x10
#define AMDDS_YUVOFF    0x20
#define AMDDS_RGBFLP    0x40
#define AMDDS_YUVFLP    0x80
#define AMDDS_ALL       0xFF
#define AMDDS_DEFAULT   AMDDS_ALL
#define AMDDS_YUV       (AMDDS_YUVOFF | AMDDS_YUVOVR | AMDDS_YUVFLP)
#define AMDDS_RGB       (AMDDS_RGBOFF | AMDDS_RGBOVR | AMDDS_RGBFLP)
#define AMDDS_PRIMARY   (AMDDS_DCIPS | AMDDS_PS)

/* Color indices */
#define iPALETTE_COLORS 256
#define iEGA_COLORS     16
#define iMASK_COLORS    3
#define iTRUECOLOR      16
#define iRED            0
#define iGREEN          1
#define iBLUE           2
#define iPALETTE        8
#define iMIXBITS        8

/* Palette sizes */
#define SIZE_EGA_PALETTE    (iEGA_COLORS * sizeof( RGBQUAD ))
#define SIZE_PALETTE        (iPALETTE_COLORS * sizeof( RGBQUAD ))
#define SIZE_MASKS          (iMASK_COLORS * sizeof( DWORD ))
#define SIZE_VIDEOHEADER    sizeof( VIDEOINFOHEADER )
#define SIZE_PREHEADER      (SIZE_VIDEOHEADER + sizeof( BITMAPINFOHEADER ))

/* Macros to get DIB size information */
#define WIDTHBYTES( x )     (DWORD)(((x) + 31) & ~31) / 8)
#define DIBWIDTHBYTES( x )  WIDTHBYTES( (DWORD)(x).biWidth * (DWORD)(x).biBitCount )
#define _DIBSIZE( x )       (DIBWIDTHBYTES( x ) * (DWORD)(x).biHeight)
#define DIBSIZE( x )        ((x).biHeight < 0 ? (-1) * _DIBSIZE( x ) : _DIBSIZE( x ))

/* Macros to manipulate bit masks */
#define BIT_MASKS_MATCH( p1, p2 ) \
    (((p1)->dwBitMasks[iRED] == (p2)->dwBitMasks[iRED]) && \
    ((p1)->dwBitMasks[iGREEN] == (p2)->dwBitMasks[iGREEN]) && \
    ((p1)->dwBitMasks[iBLUE] == (p2)->dwBitMasks[iBLUE]))
#define RESET_MASKS( x )    ZeroMemory( (PVOID)(x)->dwBitFields, SIZE_MASKS )
#define RESET_HEADER( x )   ZeroMemory( (PVOID)(x), SIZE_VIDEOHEADER )
#define RESET_PALETTE( x )  ZeroMemory( (PVOID)(x)->bmiColors, SIZE_PALETTE )

/* Other palette-related macros */
#define PALETTISED( x )         ((x)->bmiHeader.biBitCount <= iPALETTE)
#define PALETTE_ENTRIES( x )    ((DWORD)1 << (x)->bmiHeader.biBitCount)
#define HEADER( x )             (&(((VIDEOINFOHEADER *)(x))->bmiHeader))

/* Maximum MPEG-1 sequence information size */
#define MAX_SIZE_MPEG1_SEQUENCE_INFO    140

/* True color information */
typedef struct tag_TRUECOLORINFO {
    DWORD   dwBitMasks[iMASK_COLORS];
    RGBQUAD bmiColors[iPALETTE_COLORS];
} TRUECOLORINFO;

/* Video information header */
typedef struct tagVIDEOINFOHEADER {
    RECT                rcSource;
    RECT                rcTarget;
    DWORD               dwBitRate;
    DWORD               dwBitErrorRate;
    REFERENCE_TIME      AvgTimePerFrame;
    BITMAPINFOHEADER    bmiHeader;
} VIDEOINFOHEADER;

/* Macros to manipulate color information */
#define TRUECOLOR( x ) \
    ((TRUECOLORINFO *)(((LPBYTE)&((x)->bmiHeader) + (x)->bmiHeader.biSize))
#define COLORS( x ) \
    ((RGBQUAD *)(((LPBYTE)&((x)->bmiHeader)) + (x)->bmiHeader.biSize))
#define BITMASKS( x ) \
    ((DWORD *)(((LPBYTE)&((x)->bmiHeader)) + (x)->bmiHeader.biSize))

/* Video information */
typedef struct tagVIDEOINFO {
    RECT                rcSource;
    RECT                rcTarget;
    DWORD               dwBitRate;
    DWORD               dwBitErrorRate;
    REFERENCE_TIME      AvgTimePerFrame;
    BITMAPINFOHEADER    bmiHeader;
    union {
        RGBQUAD         bmiColors[iPALETTE_COLORS];
        DWORD           dwBitsMasks[iMASK_COLORS];
        TRUECOLORINFO   TrueColorInfo;
    };
} VIDEOINFO;

/* MPEG-1 video information */
typedef struct tagMPEG1VIDEOINFO {
    VIDEOINFOHEADER hdr;
    DWORD           dwStartTimeCode;
    DWORD           cbSequenceHeader;
    BYTE            bSequenceHeader[1];
} MPEG1VIDEOINFO;

/* Macros to manipulate MPEG-1 video information */
#define SIZE_MPEG1_VIDEOINFO( x ) \
    (sizeof( MPEG1VIDEOINFO ) - sizeof( BYTE ) + (x)->cbSequenceHeader)
#define MPEG1_SEQUENCE_INFO( x )    ((const BYTE *)(x)->bSequenceHeader)

/* Analog video information */
typedef struct tagAnalogVideoInfo {
    RECT            rcSource;
    RECT            rcTarget;
    DWORD           dwActiveWidth;
    DWORD           dwActiveHeight;
    REFERENCE_TIME  AvgTimePerFrame;
} ANALOGVIDEOINFO;

/* ActiveMovie frame step values */
typedef enum {
    AM_PROPERTY_FRAMESTEP_STEP              = 0x01,
    AM_PROPERTY_FRAMESTEP_CANCEL            = 0x02,
    AM_PROPERTY_FRAMESTEP_CANSTEP           = 0x03,
    AM_PROPERTY_FRAMESTEP_CANSTEPMULTIPLE   = 0x04
} AM_PROPERTY_FRAMESTEP;

/* ActiveMovie frame step */
typedef struct _AM_FRAMESTEP_STEP {
    DWORD   dwFramesToStep;
} AM_FRAMESTEP_STEP;

/* IDirectDrawVideo interface */
#undef INTERFACE
#define INTERFACE   IDirectDrawVideo
DECLARE_INTERFACE_( IDirectDrawVideo, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IDirectDrawVideo methods */
    STDMETHOD( GetSwitches )( THIS_ DWORD * ) PURE;
    STDMETHOD( SetSwitches )( THIS_ DWORD ) PURE;
    STDMETHOD( GetCaps )( THIS_ DDCAPS * ) PURE;
    STDMETHOD( GetEmulatedCaps )( THIS_ DDCAPS * ) PURE;
    STDMETHOD( GetSurfaceDesc )( THIS_ DDSURFACEDESC * ) PURE;
    STDMETHOD( GetFourCCCodes )( THIS_ DWORD *, DWORD * ) PURE;
    STDMETHOD( SetDirectDraw )( THIS_ LPDIRECTDRAW ) PURE;
    STDMETHOD( GetDirectDraw )( THIS_ LPDIRECTDRAW * ) PURE;
    STDMETHOD( GetSurfaceType )( THIS_ DWORD * ) PURE;
    STDMETHOD( SetDefault )( THIS ) PURE;
    STDMETHOD( UseScanLine )( THIS_ long ) PURE;
    STDMETHOD( CanUseScanLine )( THIS_ long * ) PURE;
    STDMETHOD( UseOverlayStretch )( THIS_ long ) PURE;
    STDMETHOD( CanUseOverlayStretch )( THIS_ long * ) PURE;
    STDMETHOD( UseWhenFullScreen )( THIS_ long ) PURE;
    STDMETHOD( WillUseFullScreen )( THIS_ long * ) PURE;
};

/* IQualProp interface */
#undef INTERFACE
#define INTERFACE   IQualProp
DECLARE_INTERFACE_( IQualProp, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IQualProp methods */
    STDMETHOD( get_FramesDroppedInRenderer )( THIS_ int * ) PURE;
    STDMETHOD( get_FramesDrawn )( THIS_ int * ) PURE;
    STDMETHOD( get_AvgFrameRate )( THIS_ int * ) PURE;
    STDMETHOD( get_Jitter )( THIS_ int * ) PURE;
    STDMETHOD( get_AvgSyncOffset )( THIS_ int * ) PURE;
    STDMETHOD( get_DevSyncOffset )( THIS_ int * ) PURE;
};

/* IFullScreenVideo interface */
#undef INTERFACE
#define INTERFACE   IFullScreenVideo
DECLARE_INTERFACE_( IFullScreenVideo, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IFullScreenVideo methods */
    STDMETHOD( CountModes )( THIS_ long * ) PURE;
    STDMETHOD( GetModeInfo )( THIS_ long, long *, long *, long * ) PURE;
    STDMETHOD( GetCurrentMode )( THIS_ long * ) PURE;
    STDMETHOD( IsModeAvailable )( THIS_ long ) PURE;
    STDMETHOD( IsModeEnabled )( THIS_ long ) PURE;
    STDMETHOD( SetEnabled )( THIS_ long, long ) PURE;
    STDMETHOD( GetClipFactor )( THIS_ long * ) PURE;
    STDMETHOD( SetClipFactor )( THIS_ long ) PURE;
    STDMETHOD( SetMessageDrain )( THIS_ HWND ) PURE;
    STDMETHOD( GetMessageDrain )( THIS_ HWND * ) PURE;
    STDMETHOD( SetMonitor )( THIS_ long ) PURE;
    STDMETHOD( GetMonitor )( THIS_ long * ) PURE;
    STDMETHOD( HideOnDeactivate )( THIS_ long ) PURE;
    STDMETHOD( IsHideOnDeactivate )( THIS ) PURE;
    STDMETHOD( SetCaption )( THIS_ BSTR ) PURE;
    STDMETHOD( GetCaption )( THIS_ BSTR * ) PURE;
    STDMETHOD( SetDefault )( THIS ) PURE;
};

/* IFullScreenVideoEx interface */
#undef INTERFACE
#define INTERFACE   IFullScreenVideoEx
DECLARE_INTERFACE_( IFullScreenVideoEx, IFullScreenVideo ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IFullScreenVideo methods */
    STDMETHOD( CountModes )( THIS_ long * ) PURE;
    STDMETHOD( GetModeInfo )( THIS_ long, long *, long *, long * ) PURE;
    STDMETHOD( GetCurrentMode )( THIS_ long * ) PURE;
    STDMETHOD( IsModeAvailable )( THIS_ long ) PURE;
    STDMETHOD( IsModeEnabled )( THIS_ long ) PURE;
    STDMETHOD( SetEnabled )( THIS_ long, long ) PURE;
    STDMETHOD( GetClipFactor )( THIS_ long * ) PURE;
    STDMETHOD( SetClipFactor )( THIS_ long ) PURE;
    STDMETHOD( SetMessageDrain )( THIS_ HWND ) PURE;
    STDMETHOD( GetMessageDrain )( THIS_ HWND * ) PURE;
    STDMETHOD( SetMonitor )( THIS_ long ) PURE;
    STDMETHOD( GetMonitor )( THIS_ long * ) PURE;
    STDMETHOD( HideOnDeactivate )( THIS_ long ) PURE;
    STDMETHOD( IsHideOnDeactivate )( THIS ) PURE;
    STDMETHOD( SetCaption )( THIS_ BSTR ) PURE;
    STDMETHOD( GetCaption )( THIS_ BSTR * ) PURE;
    STDMETHOD( SetDefault )( THIS ) PURE;

    /* IFullScreenVideoEx methods */
    STDMETHOD( SetAcceleratorTable )( THIS_ HWND, HACCEL ) PURE;
    STDMETHOD( GetAcceleratorTable )( THIS_ HWND *, HACCEL * ) PURE;
    STDMETHOD( KeepPixelAspectRatio )( THIS_ long ) PURE;
    STDMETHOD( IsKeepPixelAspectRatio )( THIS_ long * ) PURE;
};

/* IBaseVideoMixer interface */
#undef INTERFACE
#define INTERFACE   IBaseVideoMixer
DECLARE_INTERFACE_( IBaseVideoMixer, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IBaseVideoMixer methods */
    STDMETHOD( SetLeadPin )( THIS_ int ) PURE;
    STDMETHOD( GetLeadPin )( THIS_ int * ) PURE;
    STDMETHOD( GetInputPinCount )( THIS_ int * ) PURE;
    STDMETHOD( IsUsingClock )( THIS_ int * ) PURE;
    STDMETHOD( SetUsingClock )( THIS_ int ) PURE;
    STDMETHOD( GetClockPeriod )( THIS_ int * ) PURE;
    STDMETHOD( SetClockPeriod )( THIS_ int ) PURE;
};

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __AMVIDEO__ */
