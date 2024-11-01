/*
 * Copyright (c) 1983, 1993
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

#ifndef _PROTOCOL_TIMED_H_
#define _PROTOCOL_TIMED_H_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#define TSPVERSION      1
#define ANYADDR         NULL

#define TSP_ANY        0
#define TSP_ADJTIME    1
#define TSP_ACK        2
#define TSP_MASTERREQ  3
#define TSP_MASTERACK  4
#define TSP_SETTIME    5
#define TSP_MASTERUP   6
#define TSP_SLAVEUP    7
#define TSP_ELECTION   8
#define TSP_ACCEPT     9
#define TSP_REFUSE     10
#define TSP_CONFLICT   11
#define TSP_RESOLVE    12
#define TSP_QUIT       13
#define TSP_DATE       14
#define TSP_DATEREQ    15
#define TSP_DATEACK    16
#define TSP_TRACEON    17
#define TSP_TRACEOFF   18
#define TSP_MSITE      19
#define TSP_MSITEREQ   20
#define TSP_TEST       21
#define TSP_SETDATE    22
#define TSP_SETDATEREQ 23
#define TSP_LOOP       24

#define TSPTYPENUMBER  25

#define tsp_time   tsp_u.tspu_time
#define tsp_hopcnt tsp_u.tspu_hopcnt

#pragma pack( __push, 1 )

struct tsp {
    u_char  tsp_type;
    u_char  tsp_vers;
    u_short tsp_seq;
    union {
        struct timeval tspu_time;
        char   tspu_hopcnt;
    } tsp_u;
    char tsp_name[MAXHOSTNAMELEN];
};

#pragma pack( __pop )

#ifdef TSPTYPES
char *tsptype[TSPTYPENUMBER] =
    { "ANY", "ADJTIME", "ACK", "MASTERREQ", "MASTERACK", "SETTIME", "MASTERUP",
    "SLAVEUP", "ELECTION", "ACCEPT", "REFUSE", "CONFLICT", "RESOLVE", "QUIT",
    "DATE", "DATEREQ", "DATEACK", "TRACEON", "TRACEOFF", "MSITE", "MSITEREQ",
    "TEST", "SETDATE", "SETDATEREQ", "LOOP" };
#endif

#endif
