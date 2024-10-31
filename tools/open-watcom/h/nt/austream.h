/*
 *  austream.h  Audio streaming interfaces
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

#include <rpc.h>
#include <rpcndr.h>
#ifndef COM_NO_WINDOWS_H
    #include <windows.h>
    #include <ole2.h>
#endif

#ifndef __austream_h__
#define __austream_h__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#include <mmstream.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
typedef interface IAudioData            IAudioData;
typedef interface IAudioStreamSample    IAudioStreamSample;

/* IAudioMediaStream interface */
#undef INTERFACE
#define INTERFACE   IAudioMediaStream
DECLARE_INTERFACE_( IAudioMediaStream, IMediaStream ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IMediaStream methods */
    STDMETHOD( GetMultiMediaStream )( THIS_ IMultiMediaStream ** ) PURE;
    STDMETHOD( GetInformation )( THIS_ MSPID *, STREAM_TYPE * ) PURE;
    STDMETHOD( SetSameFormat )( THIS_ IMediaStream *, DWORD ) PURE;
    STDMETHOD( AllocateSample )( THIS_ DWORD, IStreamSample ** ) PURE;
    STDMETHOD( CreateSharedSample )( THIS_ IStreamSample *, DWORD, IStreamSample ** ) PURE;
    STDMETHOD( SendEndOfStream )( THIS_ DWORD ) PURE;

    /* IAudioMediaStream methods */
    STDMETHOD( GetFormat )( THIS_ WAVEFORMATEX * ) PURE;
    STDMETHOD( SetFormat )( THIS_ const WAVEFORMATEX * ) PURE;
    STDMETHOD( CreateSample )( THIS_ IAudioData *, DWORD, IAudioStreamSample ** ) PURE;
};

/* IAudioStreamSample interface */
#undef INTERFACE
#define INTERFACE   IAudioStreamSample
DECLARE_INTERFACE_( IAudioStreamSample, IStreamSample ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IStreamSample methods */
    STDMETHOD( GetMediaStream )( THIS_ IMediaStream ** ) PURE;
    STDMETHOD( GetSampleTimes )( THIS_ STREAM_TIME *, STREAM_TIME *, STREAM_TIME * ) PURE;
    STDMETHOD( SetSampleTimes )( THIS_ const STREAM_TIME *, const STREAM_TIME * ) PURE;
    STDMETHOD( Update )( THIS_ DWORD, HANDLE, PAPCFUNC, DWORD_PTR ) PURE;
    STDMETHOD( CompletionStatus )( DWORD, DWORD ) PURE;

    /* IAudioStreamSample methods */
    STDMETHOD( GetAudioData )( THIS_ IAudioData ** ) PURE;
};

/* IMemoryData interface */
#undef INTERFACE
#define INTERFACE   IMemoryData
DECLARE_INTERFACE_( IMemoryData, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IMemoryData methods */
    STDMETHOD( SetBuffer )( THIS_ DWORD, BYTE *, DWORD ) PURE;
    STDMETHOD( GetInfo )( THIS_ DWORD *, BYTE **, DWORD * ) PURE;
    STDMETHOD( SetActual )( THIS_ DWORD ) PURE;
};

/* IAudioData interface */
#undef INTERFACE
#define INTERFACE   IAudioData
DECLARE_INTERFACE_( IAudioData, IMemoryData ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IMemoryData methods */
    STDMETHOD( SetBuffer )( THIS_ DWORD, BYTE *, DWORD ) PURE;
    STDMETHOD( GetInfo )( THIS_ DWORD *, BYTE **, DWORD * ) PURE;
    STDMETHOD( SetActual )( THIS_ DWORD ) PURE;

    /* IAudioData methods */
    STDMETHOD( GetFormat )( THIS_ WAVEFORMATEX * ) PURE;
    STDMETHOD( SetFormat )( THIS_ const WAVEFORMATEX * ) PURE;
};

/* C object macros */
#if (!defined( __cplusplus ) || defined( CINTERFACE )) && defined( COBJMACROS )
    #define IAudioMediaStream_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IAudioMediaStream_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IAudioMediaStream_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IAudioMediaStream_GetMultiMediaStream( x, p ) \
        (x)->lpVtbl->GetMultiMediaStream( x, p )
    #define IAudioMediaStream_GetInformation( x, p1, p2 ) \
        (x)->lpVtbl->GetInformation( x, p1, p2 )
    #define IAudioMediaStream_SetSameFormat( x, p1, p2 ) \
        (x)->lpVtbl->SetSameFormat( x, p1, p2 )
    #define IAudioMediaStream_AllocateSample( x, p1, p2 ) \
        (x)->lpVtbl->AllocateSample( x, p1, p2 )
    #define IAudioMediaStream_CreateSharedSample( x, p1, p2, p3 ) \
        (x)->lpVtbl->CreateSharedSample( x, p1, p2, p3 )
    #define IAudioMediaStream_SendEndOfStream( x, p ) \
        (x)->lpVtbl->SendEndOfStream( x, p )
    #define IAudioMediaStream_GetFormat( x, p ) \
        (x)->lpVtbl->GetFormat( x, p )
    #define IAudioMediaStream_SetFormat( x, p ) \
        (x)->lpVtbl->SetFormat( x, p )
    #define IAudioMediaStream_CreateSample( x, p1, p2, p3 ) \
        (x)->lpVtbl->CreateSample( x, p1, p2, p3 )
    #define IAudioStreamSample_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IAudioStreamSample_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IAudioStreamSample_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IAudioStreamSample_GetMediaStream( x, p ) \
        (x)->lpVtbl->GetMediaStream( x, p )
    #define IAudioStreamSample_GetSampleTimes( x, p1, p2, p3 ) \
        (x)->lpVtbl->GetSampleTimes( x, p1, p2, p3 )
    #define IAudioStreamSample_SetSampleTimes( x, p1, p2 ) \
        (x)->lpVtbl->SetSampleTimes( x, p1, p2 ) \
    #define IAudioStreamSample_Update( x, p1, p2, p3, p4 ) \
        (x)->lpVtbl->Update( x, p1, p2, p3, p4 )
    #define IAudioStreamSample_CompletionStatus( x, p1, p2 ) \
        (x)->lpVtbl->CompletionStatus( x, p1, p2 )
    #define IAudioStreamSample_GetAudioData( x, p ) \
        (x)->lpVtbl->GetAudioData( x, p )
    #define IMemoryData_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IMemoryData_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IMemoryData_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IMemoryData_SetBuffer( x, p1, p2, p3 ) \
        (x)->lpVtbl->SetBuffer( x, p1, p2, p3 )
    #define IMemoryData_GetInfo( x, p1, p2, p3 ) \
        (x)->lpVtbl->GetInfo( x, p1, p2, p3 )
    #define IMemoryData_SetActual( x, p ) \
        (x)->lpVtbl->SetActual( x, p )
    #define IAudioData_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IAudioData_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IAudioData_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IAudioData_SetBuffer( x, p1, p2, p3 ) \
        (x)->lpVtbl->SetBuffer( x, p1, p2, p3 )
    #define IAudioData_GetInfo( x, p1, p2, p3 ) \
        (x)->lpVtbl->GetInfo( x, p1, p2, p3 )
    #define IAudioData_SetActual( x, p ) \
        (x)->lpVtbl->SetActual( x, p )
    #define IAudioData_GetFormat( x, p ) \
        (x)->lpVtbl->GetFormat( x, p )
    #define IAudioData_SetFormat( x, p ) \
        (x)->lpVtbl->SetFormat( x, p )
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

/* GUIDs */
EXTERN_C const IID  __cdecl IID_IAudioMediaStream;
EXTERN_C const IID  __cdecl IID_IAudioStreamSample;
EXTERN_C const IID  __cdecl IID_IMemoryData;
EXTERN_C const IID  __cdecl IID_IAudioData;

#endif /* __austream_h__ */
