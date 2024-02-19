##  Dual Boot
1) Flash SSD by install https://etcher.balena.io/ 
2) Ubuntu and Windows on same machine

## Install Salamander4 OS
1) Install Ubuntu 22.04.3 LTS
2) Run [script](resources/scripts/build-salamander4-ordinary.sh.txt) or download [salamander4.tar.xz](resources/scripts/salamaner4.tar.xz) from Michi  
3) If latter, run tar -xvf salamaner4.tar.xz
4) Test QEMU 
    - git clone git@git.sigmatek.at:SIG_SW_BS/devops/qemutest.git
    - `cd qemutest`
    - `./test_qemu_image.sh -b ../salamander4/salamander-core2/build`
    - [QEMU testing boot](resources/images/install_salamander/qemutest_testing-boot.png)
    - [QEMU testing shutdown](resources/images/install_salamander/qemutest_testing-shutdown.png)
5) Boot Salamander 4
    - `cd ~/Develop/Yocto/salamander4/salamander-core2/build/tmp/deploy/qemu/sigmatek-core2/salamander-image`
    - [`./qemu_def.sh`](resources/scripts/working_qemu_def.sh.txt)
    - [Welcome at Sigmatek PLC](resources/images/install_salamander/sigmatek_login.png)

## Configure ip addresses 
[Configure PC](resources/images/configure_ip/ip_static_connection_ubuntu.png) to `10.10.1.1`.   
[Salamander Gateway](resources/images/ip_list_ubuntu.png) set to `10.10.1.229`

## SSH to device
Connect to device with `ssh -oHostKeyAlgorithms=+ssh-rsa root@10.10.1.229`  
or `ssh -p 22 root@192.168.1.x` (changes often)

## LasalClass2 to device
Connect LasalClass2 with [Salamander 4](resources/images/lasal/class2/lasalclass2_ip.png), IP of [Salamander4 device](resources/images/lasal/class2/lasalclass2_salamander4_ip.png)

## Configure bridge for qemu
- Disable [ipv4](resources/images/configure_bridge/ethernet_disable_ip4.png) and [ipv6](resources/images/configure_bridge/ethernet_disable_ip6.png)
- Enter [nmtui](resources/images/configure_bridge/nmtui.png)
- Edit Connection and [\<Add\>](resources/images/add_connection.png). Select Bridge.
- [Edit](resources/images/configure_bridge/edit_connection.png) and \<Add\> Ethernet.
- [Copy name](resources/images/configure_bridge/copy_name.png) enx4cd717733f80 (4C:D7:17:73:3F:80) of Wired connection 2
- [Edit Connection of Ethernet connection 1](resources/images/configure_bridge/ethernet1.png) so that it automatically connects.
- [Activate Connection](resources/images/configure_bridge/activate_connection.png) .


## Use the Xenomai test suite
