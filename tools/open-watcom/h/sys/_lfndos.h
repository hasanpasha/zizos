/*
 *  _lfndos.h    DOS Long File Name (LFN) support definition.
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
#ifndef _SYS__LFNDOS_H_INCLUDED
#define _SYS__LFNDOS_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#if defined(__WATCOM_LFN__) && defined(__DOS__)
 #ifdef _M_I86
  #ifdef __MEDIUM__
   #pragma library ( "doslfnm" )
  #elif defined(__COMPACT__)
   #pragma library ( "doslfnc" )
  #elif defined(__LARGE__)
   #pragma library ( "doslfnl" )
  #elif defined(__HUGE__)
   #pragma library ( "doslfnh" )
  #else
   #pragma library ( "doslfns" )
  #endif
 #elif defined(__SW_3S)
  #pragma library ( "doslfn3s" )
 #else
  #pragma library ( "doslfn3r" )
 #endif
#endif

#endif
