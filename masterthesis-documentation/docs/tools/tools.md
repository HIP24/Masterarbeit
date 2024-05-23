## kvm_stat
```bash
sudo kvm_stat -s 1 -c -L test.csv
```

## [bcc](https://github.com/iovisor/bcc.git)
Clone bcc
```bash
git clone https://github.com/iovisor/bcc
```
Execute bcc
```bash
cd /usr/share/bcc/tools && sudo ./kvmexit 1
sudo kvmexit 2 > kvmexit.log
```

## [rt-tester](https://github.com/AgileDevArt/rt-tester)
Clone rt-tester
```bash
git clone https://github.com/AgileDevArt/rt-tester
```
Execute rt-tester
```bash
g++ rt-tester -o rt-tester 
./rt-tester
```