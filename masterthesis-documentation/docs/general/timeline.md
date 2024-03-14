# Timeline

| Date       | Log |
|------------|-------|
| 08.02.2024 | [Dual boot](../resources/images/dual_boot/grub.jpg) Windows and Ubuntu |
| 09.02.2024 | Booted [Salamander 4](../resources/images/yocto/sigmatek_login.png) on Ubuntu |
| 12.02.2024 | Connected Salamander 4 with [SSH](../resources/images/yocto/ssh.png)  |
| 13.02.2024 | Connected Salamander 4 with Lasal Class 2 (Christian) after configuring bridge |
| 14.02.2024 | Installed [Windows VM on Ubuntu](../resources/images/lasal/class2/windows_vm.png), installed [Lasal Class 2 on Windows VM](../resources/images/lasal/class2/lasalclass2.png), connected with [Salamander 4](../resources/images/lasal/class2/lasalclass2_connected.png) |
| 15.02.2024 | Run [pumpcontrol example](../resources/images/lasal/class2/pumpcontrol.png) successfully |
| 16.02.2024 | Increased virtual CPU in Windows |
| 19.02.2024 | [Xenomai-system-tools](../salamander4/xenomai/xenomai-system-tools.md)|
| 20.02.2024 | KernelShark |
| 21.02.2024 | Local Yocto Build finally done |
| 22.02.2024 | [trace-cmd agent](../resources/images/trace-cmd/trace-cmd_agent_host_guest.png) on guest communicates with host |
| 23.02.2024 | Teammeeting and Germany |
| 26.02.2024 | after_bitbake, kernelshark, paths |
| 27.02.2024 | Isolate CPUs on host system and let guest run on it |
| 28.02.2024 | Host-Guest [timestamp sync](../resources/images/protocol/negotiated_with_guest.png) works with VM, can view [KVM Combo plots](../resources/images/protocol/kvm_combo_plots_vis.png), does still not work with Salamander4 |
| 29.02.2024 | useful_links and search_for_x.py |
| 01.03.2024 | checklist.md, nmbridge.md, understand nmbridge |
| 04.03.2024 | Finally: Negotiated kvm time sync protocol with guest Salamander4|
| 05.03.2024 | lat worst reduced from 374.075 to 87.379 |
| 06.03.2024 | Add documentation local server |
| 07.03.2024 | Start Salamander4 CPU with [icecc](../resources/images/yocto/icecc.png) |
| 08.03.2024 | Merge master and readme |
| 11.03.2024 | [Kernel patch](../resources/images/kernel-patch/uname.png), richard meeting and settings.json |
| 12.03.2024 | real time priorities with chrt -f 50, no success |
| 13.03.2024 | Preventing kernel tasks from being scheduled on CPU4 |