# Disable the building of the seperate debug package(s).
%global debug_package %{nil}

# Dont strip the debug symbols
%global __strip /bin/true

Summary:	Kernel Driver for the Netgear A6210 Wireless Adapter (DKMS)
Name:		netgear-a6210-driver-dkms
Version:	4.6.2.1
Release:	1%{?dist}
License:	GPLv2+
URL:		https://github.com/worralph/%{name}
Source0:	https://github.com/worralph/%{name}/archive/v%{version}/.tar.gz
Source1:	https://raw.githubusercontent.com/worralph/%{name}/master/packaging/fedora/dkms.conf
Patch0:		https://raw.githubusercontent.com/worralph/%{name}/master/packaging/abs/%{name}/add-destdir-to-makefile.patch

BuildRequires:	make
BuildRequires:	gcc
BuildRequires:	kernel-headers
BuildRequires:	kernel-devel
BuildRequires:	dkms

# For adhoc building by DKMS the requires should essentially be the same
# and the ones used for the package build itself.
Requires:	make
Requires:	gcc
Requires:	kernel-headers
Requires:	kernel-devel
Requires:	dkms

%description
A dynamic kernel module driver for the Netgear A6210\
Wireless Adapter that also supports other wireless\
adapters that are based on the mt766u, mt7632u
and mt7612u family of wireless chipsets.

This includes the following released products:\
Netgear A6210 WiFi USB 3.0 Adapter (802.11ac Dual\
Band with High Gain Antenna), Netgear RangeMax Dual\
Band Wireless-N USB 2.0 Adapter WNDA3100 (Revision 3),\
Asus USB-AC55 AC1300 Dual-band USB Wireless Dongle,\
Asus USB-N53 USB Dual Band Wireless Dongle, Edimax \
AC1200 EW-7722UAC Wireless Dual Band USB 3.0 Adapter,\
EDUP 802.11 AC 1200M 2.4G/5.8G Dual Band USB 3.0\
Wireless Wifi Adapter and the Microsoft XBox One\
Wireless Adapter.

%prep
%setup -qn %{name}-%{version}
%patch0 -p1

%build
make %{?_smp_mflags}

%install
# make a copy of the sources and put it somewhere dkms can find it
mkdir -p $RPM_BUILD_ROOT/usr/src/%{name}-%{version}
cp -a $RPM_BUILD_DIR/%{name}-%{version}/* $RPM_BUILD_ROOT/usr/src/%{name}-%{version}/
# install into the build tree but dont run depmod yet
make DESTDIR=$RPM_BUILD_ROOT RUNDEPMOD=n install
# clean out the source tree ready for dkms
make -C $RPM_BUILD_ROOT/usr/src/%{name}-%{version} clean
cp %{SOURCE1} $RPM_BUILD_ROOT/usr/src/%{name}-%{version}/
# update the dkms version info for this module
sed -e "s/@_PKGBASE@/%{name}/" \
      -e "s/@PKGVER@/%{version}/" \
      -i $RPM_BUILD_ROOT/usr/src/%{name}-%{version}/dkms.conf
chmod u+x $RPM_BUILD_ROOT/lib/modules/*/kernel/drivers/net/wireless/mt7662u_sta.ko

%post
dkms install -m %{name} -v %{version}

%postun
dkms remove -m %{name} -v %{version} --all

%files
%license LICENCE
%doc README.md
%doc doc/*
/etc/Wireless/*
# the kernel module for the running kernel
/lib/modules/*/kernel/drivers/net/wireless/mt7662u_sta.ko
# source code for dkms
/usr/src/%{name}-%{version}
