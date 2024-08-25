## Thema Masterarbeit 
Virtualisierung eines Echtzeit-Betriebssystems zur Steuerung eines Roboters mit Schwerpunkt auf die 
Einhaltung der Echtzeit 

### Kurze Umschreibung 
Erstellung einer Echtzeit-Robotersteuerungsplattform unter Verwendung von Salamander OS, Xenomai, QEMU 
und PCV-521 in der Yocto-Umgebung. Die Plattform basiert auf Salamander OS und nutzt Xenomai für Echtzeit-
Funktionen. Dazu muss im ersten Schritt die Virtualisierungsplattform evaluiert werden. (QEMU, Hyper-V, Virtual 
Box, etc.) Als weiterer Schritt folgt die Anbindung eines Roboters über eine VARAN-Bus Schnittstelle. Das 
gesamte System wird in der Yocto-Umgebung erstellt und konfiguriert. 
Das Hauptziel der Arbeit ist es, herauszufinden, wie die Integration von Echtzeit-Funktionen und effizienten 
Kommunikationssystemen in eine Robotersteuerungsplattform die Reaktionszeit und Zuverlässigkeit von 
Roboteranwendungen verbessern kann. 

### Masterarbeit 
Hier ist die [Masterarbeit](Masterarbeit_Robotik_Pamuk.pdf).
!!! info
    Diese Masterarbeit wird täglich aktualisiert. Zu einem späteren Zeitpunkt kann mehr Inhalt vorhanden sein.

<div id="page-wrapper">
  <div><a href="https://codepen.io/chriscoyier/pen/eYBOvJB">Status</a>
 der Masterarbeit:<b> Nahe dem Ende</b> </div> 
  <div class="meter animate">
    <span style="width: 90%"><span></span></span>
  </div> 
  <!--<div class="meter orange nostripes">
    <span style="width: 33.3%"></span>
  </div>
  <div class="meter red">
    <span style="width: 80%"></span>
  </div>
  -->
</div>

<style>
.meter {
  box-sizing: content-box;
  height: 20px; /* Can be anything */
  position: relative;
  margin: 0; /* Just for demo spacing */
  background: #555;
  border-radius: 25px;
  padding: 3px;
  box-shadow: inset 0 -1px 1px rgba(255, 255, 255, 0.3);
}
.meter > span {
  display: block;
  height: 100%;
  border-top-right-radius: 8px;
  border-bottom-right-radius: 8px;
  border-top-left-radius: 20px;
  border-bottom-left-radius: 20px;
  background-color: rgb(43, 194, 83);
  background-image: linear-gradient(
    center bottom,
    rgb(43, 194, 83) 37%,
    rgb(84, 240, 84) 69%
  );
  box-shadow: inset 0 2px 9px rgba(255, 255, 255, 0.3),
    inset 0 -2px 6px rgba(0, 0, 0, 0.4);
  position: relative;
  overflow: hidden;
}
.meter > span:after,
.animate > span > span {
  content: "";
  position: absolute;
  top: 0;
  left: 0;
  bottom: 0;
  right: 0;
  background-image: linear-gradient(
    -45deg,
    rgba(255, 255, 255, 0.2) 25%,
    transparent 25%,
    transparent 50%,
    rgba(255, 255, 255, 0.2) 50%,
    rgba(255, 255, 255, 0.2) 75%,
    transparent 75%,
    transparent
  );
  z-index: 1;
  background-size: 50px 50px;
  animation: move 2s linear infinite;
  border-top-right-radius: 8px;
  border-bottom-right-radius: 8px;
  border-top-left-radius: 20px;
  border-bottom-left-radius: 20px;
  overflow: hidden;
}

.animate > span:after {
  display: none;
}

@keyframes move {
  0% {
    background-position: 0 0;
  }
  100% {
    background-position: 50px 50px;
  }
}

.orange > span {
  background-image: linear-gradient(#f1a165, #f36d0a);
}

.red > span {
  background-image: linear-gradient(#f0a3a3, #f42323);
}

.nostripes > span > span,
.nostripes > span::after {
  background-image: none;
}

#page-wrapper {
  width: auto;
  height: auto;
}
pre {
  background: #000;
  text-align: left;
  padding: 20px;
  margin: 0 auto 30px;
}
* {
  box-sizing: border-box;
}
</style>

<script>
    $(".meter > span").each(function () {
  $(this)
    .data("origWidth", $(this).width())
    .width(0)
    .animate(
      {
        width: $(this).data("origWidth")
      },
      1200
    );
});
</script>

<!--
## Overview
| File       | Description |
|------------|-------|
| [BS Virtualisierungsprojekt.xlsx](general/BS%20Virtualisierungsprojekt.xlsx)   | Masterthesis progress |


## PDFs
| File       | Description |
|------------|-------|
| [MA_Pamuk.pdf](resources/pdfs/MA/MA_Pamuk.pdf)   | Masterthesis description  |
| [MA_guide.pdf](resources/pdfs/MA/MA_guide.pdf)   | Masterthesis writing guide |
| [MA_precision.pdf](resources/pdfs/MA/MA_precision.pdf)   | Master thesis Robotics degree precision  |
| [MA_deadlines.pdf](resources/pdfs/MA/MA_deadlines.pdf)   | Master thesis deadlines |
| [PCV 522.pdf](resources/pdfs/Sigmatek/PCV%20522.pdf)   | PCV 522 module handbook |
| [LasalClass2_eng.pdf](resources/pdfs/Sigmatek/LasalClass2/LasalClass2_eng.pdf)   | Lasal Class 2 documentation  |


## Markdown files
### General
| File       | Description |
|------------|-------|
| [protocol.md](general/protocol.md)   | Protocol of the process |
| [timeline.md](general/timeline.md)   | Timeline view of the process |
| [components.md](general/components.md)   | Components of the process |
| [documentations.md](general/documentations.md)   | Documentations |
| [checklist.md](general/checklist.md)   | Checklist of the process |

<hr>

### Workflow
| File       | Description |
|------------|-------|
| [useful.md](workflow/useful.md)   | Useful stuff in the process |
| [useful_notneeded.md](workflow/useful_notneeded.md)   | Useful stuff that is not needed in the process |
| [useful_links.md](workflow/useful_links.md)   | Useful stuff that is not needed in the process |
| [most_popular_paths.md](workflow/most_popular_paths.md)   | Most used paths in the process |
| [problem_solution.md](workflow/problem_solution.md)   | Fix Yocto build 0001.patch |
| [vscode.md](workflow/vscode.md)   | Stuff related to VSCode |
| [gitlfs.md](workflow/gitlfs.md)   | Setup gitlfs in repository |
| [gittutorial.md](workflow/gittutorial.md)   | GIT tutorial |

<hr>

### Sigmatek 
| File       | Description |
|------------|-------|
| [bash_commands.md](sigmatek/salamander4/bash_commands.md)   | How to set up for yocto build |
| [build_LRT.md](sigmatek/salamander4/build_LRT.md)   | How to build LRT - Salamander 3 Terminal |
| [build_with_yocto.md](sigmatek/salamander4/build_with_yocto.md)  | How to bitbake a yocto salamander-image |

<hr>

### Yocto 
| File       | Description |
|------------|-------|
| [after_bitbake.md](sigmatek/yocto/after_bitbake.md)   | Commands after bitbake |

<hr>

### Xenomai
| File       | Description |
|------------|-------|
| [xenomai-system-tools.md](sigmatek/xenomai/xenomai-system-tools.md)   | Xenomai System Tools |
| [latency.md](sigmatek/xenomai/latency.md)   | Xenomai: latency tool |
| [clocktest.md](sigmatek/xenomai/clocktest.md)   | Xenomai: clocktest tool |
| [switchtest.md](sigmatek/xenomai/switchtest.md)   | Xenomai: switchtest tool |

<hr>

### trace-cmd and kernelshark
| File       | Description |
|------------|-------|
| [info.md](sigmatek/trace-cmd/analysis/info.md)   | Info about trace-cmd |
| [kernelshark.md](sigmatek/trace-cmd/analysis/kernelshark.md)   | Kernelshark commands for host and guest |

<hr>
-->
<!--
### README 
| File       | Description |
|------------|-------|
| [README.md](README.md)   | README of the masterthesis |
| [README.md](sigmatek/trace-cmd/LTS/libtraceevent-1.8.2/README.md)   | README of libtraceevent |
| [README.md](sigmatek/trace-cmd/LTS/libtracefs-1.8.0/README.md)   | README of libtracefs |
| [README.md](sigmatek/trace-cmd/LTS/trace-cmd-libtracecmd-1.5.1/README.md)   | README of libtracecmd |
| [README.md](sigmatek/trace-cmd/LTS/trace-cmd-v3.2/README.md)   | README of trace-cmd |
-->
<!--

## Scripts
### Yocto
| File       | Description |
|------------|-------|
| [after_bitbake_1.sh](sigmatek/yocto/after_bitbake_1.sh)   | Script after bitbake 1 |
| [after_bitbake_2.sh](sigmatek/yocto/after_bitbake_2.sh)   | Script after bitbake 2 |


<hr>


### QEMU config
| File       | Description |
|------------|-------|
| [nmbridge.md](sigmatek/QEMU/nmbridge.md) | Steps to configure nmbridge  |
| [qemu_def_1default.sh](sigmatek/QEMU/qemu_def_1default.sh) | default qemu_def.sh  |
| [qemu_def_2nmbridge.sh](sigmatek/QEMU/qemu_def_2nmbridge.sh) | qemu_def.sh with nm bridge  |
| [qemu_def_3vsock.sh](sigmatek/QEMU/qemu_def_3vsock.sh) |qemu_def.sh with vsock |
| [qemu_def_4schedstats.sh](sigmatek/QEMU/qemu_def_4schedstats.sh) | qemu_def.sh with schedstats  |
| [qemu_def_5taskset.sh](sigmatek/QEMU/qemu_def_5taskset.sh) | qemu_def.sh with taskset  |
| [start_qemu.sh](sigmatek/QEMU/start_qemu.sh) | Script for starting QEMU |


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
| [start_kernelshark.sh](sigmatek/trace-cmd/analysis/taskset/start_kernelshark.sh)   | Script for starting kernelshark with host and guest trace.dat |
| [start_kernelshark_convert.sh](sigmatek/trace-cmd/analysis/start_kernelshark_convert.sh)   | Script for starting kernelshark with converted v6 host and guest trace.dat |


## Python
| File       | Description |
|------------|-------|
| [kvm_exit_number.py](sigmatek/trace-cmd/analysis/default/kvm_exit_default_number.py)   | Count kvm_exit events default  |
| [kvm_exit_number.py](sigmatek/trace-cmd/analysis/taskset/kvm_exit_taskset_number.py)   | Count kvm_exit events taskset |
| [max_latency_no_taskset.py](sigmatek/xenomai/max_latency_default/max_latency_default.py)             | Plot latency of Slamander 4 QEMU with no taskset  |
| [max_latency_taskset.py](sigmatek/xenomai/max_latency_taskset/max_latency_taskset.py)                   | Plot latency of Slamander 4 QEMU with taskset  |
| [max_latency_hardware.py](sigmatek/xenomai/max_latency_hardware/max_latency_hardware.py)                   | Plot latency of Slamander 4 hardware  |
| [print_numbers.py](sigmatek/xenomai/print_numbers.py)                       | Print numbers of specified range  |
| [search_for_x.py](resources/kernel/search_for_x.py)                         | Search for lines that contain x |
| [compare_2_files.py](resources/kernel/compare_2_files.py)                   | Compare two config files line by line  |


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
| <a href="https://git.kernel.org/pub/scm/utils/trace-cmd/kernel-shark.git/" target="_blank">kernel-shark</a>  | kernel-shark git|
| <a href="https://git.kernel.org/pub/scm/libs/libtrace/libtraceevent.git/" target="_blank">libtraceevent</a>  | libtraceevent git|
| <a href="https://git.kernel.org/pub/scm/libs/libtrace/libtracefs.git/" target="_blank">libtracefs</a>  | libtracefs git|
| <a href="https://git.kernel.org/pub/scm/utils/trace-cmd/trace-cmd.git/" target="_blank">trace-cmd</a>  | trace-cmd git |
-->