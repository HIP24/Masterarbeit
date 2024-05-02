## kvm_stat
```bash
sudo kvm_stat -s 1 -c -L test.csv
```

## bcc
```bash
cd /usr/share/bcc/tools && sudo ./kvmexit 1
sudo kvmexit 2 > kvmexit.log
```

## rt-tester
```bash
g++ rt-tester -o rt-tester 
./rt-tester
```