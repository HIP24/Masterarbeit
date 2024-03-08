#!/bin/bash

# Öffne Microsoft Edge auf Bildschirm 1
microsoft-edge &

# Öffne Dateimanager auf Bildschirm 2
nautilus /home/sigma_ibo/Desktop/Masterarbeit &

nautilus /home/sigma_ibo/Desktop/salamander-image &

# Öffne VS Code auf Bildschirm 3
konsole --new-tab -e bash -c "cd /home/sigma_ibo/Develop/Yocto_local/salamander && code ."

konsole --new-tab -e bash -c "cd /home/sigma_ibo/Desktop/Masterarbeit && code ."

# Öffne das erste Terminal auf der linken Seite des Bildschirms
konsole --new-tab -e bash -c "cd"

# Öffne das zweite Terminal auf der rechten Seite des Bildschirms
konsole --new-tab -e bash -c "cd /home/sigma_ibo/Develop/Yocto_local/salamander/salamander-core2/build/tmp/deploy/qemu/sigmatek-core2/salamander-image && sudo ./qemu_def.sh"

# Öffne Virt Manager
virt-manager &

exit 0
