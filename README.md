## Introduction

This is a linux kernel driver for the Netgear A6210 wireless adapter and other wireless adapters based on the Ralink/Mediatek MT766U, MT7632U and MT7612 chipsets. The source code is based on the original MediaTek source code(1) (originally written for the 3.x series kernel in July 2014) which has been updated by Juro Bystricky, Eugene Rusalev and others to support more modern kernel versions e.g. 4.1.x.

### Supported Devices
The following devices are known to use wireless chipsets supported by this driver but there are probably many others. 
- Netgear A6210 WiFi USB 3.0 Adapter (802.11ac Dual Band with High Gain Antenna)
- Netgear RangeMax Dual Band Wireless-N USB 2.0 Adapter WNDA3100 (Revision 3)
- Asus USB-AC55 AC1300 Dual-band USB Wireless Dongle
- Asus USB-N53 USB Dual Band Wireless Dongle
- Edimax AC1200 EW-7722UAC Wireless Dual Band USB 3.0 Adapter
- EDUP 802.11 AC 1200M 2.4G/5.8G Dual Band USB 3.0 Wireless Wifi Adapter
- Microsoft XBox One Wireless Adapter

If you are aware of any other devices not listed here that use any of the supported chipsets please send us a copy of its USB ID so that we can add support directly into the driver.

### Supported Chipsets
MediaTek/Ralink
- MT766U
- MT7632U
- MT7612

### Current Status

The driver is a work in progress, despite being mostly fully functional (including AP mode) there have been reports of issues with certain combinations of devices and the linux distribution used. See known issues for more information.

### Supported Linux Kernel Versions

The driver supports the Linux kernel 4.x.x series e.g. 4.1.x LTS and more recently 4.6.1. If you are using an older kernel we recommend updating to get support.

### Linux Distribution Support

As far as I know no distributions are currently including this driver in their standard repositories. However, have a look in the packaging directory and you might be able to find links to scripts that can be used to complile a DKMS package for your distribution. At the moment we have prebuilt package recipes for Arch Linux (abs) and Fedora (RPM).

If built from source the driver itself should work on more recent Linux distributions providing that they use a modern (4.1+) series kernel. e.g.
- Ubuntu 15.10, Ubuntu 16.04 LTS
- Arch Linux
- Fedora 23
- Debian 9 "Stretch"

## Building From Source

Before building from source please consider building a package for your distribution and letting us know so that we can include your efforts in our source tree, therefore benefiting everyone. To build the driver from the source tree you will need to have git, make, gcc and the kernel headers installed.

```
$ git clone https://github.com/worralph/netgear-a6210-driver-dkms
$ cd netgear-a6210-driver-dkms
$ make
$ make install (or sudo make install)
```

### Known Issues
The following is a list of issues that have been reported
- Crashing upon device removal
- The network needs be restarted after reinserting a wireless device
- Intermittant losses of connectivity
- Low signal strength
- Activity LEDs do not work
- When using the hostspot feature and a 802.11a (5Ghz) network you may need to perform a scan first before hostapd will allow you to create a hotspot that can be seen by client devices. You can do this by using the iw command, where wlan0 is the name of your wireless adapter.
```
iw dev wlan0 scan
```

### Acknowledgements
- MediaTek for release of their source code under a GPL licence
- Juro Bystricky and Eugene Rusalev for the significant rewrite to add support for 4.x series kernels.

### Licence

This program is free software. You can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

MediaTek Inc.
Address : 5F., No.5, Tai-Yuan 1st St., Jhubei City,
Hsinchu County 302,Taiwan, R.O.C.
(c) Copyright 2002-2013, MediaTek Inc.

With contributions from;

(c) Copyright Eugene Rusalev

(c) Copyright Juro Bystricky

(c) Copyright Philip Worrall

## References

[1] http://www.mediatek.com/en/downloads1/downloads/mt7612u/

[2] https://github.com/jurobystricky/

## Notes

The original MediaTek driver source code was distributed as MT7612U_DPO_LinuxSTA_3.0.0.1_20140718.tar.bz2
