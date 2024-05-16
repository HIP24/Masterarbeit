## Am Dienstag, 20. Februar 2024, 11:20 
Hallo Halil,

>> 375us ist halt weit weg von dem was Salamander sonst an Latenz hat.
>> Damit kann man nur wenig anfangen.
>> Aber ich würde erstmal schauen die Latenz besser in Griff zu bekommen. ✅

> Wie könnte ich das am besten besser in Griff bekommen? Hast du da einen Weg für mich? Oder generell wie ich vorgehen soll?

Wie letztens erwähnt, im ersten Schritt dafür sorgen, dass die VM immer die CPU hat und möglichst wenig unterbrochen wird. ✅

> > Ich weiß jetzt nicht genau was deine Aufgabe ist.

> So lautet der Titel meiner Masterarbeit:
> Virtualisierung eines Echtzeit-Betriebssystems zur Steuerung eines Roboters mit Schwerpunkt auf die Einhaltung der Echtzeit

Das klingt eh gut.
Du kannst am Host auch mal messen wann die VM immer die CPU hat und mit dem Gast vergleichen. Da solltest dann eine schöne Korrelation zu den Ausreißern sehen. Mit den VMEnter/Exit Tracpoints solltest das gut sehen.
Siehe: https://www.youtube.com/watch?v=v0ocveEsvNU ❌

So kannst Schritt für Schritt die Latenz verbessern und jeweils nachweisen
was nun wie viel gebracht hat. ❌

LG,
//richard

<hr>

## Am Dienstag, 20. Februar 2024, 12:41 
Hallo Halil,

> Ich habe bis jetzt folgendes getan, um die Latenz zu reduzieren
>
> 1) Die Option -smp cpus=10 im QEMU-Befehl hinzugefügt um die Anzahl der CPUs zu erhöhen auf 10

Was war die Idee dahinter? Mehr CPUs im Gast bringt nur was wenn gleich viele am Host hast.
Und die Latenz an sich wird immer pro CPU gemessen. D.h. der Test pinnt einen Thread auf eine CPU. ✅

> 2) isolcpus=0,1,2 zur -append Option in QEMU hinzugefügt, um 3 CPUs zu isolieren

Naja, du musst das am Host machen. Der Gast ist ja schon echtzeitfähig, jetzt gilt es dafür zu sorgen, dass der Host ihm nicht in die Suppe spuckt. ✅

> 3) Jetzt benutze ich taskset um diese cpus zu xenomai zuzuweisen und dann werde ich nochmal testen
>
> Bin ich am richtigen Weg?

Nicht wirklich. Du wirst am Host viel drehen müssen. ✅

LG,
//richard


<hr>



## Richard Meeting 11.03.2024
CPU isolierung läuft auf User space, nicht kernel space
QEMU mit echtzeit prio chrt einschalten aber niedrige prio 1-99

1) out-of-of-the-box
2) cpi isolated auf user space
3) realtime priority experimentieren
4) cpu soll keine interrupts behandeln -> welche cpu soll ich wählen?
5) HYprerthreading ausschalten damit cpu cores nicht geteilt werden
6) kernelshark

https://www.suse.com/c/cpu-isolation-nohz_full-part-3/
https://sigma-star.at/blog/2022/02/linux-proc-prios/
https://www.osadl.org/Create-a-latency-plot-from-cyclictest-hi.bash-script-for-latency-plot.0.html


<hr>


## Richard Meeting 19.03.2024
[  235.780378][  T336] X-LRT-Timer: Sigmatek LRT Driver: time-keeper: detected overrun when waiting on period, ovr=2, res=-110

QEMU, VirtualBox, KVM, and Hyper-V? --> Salamander4

kernel patch
kernel-tasks
chrt
kvm_exit warum?
kernel tasks auf andere cpu pinnen
oder
höhere prio als andere kernel tasks haben -> zb netzwerkkarte


<hr>


## Richard Meeting 09.04.2024

### isolate CPU
taskset

### defconfig
CONFIG_PARAVIRT=y  
CONFIG_KVM_GUEST=y  
CONFIG_X86_IOAT_VAPIC_BROKEN_CTL=y  
CONFIG_MTRR_SANITIZER=y  
CONFIG_ARCH_CPUIDLE_HALTPOLL=y  
CONFIG_HUGETLBFS=y

### smp_affinity 
cat /proc/irq/*/smp_affinity  
sudo chmod 777 /proc/irq/*/smp_affinity  
sudo echo dffff > /proc/irq/*/smp_affinity  

### Enable APICV
/sys/module/kvm_intel/parameters/enable_apicv

### QEMU_vapic
-cpu host,hv-passthrough

### trace-cmd report host and guest 
results_guest_report.txt  
results_host_report.txt

https://www.sigma-star.at/blog/2022/02/linux-proc-prios/

## Richard Meeting 15.05.2024

Richard Weinberger
13:12
lstopo
aus paket hwloc
Richard Weinberger
13:34
https://docs.kernel.org/trace/ftrace.html#latency-tracing-and-events
Richard Weinberger
13:37
https://access.redhat.com/documentation/de-de/red_hat_enterprise_linux_for_real_time/7/html/tuning_guide/latency_tracing_using_trace-cmd
Richard Weinberger
13:38
"trace-cmd latency tracer"
Richard Weinberger
13:49
CONFIG_RCU_CPU_STALL_TIMEOUT
Richard Weinberger
13:52
https://wiki.linuxfoundation.org/realtime/documentation/technical_details/rcu



❌✅