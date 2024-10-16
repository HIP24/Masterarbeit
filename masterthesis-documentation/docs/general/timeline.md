# Timeline

| Date       | Log |
|------------|-------|
| Thursday, 08.02.2024 | [Dual boot](../resources/images/dual_boot/grub.jpg) Windows and Ubuntu |
| Friday, 09.02.2024 | Booted [Salamander 4](../resources/images/yocto/sigmatek_login.png) on Ubuntu |
| Monday, 12.02.2024 | Connected Salamander 4 with [SSH](../resources/images/yocto/ssh.png)  |
| Tuesday, 13.02.2024 | Connected Salamander 4 with Lasal Class 2 (Christian) after configuring bridge |
| Wednesday, 14.02.2024 | Installed [Windows VM on Ubuntu](../resources/images/lasal/class2/windows_vm.png), installed [Lasal Class 2 on Windows VM](../resources/images/lasal/class2/lasalclass2.png), connected with [Salamander 4](../resources/images/lasal/class2/lasalclass2_connected.png) |
| Thursday, 15.02.2024 | Run [pumpcontrol example](../resources/images/lasal/class2/pumpcontrol.png) successfully |
| Friday, 16.02.2024 | Increased virtual CPU in Windows |
| Monday, 19.02.2024 | [Xenomai-system-tools](../sigmatek/xenomai/xenomai_suite/xenomai-system-tools.md)|
| Tuesday, 20.02.2024 | KernelShark |
| Wednesday, 21.02.2024 | Local Yocto Build finally done |
| Thursday, 22.02.2024 | [trace-cmd agent](../resources/images/trace-cmd/trace-cmd_agent_host_guest.png) on guest communicates with host |
| Friday, 23.02.2024 | Teammeeting and Germany |
| Monday, 26.02.2024 | after_bitbake, kernelshark, paths |
| Tuesday, 27.02.2024 | Isolate CPUs on host system and let guest run on it |
| Wednesday, 28.02.2024 | Host-Guest [timestamp sync](../resources/images/protocol/negotiated_with_guest.png) works with VM, can view [KVM Combo plots](../resources/images/protocol/kvm_combo_plots_vis.png), does still not work with Salamander4 |
| Thursday, 29.02.2024 | useful_links and search_for_x.py |
| Friday, 01.03.2024 | checklist.md, nmbridge.md, understand nmbridge |
| Monday, 04.03.2024 | Finally: Negotiated kvm time sync protocol with guest Salamander4|
| Tuesday, 05.03.2024 | lat worst reduced from 374.075 to 87.379 |
| Wednesday, 06.03.2024 | Add documentation local server |
| Thursday, 07.03.2024 | Start Salamander4 CPU with [icecc](../resources/images/yocto/icecc.png) |
| Friday, 08.03.2024 | Merge master and readme |
| Monday, 11.03.2024 | [Kernel patch](../resources/images/kernel-patch/uname.png), richard meeting and settings.json |
| Tuesday, 12.03.2024 | real time priorities with chrt -f 50, no success |
| Wednesday, 13.03.2024 | Preventing kernel tasks from being scheduled on CPU4 |
| Thursday, 14.03.2024 | irq.md |
| Friday, 15.03.2024 | Timer 1000Hz|
| Monday, 18.03.2024 | kernel_processes.md, kernelshark, start thesis|
| Tuesday, 19.03.2024 | Added [Zotero](https://guides.library.iit.edu/c.php?g=720120&p=6296986), [Ubuntu Pro](https://ubuntu.com/pro/dashboard) and [Ubuntu PREEMPT_RT](https://ubuntu.com/blog/real-time-ubuntu-released)|
| Wednesday, 20.03.2024 | kvm_exit reasons [plot](../sigmatek/trace-cmd/virtualization/taskset/kvm_exits_taskset.png) |
| Thursday, 21.03.2024 | gitlfs and settings.json, plot with and without taskset, write more thesis |
| Friday, 22.03.2024 | Literature paper search |
| Monday, 25.03.2024 | Start masterthesis |
| Tuesday, 26.03.2024 | Write masterthesis  |
| Wednesday, 27.03.2024 | Write masterthesis |
| Thursday, 28.03.2024 | Write masterthesis |
| Friday, 29.03.2024 | Write masterthesis |
| Monday, 01.04.2024 | Ostern |
| Tuesday, 02.04.2024 | bcc tool |
| Wednesday, 03.04.2024 | Write masterthesis APIC_WRITE |
| Thursday, 04.04.2024 | defconfig, vapic |
| Friday, 05.04.2024 | check_smp_affinity and check_CPU_IRQ_usage |
| Monday, 08.04.2024 | kvm_exit_vapic_results |
| Tuesday, 09.04.2024 | trace-cmd report analysis |
| Wednesday, 10.04.2024 | getconf _NPROCESSORS_CONF |
| Thursday, 11.04.2024 | Richard Meeting |
| Friday, 12.04.2024 | Spec |
| Monday, 15.04.2024 | report.sh |
| Tuesday, 16.04.2024 | Updated analyze_trace.py, include in thesis |
| Wednesday, 17.04.2024 | Describe host and guest tasks |
| Thursday, 18.04.2024 | Read 4 papers |
| Friday, 19.04.2024 | Read 5 papers |
| Monday, 22.04.2024 | Boot ubuntu anew |
| Tuesday, 23.04.2024 | Rebuild workspace |
| Wednesday, 24.04.2024 | Rebuild workspace, problem_solution |
| Thursday, 25.04.2024 | Rebuild workspace, table IRQ CPU |
| Friday, 26.04.2024 | [compare.md](../sigmatek/trace-cmd/virtualization/compare.md), [ps.sh](../tools/ps/ps-e.sh) |
| Monday, 29.04.2024 | powersave, balanced, performance |
| Tuesday, 30.04.2024 | merge and failed_reason |
| Wednesday, 01.05.2024 | Feiertag |
| Thursday, 02.05.2024 | Ubuntu real-time kernel |
| Friday, 03.05.2024 | Steven yt, analyze_events and analyze_tasks |
| Monday, 06.05.2024 | report_hardware |
| Tuesday, 07.05.2024 | Richard prios, [show_all_threads.py](../tools/ps/show_all_threads.py) |
| Wednesday, 08.05.2024 | failed_reason include CPU, reorganize |
| Thursday, 09.05.2024 | Feiertag |
| Friday, 10.05.2024 | compare kernels |
| Monday, 13.05.2024 | compare config, qemu test with 2 cpus |
| Tuesday, 14.05.2024 | Hardware and OS configuration checklist |
| Wednesday, 15.05.2024 | FINALLY [LATENCY REDUCED](../sigmatek/xenomai/3rt/max_latency_rt/max_latency_rt_10min_log.md) WITH [STATS](../sigmatek/xenomai/3rt/max_latency_rt/max_latency_rt_statistics.txt) and [PLOT](../sigmatek/xenomai/3rt/max_latency_rt/max_latency_rt.png) |
| Thursday, 16.05.2024 | reorganize, papers and configs |
| Friday, 17.05.2024 | real-time-kernel-tuning websites |
| Monday, 20.05.2024 | Feiertag |
| Tuesday, 21.05.2024 | read 3 papers, [compare_2_files.py](../sigmatek/salamander4/latency_reduction/kernel-patch/compare_2_files.py) |
| Wednesday, 22.05.2024 | Configure like Intels [RT_Performance_Tuning_Best_Practice_KVM_VM.pdf](../resources/pdfs/papers/RT_Performance_Tuning_Best_Practice_KVM_VM.pdf), results in [xenomai_compare_latmax.md](../sigmatek/xenomai/xenomai_compare_latmax.md) |
| Thursday, 23.05.2024 | reorganize, test Salamander 4 |
| Friday, 24.05.2024 | QEMU with 2 CPUs |
| Monday, 27.05.2024 | Write thesis |
| Tuesday, 28.05.2024 | Write thesis |
| Wednesday, 29.05.2024 | Write thesis |
| Thursday, 30.05.2024 | Feiertag |
| Friday, 31.05.2024 | Write thesis |
| Monday, 03.06.2024 | change latency from 300 to 10000 |
| Tuesday, 04.06.2024 | Write thesis, \[DRAFT\] chapter 4 and BIOS configuration finished  |
| Wednesday, 05.06.2024 | Write thesis, \[DRAFT\] Kernel Configurations 10/19 finished |
| Thursday, 06.06.2024 | Write thesis, \[DRAFT\] Kernel Configurations 16/19 finished |
| Friday, 07.06.2024 | \[DRAFT\] Host Configurations 5/10 finished |
| Monday, 10.06.2024 | 15 hours latency test |
| Tuesday, 11.06.2024 | Lasal Class 2 test  |
| Wednesday, 12.06.2024 | Lasal Class 2 etxra test |
| Thursday, 13.06.2024 | Lasal Class 2 more extra |
| Friday, 14.06.2024 | Lasal Class 2 more extra |
| Monday, 17.06.2024 | Dirk Geschwindner, Motoren angesteuert|
| Tuesday, 18.06.2024 | reorganize |
| Wednesday, 19.06.2024 | 6 dof robot, arduino |
| Thursday, 20.06.2024 | i/o modules lasal class 2, pwm, osci |
| Friday, 21.06.2024 | FINALLY moved 2 motors of mini robot with lasal class 2 with voltage divider |
| Monday, 24.06.2024 | Graz |
| Tuesday, 25.06.2024 | Lasal Class 2 with robot |
| Wednesday, 26.06.2024 | Lasal Class 2 with robot |
| Thursday, 27.06.2024 | Richard meeting |
| Friday, 28.06.2024 | reorganize |
| Monday, 01.07.2024 | New PC setup, yocto build, QEMU test |
| Tuesday, 02.07.2024 | FINALLY virtualized hardware setup |
| Wednesday, 03.07.2024 | Frei |
| Thursday, 04.07.2024 | Frei |
| Friday, 05.07.2024 | Frei |
| Monday, 08.07.2024 | Frei |
| Tuesday, 09.07.2024 | Frei |
| Wednesday, 10.07.2024 | Frei |
| Thursday, 11.07.2024 | Frei |
| Friday, 12.07.2024 | Frei |
| Monday, 15.07.2024 | FINALLY resolved Varan Manager Error, DMA Error and moved robot with Salamander Virtualization  |
| Monday, 16-19.07.2024 | Sigmatek Work - ixagent |
| Monday, 22.07.2024 | Krankenstand |
| Tuesday, 23.07.2024 | Krankenstand |
| Wednesday, 24.07.2024 | Krankenstand |
| Thursday, 25.07.2024 | Krankenstand |
| Friday, 26.07.2024 | Krankenstand |
| Tuesday, 29.07.2024 | Sigmatek Work - ip_fallback and start third ticket |