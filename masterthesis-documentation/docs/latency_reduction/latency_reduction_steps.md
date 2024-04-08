## Steps for latency reduction

## defconfig

CONFIG_PARAVIRT=y
CONFIG_KVM_GUEST=y
CONFIG_X86_IOAT_VAPIC_BROKEN_CTL=y
CONFIG_MTRR_SANITIZER=y
CONFIG_ARCH_CPUIDLE_HALTPOLL=y
CONFIG_HUGETLBFS=y


## CPU isolation 

**CPU isolation** in Ubuntu involves restricting certain CPUs from the scheduler to enhance performance or achieve real-time behavior. Let's explore a few methods for achieving this:

1. **`isolcpus` Boot Parameter**:
    - The `isolcpus` boot parameter allows you to isolate one or more CPUs from the scheduler. Once a CPU is isolated, the scheduler won't schedule any user-space threads on it.
    - However, you'll need to manually assign processes to the isolated CPU using CPU affinity system calls or the `numactl` command².

2. **`tuned-profiles-realtime`**:
    - The `tuned-profiles-realtime` package provides a way to isolate CPUs for latency-sensitive workloads.
    - Isolating CPUs generally involves:
        - Removing all user-space threads.
        - Removing unbound kernel threads (bound kernel threads are tied to specific CPUs and cannot be moved).
        - Modifying the `/proc/irq/N/smp_affinity` property of each Interrupt Request (IRQ) number N in the system³.

3. **`tuned-profiles-cpu-partitioning`**:
    - This profile partitions system CPUs into isolated and housekeeping CPUs.
    - Isolated CPUs experience reduced jitter and fewer interruptions by the kernel, making them suitable for real-time tasks⁴.

4. **Third-Party Tools**:
    - Consider using tools like **`cpuset`** or **`tuna`**:
        - **`cpuset`**: Allows you to create CPU sets (cpusets) and move tasks (threads or processes) into specific cpusets. You can shield CPUs from the scheduler by moving tasks into an isolated cpuset.
        - **`tuna`**: Dynamically isolates a CPU core and moves processes running on that core to neighboring CPUs. You can use `tuna` to isolate a CPU core in real-time¹.



## smp_affinity 
cat /proc/irq/0/smp_affinity
sudo chmod 777 /proc/irq/0/smp_affinity
sudo echo dffff > /proc/irq/0/smp_affinity


## Enable APICV
/sys/module/kvm_intel/parameters/enable_apicv


-cpu host,hv-passthrough \