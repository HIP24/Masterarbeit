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
Execute [virtio-win-guest-tools](../resources/exe/virtio-win-guest-tools.exe) in VM  
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

## Untrack files to be ignored named “documentation/test” in git:
`git rm --cached documentation/test`  
<a href="https://kinsta.com/knowledgebase/gitignore-not-working/" target="_blank">How To Fix Gitignore Not Working</a>

## Remove a commit but keep the changes in your working directory
git reset --soft HEAD~1

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

## Thread priorities
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
