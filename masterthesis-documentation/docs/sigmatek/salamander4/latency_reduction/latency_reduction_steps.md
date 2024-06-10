## Salamander 4 latency reduction

## BIOS Configurations
| Option                     | Status    |
|----------------------------|-----------|
| Hyper Threading            | disabled  |
| Intel SpeedStep®           | disabled  |
| Intel® Speed Shift Technology | disabled |
| C States                   | disabled  |
| VT-d                       | enabled   |


## Kernel Configurations
```
GRUB_CMDLINE_LINUX="isolcpus=4 rcu_nocbs=4 nohz_full=4 default_hugepagesz=1G hugepagesz=1G hugepages=8 intel_iommu=on rdt=l3cat nmi_watchdog=0 idle=poll clocksource=tsc tsc=reliable noht audit=0 skew_tick=1 intel_pstate=disable intel.max_cstate=0 intel_idle.max_cstate=0 processor.max_cstate=0 processor_idle.max_cstate=0 nosoftlockup nohz=on no_timer_check nospectre_v2 spectre_v2_user=off kvm.kvmclock_periodic_sync=N kvm_intel.ple_gap=0 irqaffinity=0"
```

## Host Configurations

### According to [Real-time programming with Linux](https://shuhaowu.com/blog/2022/02-linux-rt-appdev-part2.html#f4)

##### Disable [simultaneous multithreading](https://en.wikipedia.org/wiki/Simultaneous_multithreading)
   -   SMT improves the performance of the CPU but decreases the determinism, thus introducing latency. How this works is outside the scope of this post. As of this writing, it is recommended for SMT to be disabled [[4]](https://shuhaowu.com/blog/2022/02-linux-rt-appdev-part2.html#f5).
   -   SMT is usually configured on the BIOS/UEFI level. How this is done varies depending on the system.  
[disable_txt.jpg](../../../resources/images/bios/disable_txt.jpg)  
[disable_hyperthreading.jpg](../../../resources/images/bios/disable_hyperthreading.jpg)

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
Remove all possible IRQs from isolated CPU with [remove_irqs_from_CPU.sh](../../../sigmatek/salamander4/latency_reduction/IRQaffinity/remove_irqs_from_CPU.sh). Check with [table_CPU_IRQ.md](../../../sigmatek/salamander4/latency_reduction/IRQaffinity/table_CPU_IRQ.md) and cat `/proc/interrupts`.

##### RCU CPU offloading
Add `rcu_nocbs=13` as boot parameter for CPU offloading in `sudo nano /etc/default/grub`
  ```
  GRUB_CMDLINE_LINUX="isolcpus=13 rcu_nocbs=13"
  ```

##### [RCU CPU Stall Warnings](https://www.kernel.org/doc/html/latest/RCU/stallwarn.html#config-rcu-cpu-stall-timeout)
  Wait until issuing an RCU CPU stall warning. 
  ```
  echo 200 | sudo tee /sys/module/rcupdate/parameters/rcu_cpu_stall_timeout
  ```
  Stall-warning messages may be enabled and disabled completely via
  ```
  echo 1 | sudo tee /sys/module/rcupdate/parameters/rcu_cpu_stall_suppress
  ```


##### Start QEMU normally and give all QEMU threads rt-priority
Start QEMU [normally with idle=poll](../../../sigmatek/QEMU/qemu_def_3hugepages_cmdline.sh). Give all QEMU threads rt-priority.
```
ps -T -p $(pgrep -f "qemu-system-x86_64 -M pc,ac") | awk '{print $2}' | tail -n +2 | xargs -I {} sudo chrt -r -p 99 {}
```

##### Kill all running user processes
Make sure there is no other running process
```
sudo kill <pid>
``` 



### According to Intel

#### Set CPU Affinity for systemd services
   Open `/etc/systemd/system.conf` with a text editor (like nano or vi) with root privileges:
   ```
   sudo nano /etc/systemd/system.conf
   ```
   Find the line that starts with `#CPUAffinity=` and change it to `CPUAffinity=0 1 2 3 5 6 7 8 9 10 11 12 13`. Save and close the file.

#### Cache Isolation for CPU and GPU
   
   To perform cache isolation for CPU and GPU, you can use the Linux `resctrl` interface. Here are the general steps:

   - **Enable the resctrl filesystem**: This is usually done by adding `resctrl` to your kernel command line. You can do this by editing your bootloader configuration. For GRUB, you would edit `/etc/default/grub` and add `resctrl` to the `GRUB_CMDLINE_LINUX_DEFAULT` line, then update GRUB with `sudo update-grub` and reboot.

   - **Create a resctrl group**: Resctrl groups are used to apply different policies to different sets of processes. You can create a new group like this:
      ```
      sudo mkdir /sys/fs/resctrl/mygroup
      ```
      Replace `mygroup` with the name you want to use for the group.

   - **Assign CPUs to the group**: You can assign CPUs to the group by writing to the `cpus` file in the group's directory. For example, to assign CPUs 0 and 1 to `mygroup`, you would do:
       ```
       echo 0-1 | sudo tee /sys/fs/resctrl/mygroup/cpus
       ```
   - **Set the cache allocation for the group**: You can set the cache allocation by writing to the `schemata` file in the group's directory. The exact value will depend on your specific needs and system configuration. Here's an example that sets 50% of the L3 cache for code (C) and data (D) on socket 0 to `mygroup`:
       ```
       echo "L3:0=ff00ff;1=ff00ff" | sudo tee /sys/fs/resctrl/mygroup/schemata
       ```
   - **Assign tasks to the group**: Finally, you can assign tasks (processes or threads) to the group by writing their PID to the `tasks` file in the group's directory. For example, to assign a task with PID 12345 to `mygroup`, you would do:
       ```
       echo 12345 | sudo tee /sys/fs/resctrl/mygroup/tasks
       ```


#### Set CPU Affinity of IRQ thread to CPU 0
   First, find the process ID (PID) of the IRQ thread for NVME:
   ```
   ps -e | grep 'irq/.*nvme'
   ```
   Then, use the `taskset` command to set the CPU affinity of this thread to CPU 0. Replace `<pid>` with the PID from the previous command:
   ```
   sudo taskset -a -p -c 0 <pid>
   ```

#### Set Device Driver Work Queue to CPU 0
   ```
   echo 1 | sudo tee /sys/devices/virtual/workqueue/cpumask
   echo 1 | sudo tee /sys/bus/workqueue/devices/writeback/cpumask
   ```

#### Disable Machine Check
   ```
   echo 0 | sudo tee /sys/devices/system/machinecheck/machinecheck0/check_interval
   ```

#### Stop Certain Services
   ```
   sudo systemctl stop irqbalance.service
   sudo systemctl stop thermald.service
   sudo systemctl stop wpa_supplicant.service
   ```

## QEMU Configurations

### Tune lapic timer advance
   You can set the value of the lapic timer advance to 7500 with this command:
   ```
   echo 7500 | sudo tee /sys/module/kvm/parameters/lapic_timer_advance_ns
   ```
   This value might be different for different chips.

### Set QEMU options for real-time VM
   You can set several options when starting your QEMU virtual machine to improve real-time performance. Here are some examples:
   - `-realtime mlock=on`: This option locks the memory of the VM to avoid swapping and lazy allocation.
   - `-balloon none`: This option disables the balloon driver, which can free and return memory to the host OS.
   - `-mem-prealloc -mem-path /dev/hugepages/`: These options enable the use of hugepages, which can reduce TLB misses and improve performance.

### Set CPU affinity and scheduling policy of QEMU CPU threads
   You can set the CPU affinity of the QEMU CPU threads to specific CPUs (in this case, CPUs 2 and 3) and set the scheduling policy to FIFO with the highest priority. You'll need to find the PIDs of the QEMU CPU threads first. Once you have the PIDs, you can use the `taskset` and `chrt` commands to set the CPU affinity and scheduling policy. Replace `<pid>` with the PID of the thread:
   ```
   sudo taskset -a -p -c 2,3 <pid>
   sudo chrt -f -p 99 <pid>
   ```

### Passthrough PCI devices into the VM
   If you need to passthrough PCI devices into the VM, you can do so using the `-device vfio-pci,host=xx:xx.x` option when starting your QEMU virtual machine. Replace `xx:xx.x` with the PCI address of the device you want to passthrough.

## Trace latency 
```
latency -h -s -T 600 -g max_latency_rt.txt
```