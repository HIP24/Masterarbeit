. /opt/salamander/sigmatek-core2/09.07.120_RC2/environment-setup-x86-sigmatekmllib32-linux
git clone --depth=1 https://source.denx.de/Xenomai/xenomai.git
cd xenomai/
autoreconf -vif
./configure
cd testsuite/latency
make -j8
cd .libs
file latency 
scp latency root@192.168.1.37:/home/root/latency