## Enable kernel modules  
[Host-Guest Tutorial](https://rostedt.org/host-guest-tutorial/)  
To have trace-cmd trace guests from the host, it is required that the guest is set up with vsocks. These are a virtual socket that lets the guest connect directly with the host. To do this, make sure that your guest kernel has the following configurations:

CONFIG_VSOCKETS=m
CONFIG_VHOST_VSOCK=m
CONFIG_VIRTIO_VSOCKETS=m
CONFIG_VIRTIO_VSOCKETS_COMMON=m
CONFIG_VSOCKETS_DIAG=m
CONFIG_VSOCKETS_LOOPBACK=m
And obviously have tracing enabled as well:

CONFIG_TRACING=y  
CONFIG_FTRACE=y  
CONFIG_FUNCTION_TRACER=y  
CONFIG_FUNCTION_GRAPH_TRACER=y  
CONFIG_DYNAMIC_FTRACE=y  
CONFIG_DYNAMIC_FTRACE_WITH_REGS=y  
CONFIG_DYNAMIC_FTRACE_WITH_DIRECT_CALLS=y  
CONFIG_DYNAMIC_FTRACE_WITH_ARGS=y  
CONFIG_SCHED_TRACER=y  
CONFIG_FTRACE_SYSCALLS=y  
CONFIG_TRACER_SNAPSHOT=y  
CONFIG_KPROBE_EVENTS=y  
CONFIG_UPROBE_EVENTS=y  
CONFIG_BPF_EVENTS=y  
CONFIG_DYNAMIC_EVENTS=y  
CONFIG_PROBE_EVENTS=y  
CONFIG_SYNTH_EVENTS=y  
CONFIG_HIST_TRIGGERS=y  


[VirtioVsock](https://wiki.qemu.org/Features/VirtioVsock)

## bitbake 
```
../init.sh -b build -m sigmatek-core2 -d salamander
bitbake salamander-image -k
```

## QEMU 
Add
`-append "console=ttyS0 console=tty1 root=/dev/sda rw panic=1 sigmatek_lrt.QEMU=1 ip=dhcp rootfstype=ext4 schedstats=enable" \`  
`-net nic,model=e1000,netdev=e1000 -netdev bridge,id=e1000,br=nm-bridge \`  
`-device vhost-vsock-pci,guest-cid=3,id=vsock0 \`

```
#!/bin/sh

if  [ ! -d drive-c/ ]; then
        echo "Filling drive-c/"
        mkdir drive-c/
        tar -C drive-c/ -xf stek-drive-c-image-sigmatek-core2.tar.gz
fi

exec qemu-system-x86_64 -M pc,accel=kvm -kernel ./bzImage \
-m 2048 -drive file=salamander-image-sigmatek-core2.ext4,format=raw,media=disk \
-append "console=ttyS0 console=tty1 root=/dev/sda rw panic=1 sigmatek_lrt.QEMU=1 ip=dhcp rootfstype=ext4 schedstats=enable" \
-net nic,model=e1000,netdev=e1000 -netdev bridge,id=e1000,br=nm-bridge \
-fsdev local,security_model=none,id=fsdev0,path=drive-c -device virtio-9p-pci,id=fs0,fsdev=fsdev0,mount_tag=/mnt/drive-C \
-device vhost-vsock-pci,guest-cid=3,id=vsock0 \
-drive if=pflash,format=qcow2,file=ovmf.code.qcow2 \
-no-reboot -nographic
```

## scp .ipk to Salamander4 and install
When you run bitbake xxx, the output of the build process, including any generated .ipk files, is typically stored in the tmp/deploy/ipk/ directory within your build directory1. The exact location can depend on your configuration and the specific recipe you’re building.

The .ipk files are package files used by opkg, a lightweight package management system. These files are created when you build a recipe that includes packaging steps.
```
cd ~/Develop/Yocto_local/salamander/salamander-core2/build/tmp/deploy/ipk/core2-64$ scp trace-cmd_2.9.1-r0_core2-64.ipk root@10.30.248.137:/home/root/bb
opkg install trace-cmd_2.9.1-r0_core2-64.ipk
```

## WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED!


```
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@    WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED!     @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
IT IS POSSIBLE THAT SOMEONE IS DOING SOMETHING NASTY!
Someone could be eavesdropping on you right now (man-in-the-middle attack)!
It is also possible that a host key has just been changed.
The fingerprint for the ED25519 key sent by the remote host is
SHA256:R1FIDyOY4bzLdNIJ3CUgwFRRzZPiq4dHL/DA5YY3Bw8.
Please contact your system administrator.
Add correct host key in /home/sigma_ibo/.ssh/known_hosts to get rid of this message.
Offending ED25519 key in /home/sigma_ibo/.ssh/known_hosts:12
  remove with:
  ssh-keygen -f "/home/sigma_ibo/.ssh/known_hosts" -R "10.30.248.137"
Host key for 10.30.248.137 has changed and you have requested strict checking.
Host key verification failed.
```
It seems like the SSH host key for the server at 10.30.248.137 has changed, which is causing the connection to fail due to strict checking. This could happen for a few reasons, such as the server being reinstalled or the SSH service being reconfigured.

You can resolve this issue by removing the old host key from your known_hosts file. The offending key is on line 12 of the file. You can remove it with the following command:

```
ssh-keygen -f "/home/sigma_ibo/.ssh/known_hosts" -R "10.30.248.137" # Salzburg
ssh-keygen -f "/home/sigma_ibo/.ssh/known_hosts" -R "192.168.1.78" # Wien"

```
This will remove the old key for 10.30.248.137 from your known_hosts file. The next time you connect, you should be prompted to accept the new host key.


