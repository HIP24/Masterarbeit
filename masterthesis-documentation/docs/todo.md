# Masterarbeit TODO

## Write
- [ ] Declaration
- [ ] Kurzfassung
- [ ] Abstract
- [ ] Introduction
    - [ ] Application Context
    - [ ] State of the art
    - [ ] Problem and task definition
    - [ ] Objective
- [ ] Methodology 
- [ ] Real-Time Robotic Application
    - [ ] Setup of Hardware Salamander
    - [ ] Setup of QEMU Salamander
    - [ ] Robotic Application
- [ ] Results 
- [ ] Discussion
- [ ] Summary and Outlook


## Rewrite 
- [ ] Salamander 4
    - [ ] Structure
    - [ ] Memory Management
    - [ ] Xenomai
- [ ] Initial Real-Time Latency
    - [ ] Salamander  Bare Metal
    - [ ] Salamander  Virtualization
- [ ] Real-Time Performance Tuning
    - [ ] BIOS Configurations
    - [ ] Kernel Configurations
    - [ ] Host OS Configurations
        - [ ] CPU affinity and isolation
        - [ ] Interrupt Affinity
        - [ ] RT-priority
        - [ ] Disable RT throttling
        - [ ] Disable timer migration
        - [ ] Set Device Driver Work Queue
        - [ ] Disable RCU CPU stall warnings
        - [ ] Stop Certain Services
        - [ ] Disable Machine Check
        - [ ] Boot into text-based environment
    - [ ] QEMU/KVM Configurations
        - [ ] Tune lapic timer advance
        - [ ] Set QEMU options for real-time VM
    - [ ] Guest OS Configurations
    - [ ] Other configurations
       

## Extra 
- [ ] To Include 
    - [ ] Latency Comparison
    - [ ] Latency taskset
    - [ ] kvm exits
    - [ ] Host and Guest tasks
    - [ ] Citation table

## Generate
- [ ] Bibliography
- [ ] List of Figures
- [ ] List of Tables
- [ ] List of Code