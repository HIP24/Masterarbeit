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
- [x] Latency got better after [isolation](../general/protocol.md#isolate-cpus-on-host-system)


## Missing
- [ ] Salamander4 über QEMU unter native Windows booten
- [ ] Salamander4 über QEMU unter WSL in native Windows booten
- [ ] Compare Ubuntu, Windows and WSL
- [ ] Preempt_RT vs Xenomai

## Richard Meeting 11.03.2024
Boot QEMU with realtime priority `chrt` but little priority 1-99  

Test latency  

- [ ] Out-of-of-the-box
    - [ ] Inspect Kernelshark
- [ ] CPU isolated on user space
    - [ ] Inspect Kernelshark
- [ ] Realtime priority experiment
    - [ ] Inspect Kernelshark
- [ ] CPU Shall not process interrupts -> select which cpu?
    - [ ] Inspect Kernelshark
- [ ] Turn off Hyprerthreading so that CPU cores are not divided
    - [ ] Inspect Kernelshark
