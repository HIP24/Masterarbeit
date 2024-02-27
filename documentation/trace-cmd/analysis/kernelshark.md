## Use kernelshark

[File trace.dat contains no data](../../resources/images/trace-cmd/kernelshark/contains_no_data.png)

Host only
```
sudo trace-cmd record -e kvm:kvm_entry -e kvm:kvm_exit
```


Host and Guest track kvm, sched, irq, irq_vectors
```
sudo trace-cmd record -e kvm -e sched -e irq -e irq_vectors -A @3:823 --name Salamander4 -e all ssh root@192.168.1.78 'ls -lR . > /dev/null'
```


Host and Guest track kvm_entry and kvm_exit
```
sudo trace-cmd record -e kvm:kvm_entry -e kvm:kvm_exit -A @3:823 --name Salamander4 -e all ssh root@192.168.1.78 'ls -lR . > /dev/null'
```


After trace-cmd raw
```
trace-cmd report
```


After trace-cmd kernelshark
```
sudo trace-cmd convert -i trace.dat -o trace_v6.dat --file-version 6 --compression none
sudo rm trace.dat
mv trace_v6.dat trace.dat
sudo trace-cmd convert -i trace-Salamander4.dat -o trace_v6.dat --file-version 6 --compression none
sudo rm trace-Salamander4.dat
mv trace_v6.dat trace-Salamander4.dat
kernelshark
```