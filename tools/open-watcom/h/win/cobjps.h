/*
 *  cobjps.h    Component Object Model (COM) proxy/stub interfaces
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

#ifndef _COBJPS_H_
#define _COBJPS_H_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

/* IRpcChannel interface */
#undef INTERFACE
#define INTERFACE   IRpcChannel
DECLARE_INTERFACE_( IRpcChannel, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IRpcChannel methods */
    STDMETHOD( GetStream )( THIS_ REFIID, int, BOOL, BOOL, DWORD, IStream FAR * FAR * ) PURE;
    STDMETHOD( Call )( THIS_ IStream FAR * ) PURE;
    STDMETHOD( GetDestCtx )( THIS_ DWORD FAR *, LPVOID FAR * ) PURE;
    STDMETHOD( IsConnected )( THIS ) PURE;
};

/* IRpcProxy interface */
#undef INTERFACE
#define INTERFACE   IRpcProxy
DECLARE_INTERFACE_( IRpcProxy, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IRpcProxy methods */
    STDMETHOD( Connect )( THIS_ IRpcChannel FAR * ) PURE;
    STDMETHOD_( void, Disconnect )( THIS ) PURE;
};

/* IRpcStub interface */
#undef INTERFACE
#define INTERFACE   IRpcStub
DECLARE_INTERFACE_( IRpcStub, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IRpcStub methods */
    STDMETHOD( Connect )( THIS_ IUnknown FAR * ) PURE;
    STDMETHOD_( void, Disconnect )( THIS ) PURE;
    STDMETHOD( Invoke )( THIS_ REFIID, int, IStream FAR *, DWORD, LPVOID ) PURE;
    STDMETHOD_( BOOL, IsIIDSupported )( THIS_ REFIID ) PURE;
    STDMETHOD_( ULONG, CountRefs )( THIS ) PURE;
};

/* IPSFactory interface */
#undef INTERFACE
#define INTERFACE   IPSFactory
DECLARE_INTERFACE_( IPSFactory, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IPSFactory methods */
    STDMETHOD( CreateProxy )( THIS_ IUnknown FAR *, REFIID, IRpcProxy FAR * FAR *, void FAR * FAR * ) PURE;
    STDMETHOD( CreateStub )( THIS_ REFIID, IUnknown FAR *, IRpcStub FAR * FAR * ) PURE;
};

#endif /* _COBJPS_H_ */
