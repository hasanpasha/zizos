///////////////////////////////////////////////////////////////////////////
// FILE: exception.h/exception (Basic exception classes)
//
// =========================================================================
//
//                          Open Watcom Project
//
// Copyright (c) 2004-2024 The Open Watcom Contributors. All Rights Reserved.
// Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
//
//    This file is automatically generated. Do not edit directly.
//
// =========================================================================
//
// Description: This header is part of the C++ standard library. It
//              defines the base class of the exception classes as
//              well as a number of helper functions related to
//              exception handling.
///////////////////////////////////////////////////////////////////////////
#ifndef _EXCEPTION_H_INCLUDED
#define _EXCEPTION_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifndef _EXCEPTION_INCLUDED
 #include <exception>
#endif
using std::exception;
using std::bad_exception;
using std::unexpected_handler;
using std::set_unexpected;
using std::unexpected;
using std::terminate_handler;
using std::set_terminate;
using std::terminate;
// using std::uncaught_exception;

// Needed for compatibility with Watcom legacy code?
// #include <stdexcept.h>

#endif