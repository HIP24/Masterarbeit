# Protocol

## Dual Boot
1) Flash SSD by installing <a href="https://etcher.balena.io/" target="_blank">etcher</a>
2) Ubuntu and Windows on same machine

## Install Salamander4 OS
1) Install Ubuntu 22.04.3 LTS
2) Do everything in [build_with_yocto.md](../sigmatek/salamander4/build_with_yocto.md)

## SSH to device
Connect to device with `ssh -oHostKeyAlgorithms=+ssh-rsa root@10.10.1.229`  
or `ssh -p 22 root@192.168.1.x` (changes often)

## LasalClass2 to device
Connect LasalClass2 with [Salamander 4](../resources/images/lasal/class2/lasalclass2_ip.png), IP of [Salamander4 device](../resources/images/lasal/class2/lasalclass2_salamander4_ip.png)

## Configure bridge for QEMU
This setup allows the virtual machines to communicate with the outside network through the Ethernet connection provided by either the laptop or the docking station.

| name       | device |
|------------|-------|
| enp0s31f6 | Laptop's Ethernet port |
| enx4cd717733f80 | Docking station's Ethernet port |

- Disable [ipv4](../resources/images/configure_bridge/ethernet_disable_ip4.png) and [ipv6](../resources/images/configure_bridge/ethernet_disable_ip6.png)
- Enter [nmtui](../resources/images/configure_bridge/nmtui.png)
- Edit Connection and [\<Add\>](../resources/images/configure_bridge/add_connection.png). Select Bridge.
- [Edit](../resources/images/configure_bridge/edit_connection.png) and \<Add\> Ethernet.
- [Copy name](../resources/images/configure_bridge/copy_name.png) enx4cd717733f80 (4C:D7:17:73:3F:80) of Wired connection 2
- [Edit Connection of Ethernet connection 1](../resources/images/configure_bridge/ethernet1.png) so that it automatically connects.
- [Activate Connection](../resources/images/configure_bridge/activate_connection.png).
- Result should look like [this](../resources/images/configure_bridge/get-to-know/connections.png) and [this](../resources/images/configure_bridge/get-to-know/bridge_connections.png).
- More info in [nmbridge.md](../sigmatek/QEMU/nmbridge.md). 

## Reduce latency
We test the system using the Xenomai test suite
- `latency`  
- `clocktest` 

### Max Latency default
Default latency 
```bash
sigma_ibo@pamhal:$ ps -eo pid,psr,comm | grep qemu
   7295  10 start_qemu.sh
   7298  17 qemu-system-x86
```

[latency -h -s -T 600 -g max_latency_default_10min.txt](../sigmatek/xenomai/1default/max_latency_default_10min_log.md)

> lat worst is 4070.018

### Max Latency with taskset

To isolate CPUs on your host system (Ubuntu), you can add the `isolcpus` option to the kernel boot configuration. Here are the steps you can follow:

1. Open the GRUB configuration file with a text editor. You can use the `nano` editor for this. Execute the following command in your terminal:
    ```bash
    sudo nano /etc/default/grub
    ```
2. Search for the entry `GRUB_CMDLINE_LINUX` and add `isolcpus=0,1,2,3,4` (or the corresponding CPU numbers you want to isolate). It should then look like this:
    ```bash
    GRUB_CMDLINE_LINUX="isolcpus=0,1,2,3,4"
    ```
3. Save the changes and close the editor. If you are using `nano`, you can do this by pressing `Ctrl+X`, then typing `Y` to save the changes, and finally pressing `Enter` to close the editor.

4. Update GRUB with the following command:
    ```bash
    sudo update-grub
    ```
5. Reboot your system for the changes to take effect.


Check with: `cat /sys/devices/system/cpu/isolated`

```bash
sigma_ibo@pamhal:~$ cat /sys/devices/system/cpu/online 
0-19
sigma_ibo@pamhal:~$ cat /sys/devices/system/cpu/isolated
0-4
```

After taskset on CPU4 with [`qemu_def_2taskset_vsock_nmbridge.sh`](../sigmatek/QEMU/qemu_def_2taskset_vsock_nmbridge.sh)
```bash
sigma_ibo@pamhal:$ ps -eo pid,psr,comm | grep qemu
   8752   0 start_qemu.sh
   8755   4 qemu-system-x86
```
[latency -h -s -T 600 -g max_latency_with_taskset_10min.txt](../sigmatek/xenomai/2taskset/max_latency_taskset_10min_log.md)

> lat worst reduced from 4070.018 to [457.545](../sigmatek/xenomai/2taskset/max_latency_taskset/max_latency_taskset.png) with [stats](../sigmatek/xenomai/2taskset/max_latency_taskset/max_latency_taskset_statistics.txt)

#### Enable Preempt_RT Kernel
Either do everything in [kernel-patch.md](../sigmatek/salamander4/latency_reduction/kernel-patch/kernel-patch.md#kernel-patch-proceedure) to patch the kernel and enable [Fully Preemptible Kernel (RT)](../resources/images/kernel-patch/fully_rt.png), or simply [enable Ubuntu Pro's real-time kernel](../resources/images/ubuntu-pro.png), [here](https://ubuntu.com/blog/real-time-ubuntu-released).

!!! info
    Before the isolation of CPU x, both kernel threads and user processes were running on this CPU. The user processes included various applications such as msedge, code, bash and qemu-system-x86.
    
    After isolating CPU x, only kernel threads and the qemu-system-x86 process appear to be running on this CPU. There do not appear to be any other user processes running on this CPU.
    
    The isolcpus option prevents the kernel from scheduling normal (non-real-time) processes on the isolated CPUs. However, there are some exceptions:

    - If a process is explicitly set to run on an isolated CPU (for example with taskset), it will run on that CPU even if it is isolated.
    - Some kernel threads can run on isolated CPUs because they are not controlled by the normal scheduler. These include the threads you see in your output, such as kthreadd, migration/4, ksoftirqd/4, kworker/4:0-events and others.
    - Interrupts can be handled on isolated CPUs unless they are explicitly redirected with the irqaffinity option.

[latency -T 600](../sigmatek/xenomai/3rt/max_latency_rt/max_latency_rt_10min_log.md)

> lat worst reduced from 457.545 to [32.216](../sigmatek/xenomai/3rt/max_latency_rt/max_latency_rt.png) with [stats](../sigmatek/xenomai/3rt/max_latency_rt/max_latency_rt_statistics.txt)

#### Realtime priority

!!! danger
    Setting a real-time priority of 99 for a process means that this process has the highest priority in the system and is executed before all other processes. This can result in other processes, including important system processes, not receiving the CPU time they need to function properly. This can lead to system instability and, in the worst case, to the system becoming unresponsive or "crashing".

    It is important to be careful when using real-time priorities and ensure that other important processes still get the CPU time they need. It might be helpful to gradually increase the real-time priority and observe the effects on the system instead of jumping straight to the highest priority.


To see the real-time priorities of all running processes, have a look at [thread priorities](../workflow/useful.md#thread-priorities).

#### Configuring the system for real-time
For now, PREEMPT\_RT is a set of patches that is supposed to be applied on top of mainline Linux. Most Linux distributions do not build it by default, and you will most likely have to do it yourself [[3]](https://shuhaowu.com/blog/2022/02-linux-rt-appdev-part2.html#f4). How this can be done falls outside the scope of this post, but there are plenty of [guides](https://docs.ros.org/en/foxy/Tutorials/Building-Realtime-rt_preempt-kernel-for-ROS-2.html) out there. Hopefully in the near future, all of PREEMPT\_RT's functionality will be merged in to mainline, and Linux distributions will provide RT-enabled kernels out-of-the-box.

Once you successfully compiled the RT kernel, the default hardware and OS configurations are usually not tuned correctly for RT. The following hardware and OS configurations should likely always be checked and tuned: [latency_reduction_steps.md](../sigmatek/salamander4/latency_reduction/latency_reduction_steps.md)

#### Third process is for latency minimization
```
13    2972    2972 qemu-system-x86_64 -M pc,ac FF    -     98
13    2972    2976 qemu-system-x86_64 -M pc,ac FF    -     98
13    2972    3292 qemu-system-x86_64 -M pc,ac FF    -     90
13    2972    8699 qemu-system-x86_64 -M pc,ac FF    -     95
```

[Salamander 4 latency comparison](../sigmatek/xenomai/xenomai_compare_latmax.md)  



## PCI initalization
sudo modprobe vfio-pci
lspci -v
lspci -nn
sudo sh -c 'echo "5112 2200" > /sys/bus/pci/drivers/vfio-pci/new_id'
lspci -v
