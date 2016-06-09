/****************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology 5th Rd.
 * Science-based Industrial Park
 * Hsin-chu, Taiwan, R.O.C.
 * (c) Copyright 2002, Ralink Technology, Inc.
 *
 * All rights reserved. Ralink's source code is an unpublished work and the
 * use of a copyright notice does not imply otherwise. This source code
 * contains confidential trade secret material of Ralink Tech. Any attemp
 * or participation in deciphering, decoding, reverse engineering or in any
 * way altering the source code is stricitly prohibited, unless the prior
 * written consent of Ralink Technology, Inc. is obtained.
 ****************************************************************************

    Module Name:
    rtusb_dev_id.c

 */

#define RTMP_MODULE_OS

#include "rtmp_comm.h"
#include "rt_os_util.h"
#include "rt_os_net.h"

/* module table */
USB_DEVICE_ID rtusb_dev_id[] = {
#ifdef MT76x2
	/* Here we define the USB IDs that the driver will register to handle. To add
	 * a device which uses a supported chipset you will need to add a new entry 
	 * into the array below. Note that the first part of the USB ID is specific
	 * to the vendor of the device whilst the second relates to a given device 
	 * and product revision. You can find a list of vendor USB IDs on 
	 * http://www.linux-usb.org/usb.ids
	 *
	 * Note that the Netgear N600 WNDA3100 comes in different revisions and only 
	 * revision 3 uses a chipset that this driver supports. 
	 *
	 * WNDA3100v1 – Atheros AR91xx (supported by external driver)
	 * WNDA3100v2 – Broadcom (Linux support unknown)
	 * WNDA3100v3 – Mediatek (supported by this driver)
	 */
	{USB_DEVICE(0x0B05, 0x180B), .driver_info = RLT_MAC_BASE}, /* ASUS USB-N53 */
	{USB_DEVICE(0x0B05, 0x17EB), .driver_info = RLT_MAC_BASE}, /* ASUS USB-AC55 */
	{USB_DEVICE(0x7392, 0xb711), .driver_info = RLT_MAC_BASE}, /* Edimax AC1200 EW-7722UAC Wireless Dual Band USB 3.0 Adapter */
	{USB_DEVICE(0x0E8D, 0x7612), .driver_info = RLT_MAC_BASE}, /* EDUP EP-AC1601 (MediaTek) */
	{USB_DEVICE(0x045e, 0x02e6), .driver_info = RLT_MAC_BASE}, /* Microsoft Xbox one Wireless Adapter for Windows */
	{USB_DEVICE(0x0846, 0x9053), .driver_info = RLT_MAC_BASE}, /* Netgear, Inc. AC1200 WiFi USB 3.0 Adapter */
	{USB_DEVICE(0x0846, 0x9014), .driver_info = RLT_MAC_BASE}, /* NetGear, Inc. N600 Wireless Dual Band WNDA3100v3 */
	{USB_DEVICE_AND_INTERFACE_INFO(0x0E8D, 0x7632, 0xff, 0xff, 0xff), .driver_info = RLT_MAC_BASE},
	{USB_DEVICE_AND_INTERFACE_INFO(0x0E8D, 0x7662, 0xff, 0xff, 0xff), .driver_info = RLT_MAC_BASE},
#endif
	{ }/* Terminating entry */
};

MODULE_DEVICE_TABLE(usb, rtusb_dev_id);
