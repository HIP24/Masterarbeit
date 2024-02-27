#!/bin/bash

cd /home/sigma_ibo/Develop/Yocto_local/salamander/salamander-core2/build/tmp/deploy/qemu/sigmatek-core2/salamander-image/ 
sudo rm qemu_def.sh
echo '#!/bin/sh

if  [ ! -d drive-c/ ]; then
        echo "Filling drive-c/"
        mkdir drive-c/
        tar -C drive-c/ -xf stek-drive-c-image-sigmatek-core2.tar.gz
fi

exec qemu-system-x86_64 -M pc,accel=kvm -kernel ./bzImage \
-m 2048 -drive file=salamander-image-sigmatek-core2.ext4,format=raw,media=disk \
-append "console=ttyS0 console=tty1 root=/dev/sda rw panic=1 sigmatek_lrt.QEMU=1 ip=dhcp rootfstype=ext4" \
-net nic,model=e1000,netdev=e1000 -netdev bridge,id=e1000,br=nm-bridge \
-fsdev local,security_model=none,id=fsdev0,path=drive-c -device virtio-9p-pci,id=fs0,fsdev=fsdev0,mount_tag=/mnt/drive-C \
-device vhost-vsock-pci,guest-cid=3,id=vsock0 \
-drive if=pflash,format=qcow2,file=ovmf.code.qcow2 \
-no-reboot -nographic' > qemu_def.sh
chmod 777 qemu_def.sh
start_qemu.sh

## OnSalamander4 ##
# ip a