After having cleared IRQs from CPU 13 
```
cat /proc/interrupts 
```
```
            CPU0       CPU1       CPU2       CPU3       CPU4       CPU5       CPU6       CPU7       CPU8       CPU9       CPU10      CPU11      CPU12      CPU13      
   1:          0          0          0          0          0          0          0          0          0          0       1377          0          0          0  IR-IO-APIC    1-edge      i8042
   8:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-IO-APIC    8-edge      rtc0
   9:          0        383          0          0          0          0          0          0          0          0          0          0          0          0  IR-IO-APIC    9-fasteoi   acpi
  14:          0          0          0          0          0          0          0          0          0          0          0          0      18547          0  IR-IO-APIC   14-fasteoi   INTC1055:00
  16:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-IO-APIC   16-fasteoi   i801_smbus
  19:          7          0          0          0          0          0          3          0          0          0          0          0          0          0  IR-IO-APIC   19-fasteoi 
  26:          0          0        874          0          0          0          0          0          0          0          0          0          0          0  IR-IO-APIC   26-fasteoi   intel_ish_ipc
  27:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-IO-APIC   27-fasteoi   idma64.0, i2c_designware.0
  40:          0     438751          0          0          0          0          0          0          0          0          0        352          0          0  IR-IO-APIC   40-fasteoi   idma64.1, i2c_designware.1
 120:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  DMAR-MSI    0-edge      dmar0
 121:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  DMAR-MSI    1-edge      dmar1
 122:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 16384-edge      PCIe PME
 123:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 98304-edge      PCIe PME
 124:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 102400-edge      PCIe PME
 125:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 114688-edge      PCIe PME, pciehp
 126:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 116736-edge      PCIe PME, pciehp
 127:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 475136-edge      PCIe PME
 129:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 2686976-edge      pciehp
 130:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 212992-edge      xhci_hcd
 131:          0          0          0         32          0          1          0          0          0          0          0          0          0          0  IR-PCI-MSI 1048576-edge      nvme0q0
 132:          0         10          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 60817408-edge      rtsx_pci
 133:          0          0          0          0          0          0          0      11554          0          0          0          0          0          0  IR-PCI-MSI 217088-edge      thunderbolt
 134:          0          0          0          0          0          0          0          0      11554          0          0          0          0          0  IR-PCI-MSI 217089-edge      thunderbolt
 135:          0          0          0          0          1          0          0          0          0         33          0          0          0          0  IR-PCI-MSI 1572864-edge      nvme1q0
 147:          0          0        144         40         16          0          0          0          0          0          0         10          0          0  IR-PCI-MSI 520192-edge      enp0s31f6
 148:          0          0          0          0          0      10372       6461          0          0          0          0          0          0          0  IR-PCI-MSI 327680-edge      xhci_hcd
 152:      66066          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1048577-edge      nvme0q1
 153:          0      65942          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1048578-edge      nvme0q2
 154:          0          0      17196          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1048579-edge      nvme0q3
 155:          0          0          0      32357          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1048580-edge      nvme0q4
 156:          0          0          0          0      64356          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1048581-edge      nvme0q5
 157:          0          0          0          0          0      68344          0          0          0          0          0          0          0          0  IR-PCI-MSI 1048582-edge      nvme0q6
 158:          0          0          0          0          0          0      24573          0          0          0          0          0          0          0  IR-PCI-MSI 1048583-edge      nvme0q7
 159:          0          0          0          0          0          0          0      15723          0          0          0          0          0          0  IR-PCI-MSI 1048584-edge      nvme0q8
 160:          0          0          0          0          0          0          0          0       9430          0          0          0          0          0  IR-PCI-MSI 1048585-edge      nvme0q9
 161:          0          0          0          0          0          0          0          0          0       9928          0          0          0          0  IR-PCI-MSI 1048586-edge      nvme0q10
 162:          0          0          0          0          0          0          0          0          0          0       8486          0          0          0  IR-PCI-MSI 1048587-edge      nvme0q11
 163:          0          0          0          0          0          0          0          0          0          0          0       7030          0          0  IR-PCI-MSI 1048588-edge      nvme0q12
 164:          0          0          0          0          0          0          0          0          0          0          0          0       6538          0  IR-PCI-MSI 1048589-edge      nvme0q13
 165:          0          0          0          0          0          0          0          0          0          0          0          0          0        872  IR-PCI-MSI 1048590-edge      nvme0q14
 166:       3467          0      15149      15234          0          0          0          0          0          0       2342          0          0          0  IR-PCI-MSI 3145728-edge      xhci_hcd
 167:         56          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1572865-edge      nvme1q1
 168:          0         67          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1572866-edge      nvme1q2
 169:          0          0         44          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1572867-edge      nvme1q3
 170:          0          0          0         78          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1572868-edge      nvme1q4
 171:          0          0          0          0         38          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1572869-edge      nvme1q5
 172:          0          0          0          0          0         34          0          0          0          0          0          0          0          0  IR-PCI-MSI 1572870-edge      nvme1q6
 173:          0          0          0          0          0          0         19          0          0          0          0          0          0          0  IR-PCI-MSI 1572871-edge      nvme1q7
 174:          0          0          0          0          0          0          0         18          0          0          0          0          0          0  IR-PCI-MSI 1572872-edge      nvme1q8
 175:          0          0          0          0          0          0          0          0         18          0          0          0          0          0  IR-PCI-MSI 1572873-edge      nvme1q9
 176:          0          0          0          0          0          0          0          0          0         31          0          0          0          0  IR-PCI-MSI 1572874-edge      nvme1q10
 177:          0          0          0          0          0          0          0          0          0          0         13          0          0          0  IR-PCI-MSI 1572875-edge      nvme1q11
 178:          0          0          0          0          0          0          0          0          0          0          0         36          0          0  IR-PCI-MSI 1572876-edge      nvme1q12
 179:          0          0          0          0          0          0          0          0          0          0          0          0         14          0  IR-PCI-MSI 1572877-edge      nvme1q13
 180:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1572878-edge      nvme1q14
 181:          0          0          0          0          0          0          0          0          0          0          0          0      18547          0  INTC1055:00  327  VEN_06CB:00
 182:          0          0          0          0          0          0          0          0          0         16          0          0          0         47  IR-PCI-MSI 360448-edge      mei_me
 183:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  als-dev0       als_consumer0
 187:          0          0          0          0          0          0        317          0          0          0          0          0          0          0  IR-PCI-MSI 514048-edge      snd_hda_intel:card0
 NMI:          4          6         48         41          5          5          2          2          1          1          1          1          3         43   Non-maskable interrupts
 LOC:      61929      72924     102439      99956      60499      61509      45444      38049      35226      33252      36278      34265      33134     105336   Local timer interrupts
 SPU:          0          0          0          0          0          0          0          0          0          0          0          0          0          0   Spurious interrupts
 PMI:          4          6         48         41          5          5          2          2          1          1          1          1          3         43   Performance monitoring interrupts
 IWI:       2146        903      11486      10086       2187       1429       1007        483        687        817        659        678        650          7   IRQ work interrupts
 RTR:          0          0          0          0          0          0          0          0          0          0          0          0          0          0   APIC ICR read retries
 RES:       5904       8387       8383       8567       7724       5206       9726       7460       7236       9113       8281       9918      15459       3312   Rescheduling interrupts
 CAL:      22974      17289      14735      15033      18986      17893      19525      16987      18218      16206      16599      15352      16192      92688   Function call interrupts
 TLB:      11666       9839       6252       6421      10398      11745      11087       8898      10356       8246       8801       7509       8320      64080   TLB shootdowns
 TRM:      88778      88671      90659     107001      88711      89105      88670      88671      88671      88671      88670      88671      88670      88670   Thermal event interrupts
 THR:          0          0          0          0          0          0          0          0          0          0          0          0          0          0   Threshold APIC interrupts
 DFR:          0          0          0          0          0          0          0          0          0          0          0          0          0          0   Deferred Error APIC interrupts
 MCE:          0          0          0          0          0          0          0          0          0          0          0          0          0          0   Machine check exceptions
 MCP:          2          3          3          3          3          3          3          3          3          3          3          3          3          3   Machine check polls
 ERR:          0
 MIS:          0
 PIN:          0          0          0          0          0          0          0          0          0          0          0          0          0        418   Posted-interrupt notification event
 NPI:          0          0          0          0          0          0          0          0          0          0          0          0          0          0   Nested posted-interrupt event
 PIW:          0          0          0          0          0          0          0          0          0          0          0          0          0          0   Posted-interrupt wakeup event
```