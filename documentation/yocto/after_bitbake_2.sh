#!/bin/bash

ip_address="192.168.1.51"

#ssh-keygen -f "/home/sigma_ibo/.ssh/known_hosts" -R "$ip_address"
cd /home/sigma_ibo/Develop/Yocto_local/salamander/salamander-core2/build/tmp/deploy/ipk/core2-64
ssh root@"$ip_address" 'mkdir bb'
scp trace-cmd_2.9.1-r0_core2-64.ipk root@"$ip_address":/home/root/bb
ssh root@"$ip_address" 'opkg install /home/root/bb/trace-cmd_2.9.1-r0_core2-64.ipk'
#start_qemu.sh
