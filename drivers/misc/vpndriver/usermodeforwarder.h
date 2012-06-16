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
 * usermodeforwarder.h
 *
 * Message types for kernel to userspace messaging.
 *
 */

#ifndef USERMODEFORWARDER_H
#define USERMODEFORWARDER_H

/* Allocate message numbers from the platform-specific portion. */
  
/** Received packet or packet to be sent.
      - uint32 flags
      - uint32 ifnum
      - uint32 protocol
      - uint32 media_header_len    (0 for packets going up)
      - uint16 route_selector      (0 in media level interceptor builds)
      - string packet data
      - uint32 extension 
        repeats SSH_INTERCEPTOR_NUM_EXTENSION_SELECTORS times. */
#define SSH_ENGINE_IPM_FORWARDER_PACKET                 201

/** Routing request from user mode.
      - string destination
      - uint32 request id */
#define SSH_ENGINE_IPM_FORWARDER_ROUTEREQ               202

/** Routing reply from kernel.
      - uint32 id
      - uint32 reachable
      - uint32 ifnum
      - uint32 mtu
      - string next_hop_gw */
#define SSH_ENGINE_IPM_FORWARDER_ROUTEREPLY             203

/** Interfaces information from kernel:
      - uint32 num_interfaces. 

      Repeats:
        - uint32 media
        - uint32 mtu
        - string name
        - string media_addr
        - uint32 num_addrs
        - string addrs array as binary data */
#define SSH_ENGINE_IPM_FORWARDER_INTERFACES             204

/** Route change notification.  No data. */
#define SSH_ENGINE_IPM_FORWARDER_ROUTECHANGE            205

/** Kernel version string. */
#define SSH_ENGINE_IPM_FORWARDER_VERSION                206

#define SSH_ENGINE_IPM_FORWARDER_SET_DEBUG              208

/** Enable / disable packet interception:
    - uint32 enable (1 to enable, 0 to disable) */
#define SSH_ENGINE_IPM_FORWARDER_ENABLE_INTERCEPTION    215

#endif /* USERMODEFORWARDER_H */
