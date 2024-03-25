#!/usr/bin/env bash
GIT=https://git.sigmatek.at/SIG_SW_BS/salamander/yocto4/salamander.git
set -e

#sudo locale-gen en_US.UTF-8
#sudo update-locale
sudo apt install lz4 git diffstat screen bzip2 cpp g++ gcc make rpcsvc-proto zstd chrpath python3-full patchelf -y
#wait

git config --global credential.helper store
[ -d salamander4 ] || git clone --recurse-submodules -j99 --shallow-submodules $GIT salamander4
cd salamander4
git submodule sync --recursive meta-* poky
git submodule update --recursive meta-* poky
for REPO in $(echo meta-sigmatek)
do
	echo update submodule $REPO
	cd $REPO
	git fetch --no-tags --progress -- git@git.sigmatek.at:SIG_SW_BS/salamander/yocto4/$REPO.git +refs/heads/*:refs/remotes/origin/*
	git checkout -f $(git rev-parse refs/remotes/origin/master^{commit})
	cd ..
done

DISTROS=( #"gecko-imx8mm" #ok
	  #"salamander-imx8mm" #gecko-image.bb: No IMAGE_CMD defined for IMAGE_FSTYPES entry 'lbi' - possibly invalid type name or missing support class
	  #"salamander-imx6" #TUNE_ARCH is unset. Please ensure your MACHINE configuration includes a valid tune configuration file which will set this correctly.
	  #"gecko-core2" #ok
	  "salamander-core2" #ok
	)

sed -i 's/XZ_MEMLIMIT ?= "50%"/XZ_MEMLIMIT ?= "16GiB"/' poky/meta/conf/bitbake.conf
sed -i 's/SDK_XZ_COMPRESSION_LEVEL ?= \"-9\"/SDK_XZ_COMPRESSION_LEVEL ?= \"-2\"/' poky/meta/classes/populate_sdk_base.bbclass
sed -i 's/2\.2\.x/master/' meta-openembedded/meta-multimedia/recipes-multimedia/fluidsynth/fluidsynth.inc
sed -i 's/source.codeaurora.org\/external\/imx/github.com\/nxp-imx/' meta-freescale/recipes-bsp/imx-atf/imx-atf_2.6.bb \
meta-freescale/dynamic-layers/openembedded-layer/recipes-dpaa/fmc/fmc_git.bb \
meta-freescale/recipes-bsp/boot-format/boot-format_git.bb \
meta-freescale/recipes-bsp/fsl-tlu/fsl-tlu_1.0.0.bb \
meta-freescale/recipes-bsp/imx-lib/imx-lib_git.bb \
meta-freescale/recipes-bsp/imx-test/imx-test_git.bb \
meta-freescale/recipes-bsp/mc-utils/mc-utils_git.bb \
meta-freescale/recipes-bsp/rcw/rcw_git.bb \
meta-freescale/recipes-bsp/u-boot/u-boot-qoriq_2021.04.bb \
meta-freescale/recipes-devtools/qemu/qemu-qoriq_4.2.bb \
meta-freescale/recipes-devtools/qoriq-cst/qoriq-cst_git.bb \
meta-freescale/recipes-dpaa/eth-config/eth-config_git.bb \
meta-freescale/recipes-dpaa/flib/flib_git.bb \
meta-freescale/recipes-dpaa/fmlib/fmlib_git.bb \
meta-freescale/recipes-dpaa2/aiopsl/aiopsl_git.bb \
meta-freescale/recipes-dpaa2/dce/dce_git.bb \
meta-freescale/recipes-dpaa2/dce/dce_git.bb \
meta-freescale/recipes-dpaa2/gpp-aioptool/gpp-aioptool_git.bb \
meta-freescale/recipes-dpaa2/restool/restool_git.bb \
meta-freescale/recipes-dpaa2/spc/spc_git.bb \
meta-freescale/recipes-extended/dpdk/dpdk_19.11-20.12.bb \
meta-freescale/recipes-extended/ipc-ust/ipc-ust_git.bb \
meta-freescale/recipes-extended/jailhouse/jailhouse_0.12.bb \
meta-freescale/recipes-extended/libpkcs11/libpkcs11_git.bb \
meta-freescale/recipes-extended/ofp/ofp_git.bb \
meta-freescale/recipes-extended/ovs-dpdk/ovs-dpdk_2.15.bb \
meta-freescale/recipes-extended/skmm-ep/skmm-ep_git.bb \
meta-freescale/recipes-extended/tsntool/tsntool_git.bb \
meta-freescale/recipes-graphics/drm/libdrm_2.4.109.imx.bb \
meta-freescale/recipes-graphics/imx-gpu-apitrace/imx-gpu-apitrace_10.0.0.bb \
meta-freescale/recipes-graphics/wayland/wayland-protocols_1.25.imx.bb \
meta-freescale/recipes-graphics/wayland/weston_9.0.0.imx.bb \
meta-freescale/recipes-kernel/ceetm/ceetm_git.bb \
meta-freescale/recipes-kernel/kernel-modules/kernel-module-ar_git.bb \
meta-freescale/recipes-kernel/kernel-modules/kernel-module-imx-gpu-viv_6.4.3.p4.0.bb \
meta-freescale/recipes-kernel/kernel-modules/kernel-module-isp-vvcam_4.2.2.16.0.bb \
meta-freescale/recipes-kernel/kernel-modules/kernel-module-ls-debug_git.bb \
meta-freescale/recipes-kernel/kernel-modules/kernel-module-nxp89xx_git.bb \
meta-freescale/recipes-kernel/kernel-modules/kernel-module-perf-qoriq_0.8.2.bb \
meta-freescale/recipes-kernel/kernel-modules/kernel-module-scatter-gather_git.bb \
meta-freescale/recipes-kernel/kernel-modules/kernel-module-uio-seville_0.1.bb \
meta-freescale/recipes-kernel/linux/linux-imx-headers_5.15.bb \
meta-freescale/recipes-kernel/linux/linux-qoriq_5.10.bb \
meta-freescale/recipes-kernel/skmm-host/skmm-host_git.bb \
meta-freescale/recipes-multimedia/alsa/imx-alsa-plugins_git.bb \
meta-freescale/recipes-multimedia/gstreamer/gstreamer1.0-plugins-bad_1.18.5.imx.bb \
meta-freescale/recipes-multimedia/gstreamer/gstreamer1.0-plugins-base_1.18.5.imx.bb \
meta-freescale/recipes-multimedia/gstreamer/gstreamer1.0-plugins-good_1.18.5.imx.bb \
meta-freescale/recipes-multimedia/gstreamer/gstreamer1.0_1.18.5.imx.bb \
meta-freescale/recipes-multimedia/gstreamer/imx-gst1.0-plugin_4.6.4.bb \
meta-freescale/recipes-security/optee-imx/optee-client_3.15.0.imx.bb \
meta-freescale/recipes-security/optee-imx/optee-os_3.15.0.imx.bb \
meta-freescale/recipes-security/optee-imx/optee-test_3.15.0.imx.bb \
meta-freescale/recipes-support/opencv/opencv_4.5.2.imx.bb \
meta-sigmatek/recipes-bsp/imx-atf/imx-atf_%.bbappend
sed -i 's/LICENSE_FLAGS_WHITELIST/LICENSE_FLAGS_ACCEPTED/' \
	meta-sigmatek/conf/machine/sigmatek-imx6.conf
mkdir -p gecko-imx8mm/build/tmp/work/cortexa53-crypto-sigmatek-linux/libgcc-initial/11.2.0-r0/gcc-11.2.0/build.aarch64-sigmatek-linux.aarch64-sigmatek-linux/libgcc
sed -i 's/^bitbake \$/bitbake cargo-native\nbitbake clang\nbitbake -k \$/' build.sh


mkdir -p $HOME/yocto/dl $HOME/yocto/sstate $HOME/yocto/ccache $HOME/yocto/cache
echo $(pwd)
[ -L dl-dir ] || ln -s $HOME/yocto/dl dl-dir
[ -L sstate-cache ] || ln -s $HOME/yocto/sstate sstate-cache
[ -L ccache ] || ln -s $HOME/yocto/ccache ccache
[ -L cache ] || ln -s $HOME/yocto/cache cache
#mkdir -p sstate-cache dl-dir ccache cache
#mount | grep salamander4/sstate-cache || sudo mount -t cifs //osbuild.sigmatek.at/sstate sstate-cache -o rsize=8388608,wsize=8388608,bsize=8388608,fsc,cache=loose,credentials=$HOME/.smbcredentials,uid=$(id -u),gid=$(id -g)
#mount | grep salamander4/dl-dir || sudo mount -t cifs //osbuild.sigmatek.at/dl-dir dl-dir -o credentials=$HOME/.smbcredentials,uid=$(id -u),gid=$(id -g)
#mount | grep salamander4/ccache || sudo mount -t cifs //osbuild.sigmatek.at/yocto-ccache ccache -o rsize=8388608,wsize=8388608,bsize=8388608,fsc,cache=loose,credentials=$HOME/.smbcredentials,uid=$(id -u),gid=$(id -g)
#mount | grep salamander4/cache || sudo mount -t cifs //osbuild.sigmatek.at/yocto-persistent cache -o rsize=8388608,wsize=8388608,bsize=8388608,fsc,cache=loose,credentials=$HOME/.smbcredentials,uid=$(id -u),gid=$(id -g)
cd sstate-cache
DIR_SSTATE="$(pwd)"
cd ..
cd dl-dir
DIR_DL="$(pwd)"
cd ..
cd ccache
DIR_CCACHE="$(pwd)"
cd ..
cd cache
DIR_PERSISTENT="$(pwd)"
cd ..

cat <<EOF | tee -a buildconfs/default.conf

BB_NUMBER_THREADS = "20"
PARALLEL_MAKE = "-j20"
PARALLEL_MAKEINST = "-j20"

INHERIT += "buildstats-summary"

INHERIT += "icecc"
ICECC_PARALLEL_MAKE = "-j 88"
ICECC_CARET_WORKAROUND = "1"
ICECC_DISABLED ??= "0"
ICECC_RECIPE_DISABLE = ""

INHERIT += "ccache"
CCACHE_TOP_DIR = "$DIR_CCACHE"

DL_DIR ?= "$DIR_DL"
BB_GENERATE_MIRROR_TARBALLS = "1"

BB_HASHSERVE = "auto"
BB_SIGNATURE_HANDLER = "OEEquivHash"
#BB_HASHSERVE_UPSTREAM = "hashserv.yocto.io:8687"

SSTATE_DIR ?= "$DIR_SSTATE"
#SSTATE_MIRRORS ?= "file://.* http://sstate.yoctoproject.org/2.0.0/PATH;downloadfilename=PATH"
#SSTATE_MIRRORS ?= "file://.* http://sstate.yoctoproject.org/PATH;downloadfilename=PATH"
#SSTATE_MIRRORS ?= "file://.* https://sstate.yoctoproject.org/all/PATH;downloadfilename=PATH"

PERSISTENT_DIR ?= "$DIR_PERSISTENT"

DISTRO_FEATURES:remove = "ptest"
EOF

cat <<EOF > meta-virtualization/recipes-core/meta/container-dummy-provides.bb
DUMMYARCH = "container-dummy-provides"
DUMMYPROVIDES = "\
   /bin/sh \
   /usr/bin/env \
"
LICENSE = "MIT"
EOF

for DIST in ${DISTROS[@]}
do
	#if [ "" = "$(pidof duperemove)" ]; then
	#	( duperemove -dr --hashfile=../../build.hashfile -b 1048576 .. 2>&1 | tail -n100 || true ) &
	#fi

	NAME=$(echo $DIST | cut -d- -f1)
	MACHINE=$(echo $DIST | cut -d- -f2)

	echo $NAME on $MACHINE
	mkdir -p $DIST
	cd $DIST
	export SIGMATEK_LRT_BRANCH=refs/heads/master
	export SIGMATEK_KENNEL_BRANCH=refs/heads/master
	export SIGMATEK_LBIMAKER_BRANCH=refs/heads/master
	export SIGMATEK_DATASERVICE_BRANCH=refs/heads/master
	export SIGMATEK_HMI_CONFIG_FRONTEND_BRANCH=main
	export ICECC_CARET_WORKAROUND=1
	if [ "fast" = "$1" ]; then
		PREFIX="screen -dmS $NAME-on-$MACHINE"
	else
		PREFIX=""
	fi
	$PREFIX time ../build.sh -b build -t T -v 09.07.109 -n 1604 -d $NAME -m sigmatek-$MACHINE -s -g 1
	cd ..
	if [ "fast" = "$1" ]; then
                echo launched screen $NAME-on-$MACHINE
        else
		#rm -Rf */build/tmp/
	        if [ "" = "$(pidof fstrim)" ]; then
			sudo fstrim -v ..
	        fi
	fi
done
