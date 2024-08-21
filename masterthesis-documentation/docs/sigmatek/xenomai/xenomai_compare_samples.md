# Salamander 4 latency comparisons

## Salamander 4 Hardware on CP 841

![Hardware](0hardware/gnuplot_max_latency_hardware.png)

---

## Salamander 4 Default Yocto Build

![Default](1default/gnuplot_max_latency_default.png)

---

## After taskset -c 4

![Taskset](2taskset/gnuplot_max_latency_taskset.png)

---

## After BIOS Configurations

![rt_kernelparam](4rt_kernelparam/gnuplot_max_latency_rt_kernelparam.png)

---

## After [Host Configurations](../salamander4/latency_reduction/latency_reduction_steps.md#host-configurations)

![rt_kernelparam_host](5rt_kernelparam_host/gnuplot_max_latency_rt_kernelparam_host.png)

---

## After [QEMU Configurations](../salamander4/latency_reduction/latency_reduction_steps.md#qemu-configurations)

![rt_kernelparam_host_qemu](6rt_kernelparam_host_qemu/gnuplot_max_latency_rt_kernelparam_host_qemu.png)

---

## All together

![all_together](012456combined/gnuplot_combined_max_latency.png)