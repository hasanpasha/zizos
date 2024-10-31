/***************************************************************************
 * FILE: stdbool.h/cstdbool (Macros to simulate the 'bool' type in C)
 *
 * =========================================================================
 *
 *                          Open Watcom Project
 *
 * Copyright (c) 2004-2024 The Open Watcom Contributors. All Rights Reserved.
 * Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
 *
 *    This file is automatically generated. Do not edit directly.
 *
 * =========================================================================
 *
 * Description: This header is part of the C99/C++ standard library. It
 *              provides a way for the programmer, at his/her option
 *              to introduce the type 'bool' into a C program.
 ***************************************************************************/
#ifndef _STDBOOL_H_INCLUDED
#define _STDBOOL_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus

#include <cstdbool>

#else /* __cplusplus not defined */

 #if defined( _NO_EXT_KEYS ) && __STDC_VERSION__ < 199901L /* C89 and extensions disabled */
  typedef unsigned char _Bool;
 #endif

 #define bool _Bool
 #define true  1
 #define false 0
 #define __bool_true_false_are_defined 1

#endif /* __cplusplus not defined */

#endif
