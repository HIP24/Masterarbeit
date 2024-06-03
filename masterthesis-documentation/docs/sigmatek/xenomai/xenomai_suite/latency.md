# latency

## Name
latency - Xenomai timer latency benchmark

## Synopsis
**latency** \[ options \]

## Description
**latency** is part of the Xenomai test suite. It is a timer latency benchmark program. The system must run a suitable Xenomai enabled kernel with the respective module (xeno\_timerbench).


## Documentation
<a href="https://manpages.debian.org/unstable/xenomai-system-tools/latency.1.en.html" target="_blank">latency - Xenomai timer latency benchmark</a>  

## Options
| Option                | Description                                                  |
|-----------------------|--------------------------------------------------------------|
| **-h**                | Print histograms of min, avg, max latencies                  |
| **-g <file>**         | Dump histogram to <file> in a format easily readable with gnuplot. |
| **-s**                | Print statistics of min, avg, max latencies                 |
| **-H <histogram-size>**| Default = 200, increase if your last bucket is full          |
| **-B <bucket-size>**   | Default = 1000ns, decrease for more resolution               |
| **-p <period_us>**     | Sampling period                                             |
| **-l <data-lines per header>** | Default=21, 0 to suppress headers                   |
| **-T <test_duration_seconds>** | Default=0, so ^C to end                                |
| **-q**                | Suppresses RTD, RTH lines if -T is used                     |
| **-D <testing_device_no>** | Number of testing device, default=0                    |
| **-t <test_mode>**    | 0=user task (default), 1=kernel task, 2=timer IRQ           |
| **-f**                | Freeze trace for each new max latency                       |
| **-c <cpu>**          | Pin measuring task down to given CPU                         |
| **-P <priority>**     | Task priority (test mode 0 and 1 only)                       |
| **-b**                | Break upon mode switch                                       |

**latency** was written by Philippe Gerum. This man page was written by Roland Stigge.

## Map
| Output       | Description |
|------------|-------|
| RTT | Real-Time Tick, shows the time at which the measurement was taken. |
| RTH | Real-Time Histogram, shows the distribution of latency values. |
| RTD | Real-Time Data, shows the actual latency measurements. |
| RTS | Real-Time Statistics, shows the overall statistics after the test is complete. |

<br>

| Output       | Description |
|------------|-------|
| lat min| The minimum latency measured.|
| lat avg| The average latency measured.|
| lat max| The maximum latency measured.|
| overrun| The number of timer overruns (situations where the next period has already arrived before the current period is done).|
| msw| The number of mode switches (switches between primary and secondary mode).|
| lat best| The best (lowest) latency measured so far.|
| lat worst| The worst (highest) latency measured so far. |

<br>

## Output: `latency -T 60`  
root@sigmatek-core2:~# latency -h -t 1 -T 5
== Sampling period: 100 us
== Test mode: in-kernel periodic task
== All results in microseconds
warming up...
RTT|  00:00:01  (in-kernel periodic task, 100 us period, priority 99)
|         | lat min | lat avg | lat max | overrun | msw | lat best | lat worst |
|---------|---------|---------|---------|---------|-----|----------|-----------|
| **RTD** | 1.485   | 2.709   | 83.739  | 0       | 0   | 1.485    | 83.739    |
| **RTD** | 2.616   | 2.703   | 34.086  | 0       | 0   | 1.485    | 83.739    |
| **RTD** | 2.616   | 2.721   | 86.141  | 0       | 0   | 1.485    | 86.141    |
| **RTD** | 2.276   | 2.711   | 63.901  | 0       | 0   | 1.485    | 86.141    |
| **RTS** | 1.485   | 2.711   | 86.141  | 0       | 0   | 00:00:05/00:00:05 |   |

| param | range | samples |
|-------|-------|---------|
| **HSD** | min   |         |
|         | 1 - 2 | 1       |
|         | 2 - 3 | 3       |
| **HSD** | avg   |         |
|         | 1 - 2 | 2       |
|         | 2 - 3 | 49391   |
|         | 3 - 4 | 437     |
|         | 4 - 5 | 35      |
|         | 5 - 6 | 12      |
|         | 6 - 7 | 9       |
|         | 7 - 8 | 42      |
|         | 9 - 10| 1       |
|         | 10 - 11| 7      |
|         | 11 - 12| 6      |
|         | 12 - 13| 8      |
|         | 13 - 14| 6      |
|         | 14 - 15| 2      |
|         | 15 - 16| 1      |
|         | 17 - 18| 1      |
|         | 18 - 19| 1      |
|         | 20 - 21| 2      |
|         | 21 - 22| 1      |
|         | 26 - 27| 2      |
|         | 27 - 28| 1      |
|         | 28 - 29| 2      |
|         | 29 - 30| 1      |
|         | 32 - 33| 2      |
|         | 33 - 34| 1      |
|         | 34 - 35| 1      |
|         | 35 - 36| 1      |
|         | 63 - 64| 1      |
|         | 83 - 84| 1      |
|         | 86 - 87| 1      |
| **HSD** | max   |         |
|         | 34 - 35 | 1       |
|         | 63 - 64 | 1       |
|         | 83 - 84 | 1       |
|         | 86 - 87 | 1       |

| param | samples | average | stddev  |
|-------|---------|---------|---------|
| **HSS** | min     | 4       | 1.750   | 0.500   |
| **HSS** | avg     | 49978   | 2.034   | 0.805   |
| **HSS** | max     | 4       | 66.500  | 23.951  |


|RTS|      1.485|      2.711|     86.141|       0|     0|    00:00:05/00:00:05|
|-------|---------|---------|---------|-------|-------|-------|

## Explanation
The test ran for 5 seconds (-T 5).  
The minimum latency (lat min) was 1.485 microseconds,  
the average latency (lat avg) was 2.711 microseconds with 49978 samples,  
and the maximum latency (lat max) was 86.141 microseconds.  
There were 0 overruns and 0 mode switches.