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
- File: [startup.sh](resources/scripts/startup.sh) 
- Configure [Startup Apps](resources/images/startup/startup_apps.png)

## Install gnome
`sudo apt install gnome-shell-extension-ubuntu-dock`

## Desktop folders not visible
`sudo apt install ubuntu-desktop`

## Windows 11 on QEMU and display settings
<a href="https://www.youtube.com/watch?v=0RiUrsljD_E" target="_blank">Install Windows 11 in KVM on Ubuntu 22.04</a>  
Execute [virtio-win-guest-tools](resources/exe/virtio-win-guest-tools.exe) in VM  
<a href="https://techglimpse.com/windows-10-virtual-machine-shows-100-percentage-cpu-utilization-qemu-kvm/" target="_blank">Windows 10 VM shows 100% CPU</a>  
QEMU settings: <a href="resources/images/qemu/qemu_settings.png" target="_blank">QEMU</a>, <a href="resources/xml/win11onQEMU.xml" target="_blank">XML win11</a>  
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


## ssh ohne Passwort
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