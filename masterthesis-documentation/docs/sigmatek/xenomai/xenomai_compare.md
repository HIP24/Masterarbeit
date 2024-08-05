# Salamander 4 latency comparisons

## Salamander 4 Hardware on CP 841

![Hardware](0hardware/max_latency_hardware/max_latency_hardware.png)

- Average latency: 4.06us
- Max latency: 10.709us
- Min latency: 2.817us
- Standard Deviation: 0.85us

---

## Salamander 4 Default Yocto Build

![Default](1default/max_latency_default/max_latency_default.png)

- Average latency: 174.5us
- Max latency: 4070.018us
- Min latency: 6.963us
- Standard Deviation: 359.27us

---

## After taskset -c 4

![Taskset](2taskset/max_latency_taskset/max_latency_taskset.png)

- Average latency: 74.78us
- Max latency: 457.545us
- Min latency: 14.113us
- Standard Deviation: 29.43us

---

## After [PREEMPT_RT Patch](../../general/protocol.md#enable-preempt_rt-kernel) and [Kernel Tuning](../salamander4/latency_reduction/latency_reduction_steps.md#according-to-real-time-programming-with-linux) 

![RT](3rt/max_latency_rt/max_latency_rt.png)

- Average latency: 17.68us
- Max latency: 32.216us
- Min latency: 8.005us
- Standard Deviation: 6.1us

---

## After [BIOS Configurations](../salamander4/latency_reduction/latency_reduction_steps.md#bios-configurations) and [Kernel Configurations](../salamander4/latency_reduction/latency_reduction_steps.md#kernel-configurations)

![rt_kernelparam](4rt_kernelparam/max_latency_rt_kernelparam/max_latency_rt_kernelparam.png)

- Average latency: 14.0us
- Max latency: 21.694us
- Min latency: 6.351us
- Standard Deviation: 1.44us

---

## After [Host Configurations](../salamander4/latency_reduction/latency_reduction_steps.md#host-configurations)

![rt_kernelparam_host](5rt_kernelparam_host/max_latency_rt_kernelparam_host/max_latency_rt_kernelparam_host.png)

- Average latency: 12.61us
- Max latency: 17.041us
- Min latency: 7.872us
- Standard Deviation: 1.8us

---

## After [QEMU Configurations](../salamander4/latency_reduction/latency_reduction_steps.md#qemu-configurations)

![rt_kernelparam_host_qemu](6rt_kernelparam_host_qemu/max_latency_rt_kernelparam_host_qemu/max_latency_rt_kernelparam_host_qemu.png)

- Average latency: 16.26us
- Max latency: 17.134us
- Min latency: 14.532us
- Standard Deviation: 0.3us