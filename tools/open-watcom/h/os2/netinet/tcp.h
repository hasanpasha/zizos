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

#ifndef _NETINET_TCP_H_
#define _NETINET_TCP_H_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#define TCPOPT_EOL               0
#define TCPOPT_NOP               1
#define TCPOPT_MAXSEG            2
#define   TCPOLEN_MAXSEG         4
#define TCPOPT_WINDOW            3
#define   TCPOLEN_WINDOW         3
#define TCPOPT_SACK_PERMITTED    4
#define   TCPOLEN_SACK_PERMITTED 2
#define TCPOPT_SACK              5
#define TCPOPT_TIMESTAMP         8
#define   TCPOLEN_TIMESTAMP     10
#define   TCPOLEN_TSTAMP_APPA   (TCPOLEN_TIMESTAMP+2)

#define TCPOPT_CC               11
#define TCPOPT_CCNEW            12
#define TCPOPT_CCECHO           13
#define TCPOLEN_CC              6
#define TCPOLEN_CC_APPA         (TCPOLEN_CC+2)
#define TCPOPT_CC_HDR(ccopt)    (TCPOPT_NOP<<24|TCPOPT_NOP<<16|(ccopt)<<8|TCPOLEN_CC)
#define TTCP_CLIENT_SND_WND     4096
#define TCPOPT_TSTAMP_HDR       (TCPOPT_NOP<<24|TCPOPT_NOP<<16|TCPOPT_TIMESTAMP<<8|TCPOLEN_TIMESTAMP)

#define TCP_MSS          512
#define TCP_MAXWIN       65535
#define TCP_MAX_WINSHIFT 14

#define TCP_NODELAY  0x01
#define TCP_MAXSEG   0x02
#define TCP_MSL      0x03
#define TCP_TIMESTMP 0x04
#define TCP_WINSCALE 0x05
#define TCP_CC       0x06
#ifdef VEGAS
#define TCP_TAHOE                     3
#define TCP_RENO                      4
#define TCP_VEGAS                     5
#define TCP_VEGAS_SPIKE_ON            6
#define TCP_VEGAS_EXP_INC_OFF         7
#define TCP_VEGAS_CONG_DETECT_OFF     8
#define TCP_VEGAS_24                  9
#define TCP_VEGAS_CONG_DETECT_PRED_ON 10
#endif

#define TH_FIN  0x01
#define TH_SYN  0x02
#define TH_RST  0x04
#define TH_PUSH 0x08
#define TH_ACK  0x10
#define TH_URG  0x20

typedef u_long tcp_seq;

#pragma pack( __push, 1 )

struct tcphdr {
    u_short th_sport;
    u_short th_dport;
    tcp_seq th_seq;
    tcp_seq th_ack;
    u_char  th_x2:4,
            th_off:4;
    u_char  th_flags;
    u_short th_win;
    u_short th_sum;
    u_short th_urp;
};

#pragma pack( __pop )

#endif
