/*
 * Copyright (c) 1982, 1986, 1990, 1993
 *      The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _NETINET_IN_H_
#define _NETINET_IN_H_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#define IPPROTO_IP    0
#define IPPROTO_ICMP  1
#define IPPROTO_IGMP  2
#define IPPROTO_GGP   3
#define IPPROTO_TCP   6
#define IPPROTO_EGP   8
#define IPPROTO_PUP   12
#define IPPROTO_UDP   17
#define IPPROTO_IDP   22
#define IPPROTO_TP    29
#define IPPROTO_EON   80
#define IPPROTO_ENCAP 98

#define IPPROTO_RAW   255
#define IPPROTO_MAX   256


#define IPPORT_RESERVED     49152
#define IPPORT_USERRESERVED 65535

struct in_addr {
    u_long s_addr;
};

#define IN_CLASSA(i)       (((long)(i) & 0x80000000) == 0)
#define IN_CLASSA_NET      0xff000000
#define IN_CLASSA_NSHIFT   24
#define IN_CLASSA_HOST     0x00ffffff
#define IN_CLASSA_MAX      128

#define IN_CLASSB(i)       (((long)(i) & 0xc0000000) == 0x80000000)
#define IN_CLASSB_NET      0xffff0000
#define IN_CLASSB_NSHIFT   16
#define IN_CLASSB_HOST     0x0000ffff
#define IN_CLASSB_MAX      65536

#define IN_CLASSC(i)       (((long)(i) & 0xe0000000) == 0xc0000000)
#define IN_CLASSC_NET      0xffffff00
#define IN_CLASSC_NSHIFT   8
#define IN_CLASSC_HOST     0x000000ff

#define IN_CLASSD(i)       (((long)(i) & 0xf0000000) == 0xe0000000)
#define IN_CLASSD_NET      0xf0000000
#define IN_CLASSD_NSHIFT   28
#define IN_CLASSD_HOST     0x0fffffff
#define IN_MULTICAST(i)    IN_CLASSD(i)

#define IN_EXPERIMENTAL(i) (((long)(i) & 0xf0000000) == 0xf0000000)
#define IN_BADCLASS(i)     (((long)(i) & 0xf0000000) == 0xf0000000)

#define INADDR_ANY         (u_long)0x00000000
#define INADDR_BROADCAST   (u_long)0xffffffff
#define INADDR_NONE        0xffffffff

#define INADDR_UNSPEC_GROUP    (u_long)0xe0000000
#define INADDR_ALLHOSTS_GROUP  (u_long)0xe0000001
#define INADDR_MAX_LOCAL_GROUP (u_long)0xe00000ff

#define IN_LOOPBACKNET 127

#define IP_OPTIONS         1
#define IP_MULTICAST_IF    2
#define IP_MULTICAST_TTL   3
#define IP_MULTICAST_LOOP  4
#define IP_ADD_MEMBERSHIP  5
#define IP_DROP_MEMBERSHIP 6
#define IP_HDRINCL         7
#define IP_TOS             8
#define IP_TTL             9
#define IP_RECVOPTS        10
#define IP_RECVRETOPTS     11
#define IP_RECVDSTADDR     12
#define IP_RETOPTS         13
#define IP_RECVTRRI        14

#define IP_DEFAULT_MULTICAST_TTL  1
#define IP_DEFAULT_MULTICAST_LOOP 1
#define IP_MAX_MEMBERSHIPS        20
#define MAX_IN_MULTI             (16*IP_MAX_MEMBERSHIPS)

#define IPPROTO_MAXID (IPPROTO_IDP+1)

#define CTL_IPPROTO_NAMES { \
    { "ip", CTLTYPE_NODE }, \
    { "icmp", CTLTYPE_NODE }, \
    { "igmp", CTLTYPE_NODE }, \
    { "ggp", CTLTYPE_NODE }, \
    { 0, 0 }, \
    { 0, 0 }, \
    { "tcp", CTLTYPE_NODE }, \
    { 0, 0 }, \
    { "egp", CTLTYPE_NODE }, \
    { 0, 0 }, \
    { 0, 0 }, \
    { 0, 0 }, \
    { "pup", CTLTYPE_NODE }, \
    { 0, 0 }, \
    { 0, 0 }, \
    { 0, 0 }, \
    { 0, 0 }, \
    { "udp", CTLTYPE_NODE }, \
    { 0, 0 }, \
    { 0, 0 }, \
    { 0, 0 }, \
    { 0, 0 }, \
    { "idp", CTLTYPE_NODE }, \
}

extern u_short CntInMulti;

#pragma pack( __push, 1 )

struct sockaddr_in {
    u_char  sin_len;
    u_char  sin_family;
    u_short sin_port;
    struct  in_addr sin_addr;
    char    sin_zero[8];
};

struct ip_opts {
    struct in_addr ip_dst;
    char   ip_opts[40];
};

struct ip_mreq {
    struct in_addr imr_multiaddr;
    struct in_addr imr_interface;
};

#pragma pack( __pop )

#endif
