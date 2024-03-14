# Linux kernel patch

[The Linux Kernel Archives](https://www.kernel.org/)  
Youtube: [Applying the Realtime patch to the Linux kernel](https://www.youtube.com/watch?v=RSfMxKuyB7Ihttps://www.youtube.com/watch?v=RSfMxKuyB7I)  

## Proceedure
Download [Linux kernel and patch](https://mirrors.edge.kernel.org/pub/linux/kernel/)  
Gunzip the patch
```
gunzip patch-*
```
Patch the kernel source code
```
patch -p1 < ../../rt_linux/patch-*
```  
Customize the configuration
```
sudo make menuconfig
```
Compile the kernel by using multiple cores. $(nproc) returns the number of processing units available. 
```
make -j$(nproc)
```
Install the kernel and its modules to the appropriate system directories.
```
sudo make modules_install install 
```
Update the bootloader
```
sudo update-grub
```
Reboot the system
```
sudo reboot 
```
This is the output 
```
$ uname -a
Linux pamhal 6.8.0-rt7 #1 SMP PREEMPT_RT Mon Mar 11 13:12:31 CET 2024 x86_64 x86_64 x86_64 GNU/Linux
```

## Troubleshooting
### Problem 1
Fully Preemptible Kernel (RT) not showing up in [menuconfig](no_fully_rt.png)  
### Solution 1
1) Run `make mrproper`  
2) Then run `make menuconfig`  

This is the [output](fully_rt.png)  
[Source](https://unix.stackexchange.com/questions/616621/real-time-patch-on-linux-5-9-1-does-not-show-fully-preemptible-option-for-arm64)

<hr>

### Problem 2
No rule to make target 'debian/canonical-certs.pem'
### Solution 2
If you get the certificate error, execute the following in the root of the kernel source
```
scripts/config --disable SYSTEM_TRUSTED_KEYS
scripts/config --disable SYSTEM_REVOCATION_KEYS
```
Then run make again and it should work!  
[Source](https://stackoverflow.com/questions/67670169/compiling-kernel-gives-error-no-rule-to-make-target-debian-certs-debian-uefi-ce)