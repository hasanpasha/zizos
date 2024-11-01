/*
 * Copyright (c) 1982, 1986, 1989, 1993
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

#ifndef _NET_IF_H_
#define _NET_IF_H_

#ifndef _TIME_
#include <sys/time.h>
#endif

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifndef IFMIB_ENTRIES
#define IFMIB_ENTRIES 42
#endif

#define IFC_ALLRTSBCAST    0x0001
#define IFC_802_3          0x0002
#define IFC_FDDI           0x0004
#define IFC_NOREDIR        0x0010

#define OPERSTATUS_UP      0x1
#define OPERSTATUS_DOWN    0x2
#define OPERSTATUS_TESTING 0x3

#define IFF_UP          0x1
#define IFF_BROADCAST   0x2
#define IFF_DEBUG       0x4
#define IFF_LOOPBACK    0x8
#define IFF_POINTOPOINT 0x10
#define IFF_LINK2       0x20
#define IFF_NOTRAILERS  IFF_LINK2
#define IFF_RUNNING     0x40
#define IFF_NOARP       0x80
#define IFF_PROMISC     0x100
#define IFF_ALLMULTI    0x200
#define IFF_BRIDGE      0x1000
#define IFF_SNAP        0x2000
#define IFF_DEFMTU      0x400
#define IFF_RFC1469_BC  1
#define IFF_RFC1469_FA  2
#define IFF_RFC1469_MA  3
#define IFF_ETHER       0x4000
#define IFF_LOOPBRD     0x8000
#define IFF_MULTICAST   0x800

#define IFF_SIMPLEX     0x10000
#define IFF_OACTIVE     0x20000
#define IFF_802_3       0x40000
#define IFF_CANONICAL   0x80000
#define IFF_RUNNINGBLK  0x100000

#define IFFE_PKTTRACE   0x00000001
#define IFFE_IPTRACE    0x00000002

#define IFF_CANTCHANGE \
    (IFF_BROADCAST|IFF_POINTOPOINT|IFF_RUNNING|IFF_OACTIVE|\
    IFF_SIMPLEX|IFF_MULTICAST|IFF_ALLMULTI)

#define HT_IP       0x01
#define HT_ETHER    0x06
#define HT_ISO88023 0x07
#define HT_ISO88025 0x09
#define HT_SLIP     0x1c
#define HT_PPP      0x18

#define ifc_buf ifc_ifcu.ifcu_buf
#define ifc_req ifc_ifcu.ifcu_req

#define ifra_dstaddr ifra_broadaddr

#define ifr_addr      ifr_ifru.ifru_addr
#define ifr_dstaddr   ifr_ifru.ifru_dstaddr
#define ifr_broadaddr ifr_ifru.ifru_broadaddr
#define ifr_flags     ifr_ifru.ifru_flags
#define ifr_metric    ifr_ifru.ifru_metric
#define ifr_data      ifr_ifru.ifru_data
#define ifr_eflags    ifr_ifru.ifru_data

#define IFNAMSIZ        16

#pragma pack( __push, 1 )

struct iftable {
    short  iftIndex;
    char   iftDescr[45];
    short  iftType;
    short  iftMtu;
    char   iftPhysAddr[6];
    short  iftOperStatus;
    u_long iftSpeed;
    u_long iftLastChange;
    u_long iftInOctets;
    u_long iftOutOctets;
    u_long iftOutDiscards;
    u_long iftInDiscards;
    u_long iftInErrors;
    u_long iftOutErrors;
    u_long iftInUnknownProtos;
    u_long iftInUcastPkts;
    u_long iftOutUcastPkts;
    u_long iftInNUcastPkts;
    u_long iftOutNUcastPkts;
};

struct ifmib {
    short ifNumber;
    struct iftable iftable[IFMIB_ENTRIES];
};

struct pkt_trace_hdr {
    u_short pt_htype;
    u_short pt_len;
    caddr_t pt_data;
    u_long  pt_tstamp;
};

struct  if_data {
    u_char ifi_type;
    u_char ifi_addrlen;
    u_char ifi_hdrlen;
    u_long ifi_mtu;
    u_long ifi_metric;
    u_long ifi_baudrate;
    u_long ifi_collisions;
    u_long ifi_ibytes;
    u_long ifi_obytes;
    u_long ifi_oqdrops;
    u_long ifi_iqdrops;
    u_long ifi_ierrors;
    u_long ifi_oerrors;
    u_long ifi_noproto;
    u_long ifi_ipackets;
    u_long ifi_opackets;
    u_long ifi_imcasts;
    u_long ifi_omcasts;
    short  ifi_OperStatus;
    struct timeval ifi_lastchange;
    u_char ifi_descr[45];
};

struct if_msghdr {
    u_short ifm_msglen;
    u_char  ifm_version;
    u_char  ifm_type;
    int     ifm_addrs;
    int     ifm_flags;
    u_short ifm_index;
    struct  if_data ifm_data;
};

struct ifa_msghdr {
    u_short ifam_msglen;
    u_char  ifam_version;
    u_char  ifam_type;
    int     ifam_addrs;
    int     ifam_flags;
    u_short ifam_index;
    int     ifam_metric;
};

struct  ifreq {
    char   ifr_name[IFNAMSIZ];             /* if name, e.g. "en0" */
    union {
        struct  sockaddr ifru_addr;
        struct  sockaddr ifru_dstaddr;
        struct  sockaddr ifru_broadaddr;
        long    ifru_flags;
        long_int ifru_metric;
        caddr_t ifru_data;
    } ifr_ifru;
};

struct ifaliasreq {
        char    ifra_name[IFNAMSIZ];
        struct  sockaddr ifra_addr;
        struct  sockaddr ifra_broadaddr;
        struct  sockaddr ifra_mask;
};

struct  ifconf {
    long_int ifc_len;
    union {
        caddr_t ifcu_buf;
        struct  ifreq  *ifcu_req;
    } ifc_ifcu;
};

#pragma pack( __pop )

#include <net/if_arp.h>
#include <netinet/in.h>

#pragma pack( __push, 1 )

struct  in_aliasreq {
    char   ifra_name[IFNAMSIZ];
    struct sockaddr_in ifra_addr;
    struct sockaddr_in ifra_broadaddr;
    struct sockaddr_in ifra_mask;
};

struct  addrreq  {
    char   ifr_name[IFNAMSIZ];
    struct sockaddr ifr_addrs;
    u_long maddr[MAX_IN_MULTI];
};

struct  statatreq {
    u_long addr;
    short  interface;
    u_long mask;
    u_long broadcast;
};

#pragma pack( __pop )

struct ifstat {
    u_long iftLastChange;
    u_long iftInOctets;
    u_long iftOutOctets;
    u_long iftOutDiscards;
    u_long iftInDiscards;
    u_long iftInErrors;
    u_long iftOutErrors;
    u_long iftInUnknownProtos;
    u_long iftInUcastPkts;
    u_long iftOutUcastPkts;
    u_long iftInNUcastPkts;
    u_long iftOutNUcastPkts;
};

#endif
