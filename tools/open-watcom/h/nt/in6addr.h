/*
 *  in6addr.h   Internet address version 6 definition
 *
 * =========================================================================
 *
 *                          Open Watcom Project
 *
 * Copyright (c) 2004-2024 The Open Watcom Contributors. All Rights Reserved.
 *
 *    This file is automatically generated. Do not edit directly.
 *
 * =========================================================================
 */

#ifndef s6_addr

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Internet address (version 6) */
typedef struct in6_addr {
    union {
        UCHAR   Byte[16];
        USHORT  Word[8];
    } u;
} IN6_ADDR;
typedef IN6_ADDR    *PIN6_ADDR;
typedef IN6_ADDR    *LPIN6_ADDR;
#define in_addr6    in6_addr
#define _S6_un      u
#define _S6_u8      Byte
#define s6_addr     _S6_un._S6_u8
#define s6_bytes    u.Byte
#define s6_words    u.Word

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* s6_addr */
