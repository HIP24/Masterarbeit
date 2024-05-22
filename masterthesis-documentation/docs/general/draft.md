## from Paper Virt. mixed...

Instead, the PREEMPT RT
patch provides several mechanisms like high-resolution timers, threaded interrupt handlers, priority inheritance implementation, Preemptible Read-Copy-Update (RCU), real-time schedulers, and a memory allocator.





## NUMA

```
sigma_ibo@sigma-ibo:~$ numactl --hardware
available: 1 nodes (0)
node 0 cpus: 0 1 2 3 4 5 6 7 8 9 10 11 12 13
node 0 size: 31772 MB
node 0 free: 10107 MB
node distances:
node   0 
  0:  10
```

The output of the numactl --hardware command shows the Non-Uniform Memory Access (NUMA) configuration of your system.

Here’s what each line means:

available: 1 nodes (0): This means that your system has 1 NUMA node available, and it is identified as node 0.
node 0 cpus: 0 1 2 3 4 5 6 7 8 9 10 11 12 13: This line lists the CPUs that are part of node 0. In this case, CPUs 0 through 13 are part of this node.
node 0 size: 31772 MB: This indicates that node 0 has a total of 31772 MB of memory.
node 0 free: 10107 MB: This shows that out of the total memory, 10107 MB is currently free and available for use.
node distances:: This section provides the relative distances between different NUMA nodes. Since you only have one node, there is only one entry here.
0: 10: This indicates that the distance from node 0 to itself is 10. The distance is a relative measure of the latency of memory access between nodes. A lower number means lower latency.
Since your system has only one NUMA node, all memory access is local, and you don’t need to worry about cross-node memory access. However, if you add more nodes in the future, you’ll need to consider the placement of processes and memory to minimize cross-node memory access. This can be done by setting CPU and memory affinity for your processes or threads, partitioning data across the NUMA nodes, and using NUMA-aware allocators. Always remember to measure and profile the NUMA characteristics of your application to identify areas where cross-node access is high. If you’re not comfortable making these changes yourself, it might be a good idea to seek help from someone who is.

The “distance” in NUMA architecture doesn’t refer to a physical distance, but rather to a measure of memory access latency. In this context, the distance from a node to itself is the baseline latency for accessing its own local memory.

The value “10” is a relative measure. It doesn’t represent an absolute time or delay, but serves as a reference point for comparing memory access latencies within the system. When comparing this to the latency of accessing memory on other nodes (in a multi-node system), a lower value would indicate lower latency.

So, when it says the distance from node 0 to itself is 10, it means that the latency for accessing local memory is set as the baseline reference value of 10. If there were other nodes, their distances would be compared to this baseline to determine whether accessing memory on those nodes would be faster or slower.

In a single-node system like yours, this value doesn’t have much practical impact since all memory access is local. But in a multi-node system, understanding these distances can be crucial for optimizing performance and minimizing latency.


## Kernel Configurations
```
GRUB_CMDLINE_LINUX="isolcpus=4 rcu_nocbs=4 nohz_full=4 default_hugepagesz=1G hugepagesz=1G hugepages=8 intel_iommu=on rdt=l3cat nmi_watchdog=0 idle=poll clocksource=tsc tsc=reliable noht audit=0 skew_tick=1 intel_pstate=disable intel.max_cstate=0 intel_idle.max_cstate=0 processor.max_cstate=0 processor_idle.max_cstate=0 nosoftlockup nohz=on no_timer_check nospectre_v2 spectre_v2_user=off kvm.kvmclock_periodic_sync=N kvm_intel.ple_gap=0 irqaffinity=0"
```

## Host Configurations

1. **Set CPU Affinity for systemd services**:
   Open `/etc/systemd/system.conf` with a text editor (like nano or vi) with root privileges:
   ```
   sudo nano /etc/systemd/system.conf
   ```
   Find the line that starts with `#CPUAffinity=` and change it to `CPUAffinity=0`. Save and close the file.

2. **Cache Isolation for CPU and GPU**:
   
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


3. **Set CPU Affinity of IRQ thread to CPU 0**:
   First, find the process ID (PID) of the IRQ thread for NVME:
   ```
   ps -e | grep 'irq/.*nvme'
   ```
   Then, use the `taskset` command to set the CPU affinity of this thread to CPU 0. Replace `<pid>` with the PID from the previous command:
   ```
   sudo taskset -a -p -c 0 <pid>
   ```

4. **Set Device Driver Work Queue to CPU 0**:
   ```
   echo 1 | sudo tee /sys/devices/virtual/workqueue/cpumask
   echo 1 | sudo tee /sys/bus/workqueue/devices/writeback/cpumask
   ```

5. **Disable Machine Check**:
   ```
   echo 0 | sudo tee /sys/devices/system/machinecheck/machinecheck0/check_interval
   ```

6. **Stop Certain Services**:
   ```
   sudo systemctl stop irqbalance.service
   sudo systemctl stop thermald.service
   sudo systemctl stop wpa_supplicant.service
   ```



## QEMU Configurations

1. **Tune lapic timer advance**:
   You can set the value of the lapic timer advance to 7500 with this command:
   ```
   echo 7500 | sudo tee /sys/module/kvm/parameters/lapic_timer_advance_ns
   ```
   This value might be different for different chips.

2. **Set QEMU options for real-time VM**:
   You can set several options when starting your QEMU virtual machine to improve real-time performance. Here are some examples:
   - `-realtime mlock=on`: This option locks the memory of the VM to avoid swapping and lazy allocation.
   - `-balloon none`: This option disables the balloon driver, which can free and return memory to the host OS.
   - `-mem-prealloc -mem-path /dev/hugepages/`: These options enable the use of hugepages, which can reduce TLB misses and improve performance.

3. **Set CPU affinity and scheduling policy of QEMU CPU threads**:
   You can set the CPU affinity of the QEMU CPU threads to specific CPUs (in this case, CPUs 2 and 3) and set the scheduling policy to FIFO with the highest priority. You'll need to find the PIDs of the QEMU CPU threads first. Once you have the PIDs, you can use the `taskset` and `chrt` commands to set the CPU affinity and scheduling policy. Replace `<pid>` with the PID of the thread:
   ```
   sudo taskset -a -p -c 2,3 <pid>
   sudo chrt -f -p 99 <pid>
   ```

4. **Passthrough PCI devices into the VM**:
   If you need to passthrough PCI devices into the VM, you can do so using the `-device vfio-pci,host=xx:xx.x` option when starting your QEMU virtual machine. Replace `xx:xx.x` with the PCI address of the device you want to passthrough.
