##  Dual Boot
1) Flash SSD by installing [etcher](https://etcher.balena.io/) 
2) Ubuntu and Windows on same machine

## Install Salamander4 OS
1) Install Ubuntu 22.04.3 LTS
2) Run [script](resources/scripts/build-salamander4-ordinary.sh) or download [salamander4.tar.xz](resources/scripts/salamaner4.tar.xz) from Michi  
3) If latter, run tar -xvf salamaner4.tar.xz
4) Test QEMU 
    - git clone git@git.sigmatek.at:SIG_SW_BS/devops/qemutest.git
    - `cd qemutest`
    - `./test_qemu_image.sh -b ../salamander4/salamander-core2/build`
    - [QEMU testing boot](resources/images/yocto/qemutest_testing-boot.png)
    - [QEMU testing shutdown](resources/images/yocto/qemutest_testing-shutdown.png)
5) Boot Salamander 4
    - `cd ~/Develop/Yocto/salamander4/salamander-core2/build/tmp/deploy/qemu/sigmatek-core2/salamander-image`
    - [`./qemu_def.sh`](resources/scripts/working_qemu_def.sh)
    - [Welcome at Sigmatek PLC](resources/images/yocto/sigmatek_login.png)

## Configure ip addresses 
[Configure PC](resources/images/configure_ip/ip_static_connection_ubuntu.png) to `10.10.1.1`.   
[Salamander Gateway](resources/images/ip_list_ubuntu.png) set to `10.10.1.229`

## SSH to device
Connect to device with `ssh -oHostKeyAlgorithms=+ssh-rsa root@10.10.1.229`  
or `ssh -p 22 root@192.168.1.x` (changes often)

## LasalClass2 to device
Connect LasalClass2 with [Salamander 4](resources/images/lasal/class2/lasalclass2_ip.png), IP of [Salamander4 device](resources/images/lasal/class2/lasalclass2_salamander4_ip.png)

## Configure bridge for qemu
This setup allows the virtual machines to communicate with the outside network through the Ethernet connection provided by either the laptop or the docking station.

| name       | device |
|------------|-------|
| enp0s31f6 | Laptop's Ethernet port |
| enx4cd717733f80 | Docking station's Ethernet port |

- Disable [ipv4](resources/images/configure_bridge/ethernet_disable_ip4.png) and [ipv6](resources/images/configure_bridge/ethernet_disable_ip6.png)
- Enter [nmtui](resources/images/configure_bridge/nmtui.png)
- Edit Connection and [\<Add\>](resources/images/configure_bridge/add_connection.png). Select Bridge.
- [Edit](resources/images/configure_bridge/edit_connection.png) and \<Add\> Ethernet.
- [Copy name](resources/images/configure_bridge/copy_name.png) enx4cd717733f80 (4C:D7:17:73:3F:80) of Wired connection 2
- [Edit Connection of Ethernet connection 1](resources/images/configure_bridge/ethernet1.png) so that it automatically connects.
- [Activate Connection](resources/images/configure_bridge/activate_connection.png).
- Result should look like [this](resources/images/configure_bridge/get-to-know/connections.png) and [this](resources/images/configure_bridge/get-to-know/bridge_connections.png).
- More info in <a href="nmbridge.md" target="_blank">nmbridge.md</a>. 


## Use the Xenomai test suite
- `latency -T 60`  
- `clocktest -D -T 60` 

```
Richard Feedback:

1. CPU-Isolierung auf dem Host: Du solltest die CPUs auf deinem Ubuntu-System (dem Host) isolieren, um sicherzustellen, dass sie nicht von anderen Aufgaben unterbrochen werden. Die Option `isolcpus=0,1,2` sollte zur Kernel-Boot-Konfiguration des Hostsystems hinzugefügt werden, nicht zur QEMU-Konfiguration. ✅ 

2. Überwachung der CPU-Nutzung und Tracing: Du solltest auf dem Hostsystem messen, wann die virtuelle Maschine (VM) immer die CPU hat und dies mit dem Gastsystem vergleichen. Dies könnte dir helfen, eine Korrelation zwischen den Zeiten zu sehen, in denen die VM die CPU hat, und den Ausreißern in der Latenz. Mit den VMEnter/Exit Tracpoints kannst du sehen, wann die VM die CPU betritt und verlässt. Dies könnte dir helfen, die Interaktion zwischen dem Host- und dem Gastsystem besser zu verstehen und zu optimieren. ❌
```

## Isolate CPUs on host system (Ubuntu)

To isolate CPUs on your host system (Ubuntu), you can add the `isolcpus` option to the kernel boot configuration. Here are the steps you can follow:

1. Open the GRUB configuration file with a text editor. You can use the `nano` editor for this. Execute the following command in your terminal:
    ```bash
    sudo nano /etc/default/grub
    ```
2. Search for the entry `GRUB_CMDLINE_LINUX` and add `isolcpus=0,1,2,3,4` (or the corresponding CPU numbers you want to isolate). It should then look like this:
    ```bash
    GRUB_CMDLINE_LINUX="isolcpus=0,1,2,3,4"
    ```
3. Save the changes and close the editor. If you are using `nano`, you can do this by pressing `Ctrl+X`, then typing `Y` to save the changes, and finally pressing `Enter` to close the editor.

4. Update GRUB with the following command:
    ```bash
    sudo update-grub
    ```
5. Reboot your system for the changes to take effect.


Check with: `cat /sys/devices/system/cpu/isolated`

```
sigma_ibo@pamhal:~$ cat /sys/devices/system/cpu/onlineboth_laptop_and_docking
0-19
sigma_ibo@pamhal:~$ cat /sys/devices/system/cpu/isolated
0-4
```

## trace-cmd Problems 
[Rostedt Tutorial](https://rostedt.org/host-guest-tutorial/)  
`sudo trace-cmd record -e kvm:kvm_entry -e kvm:kvm_exit -A @3:823 --name Salamander4 -e all`

### 2 Problems  
1. "Failed to negotiate timestamps synchronization with the host"
[timestamp_error.png](resources/images/trace-cmd/timestamp_error.png)

2. "Cannot find host / guest tracing into the loaded streams" [kvm_combo_error.png](resources/images/trace-cmd/kvm_combo_error.png)

(These were solved in [Ubuntu 22.04 VM](#ubuntu-vm-on-virtual-machine-manager))

### What I did
1.  - enabled
        - CONFIG_VSOCKETS=y
        - CONFIG_VHOST_VSOCK=y
        - CONFIG_VIRTIO_VSOCKETS=y
        - CONFIG_VIRTIO_VSOCKETS_COMMON=y
        - CONFIG_VSOCKETS_DIAG=y
        - CONFIG_VSOCKETS_LOOPBACK=y
        - CONFIG_TRACING=y  
        - CONFIG_FTRACE=y  
        - CONFIG_FUNCTION_TRACER=y  
        - CONFIG_FUNCTION_GRAPH_TRACER=y  
        - CONFIG_DYNAMIC_FTRACE=y  
        - CONFIG_DYNAMIC_FTRACE_WITH_REGS=y  
        - CONFIG_DYNAMIC_FTRACE_WITH_DIRECT_CALLS=y  
        - CONFIG_DYNAMIC_FTRACE_WITH_ARGS=y  
        - CONFIG_SCHED_TRACER=y  
        - CONFIG_FTRACE_SYSCALLS=y  
        - CONFIG_TRACER_SNAPSHOT=y  
        - CONFIG_KPROBE_EVENTS=y  
        - CONFIG_UPROBE_EVENTS=y  
        - CONFIG_BPF_EVENTS=y  
        - CONFIG_DYNAMIC_EVENTS=y  
        - CONFIG_PROBE_EVENTS=y  
        - CONFIG_SYNTH_EVENTS=y  
        - CONFIG_HIST_TRIGGERS=y  
- checked via zcat /proc/config.gz if everything landed on the kernel
- changed clocksource in guest from kvm-clock to tsc in `/sys/devices/system/clocksource/clocksource0`  
- Did not check Code yet 
2. Nothing yet, probably hand in hand with 1.

## Solution to [trace-cmd Problems](#trace-cmd-problems)
The problem was the trace-cmd version. Set both host and guest to v3.2.0 by copying the files from host to guest:
```
scp /usr/local/bin/trace-cmd root@"$ip_address":/usr/bin
scp /usr/local/lib64/libtracefs.so.1 root@"$ip_address":/lib64
scp /usr/local/lib64/libtraceevent.so.1 root@"$ip_address":/lib64
```
Now, [trace-cmd version 3.2.0](resources/images/trace-cmd/trace-cmd_version3.2.0.png) is active and [tracing the guest](resources/images/trace-cmd/time_sync.png) finally works with `trace-cmd agent` on the guest.

Using kernelshark with `kernelshark trace.dat -a trace-Salamander4.dat` or simply [`./start_kernelshark.sh`](trace-cmd/analysis//test/start_kernelshark.sh), we get the expected [visualization](resources/images/trace-cmd/kernelshark/kernelshark_combo.png). Events of the guest happen between kvm_entry and kvm_exit of the host.

## Ubuntu VM on virtual machine manager
After giving the VM [access to the vsocket](resources/images/protocol/virtm_cid.png), and installing trace-cmd along with [dependancies](trace-cmd/LTS/trace-cmd-v3.2/README.md), run [`trace-cmd agent`](resources/images/protocol/trace-cmd_agent.png). Now, the guest is able to negotiate with host about [timestamp synchronization](resources/images/protocol/negotiated_with_guest.png). After running [`./start_kernelshark.sh`](trace-cmd/analysis/test/start_kernelshark.sh), we can view [KVM Combo plots](resources/images/protocol/kvm_combo_plots.png)


<div style="text-align: right">

[Link to top](#)

</div>
