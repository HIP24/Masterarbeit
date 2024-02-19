
## Xenomai System Tools
In traditional IRQ handling, the processor suspends its current activities to service an interrupt, whereas Xenomai's IRQ handling uses an interrupt pipeline mechanism, allowing for simultaneous fetching and preparation of another interrupt while one is being processed, improving performance and reducing latency.  

What sets Xenomai4 apart from its predecessor, Xenomai3, is the complete redesign of the high-priority execution stage. This was done for portability and maintainability: I-pipe—the second iteration of the initial Adeos interrupt pipeline—has been fully replaced by Dovetail.  

<a href="https://manpages.debian.org/unstable/xenomai-system-tools/" target="_blank">Xenomai System Tools</a>  

✅ **Supported by Salamander4**

| Command | Description |
| --- | --- |
| <a href="latency.md" target="_blank">latency</a>  | Xenomai timer latency benchmark |
| <a href="clocktest.md" target="_blank">clocktest</a>  | Xenomai Clock Test |
| switchtest | Xenomai context switch test |
| dohell | Generate load, in parallel of the latency test |
| rtcanconfig | Xenomai tool for configuring the CAN controller |
| rtcansend | Xenomai tool for sending CAN messages |
| rtcanrecv | Xenomai tool for receiving CAN messages |
| xeno | Wrapper for Xenomai executables |
| xeno-config | Display Xenomai libraries configuration |
| xeno-test | Run latency test under load |

❌ **Not supported by Salamander4**

| Command | Description |
| --- | --- |
| cyclictest | Xenomai high resolution timer test |
| switchbench | Xenomai latency test for task switches |
| irqbench | Xenomai IRQ benchmark, host control |
| irqloop | Xenomai IRQ benchmark, target program |
| klatency | Xenomai kernel latency test |


## Helping videos
<a href="https://www.youtube.com/watch?v=tQ9tP-r8jx0" target="_blank">Minimize Jitter: Linux vs. Xenomai</a>  

