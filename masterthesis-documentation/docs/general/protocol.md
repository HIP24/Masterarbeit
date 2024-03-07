##  Dual Boot
1) Flash SSD by installing <a href="https://etcher.balena.io/" target="_blank">etcher</a>
2) Ubuntu and Windows on same machine

## Install Salamander4 OS
1) Install Ubuntu 22.04.3 LTS
2) Do everything in [build_with_yocto.md](../sigmatek/build_with_yocto.md)

## Configure ip addresses 
[Configure PC](../resources//images/configure_ip/ip_static_connection_ubuntu.png) to `10.10.1.1`.   
[Salamander Gateway](../resources//images/configure_ip/ip_list_ubuntu.png) set to `10.10.1.229`

## SSH to device
Connect to device with `ssh -oHostKeyAlgorithms=+ssh-rsa root@10.10.1.229`  
or `ssh -p 22 root@192.168.1.x` (changes often)

## LasalClass2 to device
Connect LasalClass2 with [Salamander 4](../resources//images/lasal/class2/lasalclass2_ip.png), IP of [Salamander4 device](../resources//images/lasal/class2/lasalclass2_salamander4_ip.png)

## Configure bridge for qemu
This setup allows the virtual machines to communicate with the outside network through the Ethernet connection provided by either the laptop or the docking station.

| name       | device |
|------------|-------|
| enp0s31f6 | Laptop's Ethernet port |
| enx4cd717733f80 | Docking station's Ethernet port |

- Disable [ipv4](../resources//images/configure_bridge/ethernet_disable_ip4.png) and [ipv6](../resources//images/configure_bridge/ethernet_disable_ip6.png)
- Enter [nmtui](../resources//images/configure_bridge/nmtui.png)
- Edit Connection and [\<Add\>](../resources//images/configure_bridge/add_connection.png). Select Bridge.
- [Edit](../resources//images/configure_bridge/edit_connection.png) and \<Add\> Ethernet.
- [Copy name](../resources//images/configure_bridge/copy_name.png) enx4cd717733f80 (4C:D7:17:73:3F:80) of Wired connection 2
- [Edit Connection of Ethernet connection 1](../resources//images/configure_bridge/ethernet1.png) so that it automatically connects.
- [Activate Connection](../resources//images/configure_bridge/activate_connection.png).
- Result should look like [this](../resources//images/configure_bridge/get-to-know/connections.png) and [this](../resources//images/configure_bridge/get-to-know/bridge_connections.png).
- More info in [nmbridge.md](../QEMU/nmbridge.md). 


## Use the Xenomai test suite
- `latency -T 60`  
- `clocktest -D -T 60` 


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
sigma_ibo@pamhal:~$ cat /sys/devices/system/cpu/online 
0-19
sigma_ibo@pamhal:~$ cat /sys/devices/system/cpu/isolated
0-4
```

Before taskset with [`qemu_def_4schedstats.sh`](../QEMU/qemu_def_4schedstats.sh)
```
sigma_ibo@pamhal:$ ps -eo pid,psr,comm | grep qemu
   7295  10 start_qemu.sh
   7298  17 qemu-system-x86
```
`latency -s -T 60`
```
root@sigmatek-core2:~# latency -s -T 60
== Sampling period: 100 us
== Test mode: periodic user-mode task
== All results in microseconds
warming up...
RTT|  00:00:01  (periodic user-mode task, 100 us period, priority 99)
RTH|----lat min|----lat avg|----lat max|-overrun|---msw|---lat best|--lat worst
RTD|      1.393|      2.908|     21.765|       0|     0|      1.393|     21.765
RTD|      1.740|      2.933|     12.989|       0|     0|      1.393|     21.765
RTD|      1.603|      2.954|     22.063|       0|     0|      1.393|     22.063
RTD|      1.361|      2.988|     22.156|       0|     0|      1.361|     22.156
RTD|      1.839|      3.059|    119.253|       2|     0|      1.361|    119.253
RTD|      1.665|      2.955|     47.442|       2|     0|      1.361|    119.253
RTD|      1.603|      2.869|     12.336|       2|     0|      1.361|    119.253
RTD|      1.649|      2.953|     17.917|       2|     0|      1.361|    119.253
RTD|      1.359|      2.990|     15.286|       2|     0|      1.359|    119.253
RTD|      1.584|      2.959|     15.387|       2|     0|      1.359|    119.253
RTD|      1.910|      2.997|     84.273|       2|     0|      1.359|    119.253
RTD|      1.799|      4.133|    112.034|       3|     0|      1.359|    119.253
RTD|      2.388|      4.397|     27.953|       3|     0|      1.359|    119.253
RTD|      1.263|      3.331|    374.075|      12|     0|      1.263|    374.075
RTD|      1.842|      2.900|    154.898|      14|     0|      1.263|    374.075
RTD|      2.170|      2.876|     14.770|      14|     0|      1.263|    374.075
RTD|      1.742|      2.952|     23.002|      14|     0|      1.263|    374.075
RTD|      2.149|      2.903|    207.981|      17|     0|      1.263|    374.075
RTD|      1.275|      2.884|    234.734|      21|     0|      1.263|    374.075
RTD|      1.456|      3.018|    190.368|      25|     0|      1.263|    374.075
RTD|      1.301|      2.855|    255.438|      27|     0|      1.263|    374.075
RTT|  00:00:22  (periodic user-mode task, 100 us period, priority 99)
RTH|----lat min|----lat avg|----lat max|-overrun|---msw|---lat best|--lat worst
RTD|      1.442|      2.847|     16.121|      27|     0|      1.263|    374.075
RTD|      1.609|      2.886|     54.156|      27|     0|      1.263|    374.075
RTD|      1.193|      2.838|     13.409|      27|     0|      1.193|    374.075
RTD|      1.175|      2.835|      9.749|      27|     0|      1.175|    374.075
RTD|      2.120|      2.833|      9.886|      27|     0|      1.175|    374.075
RTD|      1.205|      2.830|      9.281|      27|     0|      1.175|    374.075
RTD|      1.288|      2.836|     15.243|      27|     0|      1.175|    374.075
RTD|      1.358|      2.865|     24.674|      27|     0|      1.175|    374.075
RTD|      1.369|      2.852|     95.134|      27|     0|      1.175|    374.075
RTD|      1.198|      2.853|    122.350|      28|     0|      1.175|    374.075
RTD|      1.883|      2.861|    119.295|      29|     0|      1.175|    374.075
RTD|      1.479|      2.840|     16.134|      29|     0|      1.175|    374.075
RTD|      1.389|      2.853|     13.289|      29|     0|      1.175|    374.075
RTD|      1.779|      2.887|     22.949|      29|     0|      1.175|    374.075
RTD|      1.592|      2.847|     82.516|    with
RTD|      2.293|      2.843|     40.522|      29|     0|      1.175|    374.075
RTD|      1.207|      2.888|    138.783|      30|     0|      1.175|    374.075
RTD|      1.405|      2.862|     21.464|      30|     0|      1.175|    374.075
RTD|      1.218|      2.853|     13.491|      30|     0|      1.175|    374.075
RTT|  00:00:43  (periodic user-mode task, 100 us period, priority 99)
RTH|----lat min|----lat avg|----lat max|-overrun|---msw|---lat best|--lat worst
RTD|      1.269|      2.865|      9.891|      30|     0|      1.175|    374.075
RTD|      1.343|      2.866|     52.299|      30|     0|      1.175|    374.075
RTD|      1.303|      2.868|     27.312|      30|     0|      1.175|    374.075
RTD|      1.544|      2.904|     30.962|      30|     0|      1.175|    374.075
RTD|      1.310|      2.939|    193.024|      31|     0|      1.175|    374.075
RTD|      1.416|      2.917|    206.245|      34|     0|      1.175|    374.075
RTD|      1.384|      2.871|     10.043|      34|     0|      1.175|    374.075
RTD|      1.462|      2.863|    150.257|      35|     0|      1.175|    374.075
RTD|      1.570|      2.917|    152.735|      37|     0|> lat worst reduced from 374.075 to 87.379
      1.175|    374.075
RTD|      1.626|      2.983|    149.424|      40|     0|      1.175|    374.075
RTD|      1.247|      2.999|     24.876|      40|     0|      1.175|    374.075
RTD|      1.637|      2.999|     13.527|      40|     0|      1.175|    374.075
HSH|--param|--samples-|--average--|---stddev--
HSS|    min|        59|      1.085|      0.281
HSS|    avg|    599943|      2.200|      1.460
HSS|    max|        59|     68.847|     77.257
---|-----------|-----------|-----------|--------|------|-------------------------
RTS|      1.175|      2.955|    374.075|      40|     0|    00:01:00/00:01:00
```


After taskset on CPU4 with [`qemu_def_5taskset.sh`](../QEMU/qemu_def_5taskset.sh)
```
sigma_ibo@pamhal:$ ps -eo pid,psr,comm | grep qemu
   8752   0 start_qemu.sh
   8755   4 qemu-system-x86
```
```
root@sigmatek-core2:~# latency -s -T 60
== Sampling period: 100 us
== Test mode: periodic user-mode task
== All results in microseconds
warming up...
RTT|  00:00:01  (periodic user-mode task, 100 us period, priority 99)
RTH|----lat min|----lat avg|----lat max|-overrun|---msw|---lat best|--lat worst
RTD|      1.518|      2.994|     60.423|       0|     0|      1.518|     60.423
RTD|      1.245|      2.787|     50.589|       0|     0|      1.245|     60.423
RTD|      1.925|      2.845|     82.861|       0|     0|      1.245|     82.861
RTD|      1.237|      2.963|     83.906|       0|     0|      1.237|     83.906
RTD|      1.167|      2.777|     19.388|       0|     0|      1.167|     83.906
RTD|      1.333|      2.779|     33.484|       0|     0|      1.167|     83.906
RTD|      1.330|      2.921|     31.062|       0|     0|      1.167|     83.906
RTD|      1.567|      2.777|     15.960|       0|     0|      1.167|     83.906
RTD|      1.900|      2.902|     17.630|       0|     0|      1.167|     83.906
RTD|      1.230|      3.012|     55.056|       0|     0|      1.167|     83.906
RTD|      1.480|      2.822|     50.378|       0|     0|      1.167|     83.906
RTD|      1.197|      2.770|     16.093|       0|     0|      1.167|     83.906
RTD|      1.525|      2.879|     79.003|       0|     0|      1.167|     83.906
RTD|      1.417|      2.788|     39.852|       0|     0|      1.167|     83.906
RTD|      1.468|      3.857|     60.830|       0|     0|      1.167|     83.906
RTD|      2.305|      4.212|     55.658|       0|     0|      1.167|     83.906
RTD|      1.882|      4.158|     43.550|       0|     0|      1.167|     83.906
RTD|      2.059|      4.144|     49.666|       0|     0|      1.167|     83.906
RTD|      2.439|      4.157|     87.379|       0|     0|      1.167|     87.379
RTD|      2.067|      4.178|     73.607|       0|     0|      1.167|     87.379
RTD|      1.772|      3.334|     54.281|       0|     0|      1.167|     87.379
RTT|  00:00:22  (periodic user-mode task, 100 us period, priority 99)
RTH|----lat min|----lat avg|----lat max|-overrun|---msw|---lat best|--lat worst
RTD|      1.605|      2.794|     57.324|       0|     0|      1.167|     87.379
RTD|      1.196|      2.763|      7.132|       0|     0|      1.167|     87.379
RTD|      2.285|      3.849|     51.351|       0|     0|      1.167|     87.379
RTD|      2.001|      4.221|     56.
502|       0|     0|      1.167|     87.379
RTD|      1.507|      2.787|     30.784|       0|     0|      1.167|     87.379
RTD|      1.277|      2.782|     28.294|       0|     0|      1.167|     87.379
RTD|      2.193|      2.797|     28.698|       0|     0|      1.167|     87.379
RTD|      1.899|      2.772|     23.894|       0|     0|      1.167|     87.379
RTD|      1.325|      2.831|     22.687|       0|     0|      1.167|     87.379
RTD|      1.195|      2.928|     36.321|       0|     0|      1.167|     87.379
RTD|      1.644|      2.812|     31.942|       0|     0|      1.167|     87.379
RTD|      1.544|      2.780|     33.094|       0|     0|      1.167|     87.379
RTD|      1.650|      2.889|     18.863|       0|     0|      1.167|     87.379
RTD|      1.271|      2.792|     38.819|       0|     0|      1.167|     87.379
RTD|      1.902|      2.981|     59.703|       0|     0|      1.167|     87.379
RTD|      1.802|      3.091|     56.189|       0|     0|      1.167|     87.379
RTD|      1.304|      2.818|     38.355|       0|     0|      1.167|     87.379
RTD|      1.571|      2.827|     52.074|       0|     0|      1.167|     87.379
RTT|  00:00:43  (periodic user-mode task, 100 us period, priority 99)
RTH|----lat min|----lat avg|----lat max|-overrun|---msw|---lat best|--lat worst
RTD|      1.465|      2.949|     49.229|       0|     0|      1.167|     87.379
RTD|      1.765|      2.800|     42.433|       0|     0|      1.167|     87.379
RTD|      1.220|      2.967|     45.561|       0|     0|      1.167|     87.379
RTD|      1.874|      3.020|     74.500|       0|     0|      1.167|     87.379
RTD|      1.304|      2.881|     43.092|       0|     0|      1.167|     87.379
RTD|      1.231|      2.836|     10.778|       0|     0|      1.167|     87.379
RTD|      1.901|      2.944|     59.756|       0|     0|      1.167|     87.379
RTD|      1.316|      2.820|     32.074|       0|     0|      1.167|     87.379
RTD|      1.235|      2.896|     55.582|       0|     0|      1.167|     87.379
RTD|      1.171|      2.824|     68.296|       0|     0|      1.167|     87.379
RTD|      1.384|      2.832|     49.778|       0|     0|      1.167|     87.379
RTD|      1.935|      2.770|     47.123|       0|     0|      1.167|     87.379
RTD|      1.154|      2.821|     41.895|       0|     0|      1.154|     87.379
RTD|      1.315|      2.803|     36.721|       0|     0|      1.154|     87.379
RTD|      1.881|      2.983|     76.927|       0|     0|      1.154|     87.379
RTD|      1.619|      2.999|     68.384|       0|     0|      1.154|     87.379
RTD|      1.388|      2.797|     58.660|       0|     0|      1.154|     87.379
HSH|--param|--samples-|--average--|---stddev--
HSS|    min|        59|      1.119|      0.326
HSS|    avg|    599984|      2.428|      1.112
HSS|    max|        59|     46.746|     19.462
---|-----------|-----------|-----------|--------|------|-------------------------
RTS|      1.154|      3.078|     87.379|       0|     0|    00:01:00/00:01:00
```


> lat worst reduced from 374.075 to 87.379


## trace-cmd Problems 
<a href="https://rostedt.org/host-guest-tutorial/" target="_blank">Rostedt Tutorial</a>  
`sudo trace-cmd record -e kvm:kvm_entry -e kvm:kvm_exit -A @3:823 --name Salamander4 -e all`

### 2 Problems  
1. "Failed to negotiate timestamps synchronization with the host"
[timestamp_error.png](../resources//images/trace-cmd/timestamp_error.png)

2. "Cannot find host / guest tracing into the loaded streams" [kvm_combo_error.png](../resources//images/trace-cmd/kvm_combo_error.png)

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
Now, [trace-cmd version 3.2.0](../resources/images/trace-cmd/trace-cmd_version3.2.0.png) is active and [tracing the guest](../resources//images/trace-cmd/time_sync.png) finally works with `trace-cmd agent` on the guest.

Using kernelshark with `kernelshark trace.dat -a trace-Salamander4.dat` or simply [`./start_kernelshark.sh`](../trace-cmd/analysis//test/start_kernelshark.sh), we get the expected [visualization](../resources/images/trace-cmd/kernelshark/kernelshark_combo.png). Events of the guest happen between kvm_entry and kvm_exit of the host.

## Ubuntu VM on virtual machine manager
After giving the VM [access to the vsocket](../resources//images/protocol/virtm_cid.png), and installing trace-cmd along with [dependancies](../trace-cmd/LTS/trace-cmd-v3.2/README.md), run [`trace-cmd agent`](../resources//images/protocol/trace-cmd_agent.png). Now, the guest is able to negotiate with host about [timestamp synchronization](../resources//images/protocol/negotiated_with_guest.png). After running [`./start_kernelshark.sh`](../trace-cmd/analysis/test/start_kernelshark.sh), we can view [KVM Combo plots](../resources//images/protocol/kvm_combo_plots.png)


<div style="text-align: right">

[Link to top](#)

</div>
