## Microsoft Edge
### Problem
```
sigma_ibo@sigma-ibo:~$ microsoft-edge
[9283:9283:0402/093408.731168:ERROR:process_singleton_posix.cc(359)] This profile appears to be in use by another Microsoft Edge process (2953) on another computer (localhost.localdomain). Microsoft Edge has locked this profile to prevent corruption. If you're sure no other processes are using this profile, you can unlock it and relaunch Microsoft Edge.
[9283:9283:0402/093408.731251:ERROR:message_box_dialog.cc(147)] Unable to show a dialog outside the UI thread message loop: Microsoft Edge - This profile appears to be in use by another Microsoft Edge process (2953) on another computer (localhost.localdomain). Microsoft Edge has locked this profile to prevent corruption. If you're sure no other processes are using this profile, you can unlock it and relaunch Microsoft Edge.
```
### Solution
Delete SingletonLock in `/home/sigma_ibo/.config/microsoft-edge`



## Yocto 
### Problem
File://0001.patch error

[Unable to find file file://0001-Fix.patch](../resources/images/yocto/0001patch.png)

### Solution
```
cd meta-sigmatek/
git branch
code ../meta-sigmatek/
gitk
git rebase origin/master
git checkout master
git reset --hard
git checkout master
git pull
git fetch
git branch
git branch -D pamhal/virtualization
git branch
git pull
git fetch
git branch pamhal/virtual_master
git checkout pamhal/virtual_master
git branch
git status
git add recipes-kernel/stek-common/files/x86-64/defconfig
git commit
git push
git push --set-upstream origin pamhal/virtual_master
git branch
git pull
code .
cd salamander/salamander-core2
../init.sh -b build -m sigmatek-core2 -d salamander
bitbake salamander-image -k
```



## Trace-cmd 
### Problems
After following <a href="https://rostedt.org/host-guest-tutorial/" target="_blank">Rostedt Tutorial</a>, I had following problems when using: 
```
sudo trace-cmd record -e kvm:kvm_entry -e kvm:kvm_exit -A @3:823 --name Salamander4 -e all
```
#### Problem 1  
"Failed to negotiate timestamps synchronization with the host"
[timestamp_error.png](../resources/images/trace-cmd/timestamp_error.png)

#### Problem 2
"Cannot find host / guest tracing into the loaded streams" [kvm_combo_error.png](../resources/images/trace-cmd/kvm_combo_error.png)

### Solution
The problem was the trace-cmd version. Set both host and guest to v3.2.0 by copying the files from host to guest:
```
scp /usr/local/bin/trace-cmd root@"$ip_address":/usr/bin
scp /usr/local/lib64/libtracefs.so.1 root@"$ip_address":/lib64
scp /usr/local/lib64/libtraceevent.so.1 root@"$ip_address":/lib64
```
Now, [trace-cmd version 3.2.0](../resources/images/trace-cmd/trace-cmd_version3.2.0.png) is active and [tracing the guest](../resources/images/trace-cmd/time_sync.png) finally works with `trace-cmd agent` on the guest.

Using kernelshark with `kernelshark trace.dat -a trace-Salamander4.dat` or simply [`./start_kernelshark.sh`](../sigmatek/trace-cmd/analysis/taskset/start_kernelshark.sh), we get the expected [visualization](../resources/images/trace-cmd/kernelshark/kernelshark_combo.png). Events of the guest happen between kvm_entry and kvm_exit of the host.
