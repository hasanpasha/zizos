/*
 *  arpa/inet.h      Internet address manipulation routines
 *
 * =========================================================================
 *
 *                          Open Watcom Project
 *
 * Copyright (c) 2004-2024 The Open Watcom Contributors. All Rights Reserved.
 * Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
 *
 *    This file is automatically generated. Do not edit directly.
 *
 * =========================================================================
 */
#ifndef _ARPA_INET_H_INCLUDED
#define _ARPA_INET_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifndef __COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

#ifndef _SYS_TYPES_H_INCLUDED
 #include <sys/types.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif


#include <netinet/in.h>

_WCRTLINK extern int            inet_aton( const char *__cp, struct in_addr *__op );
_WCRTLINK extern in_addr_t      inet_addr( const char *__cp );
_WCRTLINK extern in_addr_t      inet_network( const char *__cp );
_WCRTLINK extern char           *inet_ntoa( struct in_addr __in );
_WCRTLINK extern struct in_addr inet_makeaddr( int __net, int __host );
_WCRTLINK extern in_addr_t      inet_lnaof( struct in_addr __in );
_WCRTLINK extern in_addr_t      inet_netof( struct in_addr __in );


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* !_ARPA_INET_H_INCLUDED */

