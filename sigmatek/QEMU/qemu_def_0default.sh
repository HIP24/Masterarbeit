#!/bin/sh

if  [ ! -d drive-c/ ]; then
	echo "Filling drive-c/"
	mkdir drive-c/
	tar -C drive-c/ -xf stek-drive-c-image-sigmatek-core2.tar.gz
fi

exec qemu-system-x86_64 -M pc,accel=kvm -kernel ./bzImage \
-m 2048 -drive file=salamander-image-sigmatek-core2.ext4,format=raw,media=disk \
-append "console=ttyS0 console=tty1 root=/dev/sda rw panic=1 sigmatek_lrt.QEMU=1 ip=10.0.2.15::10.0.2.2:255.255.255.0 rootfstype=ext4" \
-net nic,model=e1000 -net type=user,hostfwd=tcp::1954-:1954,hostfwd=tcp::1955-:1955,hostfwd=tcp::2021-:21,hostfwd=tcp::2022-:22,hostfwd=tcp::2080-:80,hostfwd=tcp::2445-:445,hostfwd=tcp::5900-:5900,hostfwd=tcp::2345-:2345 \
-fsdev local,security_model=none,id=fsdev0,path=drive-c -device virtio-9p-pci,id=fs0,fsdev=fsdev0,mount_tag=/mnt/drive-C \
-drive if=pflash,format=qcow2,file=ovmf.code.qcow2 \
-no-reboot -nographic