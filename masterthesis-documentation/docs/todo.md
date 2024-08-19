# Masterarbeit TODO

### 0. Initial
- [✅] Declaration
- [❌] Kurzfassung
- [❌] Abstract

### 1. Introduction
- [✅] 1.1 Real-Time Operating Systems
- [✅] 1.2 Application Context
- [✅] 1.3 Related Work and State of the Art
- [✅] 1.4 Problem and Task Definition
- [✅] 1.5 Objective

### 2. Methodology
- [✅] 2.1 Host Operating System
- [✅] 2.2 Guest Operating System 
  - [✅] 2.5.1 Structure
  - [✅] 2.5.2 Memory Management
- [✅] 2.3 Yocto
- [✅] 2.4 Xenomai
- [❌] 2.5 QEMU
- [💪] 2.6 Trace-cmd
- [💪] 2.7 Kernelshark
- [❌] 2.8 VARAN-Bus

### 3. Implementation
- [💪] 3.1 Initial Situation
  - [💪] 3.1.1 Salamander 4 Bare Metal
  - [💪] 3.1.2 Salamander 4 Virtualization
- [❌] 3.2 Real-Time Performance Tuning
  - [💪] 3.2.1 BIOS Configurations
  - [💪] 3.2.2 Kernel Configurations
  - [💪] 3.2.3 Host OS Configurations
    - [💪] 3.2.3.1 CPU affinity and Isolation
    - [💪] 3.2.3.2 KVM Entry and KVM Exit
    - [💪] 3.2.3.3 Interrupt Affinity
    - [💪] 3.2.3.4 RT-Priority
    - [💪] 3.2.3.5 Disable RT Throttling
    - [💪] 3.2.3.6 Disable Timer Migration
    - [💪] 3.2.3.7 Set Device Driver Work Queue
    - [💪] 3.2.3.8 Disable RCU CPU Stall Warnings
    - [💪] 3.2.3.9 Stop Certain Services
    - [💪] 3.2.3.10 Disable Machine Check
    - [💪] 3.2.3.11 Boot into text-based environment
  - [💪] 3.2.4 QEMU/KVM Configurations
    - [💪] 3.2.4.1 Tune LAPIC Timer Advance
    - [💪] 3.2.4.2 Set QEMU Options for real-time VM
  - [❌] 3.2.5 Guest OS Configurations
  - [💪] 3.2.6 Other Configurations
- [❌] 3.3 Real-Time Robotic Application
  - [💪] 3.3.1 Setup of Hardware Salamander 4
  - [💪] 3.3.2 Setup of QEMU Salamander 4
  - [❌] 3.3.3 Robotic Application

### 4. Results
- [❌] Results

### 5. Discussion
- [❌] Discussion

### 6. Summary and Outlook
- [❌] Summary and Outlook
  - [❌] 6.1 Trace-cmd & Kernelshark

### Bibliography
- [❌] Bibliography

### List of Figures
- [⌛] List of Figures

### List of Tables
- [⌛] List of Tables

### List of Code
- [⌛] List of Code

### List of Abbreviations
- [⌛] List of Abbreviations

<hr>

| Day       | Task                                                                 |
|-----------|----------------------------------------------------------------------|
| Monday    | - [✅] 1.5 Objective<br>- [✅] 2.1 Host Operating System<br>- [✅] 2.2 Guest Operating System<br>  - [✅] 2.5.1 Structure<br>  - [✅] 2.5.2 Memory Management<br>- [✅] 2.3 Yocto<br>- [✅] 2.4 Xenomai |
| Tuesday   | - [❌] 2.5 QEMU<br>- [💪] 2.6 Trace-cmd<br>- [💪] 2.7 Kernelshark<br>- [❌] 2.8 VARAN-Bus <br>- [💪] 3.1 Initial Situation<br>  - [💪] 3.1.1 Salamander 4 Bare Metal<br>  - [💪] 3.1.2 Salamander 4 Virtualization |
| Wednesday | - [❌] 3.2 Real-Time Performance Tuning<br>  - [💪] 3.2.1 BIOS Configurations<br>  - [💪] 3.2.2 Kernel Configurations<br>  - [💪] 3.2.3 Host OS Configurations<br>    - [💪] 3.2.3.1 CPU affinity and Isolation<br>    - [💪] 3.2.3.2 KVM Entry and KVM Exit<br>    - [💪] 3.2.3.3 Interrupt Affinity<br>    - [💪] 3.2.3.4 RT-Priority<br>    - [💪] 3.2.3.5 Disable RT Throttling<br>    - [💪] 3.2.3.6 Disable Timer Migration<br>    - [💪] 3.2.3.7 Set Device Driver Work Queue<br>    - [💪] 3.2.3.8 Disable RCU CPU Stall Warnings<br>    - [💪] 3.2.3.9 Stop Certain Services<br>    - [💪] 3.2.3.10 Disable Machine Check<br>    - [💪] 3.2.3.11 Boot into text-based environment<br>  - [💪] 3.2.4 QEMU/KVM Configurations<br>    - [💪] 3.2.4.1 Tune LAPIC Timer Advance<br>    - [💪] 3.2.4.2 Set QEMU Options for real-time VM<br>  - [❌] 3.2.5 Guest OS Configurations<br>  - [💪] 3.2.6 Other Configurations |
| Thursday  | - [❌] 3.3 Real-Time Robotic Application<br>  - [💪] 3.3.1 Setup of Hardware Salamander 4<br>  - [💪] 3.3.2 Setup of QEMU Salamander 4<br>  - [❌] 3.3.3 Robotic Application |
| Friday    | - [❌] Results<br>- [❌] Discussion<br>- [❌] Summary and Outlook<br>  - [❌] 6.1 Trace-cmd & Kernelshark |
| Saturday  | - [❌] Kurzfassung<br>- [❌] Abstract |
| Sunday    | - [❌] Bibliography<br>- [⌛] List of Figures<br>- [⌛] List of Tables<br>- [⌛] List of Code<br>- [⌛] List of Abbreviations |
| Monday    | Paper schreiben |
| Tuesday   | Presentation |



1. Abgabe über CIS:

2. Abgabe über Moodle (DIPL-SE):
- Masterthesis als PDF und LaTeX-Quellcode mit digital signierter eidesstattlicher Erklärung; Dateinamen: Familienname_MT_Datum_Version.
- Paper als PDF und LaTeX-Quellcode; Dateinamen: Familienname_MT_Paper_Datum_Version. - max. 2 DIN A4 Seiten, ca. 1.000 Worte, Sprache identisch mit der Sprache der Masterarbeit
- Sonstiges Dateien (z.B. Freigaben für die Verwendung von Bildern in der Masterthesis) in Unterordnern
- Powerpoint-Präsentation der Masterarbeit
- Videos zur Masterarbeit




Zu Beginn der Arbeit wurde eine ausführliche Analyse der einzelnen Virtualisierungsmöglichkeiten von Salamander 4 durchgeführt. Im Besonderen wurde hier die Virtualisierungsperformance von Ubuntu 22.04, Windows 10 und WSL unter QEMU verglichen.

First, a comprehensive literature review is conducted to understand the current trends and challenges in real-time robot control. Based on the literature study, a suitable virtualization platform is selected.

After the selection of the virtualization platform, the robot control platform is implemented. This step includes the installation and configuration of Salamander OS, Xenomai, QEMU and PCV-522 in the Yocto environment. Once the platform has been implemented, the robot is connected via a VARAN bus interface. Finally, the platform is evaluated to determine how the integration of real-time functions and efficient communication systems improves the response time and reliability of robot applications.

- Evaluation der Virtualisierungsplattform:
Ich werde verschiedene Virtualisierungsplattformen wie QEMU, Hyper-V, Virtual Box usw. evaluieren. Dies ist ein wichtiger Schritt, um die beste Plattform für meine Anforderungen zu finden.

- Erstellung und Konfiguration des Systems in der Yocto-Umgebung:
Ich werde das Yocto-Framework verwenden, um mein Embedded Linux System zu erstellen und zu konfigurieren. Yocto bietet viele Tools und Funktionen, die mir bei der Erstellung und Konfiguration meines Systems helfen können.


- Anbindung eines Roboters über eine VARAN-Bus Schnittstelle:
Ich plane, einen Roboter in mein System zu integrieren. Ich werde eine VARAN-Bus Schnittstelle verwenden, um eine schnelle und zuverlässige Kommunikation zwischen dem Roboter und dem Steuerungssystem zu gewährleisten.
