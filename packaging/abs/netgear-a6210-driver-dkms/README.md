# ArchLinux PKGBUILD for the Netgear A6210 Wireless Adapter Linux Kernel Driver (DKMS)

Inside the following directory you will find an ArchLinux compatible PKGBUILD file that can be used to package the A6210 kernel driver for ArchLinux (and potentially other ArchLinux-based distributions. e.g. Antergos, Manjaro)

### Creating the netgear-a6210-driver-dkms Package

To build the package on ArchLinux you will need to download a copy of this repository and change directory into the abs (arch build system) packaging directory. Note that you will need to have git, make, gcc and dkms 
already installed.

```
git clone https://github.com/worralph/netgear-a6210-driver-dkms
cd netgear-a6210-driver-dkms/packaging/abs/netgear-a6210-driver-dkms
```

Create the ArchLinux package based on the latest upstream release

```
makepkg
```

### Installing

To install you should run the following as root

```
pacman -U netgear-a6210-driver-dkms*.pkg.tar.xz
```

### Post-Installation

Now that you have the driver installed you should be able to plug-in your adapater and see that a new wireless interface is available. On my system it is shown as wlan0.

```
ip addr
```

If you intend to use this driver to create a wireless hostspot, using something like hostapd, you may need to perform an initial scan before this will work. e.g.

```
ip link set dev wlan0 up
iw dev wlan0 scan
```

Now you can start hostapd

```
systemctl start hostapd
```

### A Note About DKMS

As this package using the [dkms](https://wiki.archlinux.org/index.php/Dynamic_Kernel_Module_Support "DKMS") framework it will automatically compile and install a new driver for your wireless adapter whenever you upgrade/install a 
new linux kernel.

