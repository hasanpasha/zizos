/*
 *  dispex.h    Definition of IDispatchEx and related interfaces
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

#ifndef __dispex_h__
#define __dispex_h__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#include <ocidl.h>
#include <oleidl.h>
#include <oaidl.h>
#include <servprov.h>

#ifdef __cplusplus
extern "C" {
#endif

/* IDispatchEx::GetDispID() flags */
#define fdexNameCaseSensitive       0x00000001L
#define fdexNameEnsure              0x00000002L
#define fdexNameImplicit            0x00000004L
#define fdexNameCaseInsensitive     0x00000008L
#define fdexNameInternal            0x00000010L
#define fdexNameNoDynamicProperties 0x00000020L

/* IDispatchEx::GetMemberProperties() flags */
#define fdexPropCanGet              0x00000001L
#define fdexPropCannotGet           0x00000002L
#define fdexPropCanPut              0x00000004L
#define fdexPropCannotPut           0x00000008L
#define fdexPropCanPutRef           0x00000010L
#define fdexPropCannotPutRef        0x00000020L
#define fdexPropNoSideEffects       0x00000040L
#define fdexPropDynamicType         0x00000080L
#define fdexPropCanCall             0x00000100L
#define fdexPropCannotCall          0x00000200L
#define fdexPropCanConstruct        0x00000400L
#define fdexPropCannotConstruct     0x00000800L
#define fdexPropCanSourceEvents     0x00001000L
#define fdexPropCannotSourceEvents  0x00002000L
#define grfdexPropCanAll \
    (fdexPropCanGet | fdexPropCanPut | fdexPropCanPutRef | fdexPropCanCall | \
    fdexPropCanConstruct | fdexPropCanSourceEvents)
#define grfdexPropCannotAll \
    (fdexPropCannotGet | fdexPropCannotPut | fdexPropCannotPutRef | \
    fdexPropCannotCall | fdexPropCannotConstruct | fdexPropCannotSourceEvents)
#define grfdexPropExtraAll          (fdexPropNoSideEffects | fdexPropDynamicType)
#define grfdexPropAll \
    (grfdexPropCanAll | grfdexPropCannotAll | grfdexPropExtraAll)

/* IDispatchEx::GetNextDispID() flags */
#define fdexEnumDefault 0x00000001L
#define fdexEnumAll     0x00000002L

/* Additional IDispatch::Invoke() flags */
#define DISPATCH_CONSTRUCT  0x00004000L

/* Standard dispatch identifiers */
#define DISPID_THIS         (-613)
#define DISPID_STARTENUM    DISPID_UNKNOWN

/* IDispatchEx interface */
#undef INTERFACE
#define INTERFACE   IDispatchEx
DECLARE_INTERFACE_( IDispatchEx, IDispatch ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;
    
    /* IDispatch methods */
    STDMETHOD( GetTypeInfoCount )( THIS_ UINT * ) PURE;
    STDMETHOD( GetTypeInfo )( THIS_ UINT, LCID, ITypeInfo ** ) PURE;
    STDMETHOD( GetIDsOfNames )( THIS_ REFIID, LPOLESTR *, UINT, LCID, DISPID * ) PURE;
    STDMETHOD( Invoke )( THIS_ DISPID, REFIID, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT * ) PURE;

    /* IDispatchEx methods */
    STDMETHOD( GetDispID )( THIS_ BSTR, DWORD, DISPID * ) PURE;
    STDMETHOD( InvokeEx )( THIS_ DISPID, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, IServiceProvider * ) PURE;
    STDMETHOD( DeleteMemberByName )( THIS_ BSTR, DWORD ) PURE;
    STDMETHOD( DeleteMemberByDispID )( THIS_ DISPID ) PURE;
    STDMETHOD( GetMemberProperties )( THIS_ DISPID, DWORD, DWORD * ) PURE;
    STDMETHOD( GetMemberName )( THIS_ DISPID, BSTR * ) PURE;
    STDMETHOD( GetNextDispID )( THIS_ DWORD, DISPID, DISPID * ) PURE;
    STDMETHOD( GetNameSpaceParent )( THIS_ IUnknown ** ) PURE;
};

/* IDispError interface */
#undef INTERFACE
#define INTERFACE   IDispError
DECLARE_INTERFACE_( IDispError, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IDispError methods */
    STDMETHOD( QueryErrorInfo )( THIS_ GUID, IDispError ** ) PURE;
    STDMETHOD( GetNext )( THIS_ IDispError ** ) PURE;
    STDMETHOD( GetHresult )( THIS_ HRESULT * ) PURE;
    STDMETHOD( GetSource )( THIS_ BSTR * ) PURE;
    STDMETHOD( GetHelpInfo )( THIS_ BSTR *, DWORD * ) PURE;
    STDMETHOD( GetDescription )( THIS_ BSTR * ) PURE;
};

/* IVariantChangeType interface */
#undef INTERFACE
#define INTERFACE   IVariantChangeType
DECLARE_INTERFACE_( IVariantChangeType, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IVariantChangeType methods */
    STDMETHOD( ChangeType )( THIS_ VARIANT *, VARIANT *, LCID, VARTYPE ) PURE;
};

/* IObjectIdentity interface */
#undef INTERFACE
#define INTERFACE   IObjectIdentity
DECLARE_INTERFACE_( IObjectIdentity, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IObjectIdentity methods */
    STDMETHOD( IsEqualObject )( THIS_ IUnknown * ) PURE;
};

/* IProvideRuntimeContext interface */
#undef INTERFACE
#define INTERFACE   IProvideRuntimeContext
DECLARE_INTERFACE_( IProvideRuntimeContext, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IProvideRuntimeContext methods */
    STDMETHOD( GetCurrentSourceContext )( THIS_ DWORD_PTR *, VARIANT_BOOL * ) PURE;
};

/* C object macros */
#if (!defined( __cplusplus ) || defined( CINTERFACE )) && defined( COBJMACROS )
    #define IDispatchEx_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IDispatchEx_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IDispatchEx_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IDispatchEx_GetTypeInfoCount( x, p ) \
        (x)->lpVtbl->GetTypeInfoCount( x, p )
    #define IDispatchEx_GetTypeInfo( x, p1, p2, p3 ) \
        (x)->lpVtbl->GetTypeInfo( x, p1, p2, p3 )
    #define IDispatchEx_GetIDsOfNames( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->GetIDsOfNames( x, p1, p2, p3, p4, p5 )
    #define IDispatchEx_Invoke( x, p1, p2, p3, p4, p5, p6, p7, p8 ) \
        (x)->lpVtbl->Invoke( x, p1, p2, p3, p4, p5, p6, p7, p8 )
    #define IDispatchEx_GetDispID( x, p1, p2, p3 ) \
        (x)->lpVtbl->GetDispID( x, p1, p2, p3 )
    #define IDispatchEx_InvokeEx( x, p1, p2, p3, p4, p5, p6, p7 ) \
        (x)->lpVtbl->InvokeEx( x, p1, p2, p3, p4, p5, p6, p7 )
    #define IDispatchEx_DeleteMemberByName( x, p1, p2 ) \
        (x)->lpVtbl->DeleteMemberByName( x, p1, p2 )
    #define IDispatchEx_DeleteMemberByDispID( x, p ) \
        (x)->lpVtbl->DeleteMemberByDispID( x, p )
    #define IDispatchEx_GetMemberProperties( x, p1, p2, p3 ) \
        (x)->lpVtbl->GetMemberProperties( x, p1, p2, p3 )
    #define IDispatchEx_GetMemberName( x, p1, p2 ) \
        (x)->lpVtbl->GetMemberName( x, p1, p2 )
    #define IDispatchEx_GetNextDispID( x, p1, p2, p3 ) \
        (x)->lpVtbl->GetNextDispID( x, p1, p2, p3 )
    #define IDispatchEx_GetNameSpaceParent( x, p ) \
        (x)->lpVtbl->GetNameSpaceParent( x, p )
    #define IDispError_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IDispError_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IDispError_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IDispError_QueryErrorInfo( x, p1, p2 ) \
        (x)->lpVtbl->QueryErrorInfo( x, p1, p2 )
    #define IDispError_GetNext( x, p ) \
        (x)->lpVtbl->GetNext( x, p )
    #define IDispError_GetHresult( x, p ) \
        (x)->lpVtbl->GetHresult( x, p )
    #define IDispError_GetSource( x, p ) \
        (x)->lpVtbl->GetSource( x, p )
    #define IDispError_GetHelpInfo( x, p1, p2 ) \
        (x)->lpVtbl->GetHelpInfo( x, p1, p2 )
    #define IDispError_GetDescription( x, p ) \
        (x)->lpVtbl->GetDescription( x, p )
    #define IVariantChangeType_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IVariantChangeType_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IVariantChangeType_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IVariantChangeType_ChangeType( x, p1, p2, p3, p4 ) \
        (x)->lpVtbl->ChangeType( x, p1, p2, p3, p4 )
    #define IObjectIdentity_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IObjectIdentity_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IObjectIdentity_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IObjectIdentity_IsEqualObject( x, p ) \
        (x)->lpVtbl->IsEqualObject( x, p )
    #define IProvideRuntimeContext_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IProvideRuntimeContext_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IProvideRuntimeContext_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IProvideRuntimeContext_GetCurrentSourceContext( x, p1, p2 ) \
        (x)->lpVtbl->GetCurrentSourceContext( x, p1, p2 )
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

/* GUIDs */
EXTERN_C const IID  __cdecl IID_IDispatchEx;
EXTERN_C const IID  __cdecl IID_IDispError;
EXTERN_C const IID  __cdecl IID_IVariantChangeType;
EXTERN_C const IID  __cdecl IID_IObjectIdentity;
EXTERN_C const IID  __cdecl IID_IProvideRuntimeContext;

#endif /* __dispex_h__ */
