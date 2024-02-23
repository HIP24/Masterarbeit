
## Add more CPUs to QEMU virtual machine with -smp option 
The -smp option specifies the number of CPUs

Replace n with the number of CPUs you want to add. For example, if you want to add 4 CPUs, you would use -smp cpus=4.

After making these changes, the specified number of CPUs will be available when you boot your Yocto image with this script. 
```
exec qemu-system-x86_64 -M pc,accel=kvm -kernel ./bzImage \
-m 2048 -drive file=salamander-image-sigmatek-core2.ext4,format=raw,media=disk \
-append "console=ttyS0 console=tty1 root=/dev/sda rw panic=1 sigmatek_lrt.QEMU=1 ip=dhcp rootfstype=ext4 \
-net nic,model=e1000,netdev=e1000 -netdev bridge,id=e1000,br=nm-bridge \
-fsdev local,security_model=none,id=fsdev0,path=drive-c -device virtio-9p-pci,id=fs0,fsdev=fsdev0,mount_>
-drive if=pflash,format=qcow2,file=ovmf.code.qcow2 \
-smp cpus=n \
-no-reboot -nographic
```
Check with: `cat /sys/devices/system/cpu/online`
```
root@sigmatek-core2:~# cat /sys/devices/system/cpu/online
0-9
```
## Isolate CPUs with isolcpus
To use isolcpus in a Yocto image, you need to add it to the kernel command line parameters. In your case, these parameters are specified in the -append option in your QEMU command. Add isolcpus=x,y,z. Replace x,y,z with the CPU cores you want to isolate. For example, if you want to isolate cores 0, 1 and 2, you would use isolcpus=0,1,2.
```
exec qemu-system-x86_64 -M pc,accel=kvm -kernel ./bzImage \
-m 2048 -drive file=salamander-image-sigmatek-core2.ext4,format=raw,media=disk \
-append "console=ttyS0 console=tty1 root=/dev/sda rw panic=1 sigmatek_lrt.QEMU=1 ip=dhcp rootfstype=ext4 isolcpus=0,1,2" \
-net nic,model=e1000,netdev=e1000 -netdev bridge,id=e1000,br=nm-bridge \
-fsdev local,security_model=none,id=fsdev0,path=drive-c -device virtio-9p-pci,id=fs0,fsdev=fsdev0,mount_>
-drive if=pflash,format=qcow2,file=ovmf.code.qcow2 \
-smp cpus=n \
-no-reboot -nographic
```
Check with: `cat /sys/devices/system/cpu/isolated`
```
root@sigmatek-core2:~# cat /sys/devices/system/cpu/isolated
0-2
```

## Gid PID Of processes
Start latency and write output to latency_output.txt:
`latency -T 60 > latency_output.txt 2>&1 &`  
Get ID of xenomai task: `ps aux | grep latency`
```
root@sigmatek-core2:~# latency -T 60 > latency_output.txt 2>&1 &
[1] 557
root@sigmatek-core2:~# ps aux | grep latency
root       557  0.0  0.6  14040 12852 ttyS0    SLl  11:34   0:00 latency -T 60
root       563  0.0  0.0   3256  1148 ttyS0    S+   11:34   0:00 grep latency
```

## Assign tasks to the isolated CPUs 
To assign these latency tasks to the isolated CPUs, you can use the taskset command with the process ID (PID) of each latency task. For example, if you want to assign the latency task with PID 536 to CPU 1, you would use:

`taskset -pc x abc`

Remember to replace abc with the actual PID of the latency task. You can repeat this process for each latency task and each isolated CPU.


## Kill processes 
Kill processes with `kill x`


## ^M error message
The error message you're seeing is typically caused by a mismatch in line endings. Scripts that have been edited or created on Windows use a different line ending (`\r\n`) than Unix/Linux (`\n`). The `^M` in the error message is a visual representation of `\r` (carriage return), which is not expected or understood by the Linux shell.

You can convert the line endings of your script to the Unix format using a tool like `dos2unix`. Here's how you can do it:

```bash
sudo apt-get install dos2unix  # Install dos2unix tool
dos2unix /home/sigma_ibo/Desktop/Masterarbeit/documentation/resources/QEMU/start_qemu.sh
```