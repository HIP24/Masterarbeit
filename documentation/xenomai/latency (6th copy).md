# latency

## Name
latency - Xenomai timer latency benchmark

## Synopsis
**latency** \[ options \]

## Description
**latency** is part of the Xenomai test suite. It is a timer latency benchmark program. The system must run a suitable Xenomai enabled kernel with the respective module (xeno\_timerbench).

## OPTIONS
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


## Documentation
<a href="https://manpages.debian.org/unstable/xenomai-system-tools/latency.1.en.html" target="_blank">latency - Xenomai timer latency benchmark</a>  

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
root@sigmatek-core2:/usr/sbin# latency -T 60  
== Sampling period: 100 us  
== Test mode: periodic user-mode task  
== All results in microseconds  
warming up...  
RTT|  00:00:01  (periodic user-mode task, 100 us period, priority 99)|||||||
RTH|----lat min|----lat avg|----lat max|-overrun|---msw|---lat best|--lat worst
RTD|      1.681|      3.422|     90.929|       0|     0|      1.681|     90.929
RTD|      2.223|      3.203|     20.304|       0|     0|      1.681|     90.929
RTD|      2.317|      3.364|     23.173|       0|     0|      1.681|     90.929
RTD|      1.821|      3.333|    169.908|       1|     0|      1.681|    169.908
RTD|      1.644|      3.092|     23.484|       1|     0|      1.644|    169.908
RTD|      1.770|      3.182|    169.126|       2|     0|      1.644|    169.908
RTD|      1.807|      3.241|    158.419|       4|     0|      1.644|    169.908
RTD|      1.908|      3.248|    229.944|      11|     0|      1.644|    229.944
RTD|      2.196|      3.239|    135.810|      11|     0|      1.644|    229.944
RTD|      1.782|      3.222|    186.953|      13|     0|      1.644|    229.944
RTD|      2.107|      3.147|    146.794|      14|     0|      1.644|    229.944
RTD|      1.702|      3.136|     21.972|      14|     0|      1.644|    229.944
RTD|      1.663|      3.237|    107.455|      15|     0|      1.644|    229.944
RTD|      1.579|      3.248|    171.420|      17|     0|      1.579|    229.944
RTD|      1.973|      3.278|     32.868|      17|     0|      1.579|    229.944
RTD|      2.494|      3.394|    375.502|      26|     0|      1.579|    375.502
RTD|      2.009|      3.287|     82.024|      26|     0|      1.579|    375.502
RTD|      2.066|      3.250|    260.630|      28|     0|      1.579|    375.502
RTD|      2.155|      3.211|    234.989|      31|     0|      1.579|    375.502
RTD|      1.850|      3.938|    220.307|      36|     0|      1.579|    375.502
RTD|      1.807|      3.236|    221.417|      39|     0|      1.579|    375.502
RTT|  00:00:22  (periodic user-mode task, 100 us period, priority 99)|||||||
RTH|----lat min|----lat avg|----lat max|-overrun|---msw|---lat best|--lat worst
RTD|      2.542|      3.196|     26.265|      39|     0|      1.579|    375.502
RTD|      1.865|      3.158|    194.683|      40|     0|      1.579|    375.502
RTD|      1.641|      3.137|     23.661|      40|     0|      1.579|    375.502
RTD|      1.574|      3.260|     23.995|      40|     0|      1.574|    375.502
RTD|      2.029|      3.185|     87.024|      40|     0|      1.574|    375.502
RTD|      2.534|      3.130|    106.408|      41|     0|      1.574|    375.502
RTD|      1.960|      3.149|     28.831|      41|     0|      1.574|    375.502
RTD|      1.755|      3.435|     30.206|      41|     0|      1.574|    375.502
RTD|      2.683|      4.089|    197.988|      42|     0|      1.574|    375.502
RTD|      1.747|      3.323|    179.669|      44|     0|      1.574|    375.502
RTD|      2.077|      3.183|     69.423|      44|     0|      1.574|    375.502
RTD|      1.803|      3.114|     62.567|      44|     0|      1.574|    375.502
RTD|      1.799|      3.278|     76.858|      44|     0|      1.574|    375.502
RTD|      1.928|      3.124|     21.726|      44|     0|      1.574|    375.502
RTD|      2.025|      3.159|     48.561|      44|     0|      1.574|    375.502
RTD|      2.037|      3.153|     23.673|      44|     0|      1.574|    375.502
RTD|      1.593|      3.140|     25.701|      44|     0|      1.574|    375.502
RTD|      1.846|      3.340|    110.855|      45|     0|      1.574|    375.502
RTD|      2.818|      4.665|    223.871|      50|     0|      1.574|    375.502
RTD|      2.209|      3.514|    110.917|      51|     0|      1.574|    375.502
RTD|      1.848|      3.599|    127.239|      52|     0|      1.574|    375.502
RTT|  00:00:43  (periodic user-mode task, 100 us period, priority 99)|||||||
RTH|----lat min|----lat avg|----lat max|-overrun|---msw|---lat best|--lat worst
RTD|      2.443|      3.525|     84.411|      52|     0|      1.574|    375.502
RTD|      2.028|      3.201|    257.087|      55|     0|      1.574|    375.502
RTD|      1.861|      3.137|    240.561|      58|     0|      1.574|    375.502
RTD|      1.755|      3.186|    167.924|      59|     0|      1.574|    375.502
RTD|      1.731|      3.264|    180.382|      62|     0|      1.574|    375.502
RTD|      1.706|      3.206|    107.250|      63|     0|      1.574|    375.502
RTD|      1.722|      3.171|     24.803|      63|     0|      1.574|    375.502
RTD|      1.719|      3.191|    135.390|      65|     0|      1.574|    375.502
RTD|      1.913|      3.203|    166.808|      66|     0|      1.574|    375.502
RTD|      1.630|      3.146|     19.869|      66|     0|      1.574|    375.502
RTD|      2.341|      3.145|     19.776|      66|     0|      1.574|    375.502
RTD|      2.023|      3.176|     86.029|      66|     0|      1.574|    375.502
RTD|      1.830|      3.167|     22.296|      66|     0|      1.574|    375.502
RTD|      1.732|      3.308|    174.504|      70|     0|      1.574|    375.502
RTD|      1.973|      3.482|    204.055|      79|     0|      1.574|    375.502
RTD|      1.888|      3.256|    207.476|      80|     0|      1.574|    375.502
RTD|      1.838|      3.142|    160.382|      81|     0|      1.574|    375.502
---|-----------|-----------|-----------|--------|------|-------------------------
RTS|      1.574|      3.290|    375.502|      81|     0|    00:01:00/00:01:00||

