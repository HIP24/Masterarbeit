Before having cleared IRQs from CPU 13 
```
cat /proc/interrupts
```
```
            CPU0       CPU1       CPU2       CPU3       CPU4       CPU5       CPU6       CPU7       CPU8       CPU9       CPU10      CPU11      CPU12      CPU13      
   1:          0          0          0          0          0          0          0          0          0          0      19309          0          0          0  IR-IO-APIC    1-edge      i8042
   8:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-IO-APIC    8-edge      rtc0
   9:          0      11814          0          0          0          0          0          0          0          0          0          0          0          0  IR-IO-APIC    9-fasteoi   acpi
  14:          0          0          0          0          0          0          0          0          0          0          0          0     452146          0  IR-IO-APIC   14-fasteoi   INTC1055:00
  16:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-IO-APIC   16-fasteoi   i801_smbus
  19:          7          0          0          0          0          0          0          3          0          0          0          0          0          0  IR-IO-APIC   19-fasteoi 
  26:          0          0       4516          0          0          0          0          0          0          0          0          0          0        422  IR-IO-APIC   26-fasteoi   intel_ish_ipc
  27:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-IO-APIC   27-fasteoi   idma64.0, i2c_designware.0
  40:          0   10752888          0          0          0          0          0          0          0          0          0          0        436          0  IR-IO-APIC   40-fasteoi   idma64.1, i2c_designware.1
 120:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  DMAR-MSI    0-edge      dmar0
 121:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  DMAR-MSI    1-edge      dmar1
 122:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 16384-edge      PCIe PME
 123:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 98304-edge      PCIe PME
 124:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 102400-edge      PCIe PME
 125:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 114688-edge      PCIe PME, pciehp
 126:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 116736-edge      PCIe PME, pciehp
 127:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 475136-edge      PCIe PME
 129:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 2686976-edge      pciehp
 130:          0         18          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 60817408-edge      rtsx_pci
 131:          0          0          0          0          0      12311          0          0          0          0          0          0          0          0  IR-PCI-MSI 217088-edge      thunderbolt
 132:          0          0          0          0          0          0      12311          0          0          0          0          0          0          0  IR-PCI-MSI 217089-edge      thunderbolt
 134:          0          1          0          0          0          0          0          0          0         32          0          0          0          0  IR-PCI-MSI 1048576-edge      nvme0q0
 135:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 212992-edge      xhci_hcd
 139:       1450         75        408        495        571        670          0          0          0         10        375        725        905          0  IR-PCI-MSI 520192-edge      enp0s31f6
 150:          0          0          0          1          0          0          0          0          0          0         33          0          0          0  IR-PCI-MSI 1572864-edge      nvme1q0
 151:     124400          0          9     396673        916       8006          0          0       6666          0          0          0          0          0  IR-PCI-MSI 327680-edge      xhci_hcd
 152:      96366          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1048577-edge      nvme0q1
 153:          0     104918          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1048578-edge      nvme0q2
 154:          0          0      99756          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1048579-edge      nvme0q3
 155:          0          0          0     100280          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1048580-edge      nvme0q4
 156:          0          0          0          0     122165          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1048581-edge      nvme0q5
 157:          0          0          0          0          0     123954          0          0          0          0          0          0          0          0  IR-PCI-MSI 1048582-edge      nvme0q6
 158:          0          0          0          0          0          0      40358          0          0          0          0          0          0          0  IR-PCI-MSI 1048583-edge      nvme0q7
 159:          0          0          0          0          0          0          0      27860          0          0          0          0          0          0  IR-PCI-MSI 1048584-edge      nvme0q8
 160:          0          0          0          0          0          0          0          0      25796          0          0          0          0          0  IR-PCI-MSI 1048585-edge      nvme0q9
 161:          0          0          0          0          0          0          0          0          0      23860          0          0          0          0  IR-PCI-MSI 1048586-edge      nvme0q10
 162:          0          0          0          0          0          0          0          0          0          0      22513          0          0          0  IR-PCI-MSI 1048587-edge      nvme0q11
 163:          0          0          0          0          0          0          0          0          0          0          0      21208          0          0  IR-PCI-MSI 1048588-edge      nvme0q12
 164:          0          0          0          0          0          0          0          0          0          0          0          0      20633          0  IR-PCI-MSI 1048589-edge      nvme0q13
 165:          0          0          0          0          0          0          0          0          0          0          0          0          0        915  IR-PCI-MSI 1048590-edge      nvme0q14
 166:      28456       1200    1171186       1125        649      14526          0          0          0          0          0      47561          0          0  IR-PCI-MSI 3145728-edge      xhci_hcd
 167:         20          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1572865-edge      nvme1q1
 168:          0         12          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1572866-edge      nvme1q2
 169:          0          0         38          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1572867-edge      nvme1q3
 170:          0          0          0         38          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1572868-edge      nvme1q4
 171:          0          0          0          0         65          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1572869-edge      nvme1q5
 172:          0          0          0          0          0         67          0          0          0          0          0          0          0          0  IR-PCI-MSI 1572870-edge      nvme1q6
 173:          0          0          0          0          0          0         21          0          0          0          0          0          0          0  IR-PCI-MSI 1572871-edge      nvme1q7
 174:          0          0          0          0          0          0          0         22          0          0          0          0          0          0  IR-PCI-MSI 1572872-edge      nvme1q8
 175:          0          0          0          0          0          0          0          0         28          0          0          0          0          0  IR-PCI-MSI 1572873-edge      nvme1q9
 176:          0          0          0          0          0          0          0          0          0          6          0          0          0          0  IR-PCI-MSI 1572874-edge      nvme1q10
 177:          0          0          0          0          0          0          0          0          0          0        108          0          0          0  IR-PCI-MSI 1572875-edge      nvme1q11
 178:          0          0          0          0          0          0          0          0          0          0          0         59          0          0  IR-PCI-MSI 1572876-edge      nvme1q12
 179:          0          0          0          0          0          0          0          0          0          0          0          0         65          0  IR-PCI-MSI 1572877-edge      nvme1q13
 180:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  IR-PCI-MSI 1572878-edge      nvme1q14
 181:          0          0          0          0          0          0          0          0          0          0          0          0     452146          0  INTC1055:00  327  VEN_06CB:00
 182:          0          0         16          0          0          0          0          0          0          0          0          0          0         58  IR-PCI-MSI 360448-edge      mei_me
 183:          0          0          0          0          0          0          0          0          0          0          0          0          0          0  als-dev0       als_consumer0
 187:          0          0          0          0          0          0          0        317          0          0          0          0          0          0  IR-PCI-MSI 514048-edge      snd_hda_intel:card0
 NMI:         71        142        227        236        101         92         58         49         45         41         41         38         86       1523   Non-maskable interrupts
 LOC:    2520020    2845998    3878408    4378251    4144648    4006858    2473139    1946408    1645980    1418209    1507656    1386311    1356306    2883073   Local timer interrupts
 SPU:          0          0          0          0          0          0          0          0          0          0          0          0          0          0   Spurious interrupts
 PMI:         71        142        227        236        101         92         58         49         45         41         41         38         86       1523   Performance monitoring interrupts
 IWI:      55977      29721      87850     115503      88726      74493      35478      25545      20509      16631      17628      15284      20174          8   IRQ work interrupts
 RTR:          0          0          0          0          0          0          0          0          0          0          0          0          0          0   APIC ICR read retries
 RES:     120042     244333     108169     115419     167112     156467     211124     162484     146131     150739     153694     193125     357759      66661   Rescheduling interrupts
 CAL:     293083     264059     489445     529908     427216     339166     241785     189781     176399     150903     141844     133108     121233     141731   Function call interrupts
 TLB:     168267     158135     211607     211632     189948     177720     159490     138424     130736     124237     117690     110943      95719     102571   TLB shootdowns
 TRM:     311850     311683     317693     346089     312264     312196     311671     311671     311671     311671     311670     311670     311668     311670   Thermal event interrupts
 THR:          0          0          0          0          0          0          0          0          0          0          0          0          0          0   Threshold APIC interrupts
 DFR:          0          0          0          0          0          0          0          0          0          0          0          0          0          0   Deferred Error APIC interrupts
 MCE:          0          0          0          0          0          0          0          0          0          0          0          0          0          0   Machine check exceptions
 MCP:         37         38         38         38         38         38         38         38         38         38         38         38         38         38   Machine check polls
 ERR:          0
 MIS:          0
 PIN:        261        282       6069       8798        609        421        260        113         55         58         29         32         38       2516   Posted-interrupt notification event
 NPI:          0          0          0          0          0          0          0          0          0          0          0          0          0          0   Nested posted-interrupt event
 PIW:          0          0          0          0          0          0          0          0          0          0          0          0          0          0   Posted-interrupt wakeup event
```