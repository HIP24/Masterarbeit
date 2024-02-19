# clocktest

### Name

clocktest - Xenomai Clock Test

## Synopsis

**clocktest** \[_OPTIONS_\]

## Description

**clocktest** is part of the Xenomai test suite and tests the Clock. For each CPU, it repeatedly prints a time offset (compared to the reference gettimeofday()), a drift value, the number of warps and the maximum warp in microseconds.

For this program to work, you need to run a suitable Xenomai enabled kernel with the respective module (xeno\_posix).

## Options
| Option                       | Description                                                             |
|------------------------------|-------------------------------------------------------------------------|
| **\-C <clock_id>**              | Clock to be tested, default=0 (CLOCK_REALTIME=0, CLOCK_MONOTONIC=1, CLOCK_HOST_REALTIME=42) |
| **\-T <test_duration_seconds>** | Default=0 (Never stop, ^C to end)                                      |
| **\-D**                         | Print extra diagnostics for CLOCK_HOST_REALTIME                         |

**clocktest** was written by Jan Kiszka. This man page was written by Roland Stigge.

## Documentation
<a href="https://manpages.debian.org/unstable/xenomai-system-tools/clocktest.1.en.html" target="_blank">clocktest - Xenomai Clock Test</a>  

## Map
| Output | Description |
| --- | --- |
| CPU | The CPU on which the test was run |
| ToD offset [us] | The offset of the Time of Day (ToD) clock in microseconds (us) |
| ToD drift [us/s] | The drift of the ToD clock in microseconds per second (us/s) |
| warps | The number of "warps" or significant jumps in system time |
| max delta [us] | The maximum observed difference (delta) in the time, in microseconds (us) |



## Output: `clocktest -D -T 60`  
root@sigmatek-core2:/usr/sbin# clocktest -D -T 60
== Testing built-in CLOCK_REALTIME (0)
| CPU | ToD offset [us] | ToD drift [us/s] | Warps | Max Delta [us] |
|-----|------------------|-------------------|-------|-----------------|
|   0 |              0.7 |            -0.005 |     0 |             0.0 |

