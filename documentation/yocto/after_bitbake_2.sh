#!/bin/bash

ip_address="192.168.1.141"

#ssh-keygen -f "/home/sigma_ibo/.ssh/known_hosts" -R "$ip_address"
#cd /home/sigma_ibo/Develop/Yocto_local/salamander/salamander-core2/build/tmp/deploy/ipk/core2-64
#ssh root@"$ip_address" 'mkdir bb'
ssh-keygen
ssh-copy-id root@"$ip_address"
scp /usr/local/bin/trace-cmd root@"$ip_address":/usr/bin
scp /usr/local/lib64/libtracefs.so.1 root@"$ip_address":/lib64
scp /usr/local/lib64/libtraceevent.so.1 root@"$ip_address":/lib64
#ssh root@"$ip_address" 'opkg install /home/root/bb/trace-cmd_2.9.1-r0_core2-64.ipk'
#start_qemu.sh
