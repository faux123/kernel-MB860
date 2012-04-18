/*
 * The following copyright notice must be included in all
 * copies, modified as well as unmodified, of this file.
 *
 * Copyright (c) 2010  AuthenTec Inc.
 * All rights reserved.
 *
 * Non-confidential per the associated AuthenTec-Motorola
 * Product Schedule.
 *
 */

/*
 * sshincludes.h
 *
 * Common include file.
 *
 */

#ifndef SSHINCLUDES_H
#define SSHINCLUDES_H

/* Defines related to segmented memory architectures. */
#ifndef NULL_FNPTR
#define NULL_FNPTR  NULL
#endif

/* Macros for giving branch prediction hints to the compiler. The
   result type of the expression must be an integral type. */
#if __GNUC__ >= 3
#define SSH_PREDICT_TRUE(expr) __builtin_expect(!!(expr), 1)
#define SSH_PREDICT_FALSE(expr) __builtin_expect(!!(expr), 0)
#else /* __GNUC__ >= 3 */
#define SSH_PREDICT_TRUE(expr) (!!(expr))
#define SSH_PREDICT_FALSE(expr) (!!(expr))
#endif /* __GNUC__ >= 3 */

/* Macros for marking functions to be placed in a special section. */
#if __GNUC__ >= 3
#define SSH_FASTTEXT __attribute__((__section__ (".text.fast")))
#else /* __GNUC__ >= 3 */
#define SSH_FASTTEXT
#endif /* __GNUC__ >= 3 */

/* Some generic pointer types. */
typedef char *SshCharPtr;
typedef void *SshVoidPtr;

#include "kernel_includes.h"

/* Some internal headers used in almost every file. */
#include "sshdebug.h"
#include "engine_alloc.h"

#endif /* SSHINCLUDES_H */
