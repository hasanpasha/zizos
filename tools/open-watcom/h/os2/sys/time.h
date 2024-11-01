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

#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#include <sys/types.h>

#define TIMEVAL_TO_TIMESPEC(tv, ts) { \
    (ts)->ts_sec = (tv)->tv_sec; \
    (ts)->ts_nsec = (tv)->tv_usec * 1000; \
}
#define TIMESPEC_TO_TIMEVAL(tv, ts) { \
    (tv)->tv_sec = (ts)->ts_sec; \
    (tv)->tv_usec = (ts)->ts_nsec / 1000; \
}

#define DST_NONE 0
#define DST_USA  1
#define DST_AUST 2
#define DST_WET  3
#define DST_MET  4
#define DST_EET  5
#define DST_CAN  6

#define timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#define timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#ifndef timercmp
#define timercmp(tvp, uvp, cmp) \
    (((tvp)->tv_sec == (uvp)->tv_sec) ? \
    ((tvp)->tv_usec cmp (uvp)->tv_usec) : \
    ((tvp)->tv_sec cmp (uvp)->tv_sec))
#endif

#define ITIMER_REAL    0
#define ITIMER_VIRTUAL 1
#define ITIMER_PROF    2

struct timeval {
    long tv_sec;
    long tv_usec;
};

#ifndef _TIMESPEC_DEFINED
 #define _TIMESPEC_DEFINED
#pragma pack( __push, 4 )
 struct timespec {
   union {
     __w_time_t tv_sec;
     __w_time_t ts_sec;
   };
   union {
     long       tv_nsec;
     long       ts_nsec;
   };
 };
#pragma pack( __pop )
#endif /* _TIMESPEC_DEFINED */

#pragma pack( __push, 4 )

struct  itimerval {
    struct timeval it_interval;
    struct timeval it_value;
};

#pragma pack( __pop )

struct timezone {
    int tz_minuteswest;
    int tz_dsttime;
};

struct clockinfo {
    int hz;
    int tick;
    int stathz;
    int profhz;
};

#include <time.h>

#ifndef _POSIX_SOURCE
#include <sys/cdefs.h>

__BEGIN_DECLS
int _System adjtime __TCPPROTO((const struct timeval *, struct timeval *));
int _System getitimer __TCPPROTO((int, struct itimerval *));
int _System gettimeofday __TCPPROTO((struct timeval *, struct timezone *));
int _System setitimer __TCPPROTO((int, const struct itimerval *, struct itimerval *));
int _System settimeofday __TCPPROTO((const struct timeval *, const struct timezone *));
int _System utimes __TCPPROTO((const char *, const struct timeval *));
__END_DECLS
#endif

#endif
