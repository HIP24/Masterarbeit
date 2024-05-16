## KVM Exit Reasons
| Exit Reason         | Description                                                    |
|---------------------|-----------------------------------------------------------|
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



### APIC_WRITE

- Guest Makes a Request: A process in the guest (the virtual machine) makes a request, such as a read or write operation to a device.
- Hypervisor Intercepts the Request: The hypervisor (the host system) intercepts this request. The guest does not communicate directly with the hardware.
- Hypervisor Handles the Request: The hypervisor communicates with the actual hardware to handle the request.
- Device Sends an Interrupt: When the requested operation is complete (for example, data is ready to be sent back to the guest), the device sends an interrupt signal.
- Hypervisor Receives the Interrupt: This interrupt is first received by the hypervisor.
- Hypervisor Creates a Guest Interrupt: The hypervisor then creates a “guest interrupt” which is delivered to the guest when it is next scheduled to run.
- Guest Handles the Interrupt: This guest interrupt triggers the appropriate handler in the guest to process the incoming data or handle the completed operation.

In the context of APIC virtualization, the APIC (Advanced Programmable Interrupt Controller) is virtualized by the hypervisor. This means that when the guest tries to interact with the APIC, it’s actually interacting with a virtual representation of the APIC provided by the hypervisor. This allows the hypervisor to maintain control over the hardware and manage the delivery of interrupts to the guests.

[terenceli.github](https://terenceli.github.io/)  
[terenceli.github/apicv](https://terenceli.github.io/%E6%8A%80%E6%9C%AF/2018/08/29/apicv)  
[terenceli.github/kvm-performance](https://terenceli.github.io/%E6%8A%80%E6%9C%AF/2020/09/10/kvm-performance-1)  
[Intel APIC Virtualization Technology](https://edc.intel.com/content/www/us/en/design/ipla/software-development-platforms/client/platforms/alder-lake-desktop/12th-generation-intel-core-processors-datasheet-volume-1-of-2/002/intel-apic-virtualization-technology-intel-apicv/)


#### APIC Virtualization (APICv)
Newer Intel processors offer hardware virtualization of the Advanced Programmable Interrupt Controller (APICv). APICv improves virtualized AMD64 and Intel 64 guest performance by allowing the guest to directly access the APIC, dramatically cutting down interrupt latencies and the number of virtual machine exits caused by the APIC. This feature is used by default in newer Intel processors and improves I/O performance.