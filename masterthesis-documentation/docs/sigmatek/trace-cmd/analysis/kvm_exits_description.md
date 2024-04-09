| Exit Reason         | Description                                               | Frequency     |
|---------------------|-----------------------------------------------------------|---------------|
| APIC_WRITE          | Triggered when the guest writes to its Advanced Programmable Interrupt Controller (APIC).                                     | 
| EXTERNAL_INTERRUPT  | Triggered when an external hardware interrupt occurs, usually caused by hardware devices signaling the host’s CPU.            |
| HLT                 | Triggered when the guest executes the HLT instruction, halting the CPU until the next external interrupt is fired.            | 
| EPT_MISCONFIG       | Triggered due to a misconfiguration in the Extended Page Tables (EPT), a memory management feature in modern CPUs.            | 
| PREEMPTION_TIMER    | Triggered when the preemption timer of the host expires, related to the host’s scheduling of the guest.                       | 
| PAUSE_INSTRUCTION   | Triggered when the PAUSE instruction is executed, used in spinlock loops to improve performance and reduce power consumption. |
| EPT_VIOLATION       | Triggered when a guest access to a page would result in a violation of the EPT permission settings.                           | 
| IO_INSTRUCTION      | Triggered when the guest executes an I/O instruction, such as IN or OUT.                                                      | 
| EOI_INDUCED         | Triggered when an end-of-interrupt (EOI) signal is sent to the APIC.                                                          | 
| MSR_READ            | Triggered when the guest reads from a Model-Specific Register (MSR).                                                          | 
| CPUID               | Triggered when the guest executes the CPUID instruction, used to identify the processor.                                      | 
