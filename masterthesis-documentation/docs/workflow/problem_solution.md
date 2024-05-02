## Microsoft Edge
### Problem
```bash
sigma_ibo@sigma-ibo:~$ microsoft-edge
[9283:9283:0402/093408.731168:ERROR:process_singleton_posix.cc(359)] This profile appears to be in use by another Microsoft Edge process (2953) on another computer (localhost.localdomain). Microsoft Edge has locked this profile to prevent corruption. If you're sure no other processes are using this profile, you can unlock it and relaunch Microsoft Edge.
[9283:9283:0402/093408.731251:ERROR:message_box_dialog.cc(147)] Unable to show a dialog outside the UI thread message loop: Microsoft Edge - This profile appears to be in use by another Microsoft Edge process (2953) on another computer (localhost.localdomain). Microsoft Edge has locked this profile to prevent corruption. If you're sure no other processes are using this profile, you can unlock it and relaunch Microsoft Edge.
```

### Solution
Delete SingletonLock in `/home/sigma_ibo/.config/microsoft-edge`



## Yocto 
### Problem 1
File://0001.patch error

[Unable to find file file://0001-Fix.patch](../resources/images/yocto/0001patch.png)

### Solution 1
```bash
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

### Problem 2
```bash
ERROR: salamander-image-1.0-r0 do_rootfs: Unable to install packages. Command '/home/sigma_ibo/Develop/Yocto_local/salamander/salamander-core2/build/tmp/work/sigmatek_core2-sigmatek-linux/salamander-image/1.0-r0/recipe-sysroot-native/usr/bin/opkg --volatile-cache -f /home/sigma_ibo/Develop/Yocto_local/salamander/salamander-core2/build/tmp/work/sigmatek_core2-sigmatek-linux/salamander-image/1.0-r0/opkg.conf -t /home/sigma_ibo/Develop/Yocto_local/salamander/salamander-core2/build/tmp/work/sigmatek_core2-sigmatek-linux/salamander-image/1.0-r0/temp/ipktemp/ -o /home/sigma_ibo/Develop/Yocto_local/salamander/salamander-core2/build/tmp/work/sigmatek_core2-sigmatek-linux/salamander-image/1.0-r0/rootfs  --force_postinstall --prefer-arch-to-version --no-install-recommends  --force-maintainer --force-overwrite install cups-locale-en lib32-cups-locale-en' returned 255:
 * opkg_prepare_url_for_install: Couldn't find anything to satisfy 'lib32-cups-locale-en'.

ERROR: Logfile of failure stored in: /home/sigma_ibo/Develop/Yocto_local/salamander/salamander-core2/build/tmp/work/sigmatek_core2-sigmatek-linux/salamander-image/1.0-r0/temp/log.do_rootfs.76045
ERROR: Task (/home/sigma_ibo/Develop/Yocto_local/salamander/meta-sigmatek/recipes-sigmatek/images/salamander-image.bb:do_rootfs) failed with exit code '1'
```

### Solution 2
bitbake -c do_cleanall lib32-cups

## Trace-cmd 
After following <a href="https://rostedt.org/host-guest-tutorial/" target="_blank">Rostedt Tutorial</a>, I had following problems when using: 
```bash
sudo trace-cmd record -e kvm:kvm_entry -e kvm:kvm_exit -A @3:823 --name Salamander4 -e all
```
### Problem 1  
"Failed to negotiate timestamps synchronization with the host"
[timestamp_error.png](../resources/images/trace-cmd/timestamp_error.png)

### Problem 2
"Cannot find host / guest tracing into the loaded streams" [kvm_combo_error.png](../resources/images/trace-cmd/kvm_combo_error.png)

### Solution
The problem was the trace-cmd version. Set both host and guest to v3.2.0 by copying the files from host to guest:
```bash
scp /usr/local/bin/trace-cmd root@"$ip_address":/usr/bin
scp /usr/local/lib64/libtracefs.so.1 root@"$ip_address":/lib64
scp /usr/local/lib64/libtraceevent.so.1 root@"$ip_address":/lib64
```
Now, [trace-cmd version 3.2.0](../resources/images/trace-cmd/trace-cmd_version3.2.0.png) is active and [tracing the guest](../resources/images/trace-cmd/time_sync.png) finally works with `trace-cmd agent` on the guest.

Using kernelshark with `kernelshark trace.dat -a trace-Salamander4.dat` or simply [`./start_kernelshark.sh`](../sigmatek/trace-cmd/analysis/taskset/start_kernelshark.sh), we get the expected [visualization](../resources/images/trace-cmd/kernelshark/kernelshark_combo.png). Events of the guest happen between kvm_entry and kvm_exit of the host.



## bcc
### Problem 1
Unable to find clang libraries
```bash
sigma_ibo@sigma-ibo:~/Desktop/latency/bcc/build$ cmake ..
-- Latest recognized Git tag is v0.30.0
-- Git HEAD is 6a5602cef2ebd97c351554d53a4f95532db6a568
-- Revision is 0.30.0+6a5602ce (major 0, minor 30, patch 0)
-- Kernel release: 6.5.0-26-generic
-- Kernel headers: /usr/src/linux-headers-6.5.0-26-generic
-- Found LLVM: /usr/lib/llvm-14/include 14.0.0 (Use LLVM_ROOT envronment variable for another version of LLVM)
CMake Error at CMakeLists.txt:173 (message):
  Unable to find clang libraries


-- Configuring incomplete, errors occurred!
See also "/home/sigma_ibo/Desktop/latency/bcc/CMakeFiles/CMakeOutput.log".
```

### Solution 1
```bash
sudo apt install libclang-dev
```
[Source](https://askubuntu.com/questions/1220739/llvm-dev-package-missing-libclangbasic)


### Problem 2
It seems that the library is trying to access the symbol bpf_module_create_b in the shared library libbcc.so.0, but it can’t find it.
```bash
root@sigma-ibo:/usr/share/bcc/tools# sudo ./kvmexit
Traceback (most recent call last):
  File "/usr/share/bcc/tools/./kvmexit", line 32, in <module>
    from bcc import BPF
  File "/usr/lib/python3/dist-packages/bcc/__init__.py", line 27, in <module>
    from .libbcc import lib, bcc_symbol, bcc_symbol_option, bcc_stacktrace_build_id, _SYM_CB_TYPE
  File "/usr/lib/python3/dist-packages/bcc/libbcc.py", line 20, in <module>
    lib.bpf_module_create_b.restype = ct.c_void_p
  File "/usr/lib/python3.10/ctypes/__init__.py", line 387, in __getattr__
    func = self.__getitem__(name)
  File "/usr/lib/python3.10/ctypes/__init__.py", line 392, in __getitem__
    func = self._FuncPtr((name_or_ordinal, self))
AttributeError: /lib/x86_64-linux-gnu/libbcc.so.0: undefined symbol: bpf_module_create_b
```

### Solution 2
```bash
sudo rm -fr /usr/lib/python3/dist-packages/bcc
cd /usr/share/bcc/tools && sudo ./kvmexit
```
[Source](https://github.com/iovisor/bcc/issues/4583)

## QEMU
### Problem
```bash
$ sudo ./qemu_def.sh 
failed to parse default acl file `/etc/qemu/bridge.conf'
qemu-system-x86_64: -netdev bridge,id=e1000,br=nm-bridge: bridge helper failed
```

### Solution
```bash
sudo mkdir /etc/qemu && cd /etc/qemu 
echo "allow nm-bridge" | sudo tee bridge.conf > /dev/null
```

## Kernel Patch
### Problem 1
Fully Preemptible Kernel (RT) not showing up in [menuconfig](../sigmatek/latency_reduction/kernel-patch/no_fully_rt.png)  

### Solution 1
1) Run `make mrproper`  
2) Then run `make menuconfig`  

This is the [output](../sigmatek/latency_reduction/kernel-patch/fully_rt.png)  
[Source](https://unix.stackexchange.com/questions/616621/real-time-patch-on-linux-5-9-1-does-not-show-fully-preemptible-option-for-arm64)

<hr>
OR 
<hr>

In `arch/Kconfig`, search for the entry: `ARCH_SUPPORTS_RT`. 

Change the entry from

```bash
config ARCH_SUPPORTS_RT
    bool
```
to
```bash
config ARCH_SUPPORTS_RT
    def_bool y
```
When you now also have the `EXPERT` (General Setup -> Embedded System) flag enabled you should see the option `Fully Preemptible Kernel (Real-Time)` under General Setup -> Preemption Model.

[Source](https://unix.stackexchange.com/questions/582075/trouble-selecting-fully-preemptible-kernel-real-time-when-configuring-compil
)



### Problem 2
No rule to make target 'debian/canonical-certs.pem'

### Solution 2
If you get the certificate error, execute the following in the root of the kernel source
```bash
scripts/config --disable SYSTEM_TRUSTED_KEYS
scripts/config --disable SYSTEM_REVOCATION_KEYS
```
Then run make again and it should work!  
[Source](https://stackoverflow.com/questions/67670169/compiling-kernel-gives-error-no-rule-to-make-target-debian-certs-debian-uefi-ce)

## 