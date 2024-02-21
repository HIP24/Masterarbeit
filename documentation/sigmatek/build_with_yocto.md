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


## Tipps
### Using less cores
If you build locally, you may run into the problem that you system is loaded heavily by the yocto build. In fact the load can be so heavy that working with your system on other task can become very slow due to lack of responsiveness.

One solution is to tell yocto to use less threads for the build by adding the following line to ~/some/path/build/conf/local.conf

```
BB_NUMBER_THREADS = "${@oe.utils.cpu_count()//2}"
```
In this example we set the number of threads to half the number of cpu cores on the system. In addition one can also set the number of parallel compilations done by make:
```
PARALLEL_MAKE = "-j${@oe.utils.cpu_count()//2}"
```

### Using jenkins as download mirror
Sometimes it happens that servers that hold repos necessary for builds are down. In this case it is possible to use the jenkins as a download mirror.

For this you simply add the following two lines to one of the config files, e.g. site.conf

```
SOURCE_MIRROR_URL ?= "http://osjenkins.lhau.sigaut.org:8080/userContent/downloads/"
INHERIT += "own-mirrors"
```

## Sigmatek Documentation

<!-- [Build LRT](http://swrtd01.lhau.sigaut.org:8000/docs/rtfm/en/latest/getting_started_at_sigmatek/build_lrt.html#build-lrt-label)-->
<a href="http://swrtd01.lhau.sigaut.org:8000/docs/rtfm/en/latest/getting_started_at_sigmatek/build_yocto.html" target="_blank">Build with Yocto</a>