# Master 
## Overview
| File       | Description |
|------------|-------|
| [BS Virtualisierungsprojekt.xlsx](general/BS Virtualisierungsprojekt.xlsx)   | Masterthesis progress |

## Markdown files
### General
| File       | Description |
|------------|-------|
| [protocol.md](general/protocol.md)   | Protocol of the process |
| [timeline.md](general/timeline.md)   | Timeline view of the process |
| [components.md](general/components.md)   | Components of the process |
| [useful.md](workflow/useful.md)   | Useful stuff in the process |
| [useful_notneeded.md](workflow/useful_notneeded.md)   | Useful stuff that is not needed in the process |
| [most_popular_paths.md](workflow/most_popular_paths.md)   | Most used paths in the process |

<hr>

### Sigmatek 
| File       | Description |
|------------|-------|
| [bash_commands.md](sigmatek/bash_commands.md)   | How to set up for yocto build |
| [build_LRT.md](sigmatek/build_LRT.md)   | How to build LRT - Salamander 3 Terminal |
| [build_with_yocto.md](sigmatek/build_with_yocto.md)  | How to bitbake a yocto salamander-image |

<hr>

### Yocto 
| File       | Description |
|------------|-------|
| [fix.md](salamander4/yocto/fix.md)   | Fix Yocto build 0001.patch |
| [after_bitbake.md](salamander4/yocto/after_bitbake.md)   | Commands after bitbake |

<hr>

### Xenomai
| File       | Description |
|------------|-------|
| [xenomai-system-tools.md](salamander4/xenomai/xenomai-system-tools.md)   | Xenomai System Tools |
| [latency.md](salamander4/xenomai/latency.md)   | Xenomai: latency tool |
| [clocktest.md](salamander4/xenomai/clocktest.md)   | Xenomai: clocktest tool |
| [switchtest.md](salamander4/xenomai/switchtest.md)   | Xenomai: switchtest tool |

<hr>

### trace-cmd and kernelshark
| File       | Description |
|------------|-------|
| [info.md](salamander4/trace-cmd/analysis/info.md)   | Info about trace-cmd |
| [kernelshark.md](salamander4/trace-cmd/analysis/kernelshark.md)   | Kernelshark commands for host and guest |

<hr>

### README 
| File       | Description |
|------------|-------|
| [README.md](README.md)   | README of the masterthesis |
| [README.md](salamander4/trace-cmd/LTS/libtraceevent-1.8.2/README.md)   | README of libtraceevent |
| [README.md](salamander4/trace-cmd/LTS/libtracefs-1.8.0/README.md)   | README of libtracefs |
| [README.md](salamander4/trace-cmd/LTS/trace-cmd-libtracecmd-1.5.1/README.md)   | README of libtracecmd |
| [README.md](salamander4/trace-cmd/LTS/trace-cmd-v3.2/README.md)   | README of trace-cmd |


## Scripts
### Yocto
| File       | Description |
|------------|-------|
| [after_bitbake_1.sh](salamander4/yocto/after_bitbake_1.sh)   | Script after bitbake 1 |
| [after_bitbake_2.sh](salamander4/yocto/after_bitbake_2.sh)   | Script after bitbake 2 |

<hr>

### QEMU config
| File       | Description |
|------------|-------|
| [qemu_def_1default.sh](salamander4/QEMU/qemu_def_1default.sh) | default qemu_def.sh  |
| [qemu_def_2nmbridge.sh](salamander4/QEMU/qemu_def_2nmbridge.sh) | qemu_def.sh with nm bridge  |
| [qemu_def_3vsock.sh](salamander4/QEMU/qemu_def_3vsock.sh) |qemu_def.sh with vsock |
| [qemu_def_4schedstats.sh](salamander4/QEMU/qemu_def_4schedstats.sh) | qemu_def.sh with schedstats  |
| [qemu_def_5taskset.sh](salamander4/QEMU/qemu_def_5taskset.sh) | qemu_def.sh with taskset  |
| [start_qemu.sh](salamander4/QEMU/start_qemu.sh) | Script for starting QEMU |


<hr>




### Resources 
| File       | Description |
|------------|-------|
| [startup_console.sh](resources/scripts/startup_console.sh)   | Startup script for console |
| [startup_konsole.sh](resources/scripts/startup_konsole.sh)   | Startup script for konsole |

<hr>


### trace-cmd and kernelshark
| File       | Description |
|------------|-------|
| [start_kernelshark.sh](salamander4/trace-cmd/analysis/test/start_kernelshark.sh)   | Script for starting kernelshark with host and guest trace.dat |
| [start_kernelshark_convert.sh](salamander4/trace-cmd/analysis/test/start_kernelshark_convert.sh)   | Script for starting kernelshark with converted v6 host and guest trace.dat |

## GIT
### Sigmatek
| File                                       | Description            |
|--------------------------------------------|------------------------|
| <a href="https://git.sigmatek.at/SIG_SW_BS/salamander/LRT" target="_blank">LRT.git</a>                     | LRT.git                |
| <a href="https://git.sigmatek.at/SIG_SW_BS/salamander/SalamanderTools.git" target="_blank">SalamanderTools.git</a> | SalamanderTools.git    |
| <a href="https://git.sigmatek.at/SIG_SW_BS/salamander/u-boot.git" target="_blank">u-boot.git</a>            | u-boot.git             |
| <a href="https://git.sigmatek.at/SIG_SW_BS/salamander/ipipe.git" target="_blank">ipipe.git</a>             | ipipe.git              |
| <a href="https://git.sigmatek.at/SIG_SW_BS/salamander/xenomai" target="_blank">xenomai</a>                | xenomai                |
| <a href="https://git.sigmatek.at/SIG_SW_BS/salamander/yocto4/salamander.git" target="_blank">salamander.git</a>  | salamander.git         |

<hr>

### trace-cmd and kernelshark
| File       | Description |
|------------|-------|
| <a href="https://git.kernel.org/pub/scm/utils/salamander4/trace-cmd/kernel-shark.git/" target="_blank">kernel-shark</a>  | kernel-shark git|
| <a href="https://git.kernel.org/pub/scm/libs/libtrace/libtraceevent.git/" target="_blank">libtraceevent</a>  | libtraceevent git|
| <a href="https://git.kernel.org/pub/scm/libs/libtrace/libtracefs.git/" target="_blank">libtracefs</a>  | libtracefs git|
| <a href="https://git.kernel.org/pub/scm/utils/salamander4/trace-cmd/trace-cmd.git/" target="_blank">trace-cmd</a>  | trace-cmd git |
