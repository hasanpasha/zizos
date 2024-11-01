/*
 * Copyright (c) 1980, 1986, 1993
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

#ifndef _NET_ROUTE_H_
#define _NET_ROUTE_H_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#define RTM_RTTUNIT     1000000
#define RTTTOPRHZ(r)    ((r) / (RTM_RTTUNIT / PR_SLOWHZ))

#define RTENTRY_COUNT 512

#define RTF_UP          0x1
#define RTF_GATEWAY     0x2
#define RTF_HOST        0x4
#define RTF_REJECT      0x8
#define RTF_DYNAMIC     0x10
#define RTF_MODIFIED    0x20
#define RTF_DONE        0x40
#define RTF_MASK        0x80
#define RTF_CLONING     0x100
#define RTF_XRESOLVE    0x200
#define RTF_LLINFO      0x400
#define RTF_STATIC      0x800
#define RTF_BLACKHOLE   0x1000
#define RTF_LLTEMP      0x2000
#define RTF_PROTO2      0x4000
#define RTF_PROTO1      0x8000
#define RTF_PRCLONING   0x10000
#define RTF_WASCLONED   0x20000
#define RTF_PROTO3      0x40000
#define RTF_CHAINDELETE 0x80000
#define RTF_PINNED      0x100000
#define RTF_TUNNEL      0x200000
#define RTF_CRYPT       0x400000
#define RTF_AUTH        0x800000

#define RTM_VERSION 4

#define RTM_ADD      0x1
#define RTM_DELETE   0x2
#define RTM_CHANGE   0x3
#define RTM_GET      0x4
#define RTM_LOSING   0x5
#define RTM_REDIRECT 0x6
#define RTM_MISS     0x7
#define RTM_LOCK     0x8
#define RTM_OLDADD   0x9
#define RTM_OLDDEL   0xa
#define RTM_RESOLVE  0xb
#define RTM_NEWADDR  0xc
#define RTM_DELADDR  0xd
#define RTM_IFINFO   0xe

#define RTV_MTU      0x1
#define RTV_HOPCOUNT 0x2
#define RTV_EXPIRE   0x4
#define RTV_RPIPE    0x8
#define RTV_SPIPE    0x10
#define RTV_SSTHRESH 0x20
#define RTV_RTT      0x40
#define RTV_RTTVAR   0x80

#define RTA_DST      0x1
#define RTA_GATEWAY  0x2
#define RTA_NETMASK  0x4
#define RTA_GENMASK  0x8
#define RTA_IFP      0x10
#define RTA_IFA      0x20
#define RTA_AUTHOR   0x40
#define RTA_BRD      0x80

#define RTAX_DST     0
#define RTAX_GATEWAY 1
#define RTAX_NETMASK 2
#define RTAX_GENMASK 3
#define RTAX_IFP     4
#define RTAX_IFA     5
#define RTAX_AUTHOR  6
#define RTAX_BRD     7
#define RTAX_MAX     8


struct rt_metrics {
    u_long rmx_locks;
    u_long rmx_mtu;
    u_long rmx_hopcount;
    u_long rmx_expire;
    u_long rmx_recvpipe;
    u_long rmx_sendpipe;
    u_long rmx_ssthresh;
    u_long rmx_rtt;
    u_long rmx_rttvar;
    u_long rmx_pksent;
    u_long rmx_filler[4];
};

#pragma pack( __push, 1 )

struct ortentry {
    u_long rt_hash;
    struct sockaddr rt_dst;
    struct sockaddr rt_gateway;
    short  rt_flags;
    short  rt_refcnt;
    u_long rt_use;
    void   *rt_ifp;
    long   metric1;
    long   metric2;
    long   metric3;
    long   metric4;
};

struct rtentries {
    short  hostcount;
    short  netcount;
    struct ortentry rttable[RTENTRY_COUNT];
};

#pragma pack( __pop )


struct  rtstat {
        short   rts_badredirect;        /* bogus redirect calls */
        short   rts_dynamic;            /* routes created by redirects */
        short   rts_newgateway;         /* routes modified by redirects */
        short   rts_unreach;            /* lookups which failed */
        short   rts_wildcard;           /* lookups satisfied by a wildcard */
};

#pragma pack( __push, 1 )

struct rt_msghdr {
#define IFNAMSIZ        16
        u_short rtm_msglen;     /* to skip over non-understood messages */
        u_char  rtm_version;    /* future binary compatibility */
        u_char  rtm_type;       /* message type */
        u_short rtm_index;      /* index for associated ifp */
        short   rtm_unit;       /* new field for subnet routing */
        int     rtm_flags;      /* flags, incl. kern & message, e.g. DONE */
        int     rtm_addrs;      /* bitmask identifying sockaddrs in msg */
        pid_t   rtm_pid;        /* identify sender */
        int     rtm_seq;        /* for sender to identify action */
        int     rtm_errno;      /* why failed */
        int     rtm_use;        /* from rtentry */
        u_long  rtm_inits;      /* which metrics we are initializing */
        u_long  rtm_netmask;    /* new field for subnet routing */
        char    rtm_name[IFNAMSIZ]; /* new field for subnet routing */
        struct  rt_metrics rtm_rmx; /* metrics themselves */
};

#pragma pack( __pop )

struct rt_addrinfo {
    int    rti_addrs;
    struct sockaddr *rti_info[RTAX_MAX];
};

struct route_cb {
    int ip_count;
    int ns_count;
    int iso_count;
    int any_count;
};

#endif
