# Fedora RPM package for the Netgear A6210 Wireless Adapter Linux Kernel Driver (DKMS)

Inside the following directory you will find a RPM specfile that can be used to package the A6210 kernel driver for Fedora Linux (and potentially other RPM-based distributions). If you are an end user we provide prebuilt binary packages which you can find on the the releases page.

### Creating the netgear-a6210-driver-dkms Package

To build the package on Fedora you will need a copy of rpmdevtools (rpmbuild etc.) plus make, gcc, dkms, kernel headers and kernel devel.

Create the rpm build tree if you don't already have one setup.

```
rpmdev-setuptree
```

Next copy the .spec file in this folder into your ~/rpmbuild/SPECS directory

```
wget https://raw.githubusercontent.com/worralph/netgear-a6210-driver-dkms/master/packaging/fedora/netgear-a6210-driver-dkms.spec
cp netgear-a6210-driver-dkms.spec ~/rpmbuild/SPECS
```

### Fetching the upstream sources

Use the spectool helper program to download the upstream source code for this package

```
spectool -R -g ~/rpmbuild/SPECS/netgear-a6210-driver-dkms.spec
```

### Building the package 

Now you can start the build process

```
rpmbuild -ba ~/rpmbuild/SPECS/netgear-a6210-driver-dkms.spec
```

### Installing

If all goes well your binary rpm package will be saved to the ~/rpmbuild/RPMS/x86_64 directory. To install use the rpm command as administrator.

```
sudo rpm -i ~/rpmbuild/RPMS/x86_64/netgear-a6210-driver-dkms*.rpm
```

### Post-Installation

By default the Fedora kernel will not load kernel modules that have not been signed by a trusted certificate. 

To workaround this issue you can either (1) build a custom kernel and disable module verification or (2) sign the module with your
own private key and add this key to your system's list of trusted keys. 

In the case of the later you should follow the instructions detailed on https://www.kernel.org/doc/Documentation/module-signing.txt 
to create a keypair and sign the mt7662u_sta.ko file (it can be found in /lib/modules/$KERNELVERSION/kernel/drivers/net/wireless/mt7662u_sta.ko)

Once the driver file is signed you will need to add your private key to the system's trusted keys and then reboot your machine.

## Using the Driver

Now you have the driver installed, signed and you have rebooted you should be able to plug-in your adapater and see that a new wireless interface is available. On my system it is shown as wlan0.

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
new linux kernel. Remember that, unless you are using a custom kernel that doesn't require module verification, you will need to sign each new built module with your private key otherwise it will not be loaded.

