Installing BCC from source:

1. **Install the necessary dependencies**:
```bash
sudo apt-get install -y bpfcc-tools libbpfcc libbpfcc-dev linux-headers-$(uname -r)
```
```bash
sudo apt install -y zip bison build-essential cmake flex git libedit-dev \
  libllvm14 llvm-14-dev libclang-14-dev python3 zlib1g-dev libelf-dev libfl-dev python3-setuptools \
  liblzma-dev libdebuginfod-dev arping netperf iperf
```


2. **Clone the BCC repository**:
```bash
git clone https://github.com/iovisor/bcc.git
```

3. **Build BCC**:
```bash
mkdir bcc/build && cd bcc/build
cmake ..
make
```

4. **Install BCC**:
```bash
sudo make install
```

5. **Update the shared library cache**:
```bash
sudo ldconfig
```

6. **Run kvmexit**
```bash
cd /usr/share/bcc/tools && sudo ./kvmexit
```
