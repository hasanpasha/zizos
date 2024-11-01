/*-
 * Copyright (c) 1983, 1989, 1993
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

#ifndef _PROTOCOL_ROUTED_H_
#define _PROTOCOL_ROUTED_H_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#define RIPVERSION      1

#define RIPCMD_REQUEST  1
#define RIPCMD_RESPONSE 2
#define RIPCMD_TRACEON  3
#define RIPCMD_TRACEOFF 4

#define RIPCMD_MAX 5
#ifdef RIPCMDS
char *ripcmds[RIPCMD_MAX] = {"#0", "REQUEST", "RESPONSE", "TRACEON", "TRACEOFF"};
#endif

#define HOPCNT_INFINITY 16
#define MAXPACKETSIZE   512

#define TIMER_RATE      30

#define SUPPLY_INTERVAL 30
#define MIN_WAITTIME    2
#define MAX_WAITTIME    5

#define EXPIRE_TIME     180
#define GARBAGE_TIME    240

#define rip_nets      ripun.ru_nets
#define rip_tracefile ripun.ru_tracefile

#pragma pack( __push, 1 )

struct netinfo {
    struct sockaddr rip_dst;
    int    rip_metric;
};

struct rip {
    u_char rip_cmd;
    u_char rip_vers;
    u_char rip_res1[2];
    union {
        struct  netinfo ru_nets[1];
        char    ru_tracefile[1];
    } ripun;
};

#pragma pack( __pop )

#endif
