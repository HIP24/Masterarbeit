# Protocol

##  Dual Boot
1) Flash SSD by installing <a href="https://etcher.balena.io/" target="_blank">etcher</a>
2) Ubuntu and Windows on same machine

## Install Salamander4 OS
1) Install Ubuntu 22.04.3 LTS
2) Do everything in [build_with_yocto.md](../sigmatek/salamander4/build_with_yocto.md)

## SSH to device
Connect to device with `ssh -oHostKeyAlgorithms=+ssh-rsa root@10.10.1.229`  
or `ssh -p 22 root@192.168.1.x` (changes often)

## LasalClass2 to device
Connect LasalClass2 with [Salamander 4](../resources/images/lasal/class2/lasalclass2_ip.png), IP of [Salamander4 device](../resources/images/lasal/class2/lasalclass2_salamander4_ip.png)

## Configure bridge for QEMU
This setup allows the virtual machines to communicate with the outside network through the Ethernet connection provided by either the laptop or the docking station.

| name       | device |
|------------|-------|
| enp0s31f6 | Laptop's Ethernet port |
| enx4cd717733f80 | Docking station's Ethernet port |

- Disable [ipv4](../resources/images/configure_bridge/ethernet_disable_ip4.png) and [ipv6](../resources/images/configure_bridge/ethernet_disable_ip6.png)
- Enter [nmtui](../resources/images/configure_bridge/nmtui.png)
- Edit Connection and [\<Add\>](../resources/images/configure_bridge/add_connection.png). Select Bridge.
- [Edit](../resources/images/configure_bridge/edit_connection.png) and \<Add\> Ethernet.
- [Copy name](../resources/images/configure_bridge/copy_name.png) enx4cd717733f80 (4C:D7:17:73:3F:80) of Wired connection 2
- [Edit Connection of Ethernet connection 1](../resources/images/configure_bridge/ethernet1.png) so that it automatically connects.
- [Activate Connection](../resources/images/configure_bridge/activate_connection.png).
- Result should look like [this](../resources/images/configure_bridge/get-to-know/connections.png) and [this](../resources/images/configure_bridge/get-to-know/bridge_connections.png).
- More info in [nmbridge.md](../sigmatek/QEMU/nmbridge.md). 

## Reduce latency
We test the system using the Xenomai test suite
- `latency -T 60`  
- `clocktest -D -T 60` 

### Out-of-the-box 
Before taskset with [`qemu_def_4schedstats.sh`](../sigmatek/QEMU/qemu_def_4schedstats.sh)
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
RTD|      1.570|      2.917|    152.735|      37|     0|      1.175|    374.075
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

> lat worst reduced from 374.075 to 87.379


### Isolate CPUs on host

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

After taskset on CPU4 with [`qemu_def_5taskset.sh`](../sigmatek/QEMU/qemu_def_5taskset.sh)
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

### Enable Preempt_RT Kernel
Do everything in [kernel-patch.md](../sigmatek/latency_reduction/kernel-patch/kernel-patch.md) to patch the kernel and enable Fully Preemptible Kernel (RT).

!!! info
    Before the isolation of CPU 4, both kernel threads and user processes were running on this CPU. The user processes included various applications such as msedge, code, bash and qemu-system-x86.
    
    After isolating CPU 4, only kernel threads and the qemu-system-x86 process appear to be running on this CPU. There do not appear to be any other user processes running on this CPU.
    
    The isolcpus option prevents the kernel from scheduling normal (non-real-time) processes on the isolated CPUs. However, there are some exceptions:

    - If a process is explicitly set to run on an isolated CPU (for example with taskset), it will run on that CPU even if it is isolated.
    - Some kernel threads can run on isolated CPUs because they are not controlled by the normal scheduler. These include the threads you see in your output, such as kthreadd, migration/4, ksoftirqd/4, kworker/4:0-events and others.
    - Interrupts can be handled on isolated CPUs unless they are explicitly redirected with the irqaffinity option.

```
sigma_ibo@pamhal:$ ps -e -o pid,psr,comm | awk '$2 == 4'
      2   4 kthreadd
     18   4 pr/legacy
     35   4 cpuhp/4
     36   4 idle_inject/4
     37   4 irq_work/4
     38   4 migration/4
     39   4 rcuc/4
     40   4 ktimers/4
     41   4 ksoftirqd/4
     42   4 kworker/4:0-events
     43   4 kworker/4:0H-kblockd
    198   4 kdevtmpfs
    201   4 kauditd
    207   4 kcompactd0
    208   4 ksmd
    237   4 irq/124-PCIe PME
    252   4 hwrng
    268   4 kworker/4:1-events
    372   4 irq/138-rtsx_pci
    416   4 irq/178-nvme1q5
    483   4 jbd2/nvme1n1p2-8
    866   4 irq/230-iwlwifi:queue_14
    867   4 irq/230-s-iwlwifi:queue_14
    913   4 kworker/R-ttm
    914   4 card0-crtc0
    915   4 card0-crtc1
    916   4 card0-crtc2
    917   4 card0-crtc3
   1677   4 krfcommd
   3184   4 kworker/4:1H-kblockd
   3370   4 qemu-system-x86
   3387   4 kvm-nx-lpage-recovery-3370
   3776   4 kvm-pit/3370
```

The latency is way too unreliable and not realtime.
```
root@sigmatek-core2:~# latency -s -T 60
== Sampling period: 100 us
== Test mode: periodic user-mode task
== All results in microseconds
warming up...
RTT|  00:00:01  (periodic user-mode task, 100 us period, priority 99)
RTH|----lat min|----lat avg|----lat max|-overrun|---msw|---lat best|--lat worst
RTD|      0.995|      2.722|   4154.694|      47|     0|      0.995|   4154.694
RTD|      0.916|      2.406|    303.367|      58|     0|      0.916|   4154.694
RTD|      0.723|      2.305|    295.200|      68|     0|      0.723|   4154.694
RTD|      0.901|      2.330|    244.994|      76|     0|      0.723|   4154.694
RTD|      0.950|      2.247|    220.734|      80|     0|      0.723|   4154.694
RTD|      0.725|      2.130|     53.888|      80|     0|      0.723|   4154.694
RTD|      0.794|      2.270|    117.382|      81|     0|      0.723|   4154.694
RTD|      0.691|      2.748|   4907.415|     133|     0|      0.691|   4907.415
RTD|      0.982|      2.253|     67.471|     133|     0|      0.691|   4907.415
RTD|      0.748|      2.221|     90.370|     133|     0|      0.691|   4907.415
RTD|      0.818|      2.230|     63.722|     133|     0|      0.691|   4907.415
RTD|      1.045|      2.193|     50.296|     133|     0|      0.691|   4907.415
RTD|      1.216|      2.213|     37.887|     133|     0|      0.691|   4907.415
RTD|      1.040|      2.211|     46.584|     133|     0|      0.691|   4907.415
RTD|      0.676|      2.283|    716.719|     142|     0|      0.676|   4907.415
RTD|      0.590|      2.240|    148.979|     143|     0|      0.590|   4907.415
RTD|      0.700|      2.218|    144.958|     148|     0|      0.590|   4907.415
RTD|      0.598|      2.818|    161.812|     153|     0|      0.590|   4907.415
RTD|      0.852|      2.202|    127.750|     157|     0|      0.590|   4907.415
RTD|      1.118|      2.705|   4493.786|     205|     0|      0.590|   4907.415
RTD|      0.630|      2.226|    189.791|     207|     0|      0.590|   4907.415
RTT|  00:00:22  (periodic user-mode task, 100 us period, priority 99)
RTH|----lat min|----lat avg|----lat max|-overrun|---msw|---lat best|--lat worst
RTD|      1.043|      3.102|   4843.394|     287|     0|      0.590|   4907.415
RTD|      0.981|      2.579|   2054.323|     312|     0|      0.590|   4907.415
RTD|      1.006|      2.346|    203.226|     318|     0|      0.590|   4907.415
RTD|      0.946|      2.333|    173.532|     323|     0|      0.590|   4907.415
RTD|      0.741|      2.413|    195.747|     328|     0|      0.590|   4907.415
RTD|      0.695|      2.369|    224.494|     334|     0|      0.590|   4907.415
RTD|      0.921|      2.385|    477.227|     343|     0|      0.590|   4907.415
RTD|      1.263|      2.616|   3155.684|     378|     0|      0.590|   4907.415
RTD|      0.775|      2.252|    179.318|     380|     0|      0.590|   4907.415
RTD|      0.721|      2.226|     25.904|     380|     0|      0.590|   4907.415
RTD|      0.810|      2.200|    189.302|     382|     0|      0.590|   4907.415
RTD|      0.619|      2.295|    211.109|     387|     0|      0.590|   4907.415
RTD|      0.681|      2.716|   4740.773|     436|     0|      0.590|   4907.415
RTD|      0.745|      2.244|    184.998|     439|     0|      0.590|   4907.415
RTD|      0.806|      2.259|    184.789|     443|     0|      0.590|   4907.415
RTD|      0.577|      2.320|    259.109|     450|     0|      0.577|   4907.415
RTD|      0.927|      2.595|   1453.449|     474|     0|      0.577|   4907.415
RTD|      0.824|      2.710|   3261.857|     514|     0|      0.577|   4907.415
RTD|      0.718|      2.450|    229.777|     522|     0|      0.577|   4907.415
RTD|      0.773|      2.382|    238.656|     531|     0|      0.577|   4907.415
RTD|      0.815|      2.470|    268.511|     538|     0|      0.577|   4907.415
RTT|  00:00:43  (periodic user-mode task, 100 us period, priority 99)
RTH|----lat min|----lat avg|----lat max|-overrun|---msw|---lat best|--lat worst
RTD|      1.500|      2.560|    384.558|     554|     0|      0.577|   4907.415
RTD|      1.371|      2.475|    243.396|     562|     0|      0.577|   4907.415
RTD|      0.624|      2.573|    511.409|     576|     0|      0.577|   4907.415
RTD|      0.899|      3.044|   4593.851|     648|     0|      0.577|   4907.415
RTD|      1.090|      2.827|   3403.441|     688|     0|      0.577|   4907.415
RTD|      0.900|      2.549|    337.856|     701|     0|      0.577|   4907.415
RTD|      0.979|      2.323|    282.412|     711|     0|      0.577|   4907.415
RTD|      0.768|      2.298|    236.064|     718|     0|      0.577|   4907.415
RTD|      0.846|      2.243|    202.747|     723|     0|      0.577|   4907.415
RTD|      0.732|      3.081|   4731.553|     810|     0|      0.577|   4907.415
RTD|      1.630|      2.339|    264.409|     818|     0|      0.577|   4907.415
RTD|      0.820|      2.417|    305.139|     829|     0|      0.577|   4907.415
RTD|      0.857|      2.954|   5926.355|     899|     0|      0.577|   5926.355
RTD|      0.752|      2.234|    273.349|     906|     0|      0.577|   5926.355
RTD|      0.630|      2.290|    225.216|     914|     0|      0.577|   5926.355
RTD|      1.323|      2.322|    226.582|     920|     0|      0.577|   5926.355
RTD|      1.181|      2.296|    224.922|     928|     0|      0.577|   5926.355
HSH|--param|--samples-|--average--|---stddev--
HSS|    min|        59|      0.220|      0.418
HSS|    avg|    598956|      1.996|      4.444
HSS|    max|        59|    219.780|     84.249
---|-----------|-----------|-----------|--------|------|-------------------------
RTS|      0.577|      2.428|   5926.355|     928|     0|    00:01:00/00:01:00
```
### Realtime priority

!!! danger
    Setting a real-time priority of 99 for a process means that this process has the highest priority in the system and is executed before all other processes. This can result in other processes, including important system processes, not receiving the CPU time they need to function properly. This can lead to system instability and, in the worst case, to the system becoming unresponsive or "crashing".

    It is important to be careful when using real-time priorities and ensure that other important processes still get the CPU time they need. It might be helpful to gradually increase the real-time priority and observe the effects on the system instead of jumping straight to the highest priority.


To see the real-time priorities of all running processes, you can use this command:
```
ps -eo pid,comm,ni,rtprio,cls
```

### Ubuntu VM on virtual machine manager
After giving the VM [access to the vsocket](../resources/images/protocol/virtm_cid.png), and installing trace-cmd along with dependancies<!--[dependancies](../salamander4/trace-cmd/LTS/trace-cmd-v3.2/README.md)-->, run [`trace-cmd agent`](../resources/images/protocol/trace-cmd_agent.png). Now, the guest is able to negotiate with host about [timestamp synchronization](../resources/images/protocol/negotiated_with_guest.png). After running [`./start_kernelshark.sh`](../sigmatek/trace-cmd/analysis/taskset/start_kernelshark.sh), we can view [KVM Combo plots](../resources/images/protocol/kvm_combo_plots.png)


## Connect to hardware Salamander 4
ssh root@192.168.1.244


## bcc
```
git clone https://github.com/iovisor/bcc

```