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
 * linux_versions.h
 *
 * Linux interceptor kernel version specific defines. When adding support
 * for new kernel versions, add the kernel version specific block to the
 * bottom of the file and undefine any removed feature defines inherited
 * from earlier kernel version blocks.
 *
 */

#ifndef LINUX_VERSION_H
#define LINUX_VERSION_H

#include <linux/version.h>

#ifndef KERNEL_VERSION
#define KERNEL_VERSION(a,b,c) (((a) << 16) + ((b) << 8) + (c))
#endif /* KERNEL_VERSION */

/* 2.6.32 is the highest version currently supported */
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,32)
#error "Kernel versions after 2.6.32 are not supported"
#endif /* LINUX_VERSION_CODE > KERNEL_VERSION(2,6,32) */

/* 2.4 is not supported */
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,0)
#error "Kernel versions pre 2.6.0 are not supported"
#endif /* LINUX_VERSION_CODE < KERNEL_VERSION(2,6,0) */

/* 2.6 series specific things */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,0)
#define LINUX_HAS_SKB_SECURITY 1
#define LINUX_HAS_SKB_STAMP 1
#define LINUX_HAS_SKB_NFCACHE 1
#define LINUX_HAS_SKB_NFDEBUG 1
#define LINUX_SKB_LINEARIZE_NEEDS_FLAGS 1
#define LINUX_INODE_OPERATION_PERMISSION_HAS_NAMEIDATA 1
#define LINUX_HAS_PROC_DIR_ENTRY_OWNER 1
#endif /* >= 2.6.0 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,4)
#define LINUX_HAS_SKB_MAC_LEN 1
#endif /* >= 2.6.4 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,9)
#define LINUX_HAS_ETH_HDR 1
#endif /* >= 2.6.9 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,12) 
#define LINUX_HAS_DST_MTU 1
#define LINUX_HAS_DEV_GET_FLAGS 1
#endif /* >= 2.6.12 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,13)
#undef LINUX_HAS_SKB_SECURITY
#undef LINUX_HAS_SKB_STAMP
#undef LINUX_HAS_SKB_NFCACHE
#undef LINUX_HAS_SKB_NFDEBUG
#endif /* >= 2.6.13 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,15)
#define LINUX_HAS_NETIF_F_UFO 1
#endif /* >= 2.6.15 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,16)
#define LINUX_HAS_IP6CB_NHOFF 1
#define LINUX_FRAGMENTATION_AFTER_NF_POST_ROUTING 1
#endif /* >= 2.6.16 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,18)
#undef LINUX_SKB_LINEARIZE_NEEDS_FLAGS
#define LINUX_HAS_NETIF_F_GSO        1
#define LINUX_HAS_NETIF_F_TSO6       1
#define LINUX_HAS_NETIF_F_TSO_ECN    1
#define LINUX_HAS_NETIF_F_GSO_ROBUST 1
#endif /* >= 2.6.18 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,19)
#define LINUX_HAS_NEW_CHECKSUM_FLAGS 1
#define LINUX_NEED_IF_ADDR_H 1
#endif /* >= 2.6.19 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,20)
#define LINUX_HAS_SKB_MARK 1
#define LINUX_HAS_SKB_CSUM_OFFSET 1
#endif /* >= 2.6.20 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,22)
#define LINUX_HAS_NETDEVICE_ACCESSORS 1 
#define LINUX_HAS_SKB_DATA_ACCESSORS 1
#define LINUX_HAS_SKB_CSUM_START 1
#endif /* >= 2.6.22 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)
#define LINUX_NET_DEVICE_HAS_ARGUMENT 1
#define LINUX_NF_HOOK_SKB_IS_POINTER  1
#endif /* >= 2.6.24 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,25)
#define LINUX_NF_INET_HOOKNUMS 1
#define LINUX_IP_ROUTE_OUTPUT_KEY_HAS_NET_ARGUMENT 1
#endif /* >= 2.6.25 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,26)
#define LINUX_IP6_ROUTE_OUTPUT_KEY_HAS_NET_ARGUMENT 1
#endif /* >= 2.6.26 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,27)
#undef LINUX_INODE_OPERATION_PERMISSION_HAS_NAMEIDATA
#endif /* >= 2.6.27 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,28)
#define LINUX_HAS_NFPROTO_ARP 1
#endif /* >= 2.6.28 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,29)
#define LINUX_HAS_TASK_CRED_STRUCT 1
#endif /* >= 2.6.29 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,30)
#undef LINUX_HAS_PROC_DIR_ENTRY_OWNER
#endif /* >= 2.6.30 */

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,31)
#define LINUX_HAS_SKB_DST_FUNCTIONS 1
#endif /* >= 2.6.31 */

#endif /* LINUX_VERSION_H */
