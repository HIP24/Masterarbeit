Installing BCC from source:

1. **Install the necessary dependencies**:
```bash
sudo apt-get install -y git bison cmake flex libedit-dev \
  libllvm6.0 llvm-6.0-dev libclang-6.0-dev python zlib1g-dev libelf-dev
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
