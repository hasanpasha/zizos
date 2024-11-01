/*
 * Copyright (c) 1982, 1986, 1993
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

#ifndef _NETINET_IP_VAR_H_
#define _NETINET_IP_VAR_H_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#define IPCTL_FORWARDING     1
#define IPCTL_SENDREDIRECTS  2
#define IPCTL_INETCFG        40
#define IPCTL_INETVER        41
#define IPCTL_FORWARD        42
#define IPCTL_FIREWALL       43
#define IPCTL_ARPTKILLC      44
#define IPCTL_ARPTKILLI      45
#define FRAGCTL_TTL          46
#define IPCTL_SYNATTACK      47
#define IPCTL_MULTIDEFROUTES 48

#define MAX_IPOPTLEN    40

#define IPCTL_NAMES { \
    { 0, 0 }, \
    { "forwarding", CTLTYPE_INT }, \
    { "redirect", CTLTYPE_INT }, \
    { "mtu", CTLTYPE_INT }, \
    { "multi-default-routes", CTLTYPE_INT }, \
    { "inetver", CTLTYPE_INETVER }, \
    { "inetcfg", CTLTYPE_INETCFG }, \
}

#pragma pack( __push, 1 )

struct ipovly {
    caddr_t ih_next, ih_prev;
    u_char  ih_x1;
    u_char  ih_pr;
    short   ih_len;
    struct  in_addr ih_src;
    struct  in_addr ih_dst;
};

struct ipq {
    struct  ipq *next,*prev;
    u_char  ipq_ttl;
    u_char  ipq_p;
    u_short ipq_id;
    struct  ipasfrag *ipq_next,*ipq_prev;
    struct  in_addr ipq_src,ipq_dst;
};

struct  ipasfrag {
    u_char   ip_hl:4,
             ip_v:4;
    u_char   ipf_mff;
    u_short  ip_len;
    u_short  ip_id;
    short    ip_off;
    u_char   ip_ttl;
    u_char   ip_p;
    u_short  ip_sum;
    struct   ipasfrag *ipf_next;
    struct   ipasfrag *ipf_prev;
};

#pragma pack( __pop )

struct  ipstat {
    u_long ips_total;
    u_long ips_badsum;
    u_long ips_tooshort;
    u_long ips_toosmall;
    u_long ips_badhlen;
    u_long ips_badlen;
    u_long ips_fragments;
    u_long ips_fragdropped;
    u_long ips_fragtimeout;
    u_long ips_forward;
    u_long ips_cantforward;
    u_long ips_redirectsent;
    u_long ips_noproto;
    u_long ips_delivered;
    u_long ips_localout;
    u_long ips_odropped;
    u_long ips_reassembled;
    u_long ips_fragmented;
    u_long ips_ofragments;
    u_long ips_cantfrag;
    u_long ips_badoptions;
    u_long ips_noroute;
    u_long ips_badvers;
    u_long ips_rawout;
};

#endif
