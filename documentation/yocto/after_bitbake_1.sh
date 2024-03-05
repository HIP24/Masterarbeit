#!/bin/bash

cd /home/sigma_ibo/Develop/Yocto_local/salamander/salamander-core2/build/tmp/deploy/qemu/sigmatek-core2/salamander-image/ 
sudo rm qemu_def.sh
cat /home/sigma_ibo/Desktop/Masterarbeit/documentation/resources/QEMU/qemu_def_5taskset.sh > qemu_def.sh
chmod 777 qemu_def.sh
start_qemu.sh

## OnSalamander4 ##
# ip a