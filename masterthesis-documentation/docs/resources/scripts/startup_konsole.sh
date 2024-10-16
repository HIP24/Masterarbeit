#!/bin/bash

# Set CPU masks in konsole
konsole --new-tab -e bash -c "echo 2f | sudo tee /sys/bus/workqueue/devices/writeback/cpumask"&
konsole --new-tab -e bash -c "echo 2f | sudo tee /sys/devices/virtual/workqueue/cpumask"&
konsole --new-tab -e bash -c "echo 0 | sudo tee /sys/devices/system/machinecheck/machinecheck0/check_interval"&
konsole --new-tab -e bash -c "sudo systemctl stop irqbalance.service"&
konsole --new-tab -e bash -c "sudo systemctl stop wpa_supplicant.service"&
konsole --new-tab -e bash -c "sudo systemctl stop thermald.service"&
konsole --new-tab -e bash -c "echo 7500 | sudo tee /sys/module/kvm/parameters/lapic_timer_advance_ns"&
wait

# Initialize PCI slot
konsole --new-tab -e bash -c "sudo sh -c 'echo \"5112 2200\" > /sys/bus/pci/drivers/vfio-pci/new_id'"


# VS Code
konsole --new-tab -e bash -c "cd /home/robot_ibo/Develop/salamander && code ."&
konsole --new-tab -e bash -c "cd /home/robot_ibo/Desktop/Masterarbeit && code ."&
konsole --new-tab -e bash -c "cd /home/robot_ibo && code ."&

# Konsole
konsole &
konsole --new-tab -e bash -c "cd /home/robot_ibo/Develop/salamander/salamander-core2/build/tmp/deploy/qemu/sigmatek-core2/salamander-image && sudo ./qemu_def.sh"&
#konsole --new-tab -e bash -c "cd /home/robot_ibo/Desktop/Masterarbeit/masterthesis-documentation/docs/sigmatek/salamander4/latency_reduction/IRQaffinity && ./cpuaffinity.sh"&
#konsole --new-tab -e bash -c "cd /home/sigma_ibo/Desktop/Masterarbeit/masterthesis-documentation/docs/sigmatek/salamander4/latency_reduction/IRQaffinity && ./remove_irqs_from_CPU.sh 4"&


# Konsole 
konsole --new-tab -e bash -c "cd /home/sigma_ibo/Desktop/Masterarbeit/masterthesis-documentation/docs/sigmatek/salamander4/latency_reduction/IRQaffinity && ./cpuaffinity.sh"&




# Überprüfen, ob ein Prozess mit "htop" im Namen läuft
if ! ps aux | grep -i "htop" | grep -v "grep"
then
    # Starte Microsoft Edge, wenn es nicht bereits läuft
    konsole --new-tab -e bash -c "htop"&
fi

# Überprüfen, ob ein Prozess mit "top" im Namen läuft
if ! ps aux | grep -i "top" | grep -v "grep"
then
    # Starte Microsoft Edge, wenn es nicht bereits läuft
    konsole --new-tab -e bash -c "top"&
fi

# Überprüfen, ob ein Prozess mit "msedge" im Namen läuft
if ! ps aux | grep -i "msedge" | grep -v "grep"
then
    # Starte Microsoft Edge, wenn es nicht bereits läuft
    microsoft-edge &
fi

# Öffne Virt Manager
virt-manager &

# Öffne Mechvibes
mechvibes &

exit 0