# Checklist

## Done
- [x] Install Ubuntu 22.04.3 LTS
- [x] Local Yocto Build: Salamander4 
- [x] Linux Kernel Configuration with Xenomai
- [x] Boot Salamander4 in QEMU under native Ubuntu 
- [x] Configured bridge for QEMU
- [x] Connected LasalClass2 with [Salamander 4]
- [x] Enabled access to the vsocket for guest
- [x] trace-cmd and kernelshark with Salamander4 as guest 
- [x] Used the Xenomai test suite: latency -T 60` 
- [x] Isolated host CPU for guest
- [x] Latency got better after [isolation](../general/protocol.md#max-latency-with-taskset)
- [x] Analyze Host and Guest Processes
- [x] Latency got much better after [rt-patch](../general/protocol.md#max-latency-with-rt)
- [x] Latency got even better after Intels [RT_Performance_Tuning_Best_Practice_KVM_VM.pdf](../resources/pdfs/papers/RT_Performance_Tuning_Best_Practice_KVM_VM.pdf): [xenomai_compare.md](../sigmatek/xenomai/xenomai_compare.md)

## Missing
- [ ] Inspect kvm_exit reasons
- [ ] Adapt QEMU script to work with chrt
- [ ] 
- [ ] 
- [ ] 


## Appendix: Hardware and OS configuration checklist
[Real-time programming with Linux](https://shuhaowu.com/blog/2022/02-linux-rt-appdev-part2.html)  
This serves as a non-exhaustive starting point on the things to check for the hardware and OS. The list is constructed based on my survey of the literature (mostly conference talks, with some internet articles). Remember to always validate the final scheduling latency with something like cyclictest!

- [x] [Disable SMT](../sigmatek/salamander4/latency_reduction/latency_reduction_steps.md#disable-simultaneous-multithreading)
- [x] [Disable dynamic frequency scaling](../sigmatek/salamander4/latency_reduction/latency_reduction_steps.md/#disable-dynamic-frequency-scaling)
- [x] Check for the presence of system management interrupts; if possible, consult with the hardware vendor (remember to always verify their claims)
- [x] Understand the NUMA of the computer and minimize cross-node memory access within the RT process
- [x] [Disable RT throttling](../sigmatek/salamander4/latency_reduction/latency_reduction_steps.md#disable-rt-throttling)
- [x] Disable any unneeded RT services/daemons already running on the OS
- [x] Possibly setup isolcpu (or use cgroups to accomplish the same thing)
- [] Look into kernel configurations that may affect RT performance such as CONFIG_LOCKUP_DETECTOR, CONFIG_DETECT_HUNG_TASK, CONFIG_NO_HZ, CONFIG_HZ_*, CONFIG_NO_HZ_FULL, and possibly more.
- [] Configure the memory lock and rtprio permissions in /etc/security/limits.d.
- [x] Do the [latency_reduction_steps.md](../sigmatek/salamander4/latency_reduction/latency_reduction_steps.md)
- []
