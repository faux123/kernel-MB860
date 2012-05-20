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
 * linux_mutex_internal.h
 *
 * Linux interceptor internal defines for kernel mutex API.
 *
 */

#ifndef LINUX_MUTEX_INTERNAL_H
#define LINUX_MUTEX_INTERNAL_H

#include <linux/spinlock.h>
#include <asm/current.h>

typedef struct SshKernelMutexRec
{
  spinlock_t lock;
  unsigned long flags;

#ifdef DEBUG_LIGHT
  Boolean taken;
  unsigned long jiffies;
#endif
} SshKernelMutexStruct;

#ifdef CONFIG_PREEMPT

#include <linux/preempt.h>

#define icept_preempt_enable()  preempt_enable()
#define icept_preempt_disable() preempt_disable()

#else /* CONFIG_PREEMPT */

#define icept_preempt_enable()  do {;} while(0)
#define icept_preempt_disable() do {;} while(0)

#endif /* CONFIG_PREEMPT */

#endif /* LINUX_MUTEX_INTERNAL_H */
