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
- `latency -T 60`  
- `clocktest -D -T 60` 

### Max Latency default
With [`qemu_def_2nmbridge.sh`](../sigmatek/QEMU/qemu_def_2nmbridge.sh), no taskset 
```bash
sigma_ibo@pamhal:$ ps -eo pid,psr,comm | grep qemu
   7295  10 start_qemu.sh
   7298  17 qemu-system-x86
```

[latency -h -s -T 600 -g max_latency_default_10min.txt](../sigmatek/xenomai/default/max_latency_default_10min_log.md)

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

After taskset on CPU4 with [`qemu_def_4taskset.sh`](../sigmatek/QEMU/qemu_def_4taskset.sh)
```bash
sigma_ibo@pamhal:$ ps -eo pid,psr,comm | grep qemu
   8752   0 start_qemu.sh
   8755   4 qemu-system-x86
```
[latency -h -s -T 600 -g max_latency_with_taskset_10min.txt](../sigmatek/xenomai/taskset/max_latency_taskset_10min_log.md)

> lat worst reduced from 4070.018 to [457.545](../sigmatek/xenomai/taskset/max_latency_taskset/max_latency_taskset.png) with [stats](../sigmatek/xenomai/taskset/max_latency_taskset/max_latency_taskset_statistics.txt)

### Max Latency with rt
#### Enable Preempt_RT Kernel
Either do everything in [kernel-patch.md](../sigmatek/salamander4/latency_reduction/kernel-patch/kernel-patch.md) to patch the kernel and enable Fully Preemptible Kernel (RT).  
Or simply [enable Ubuntu Pro's real-time kernel](https://ubuntu.com/blog/real-time-ubuntu-released).

!!! info
    Before the isolation of CPU x, both kernel threads and user processes were running on this CPU. The user processes included various applications such as msedge, code, bash and qemu-system-x86.
    
    After isolating CPU x, only kernel threads and the qemu-system-x86 process appear to be running on this CPU. There do not appear to be any other user processes running on this CPU.
    
    The isolcpus option prevents the kernel from scheduling normal (non-real-time) processes on the isolated CPUs. However, there are some exceptions:

    - If a process is explicitly set to run on an isolated CPU (for example with taskset), it will run on that CPU even if it is isolated.
    - Some kernel threads can run on isolated CPUs because they are not controlled by the normal scheduler. These include the threads you see in your output, such as kthreadd, migration/4, ksoftirqd/4, kworker/4:0-events and others.
    - Interrupts can be handled on isolated CPUs unless they are explicitly redirected with the irqaffinity option.

[latency -T 600](../sigmatek/xenomai/rt/max_latency_rt/max_latency_rt_10min_log.md)

> lat worst reduced from 457.545 to [32.216](../sigmatek/xenomai/rt/max_latency_rt/test_max_latency.png) with [stats](../sigmatek/xenomai/rt/max_latency_rt/test_max_latency_statistics.txt)

#### Realtime priority

!!! danger
    Setting a real-time priority of 99 for a process means that this process has the highest priority in the system and is executed before all other processes. This can result in other processes, including important system processes, not receiving the CPU time they need to function properly. This can lead to system instability and, in the worst case, to the system becoming unresponsive or "crashing".

    It is important to be careful when using real-time priorities and ensure that other important processes still get the CPU time they need. It might be helpful to gradually increase the real-time priority and observe the effects on the system instead of jumping straight to the highest priority.


To see the real-time priorities of all running processes, have a look at [thread priorities](../workflow/useful.md#thread-priorities).

#### Configuring the system for real-time
For now, PREEMPT\_RT is a set of patches that is supposed to be applied on top of mainline Linux. Most Linux distributions do not build it by default, and you will most likely have to do it yourself [[3]](https://shuhaowu.com/blog/2022/02-linux-rt-appdev-part2.html#f4). How this can be done falls outside the scope of this post, but there are plenty of [guides](https://docs.ros.org/en/foxy/Tutorials/Building-Realtime-rt_preempt-kernel-for-ROS-2.html) out there. Hopefully in the near future, all of PREEMPT\_RT's functionality will be merged in to mainline, and Linux distributions will provide RT-enabled kernels out-of-the-box.

Once you successfully compiled the RT kernel, the default hardware and OS configurations are usually not tuned correctly for RT. The following hardware and OS configurations should likely always be checked and tuned:

##### Disable [simultaneous multithreading](https://en.wikipedia.org/wiki/Simultaneous_multithreading)
    -   SMT improves the performance of the CPU but decreases the determinism, thus introducing latency. How this works is outside the scope of this post. As of this writing, it is recommended for SMT to be disabled [[4]](https://shuhaowu.com/blog/2022/02-linux-rt-appdev-part2.html#f5).
    -   SMT is usually configured on the BIOS/UEFI level. How this is done varies depending on the system.  
[disable_txt.jpg](../resources/images/bios/disable_txt.jpg)  
[disable_hyperthreading.jpg](../resources/images/bios/disable_hyperthreading.jpg)

##### Disable [dynamic frequency scaling](https://wiki.archlinux.org/title/CPU_frequency_scaling)
    -   Modern CPUs ramp down their clock frequencies while idling and ramp up when there is load. This introduces unpredictability as it causes the performance of the CPU to vary with time. Anecdotally, I have noticed an order of magnitude higher worst-case latency when frequency scaling is on compared to when it is off.
    ```
    sigma_ibo@sigma-ibo:~/Downloads$ for i in /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor; do echo "performance" | sudo tee $i; done
    performance
    performance
    performance
    performance
    performance
    performance
    performance
    performance
    performance
    performance
    performance
    performance
    performance
    performance
    ```
    To automate this process open `crontab -e` and enter
    ```
    @reboot for i in /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor; do echo 'performance' | sudo tee $i; done
    ```
    -   How this can be turned off varies per system. Usually this involves configuring both the BIOS/UEFI and Linux (usually by selecting the performance CPU frequency governor).

##### Disable [RT throttling](https://wiki.linuxfoundation.org/realtime/documentation/technical_basics/sched_rt_throttling)
Before the widespread availability of multicore systems, if an RT process uses up all of the available CPU time, it can cause the entire system to hang. This is because the Linux scheduler will not run a non-RT process if the RT process continuously hogs the CPU. To avoid this kind of system lockup, especially on desktop-oriented systems where any process can request to be RT, the Linux kernel has a feature to throttle RT processes if it uses 0.95 s out of every 1 s of CPU time. This is done by pausing the process for the last 0.05 s and thus may result in deadline misses during the moments when the process is paused [[5]](https://shuhaowu.com/blog/2022/02-linux-rt-appdev-part2.html#f6). This can be turned off by writing the value \-1 to the file `/proc/sys/kernel/sched_rt_runtime_us` on every system boot.  
To permanently disable real-time (RT) throttling, you can add the following line to your `/etc/sysctl.conf` file:

1. Open the `/etc/sysctl.conf` file in a text editor. You might need to use \`sudo\` to edit this file.
```bash  
sudo nano /etc/sysctl.conf  
```
2. Add the following line to the end of the file:
```bash  
kernel.sched_rt_runtime_us = -1  
```
3. Save the file and exit the editor.
4. To load the new configuration, run the following command:

```bash  
sudo sysctl -p  
```

        This will apply the change immediately and also preserve it across reboots.  

##### Check and make sure no unexpected RT processes are running on your system
-   Sometimes, the base OS can spawn a high-priority RT process on boot as a part of some functionalities it provides. If these functionalities are not needed, it is advisable to disable the offending RT process. Near the end of this post, I will provide an example for this.
-   Sometimes, the kernel can be configured with such a process. See documentation on the kernel build variables CONFIG\_LOCKUP\_DETECTOR and CONFIG\_DETECT\_HUNG\_TASK.
-   Disabling these processes usually involves consulting with the documentations of your Linux distribution of choice.

There are other configurations that may be relevant depending on your use case, some of which are documented in [this talk](https://www.youtube.com/watch?v=NrjXEaTSyrw) and [this other talk](https://www.youtube.com/watch?v=w3yT8zJe0Uw). Additionally, quality-of-life configurations, such the variables in /etc/security/limits.conf, may need to be tuned as well. I encourage the reader to look at pre-made distributions such as the [ROS2 real-time Raspberry Pi image](https://github.com/ros-realtime/ros-realtime-rpi4-image) (which I incidentally also worked on) for more inspiration. Although providing a complete checklist for system configuration is outside the scope of this post (if it is even possible), I included an non-exhaustive checklist [at the bottom of this post](https://shuhaowu.com/blog/2022/02-linux-rt-appdev-part2.html#appendix-hardware-and-os-configuration-checklist) as a starting point.

##### IRQ affinity
Remove all possible IRQs from isolated CPU with [remove_irqs_from_CPU.sh](../sigmatek/salamander4/latency_reduction/IRQaffinity/remove_irqs_from_CPU.sh). Check with [table_CPU_IRQ.md](../sigmatek/salamander4/latency_reduction/IRQaffinity/table_CPU_IRQ.md) and cat `/proc/interrupts`.

##### RCU CPU offloading
Add `rcu_nocbs=13` as boot parameter for CPU offloading in `sudo nano /etc/default/grub`
  ```
  GRUB_CMDLINE_LINUX="isolcpus=13 rcu_nocbs=13"
  ```

##### Suppress rcu cpu stall
  ```
  echo 1 | sudo tee /sys/module/rcupdate/parameters/rcu_cpu_stall_suppress
  ```

##### Maybe?
  ```
  echo 200 | sudo tee /sys/module/rcupdate/parameters/rcu_cpu_stall_timeout
  ```

##### Start QEMU normally with idle=poll  
Start QEMU [normally with idle=poll](../sigmatek/QEMU/qemu_def_5idle=poll.sh). Give all QEMU threads rt-priority.
```
ps -T -p $(pgrep -f "qemu-system-x86_64 -M pc,ac") | awk '{print $2}' | tail -n +2 | xargs -I {} sudo chrt -r -p 99 {}
```

##### Kill all running user processes
Make sure there is no other running process

##### Trace latency 
  ```
  latency -h -s -T 600 -g max_latency_rt.txt
  ```
