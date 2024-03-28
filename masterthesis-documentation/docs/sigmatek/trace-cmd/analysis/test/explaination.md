## APIC_WRITE

- Guest Makes a Request: A process in the guest (the virtual machine) makes a request, such as a read or write operation to a device.
- Hypervisor Intercepts the Request: The hypervisor (the host system) intercepts this request. The guest does not communicate directly with the hardware.
- Hypervisor Handles the Request: The hypervisor communicates with the actual hardware to handle the request.
- Device Sends an Interrupt: When the requested operation is complete (for example, data is ready to be sent back to the guest), the device sends an interrupt signal.
- Hypervisor Receives the Interrupt: This interrupt is first received by the hypervisor.
- Hypervisor Creates a Guest Interrupt: The hypervisor then creates a “guest interrupt” which is delivered to the guest when it is next scheduled to run.
- Guest Handles the Interrupt: This guest interrupt triggers the appropriate handler in the guest to process the incoming data or handle the completed operation.

In the context of APIC virtualization, the APIC (Advanced Programmable Interrupt Controller) is virtualized by the hypervisor. This means that when the guest tries to interact with the APIC, it’s actually interacting with a virtual representation of the APIC provided by the hypervisor. This allows the hypervisor to maintain control over the hardware and manage the delivery of interrupts to the guests.

https://terenceli.github.io/%E6%8A%80%E6%9C%AF/2018/08/29/apicv

https://terenceli.github.io/

https://edc.intel.com/content/www/us/en/design/ipla/software-development-platforms/client/platforms/alder-lake-desktop/12th-generation-intel-core-processors-datasheet-volume-1-of-2/002/intel-apic-virtualization-technology-intel-apicv/


## APIC Virtualization (APICv)
Newer Intel processors offer hardware virtualization of the Advanced Programmable Interrupt Controller (APICv). APICv improves virtualized AMD64 and Intel 64 guest performance by allowing the guest to directly access the APIC, dramatically cutting down interrupt latencies and the number of virtual machine exits caused by the APIC. This feature is used by default in newer Intel processors and improves I/O performance.