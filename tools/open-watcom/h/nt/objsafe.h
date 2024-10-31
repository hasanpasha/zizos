/*
 *  objsafe.h   Object safety interface
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

#ifndef __objsafe_h__
#define __objsafe_h__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Interface safety option flags */
#define INTERFACESAFE_FOR_UNTRUSTED_CALLER  0x00000001L
#define INTERFACESAFE_FOR_UNTRUSTED_DATA    0x00000002L
#define INTERFACE_USES_DISPEX               0x00000004L
#define INTERFACE_USES_SECURITY_MANAGER     0x00000008L

/* IObjectSafety interface */
#undef INTERFACE
#define INTERFACE   IObjectSafety
DECLARE_INTERFACE_( IObjectSafety, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IObjectSafety methods */
    STDMETHOD( GetInterfaceSafetyOptions )( THIS_ REFIID, DWORD *, DWORD * ) PURE;
    STDMETHOD( SetInterfaceSafetyOptions )( THIS_ REFIID, DWORD, DWORD ) PURE;
};
typedef IObjectSafety   *LPOBJECTSAFETY;

/* C object macros */
#if (!defined( __cplusplus ) || defined( CINTERFACE )) && defined( COBJMACROS )
    #define IObjectSafety_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IObjectSafety_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IObjectSafety_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IObjectSafety_GetInterfaceSafetyOptions( x, p1, p2, p3 ) \
        (x)->lpVtbl->GetInterfaceSafetyOptions( x, p1, p2, p3 )
    #define IObjectSafety_SetInterfaceSafetyOptions( x, p1, p2, p3 ) \
        (x)->lpVtbl->SetInterfaceSafetyOptions( x, p1, p2, p3 )
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

/* GUIDs */
EXTERN_C const IID  __cdecl IID_IObjectSafety;

#endif /* __objsafe_h__ */
