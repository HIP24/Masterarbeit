## Symbolic Link to Windows Folder
`ln -s /media/sigma_ibo/Windows/Dokumente\ und\ Einstellungen/Pamibr/Desktop/Masterarbeit/ /home/sigma_ibo/Desktop/`  
<a href="https://www.howtogeek.com/287014/how-to-create-and-use-symbolic-links-aka-symlinks-on-linux/" target="_blank">Symbolic Link to Windows Folder</a>


## Mount Windows partition Desktop
- `sudo nano /etc/fstab`  
- At the end of the file, add: UUID=0E58A36658A34B73 /home/sigma_ibo/Desktop ntfs defaults 0 0, it looks like 
<a href="resources/images/useful/mount_windows.png" target="_blank">this</a>  
- reboot

## How to Extract (Unzip) tar.xz File
<a href="https://linuxize.com/post/how-to-extract-unzip-tar-xz-file/" target="_blank">How to Extract (Unzip) tar.xz File</a>

## Launch programs after startup
- `nano /home/sigma_ibo/startup.sh`
- `chmod +x /home/sigma_ibo/startup.sh`
- File: [startup.sh](resources/scripts/startup.sh.txt) 
- Configure [Startup Apps](resources/images/startup/startup_apps.png)

## Install gnome
`sudo apt install gnome-shell-extension-ubuntu-dock`

## Desktop folders not visible
`sudo apt install ubuntu-desktop`

## Windows 11 on QEMU and display settings
<a href="https://www.youtube.com/watch?v=0RiUrsljD_E" target="_blank">Install Windows 11 in KVM on Ubuntu 22.04</a>  
Execute [virtio-win-guest-tools](resources/exe/virtio-win-guest-tools.exe) in VM  
<a href="https://techglimpse.com/windows-10-virtual-machine-shows-100-percentage-cpu-utilization-qemu-kvm/" target="_blank">Windows 10 VM shows 100% CPU</a>  
QEMU settings: <a href="resources/images/qemu/qemu_settings.png" target="_blank">QEMU</a>, <a href="resources/xml/win11onQEMU.xml.txt" target="_blank">XML win11</a>  
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

## start_qemu.sh from everytwhere
Script [start_qemu.sh](resources/QEMU/start_qemu.sh) needs to be in `/home/sigma_ibo/Desktop/Masterarbeit/documentation/resources/QEMU/`. 
```
sudo nano ~/.bashrc
export PATH=$PATH:/home/sigma_ibo/Desktop/Masterarbeit/documentation/resources/QEMU/
```
## Add konsole to replace console
[nautilus-open-any-terminal](git%20clone/nautilus-open-any-terminal/)
