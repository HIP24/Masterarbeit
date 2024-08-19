# Masterarbeit TODO

Kurzfassung

## 0. Initial
- [✅] Declaration
- [❌] Kurzfassung
- [❌] Abstract

## 1. Introduction
- [✅] 1.1 Real-Time Operating Systems
- [✅] 1.2 Application Context
- [✅] 1.3 Related Work and State of the Art
- [✅] 1.4 Problem and Task Definition
- [🔜] 1.5 Objective

## 2. Methodology
- [❌] 2.1 Yocto
- [❌] 2.2 QEMU
- [💪] 2.3 Xenomai
- [❌] 2.4 VARAN-Bus
- [💪] 2.5 Salamander 4
  - [💪] 2.5.1 Structure
  - [💪] 2.5.2 Memory Management

## 3. Implementation
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

## 4. Results
- [❌] Results

## 5. Discussion
- [❌] Discussion

## 6. Summary and Outlook
- [❌] Summary and Outlook
  - [❌] 6.1 Trace-cmd & Kernelshark

## Bibliography
- [⌛] Bibliography

## List of Figures
- [⌛] List of Figures

## List of Tables
- [⌛] List of Tables

## List of Code
- [⌛] List of Code

## List of Abbreviations
- [⌛] List of Abbreviations









Zu Beginn der Arbeit wurde eine ausführliche Analyse der einzelnen Virtualisierungsmöglichkeiten von Salamander 4 durchgeführt. Im Besonderen wurde hier die Virtualisierungsperformance von Ubuntu 22.04, Windows 10 und WSL unter QEMU verglichen.

First, a comprehensive literature review is conducted to understand the current trends and challenges in real-time robot control. Based on the literature study, a suitable virtualization platform is selected.

After the selection of the virtualization platform, the robot control platform is implemented. This step includes the installation and configuration of Salamander OS, Xenomai, QEMU and PCV-522 in the Yocto environment. Once the platform has been implemented, the robot is connected via a VARAN bus interface. Finally, the platform is evaluated to determine how the integration of real-time functions and efficient communication systems improves the response time and reliability of robot applications.

- Evaluation der Virtualisierungsplattform:
Ich werde verschiedene Virtualisierungsplattformen wie QEMU, Hyper-V, Virtual Box usw. evaluieren. Dies ist ein wichtiger Schritt, um die beste Plattform für meine Anforderungen zu finden.

- Erstellung und Konfiguration des Systems in der Yocto-Umgebung:
Ich werde das Yocto-Framework verwenden, um mein Embedded Linux System zu erstellen und zu konfigurieren. Yocto bietet viele Tools und Funktionen, die mir bei der Erstellung und Konfiguration meines Systems helfen können.


- Anbindung eines Roboters über eine VARAN-Bus Schnittstelle:
Ich plane, einen Roboter in mein System zu integrieren. Ich werde eine VARAN-Bus Schnittstelle verwenden, um eine schnelle und zuverlässige Kommunikation zwischen dem Roboter und dem Steuerungssystem zu gewährleisten.
