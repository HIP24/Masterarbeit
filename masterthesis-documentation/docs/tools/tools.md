## kvm_stat
```
sudo kvm_stat -s 1 -c -L test.csv
```

## bcc
```
cd /usr/share/bcc/tools && sudo ./kvmexit 1
sudo kvmexit 2 > kvmexit.log
```