# Checklist

## Done
- [x] Install Ubuntu 22.04.3 LTS
- [x] Local Yocto Build: Salamander4 
- [x] Linux Kernel Configuration with Xenomai
- [x] Boot Salamander4 in QEMU under native Ubuntu 
- [x] Configured bridge for QEMU
- [x] Connected LasalClass2 with [Salamander 4]
- [x] Enabled access to the vsocket for guest
- [x] trace-cmd and kernelshark worked for Ubuntu VM
- [x] trace-cmd and kernelshark with Salamander4 as guest 
- [x] Used the Xenomai test suite: latency -T 60` 
- [x] Isolated host CPU for guest
- [x] Latency got better after [isolation](../general/protocol.md#isolate-cpus-on-host)


## Missing
- [ ] Inspect kvm_exit reasons
- [ ] Analyze Host and Guest Processes
- [ ] 


## Appendix: Hardware and OS configuration checklist
This serves as a non-exhaustive starting point on the things to check for the hardware and OS. The list is constructed based on my survey of the literature (mostly conference talks, with some internet articles). Remember to always validate the final scheduling latency with something like cyclictest!

- [x] [Disable SMT](protocol.md#disable-simultaneous-multithreading-smt-also-referred-to-as-hyper-threading-for-intel-cpus)
- [x] [Disable dynamic frequency scaling](protocol.md/#disable-dynamic-frequency-scaling)
- [] Check for the presence of system management interrupts; if possible, consult with the hardware vendor (remember to always verify their claims)
- [] Understand the NUMA of the computer and minimize cross-node memory access within the RT process
- [x] [Disable RT throttling](protocol.md#disable-rt-throttling)
- [x] Disable any unneeded RT services/daemons already running on the OS
- [x] Possibly setup isolcpu (or use cgroups to accomplish the same thing)
- [] Look into kernel configurations that may affect RT performance such as CONFIG_LOCKUP_DETECTOR, CONFIG_DETECT_HUNG_TASK, CONFIG_NO_HZ, CONFIG_HZ_*, CONFIG_NO_HZ_FULL, and possibly more.
- [] Configure the memory lock and rtprio permissions in /etc/security/limits.d.