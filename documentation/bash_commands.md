# Essential packages
sudo apt install gcc g++ libelf-dev libssl-dev make pkg-config gawk wget git diffstat unzip texinfo gcc build-essential chrpath socat cpio python3 python3-pip python3-pexpect xz-utils debianutils iputils-ping python3-git python3-jinja2 libegl1-mesa libsdl1.2-dev python3-subunit mesa-common-dev zstd liblz4-tool file locales libacl1

# Fetch script for yocto
chmod +x fetchsdk.sh  
./fetchsdk.sh -h  
./fetchsdk.sh Salamander4_sigmatek-core2  
chmod +x sigmatek-salamander-glibc-x86_64-salamander-image-core2-64-toolchain-09.07.119_T1701.sh  
./sigmatek-salamander-glibc-x86_64-salamander-image-core2-64-toolchain-09.07.119_T1701.sh  

Each time you wish to use the SDK in a new shell session, you need to source the environment setup script e.g.  
. /opt/salamander/sigmatek-core2/09.07.119_T1701/environment-setup-core2-64-sigmatek-linux  
. /opt/salamander/sigmatek-core2/09.07.119_T1701/environment-setup-x86-sigmatekmllib32-linux  

# Mount storage
sudo blkid  
sudo nano /etc/fstab  
sudo mount -a  
sudo chown -R sigma_ibo /home/sigma_ibo/Develop  
df -h ~/Develop  

# Setup
mkdir ~/Develop  
mkdir ~/Develop/docker  
mkdir ~/Develop/jenkins  
mkdir ~/Develop/jenkins/home  
cd ~/Develop/jenkins/home  
ssh-keygen -t ed25519 -C "halil.pamuk@sigmatek.at"  
cat ~/.ssh/id_ed25519.pub  
ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAINJ1I5EULqfk9w3uyyWgkWZmrLur+0v6mOEWk2c6GblE halil.pamuk@sigmatek.at  
git clone git@git.sigmatek.at:SIG_SW_BS/salamander/LRT.git  
git clone git@git.sigmatek.at:SIG_SW_BS/salamander/SalamanderTools.git  
git clone git@git.sigmatek.at:SIG_SW_BS/salamander/u-boot.git  
mkdir kernel  && cd kernel
git clone git@git.sigmatek.at:SIG_SW_BS/salamander/ipipe.git  
git clone git@git.sigmatek.at:SIG_SW_BS/salamander/xenomai  

# Yocto example
<a href="https://learn.arm.com/learning-paths/embedded-systems/yocto_qemu/yocto_build/" target="_blank">Minimal Yocto Linux image</a>

# Salamander 4 with yocto
git clone --recurse-submodules git@git.sigmatek.at:SIG_SW_BS/salamander/yocto4/salamander.git  
cd Develop/jenkins/home/salamander/  
mkdir core2  
cd core2  
../init.sh -b build -m sigmatek-core2 -d salamander  
bitbake salamander-image -k  

# Desktop folders not visible
sudo apt install ubuntu-desktop