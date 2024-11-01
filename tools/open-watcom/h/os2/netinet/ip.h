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

#ifndef _NETINET_IP_H_
#define _NETINET_IP_H_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#define IPVERSION       4

#define IP_DF      0x4000
#define IP_MF      0x2000
#define IP_OFFMASK 0x1fff

#define IP_MAXPACKET 65535

#define IPTOS_LOWDELAY    0x10
#define IPTOS_THROUGHPUT  0x08
#define IPTOS_RELIABILITY 0x04

#define IPTOS_PREC_NETCONTROL      0xe0
#define IPTOS_PREC_INTERNETCONTROL 0xc0
#define IPTOS_PREC_CRITIC_ECP      0xa0
#define IPTOS_PREC_FLASHOVERRIDE   0x80
#define IPTOS_PREC_FLASH           0x60
#define IPTOS_PREC_IMMEDIATE       0x40
#define IPTOS_PREC_PRIORITY        0x20
#define IPTOS_PREC_ROUTINE         0x00

#define IPOPT_COPY      0x80
#define IPOPT_COPIED(o) ((o)&IPOPT_COPY)
#define IPOPT_CLASS(o)  ((o)&0x60)
#define IPOPT_NUMBER(o) ((o)&0x1f)

#define IPOPT_CONTROL   0x00
#define IPOPT_RESERVED1 0x20
#define IPOPT_DEBMEAS   0x40
#define IPOPT_RESERVED2 0x60

#define IPOPT_EOL 0
#define IPOPT_NOP 1

#define IPOPT_RR       7
#define IPOPT_TS       68
#define IPOPT_SECURITY 130
#define IPOPT_LSRR     131
#define IPOPT_SATID    136
#define IPOPT_SSRR     137
#define IPOPT_RALERT   148

#define IPOPT_OPTVAL 0
#define IPOPT_OLEN   1
#define IPOPT_OFFSET 2
#define IPOPT_MINOFF 4

#define IPOPT_TS_TSONLY    0
#define IPOPT_TS_TSANDADDR 1
#define IPOPT_TS_PRESPEC   3

#define IPOPT_SECUR_UNCLASS   0x0000
#define IPOPT_SECUR_CONFID    0xf135
#define IPOPT_SECUR_EFTO      0x789a
#define IPOPT_SECUR_MMMM      0xbc4d
#define IPOPT_SECUR_RESTR     0xaf13
#define IPOPT_SECUR_SECRET    0xd788
#define IPOPT_SECUR_TOPSECRET 0x6bc5

#define MAXTTL    255
#define IPFRAGTTL 60
#define IPTTLDEC  1
#define IP_MSS    576


#pragma pack( __push, 1 )

struct ip {
    u_char   ip_hl:4,
             ip_v:4;
    u_char   ip_tos;
    u_short  ip_len;
    u_short  ip_id;
    short    ip_off;
    u_char   ip_ttl;
    u_char   ip_p;
    u_short  ip_sum;
    struct   in_addr ip_src,ip_dst;
};

struct  ip_timestamp {
    u_char   ipt_code;
    u_char   ipt_len;
    u_char   ipt_ptr;
    u_char   ipt_flg:4,
             ipt_oflw:4;
    union ipt_timestamp {
        n_long  ipt_time[1];
        struct  ipt_ta {
            struct in_addr ipt_addr;
            n_long ipt_time;
        } ipt_ta[1];
    } ipt_timestamp;
};

#pragma pack( __pop )

#endif
