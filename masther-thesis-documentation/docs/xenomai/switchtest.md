# switchtest

## Name
switchtest - Xenomai context switch test

## Synopsis
**switchtest** \[options\] threadspec threadspec...

## Description
**switchtest** is part of Xenomai. It can be used to test thread context switches. **switchtest** creates threads of various types and attempts to switch context between these threads, printing the count of context switches every second. A suitable Xenomai enabled kernel with the respective module (xeno\_posix) must be installed.

## Documentation
<a href="https://manpages.debian.org/unstable/xenomai-system-tools/switchtest.1.en.html" target="_blank">switchtest - Xenomai context switch test</a>  


## Options
Each threadspec specifies the characteristics of a thread to be created:

threadspec = (rtk|rtup|rtus|rtuo)(\_fp|\_ufpp|\_ufps)\*\[0-9\]\*

| Thread Specification  | Description                                                |
|-----------------------|------------------------------------------------------------|
| rtk                   | Kernel-space real-time thread                               |
| rtup                  | User-space real-time thread running in primary mode         |
| rtus                  | User-space real-time thread running in secondary mode       |
| rtuo                  | User-space real-time thread oscillating between modes       |
| _fp                   | Thread with XNFPU bit armed (valid for rtk only)            |
| _ufpp                 | Thread using FPU in primary mode (invalid for rtus)        |
| _ufps                 | Thread using FPU in secondary mode (invalid for rtk, rtup) |
| [0-9]                 | CPU ID where the thread will run (0 if unspecified)        |


Passing no **threadspec** is equivalent to running:

switchtest rtkN rtkN rtk\_fpN rtk\_fpN rtk\_fp\_ufppN rtk\_fp\_ufppN rtupN rtupN rtup\_ufppN rtup\_ufppN rtusN rtusN rtus\_ufpsN rtus\_ufpsN rtuoN rtuoN rtuo\_ufppN rtuo\_ufppN rtuo\_ufpsN rtuo\_ufpsN rtuo\_ufpp\_ufpsN rtuo\_ufpp\_ufpsN

with N=1,...,nr\_cpus, i.e. occurrences of all the arguments for each CPU

Passing only the --nofpu or -n argument is equivalent to running:

switchtest rtkN rtkN rtupN rtupN rtusN rtusN rtuoN rtuoN

similar to the above.

**switchtest** accepts the following options:

| Option                   | Description                                          |
|--------------------------|------------------------------------------------------|
| --help, -h               | Print usage information and exit                      |
| --lines <lines>, -l <lines> | Print headers every <lines> lines                    |
| --quiet, -q              | Prevent the program from printing context switch count every second |
| --timeout <duration>, -T <duration> | Limit the test duration to <duration> seconds   |
| --nofpu, -n              | Disable any use of FPU instructions                   |


**switchtest** was written by Philippe Gerum and Gilles Chanteperdrix. This man page was written by Roland Stigge.


## Map
| Output       | Description |
|------------|-------|
| RTT | Real-Time Tick, shows the time at which the measurement was taken. |
| RTH | Real-Time Histogram, shows the distribution of latency values. |
| RTD | Real-Time Data, shows the actual latency measurements. |
| RTS | Real-Time Statistics, shows the overall statistics after the test is complete. |

<br>

## Output: `switchtest -T 60`  

