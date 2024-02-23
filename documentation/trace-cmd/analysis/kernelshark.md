## Use kernelshark

[File trace.dat contains no data](../../resources/images/trace-cmd/kernelshark/contains_no_data.png)

```
sudo trace-cmd record -e kvm:kvm_entry -e kvm:kvm_exit
trace-cmd report
sudo trace-cmd convert -i trace.dat -o trace_v6.dat --file-version 6 --compression none
sudo rm trace.dat
mv trace_v6.dat trace.dat
kernelshark
```