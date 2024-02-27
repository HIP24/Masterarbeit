## qemu_def.sh
```
cd /home/sigma_ibo/Develop/Yocto_local/salamander/salamander-core2/build/tmp/deploy/qemu/sigmatek-core2/salamander-image
```

## bitbake
```
cd /home/sigma_ibo/Develop/Yocto_local/salamander/salamander-core2
../init.sh -b build -m sigmatek-core2 -d salamander
bitbake salamander-image -k
```

## trace-cmd analysis
```
cd /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/analysis/
```