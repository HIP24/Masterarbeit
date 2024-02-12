1) Install Ubuntu 22.04.3 LTS
2) Run [script](scripts/build-salamander4-ordinary.sh) or download [salamander4.tar.xz](scripts/salamaner4.tar.xz) from Michi  
3) If latter, run tar -xvf salamaner4.tar.xz
4) Test QEMU 
    - git clone git@git.sigmatek.at:SIG_SW_BS/devops/qemutest.git
    - cd qemutest
    - ./test_qemu_image.sh -b ../salamander4/salamander-core2/build
5) Boot Salamander 4
    - cd ~/Develop/Yocto/salamander4/salamander-core2/build/tmp/deploy/qemu/sigmatek-core2/salamander-image
    - ./qemu_def.sh