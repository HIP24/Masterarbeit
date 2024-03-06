# Build LRT - Salamander 3 Terminal

## Set SDK
```
. /opt/poky/1.6.2/environment-setup-cortexa9-vfp-neon-poky-linux-gnueabi 
```


## Open 2 terminals

### Terminal 1: SSH Remote Connection

1. Connect to terminal device with `ssh -oHostKeyAlgorithms=+ssh-rsa root@10.10.116.13`
2. Stop init.d with `/etc/init.d/lrt stop` or `killall -9 LRT*`
3. Do Terminal 2
4. Start init.d with `/etc/init.d/lrt start` or `./LRTConfig.exe`

### Terminal 2: Code, make and scp

1. Navigate to  `~/Develop/jenkins/home/LRT`.
2. Open VS Code with  `. code` and edit LRT
3. Run `make` when finished
4. Copy contents to terminal device after stopping init.d with `scp -oHostKeyAlgorithms=+ssh-rsa build-Linux-arm-S3.meson/*/LRT*.exe root@10.10.116.13:`


## Sigmatek Documentation

<!-- [Build LRT](http://swrtd01.lhau.sigaut.org:8000/docs/rtfm/en/latest/getting_started_at_sigmatek/build_lrt.html#build-lrt-label)-->
<a href="http://swrtd01.lhau.sigaut.org:8000/docs/rtfm/en/latest/getting_started_at_sigmatek/build_lrt.html#build-lrt-label" target="_blank">Build LRT</a>