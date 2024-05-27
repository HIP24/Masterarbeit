# Useful Stuff

## Symbolic Link to Windows Folder
`ln -s /media/sigma_ibo/Windows/Dokumente\ und\ Einstellungen/Pamibr/Desktop/Masterarbeit/ /home/sigma_ibo/Desktop/`  
<a href="https://www.howtogeek.com/287014/how-to-create-and-use-symbolic-links-aka-symlinks-on-linux/" target="_blank">Symbolic Link to Windows Folder</a>


## Mount Windows partition Desktop
- `sudo nano /etc/fstab`  
- At the end of the file, add: UUID=0E58A36658A34B73 /home/sigma_ibo/Desktop ntfs defaults 0 0, it looks like 
<a href="../resources/images/useful/mount_windows.png" target="_blank">this</a>  
- reboot

## How to Extract (Unzip) tar.xz File
<a href="https://linuxize.com/post/how-to-extract-unzip-tar-xz-file/" target="_blank">How to Extract (Unzip) tar.xz File</a>

## Launch programs after startup
- `nano /home/sigma_ibo/startup.sh`
- `chmod +x /home/sigma_ibo/startup.sh`
- File: [startup.sh](../resources/scripts/startup_konsole.sh) 
- Configure [Startup Apps](../resources/images/startup/startup_apps.png)

## Install gnome
`sudo apt install gnome-shell-extension-ubuntu-dock`

## Desktop folders not visible
`sudo apt install ubuntu-desktop`

## Windows 11 on QEMU and display settings
<a href="https://www.youtube.com/watch?v=0RiUrsljD_E" target="_blank">Install Windows 11 in KVM on Ubuntu 22.04</a>  
Execute virtio-win-guest-tools in VM  
<a href="https://techglimpse.com/windows-10-virtual-machine-shows-100-percentage-cpu-utilization-qemu-kvm/" target="_blank">Windows 10 VM shows 100% CPU</a>  
QEMU settings: <a href="../resources/images/qemu/qemu_settings.png" target="_blank">QEMU</a>, <a href="../resources/xml/win11onQEMU.xml" target="_blank">XML win11</a>  
<a href="https://www.youtube.com/watch?v=ZqBJzrQy7Do" target="_blank">Windows 10 VM Settings</a>

## Remove keyring from Edge
To stop being prompted to unlock the ‘default’ keyring on boot, set a blank password for the keyring.
- Open the utility “Passwords & Keys”. If not installed: `sudo apt-get install seahorse`  
- Right-click the “Login” folder and select “Change Password”.
- Enter your old password and leave the new password blank.

## See how many cores you have
`nproc` or `cat /proc/cpuinfo | grep processor | wc -l` or `cat /proc/cpuinfo | grep 'core id'` or `lscpu`

## start_qemu.sh from everywhere
Script [start_qemu.sh](../sigmatek/QEMU/start_qemu.sh) needs to be in `/home/sigma_ibo/Desktop/Masterarbeit/masterthesis-documentation/QEMU/`. 
```bash
sudo nano ~/.bashrc
export PATH=$PATH:/home/sigma_ibo/Desktop/Masterarbeit/documentation/resources/QEMU/
```

## Add konsole to replace console
<a href="https://github.com/Stunkymonkey/nautilus-open-any-terminal" target="_blank">nautilus-open-any-terminal</a>  
<a href="https://askubuntu.com/questions/1351228/change-default-terminal-with-right-click-option-open-in-terminal-in-file-manag" target="_blank">Change default terminal with right-click option "Open in Terminal" in file manager</a>


## SSH ohne Passwort
Um eine SSH-Verbindung von Ihrem Host-Computer zu Ihrem Gast-Computer (oder Server) herzustellen, können Sie die folgenden Schritte ausführen:

1. **Generieren Sie ein SSH-Schlüsselpaar auf Ihrem Host-Computer**. Sie können dies mit dem Befehl `ssh-keygen` tun. Sie werden aufgefordert, ein Passwort einzugeben, aber Sie können einfach Enter drücken, um kein Passwort zu setzen (obwohl dies aus Sicherheitsgründen nicht empfohlen wird).

```bash
ssh-keygen
```

2. **Kopieren Sie Ihren öffentlichen Schlüssel auf den Gast-Computer**. Sie können dies mit dem Befehl `ssh-copy-id` tun. Ersetzen Sie `benutzername` durch Ihren Benutzernamen auf dem Gast-Computer und `ip_address` durch die IP-Adresse des Gast-Computers.

```bash
ssh-copy-id root@192.168.1.51
```

3. **Stellen Sie eine SSH-Verbindung zum Gast-Computer her**. Sie können dies mit dem Befehl `ssh` tun. Ersetzen Sie wieder `benutzername` und `ip_address` durch Ihren Benutzernamen und die IP-Adresse des Gast-Computers.

```bash
ssh root@192.168.1.51
```

Nachdem Sie diese Schritte ausgeführt haben, sollten Sie in der Lage sein, sich ohne Passwort bei Ihrem Gast-Computer anzumelden. 

Wenn Sie den ssh-copy-id Befehl verwenden, wird Ihr öffentlicher SSH-Schlüssel in der Datei `~/.ssh/authorized_keys` auf dem Gast-Computer (dem Computer, zu dem Sie eine SSH-Verbindung herstellen) gespeichert.

Jede Zeile in dieser Datei repräsentiert einen öffentlichen Schlüssel, der für die Authentifizierung zugelassen ist. Wenn Sie also mehrere Schlüssel haben, die Sie verwenden, um sich bei diesem Computer anzumelden, wird jeder Schlüssel als separate Zeile in dieser Datei angezeigt

## Check on which CPU a task is running
`ps -eo pid,psr,comm | grep <name>`


## Limit WSL2 resources

Edit the WSL config to limit the memory usage as mentioned here.
```bash
#turn off all wsl instances such as docker-desktop
wsl --shutdown
notepad "$env:USERPROFILE/.wslconfig"
```
Set the values you want for CPU core and Memory:

```bash
[wsl2]
memory=3GB   # Limits VM memory in WSL 2 up to 3GB
processors=2 # Makes the WSL 2 VM use two virtual processors
```

## Connect to hardware Salamander 4
ssh root@192.168.1.244

## Boot parameters
cat /proc/cmdline

## Stress the CPUs
stress -c $(nproc)

## Check cpu MAXMHZ, MINMHZ, CURRENT MHZ 
```
$ lscpu --all --extended
CPU NODE SOCKET CORE L1d:L1i:L2:L3 ONLINE    MAXMHZ   MINMHZ      MHZ
  0    0      0    0 0:0:0:0          yes 5000,0000 400,0000 2900.000
  1    0      0    1 4:4:1:0          yes 5000,0000 400,0000 2900.000
  2    0      0    2 8:8:2:0          yes 5200,0000 400,0000 2900.000
  3    0      0    3 12:12:3:0        yes 5200,0000 400,0000 4174.117
  4    0      0    4 16:16:4:0        yes 5000,0000 400,0000 2900.000
  5    0      0    5 20:20:5:0        yes 5000,0000 400,0000 2900.000
  6    0      0    6 24:24:6:0        yes 4000,0000 400,0000 2926.742
  7    0      0    7 25:25:6:0        yes 4000,0000 400,0000 2900.000
  8    0      0    8 26:26:6:0        yes 4000,0000 400,0000 2900.000
  9    0      0    9 27:27:6:0        yes 4000,0000 400,0000 2900.000
 10    0      0   10 28:28:7:0        yes 4000,0000 400,0000 3332.776
 11    0      0   11 29:29:7:0        yes 4000,0000 400,0000 2900.000
 12    0      0   12 30:30:7:0        yes 4000,0000 400,0000 2900.000
 13    0      0   13 31:31:7:0        yes 4000,0000 400,0000 3218.336
```

## See threads of a task
```bash
sigma_ibo@sigma-ibo:~$ ls /proc/464458/task | wc -l
6
sigma_ibo@sigma-ibo:~$ htop -H -p 464458
```

## Thread priorities

[Set / Manipulate Real Time Attributes of a Linux Process](https://www.cyberciti.biz/faq/howto-set-real-time-scheduling-priority-process)  
Full list of all threads on the system with process id, thread id, short name, scheduling policy, nice value and realtime-priority.
ps reports SCHED_DEADLINE as DLN, SCHED_OTHER as TS, SCHED_BATCH as B, SCHED_IDLE as IDL, SCHED_FIFO as FF and SCHED_RR as RR.
```
ps axHo psr,pid,lwp,args,policy,nice,rtprio
```
All the tasks on CPU 13
```
ps axHo psr,pid,lwp,args,policy,nice,rtprio | awk '$1 == 13'
```
All rt processes
```
ps axHo psr,pid,lwp,args,policy,nice,rtprio | grep -P '\s[0-9]+\s*$'
ps axHo psr,pid,lwp,args,policy,nice,rtprio | awk '$NF ~ /^[0-9]+$/' | sort -k4,4 -V > rt_processes.txt
```
Set all threads of a process to a real-time priority
```
ps -T -p $(pgrep -f "qemu-system-x86_64 -M pc,ac") | awk '{print $2}' | tail -n +2 | xargs -I {} sudo chrt -f -p 10 {}
```
Watch it
```
watch -d -c -n 1 "ps axHo psr,pid,lwp,args,policy,nice,rtprio | awk '\$1 == 4'"
```

## Test suite: rt-tests
[An Analysis of the Real-Time Performance of Linux Kernels](https://www.opensourceforu.com/2021/05/an-analysis-of-the-real-time-performance-of-linux-kernels/)
The rt-tests test suite contains programs to test various real-time Linux features; more details are available [here](https://wiki.linuxfoundation.org/realtime/documentation/howto/tools/rt-tests). The step-by-step procedure to install the rt-tests suite from the source is given below.

First, you need to install the libraries:
```
sudo apt-get install build-essential libnuma-dev
```

Next, clone the code and build from the source:
```
git clone git://git.kernel.org/pub/scm/utils/rt-tests/rt-tests.git
cd rt-tests
git checkout stable/v1.0
make all
make install
```

## Useful Not needed

### Add more CPUs to QEMU virtual machine with -smp option 
The -smp option specifies the number of CPUs

Replace n with the number of CPUs you want to add. For example, if you want to add 4 CPUs, you would use -smp cpus=4.

After making these changes, the specified number of CPUs will be available when you boot your Yocto image with this script. 
```bash
exec qemu-system-x86_64 -M pc,accel=kvm -kernel ./bzImage \
-m 2048 -drive file=salamander-image-sigmatek-core2.ext4,format=raw,media=disk \
-append "console=ttyS0 console=tty1 root=/dev/sda rw panic=1 sigmatek_lrt.QEMU=1 ip=dhcp rootfstype=ext4 \
-net nic,model=e1000,netdev=e1000 -netdev bridge,id=e1000,br=nm-bridge \
-fsdev local,security_model=none,id=fsdev0,path=drive-c -device virtio-9p-pci,id=fs0,fsdev=fsdev0,mount_>
-drive if=pflash,format=qcow2,file=ovmf.code.qcow2 \
-smp cpus=n \
-no-reboot -nographic
```
Check with: `cat /sys/devices/system/cpu/online`
```bash
root@sigmatek-core2:~# cat /sys/devices/system/cpu/online
0-9
```

### Isolate CPUs in QEMU with isolcpus
To use isolcpus in a Yocto image, you need to add it to the kernel command line parameters. In your case, these parameters are specified in the -append option in your QEMU command. Add isolcpus=x,y,z. Replace x,y,z with the CPU cores you want to isolate. For example, if you want to isolate cores 0, 1 and 2, you would use isolcpus=0,1,2.
```bash
exec qemu-system-x86_64 -M pc,accel=kvm -kernel ./bzImage \
-m 2048 -drive file=salamander-image-sigmatek-core2.ext4,format=raw,media=disk \
-append "console=ttyS0 console=tty1 root=/dev/sda rw panic=1 sigmatek_lrt.QEMU=1 ip=dhcp rootfstype=ext4 isolcpus=0,1,2" \
-net nic,model=e1000,netdev=e1000 -netdev bridge,id=e1000,br=nm-bridge \
-fsdev local,security_model=none,id=fsdev0,path=drive-c -device virtio-9p-pci,id=fs0,fsdev=fsdev0,mount_>
-drive if=pflash,format=qcow2,file=ovmf.code.qcow2 \
-smp cpus=n \
-no-reboot -nographic
```
Check with: `cat /sys/devices/system/cpu/isolated`
```bash
root@sigmatek-core2:~# cat /sys/devices/system/cpu/isolated
0-2
```

### Gid PID Of processes
Start latency and write output to latency_output.txt:
`latency -T 60 > latency_output.txt 2>&1 &`  
Get ID of xenomai task: `ps aux | grep latency`
```bash
root@sigmatek-core2:~# latency -T 60 > latency_output.txt 2>&1 &
[1] 557
root@sigmatek-core2:~# ps aux | grep latency
root       557  0.0  0.6  14040 12852 ttyS0    SLl  11:34   0:00 latency -T 60
root       563  0.0  0.0   3256  1148 ttyS0    S+   11:34   0:00 grep latency
```

### Assign tasks to the isolated CPUs 
To assign these latency tasks to the isolated CPUs, you can use the taskset command with the process ID (PID) of each latency task. For example, if you want to assign the latency task with PID 536 to CPU 1, you would use:

`taskset -pc x abc`

Remember to replace abc with the actual PID of the latency task. You can repeat this process for each latency task and each isolated CPU.


### Kill processes 
Kill processes with `kill x`


### ^M error message
The error message you're seeing is typically caused by a mismatch in line endings. Scripts that have been edited or created on Windows use a different line ending (`\r\n`) than Unix/Linux (`\n`). The `^M` in the error message is a visual representation of `\r` (carriage return), which is not expected or understood by the Linux shell.

You can convert the line endings of your script to the Unix format using a tool like `dos2unix`. Here's how you can do it:

```bash
sudo apt-get install dos2unix  # Install dos2unix tool
dos2unix <file>
```

### Split too long Prompt
[ChatGPT PROMPTs Splitter](https://chatgpt-prompt-splitter.jjdiaz.dev/)

### Configure ip addresses 
[Configure PC](../resources/images/configure_ip/ip_static_connection_ubuntu.png) to `10.10.1.1`.   
[Salamander Gateway](../resources/images/configure_ip/ip_list_ubuntu.png) set to `10.10.1.229`

### Ubuntu VM on virtual machine manager
After giving the VM [access to the vsocket](../resources/images/protocol/virtm_cid.png), and installing trace-cmd along with dependancies<!--[dependancies](../salamander4/trace-cmd/LTS/trace-cmd-v3.2/README.md)-->, run [`trace-cmd agent`](../resources/images/protocol/trace-cmd_agent.png). Now, the guest is able to negotiate with host about [timestamp synchronization](../resources/images/protocol/negotiated_with_guest.png). After running [`./start_kernelshark.sh`](../sigmatek/trace-cmd/virtualization/taskset/start_kernelshark.sh), we can view [KVM Combo plots](../resources/images/protocol/kvm_combo_plots.png)
