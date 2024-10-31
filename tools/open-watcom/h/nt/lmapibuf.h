/*
 *  lmapibuf.h  LAN Manager API buffer functions
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

#ifndef _LMAPIBUF_
#define _LMAPIBUF_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Functions in NETAPI32.DLL */
NET_API_STATUS NET_API_FUNCTION NetApiBufferAllocate( DWORD, LPVOID * );
NET_API_STATUS NET_API_FUNCTION NetApiBufferFree( LPVOID );
NET_API_STATUS NET_API_FUNCTION NetApiBufferReallocate( LPVOID, DWORD, LPVOID * );
NET_API_STATUS NET_API_FUNCTION NetApiBufferSize( LPVOID, LPDWORD );
NET_API_STATUS NET_API_FUNCTION NetapipBufferAllocate( DWORD, LPVOID * );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _LMAPIBUF_ */
