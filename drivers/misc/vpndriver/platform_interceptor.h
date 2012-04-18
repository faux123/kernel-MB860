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
 * platform_interceptor.h
 *
 * Linux interceptor specific defines for the Interceptor API.
 *
 */

#ifndef SSH_PLATFORM_INTERCEPTOR_H

#define SSH_PLATFORM_INTERCEPTOR_H 1

#ifdef KERNEL
#ifndef KERNEL_INTERCEPTOR_USE_FUNCTIONS

#define ssh_interceptor_packet_len(pp) \
  ((size_t)((SshInterceptorInternalPacket)(pp))->skb->len)

#include "linux_params.h"
#include "linux_packet_internal.h"

#endif /* KERNEL_INTERCEPTOR_USE_FUNCTIONS */
#endif /* KERNEL */

#endif /* SSH_PLATFORM_INTERCEPTOR_H */
