# Build with Yocto

## Clone the repo
The first step is to clone the yocto4/salamander git repo: NOTE: In order to clone all dependent repositories, clone the repo with –recurse-submodules.
```
git clone --recurse-submodules git@git.sigmatek.at:SIG_SW_BS/salamander/yocto4/salamander.git
```

## Initialize
Now you should be left with a subdirectory called salamander.

Note: It is a good idea to do the actual build inside a subdirectory named after the specific architecture (e.g. aarch64). This way the directory structure can be used for multible builds without losing track of the overall picture.
```
cd salamander
mkdir core2 && cd core2
```

Next we need to initialize the build environment by calling the init.sh script. Example for Salamander:
```
../init.sh -b build -m sigmatek-core2 -d salamander
```
Call the init.sh script without parameters to get a full list of options, like how to build Salamander. You can get a full list of options by calling the script without any parameters. There is also stated what to put after -m option for building an arm version. The -b option defines the build output directory (which will be created by the script if it does not exist).

## Build image
Now you can run bitbake for building a gecko-image or salamander-image:

To continue the build after an error, start bitbake with -k or –continue.
```
bitbake salamander-image -k
```
This process can take up to several hours. So you better are not in a hurry.

Afterwards you will find a .lbi-file in the deploy-subdir `~/Develop/jenkins/home/buildwithyocto/salamander/core2/build/tmp/deploy/resources/images/sigmatek-core2/`

Hopefully everything goes according to plan. If you encounter a build problem and you punch through it, please write some trouble shooting for this ;-)


## Sigmatek Documentation

<!-- [Build LRT](http://swrtd01.lhau.sigaut.org:8000/docs/rtfm/en/latest/getting_started_at_sigmatek/build_lrt.html#build-lrt-label)-->
<a href="http://swrtd01.lhau.sigaut.org:8000/docs/rtfm/en/latest/getting_started_at_sigmatek/build_yocto.html" target="_blank">Build with Yocto</a>