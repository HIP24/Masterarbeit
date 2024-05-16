# Linux kernel patch

[The Linux Kernel Archives](https://www.kernel.org/)  

See all kernels on system
```bash
dpkg --get-selections | grep linux-image
```
Remove unused kernel
```bash
sudo apt remove --purge linux-image-<uname-r>
sudo apt-get purge linux-image-<uname-r>
```

Kernel Basic  
- ✅ [Kernel Basics](https://www.youtube.com/watch?v=rTcnTOXf_jM)  
- ✅ [How to remove an old Linux kernel](https://www.youtube.com/watch?v=KIk0GqtzDsc)  
- ✅ [How to Remove Old Kernel in Kali Linux](https://www.youtube.com/watch?v=wOgxZG1imCA)  

Real-time kernel  
- ✅ [Introduction to Realtime Linux](https://www.youtube.com/watch?v=BKkX9WASfpI&list=PLmDQKQxAsgbak5aWa6WDKPvZeLcRKTUDE)  
- ✅ [An introduction to real-time Linux](https://www.youtube.com/watch?v=-wAo6bWh4jM)  
- ✅ [Kernel Recipes 2016 - Understanding a Real-Time System Steven Rostedt](https://www.youtube.com/watch?v=w3yT8zJe0Uw&list=PLwTK7uwfVP9cINa54L2ID3DNLv29RwdnU)  
- ✅ [Ubuntu Pro Realtime Kernel Performance Comparison (2023)](https://www.youtube.com/watch?v=sUDMG6ey9d0)  
- [2. Kernel Configuration - Building a Custom Linux Kernel](https://www.youtube.com/watch?v=T5SZERvLriA)  
- [A Checklist for Writing Linux Real-Time Applications](https://www.youtube.com/watch?v=NrjXEaTSyrw)
- [Finding Sources of Latency on your Linux System - Steven Rostedt, VMware](https://www.youtube.com/watch?v=Tkra8g0gXAU)

Patch  
- ✅ [Applying the Realtime patch to the Linux kernel](https://www.youtube.com/watch?v=RSfMxKuyB7Ihttps://www.youtube.com/watch?v=RSfMxKuyB7I)  
- [Tuning a real-time kernel](https://ubuntu.com/blog/real-time-kernel-tuning)  


## Kernel Patch Proceedure
Download [Linux kernel and patch](https://mirrors.edge.kernel.org/pub/linux/kernel/)  
Gunzip the patch
```bash
gunzip patch-*
```
Patch the kernel source code
```bash
patch -R -p1 < ../patch-*
```  
Customize the configuration
```bash
sudo make menuconfig
```
Compile the kernel by using multiple cores. $(nproc) returns the number of processing units available. 
```bash
make -j$(nproc)
```
Install the kernel and its modules to the appropriate system directories.
```bash
sudo make modules_install install 
```
Update the bootloader
```bash
sudo update-grub
```
Reboot the system
```bash
sudo reboot 
```
This is the output 
```bash
$ uname -a
Linux pamhal 6.8.0-rt7 #1 SMP PREEMPT_RT Mon Mar 11 13:12:31 CET 2024 x86_64 x86_64 x86_64 GNU/Linux
```

## Useful stuff
[qemu-optimization](https://null-src.com/posts/qemu-optimization/post.php)  