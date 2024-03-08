#!/bin/bash

# Öffne Microsoft Edge auf Bildschirm 1
microsoft-edge &
sleep 2
wmctrl -r :ACTIVE: -e 0,0,0,1920,1080

# Öffne VS Code auf Bildschirm 3
gnome-terminal -- bash -c "cd /home/sigma_ibo/Develop/Yocto_local/salamander && code ." &
sleep 2
wmctrl -r :ACTIVE: -e 0,1920,0,960,1080

gnome-terminal -- bash -c "cd /home/sigma_ibo/Desktop/Masterarbeit && code ." &
sleep 2
wmctrl -r :ACTIVE: -e 0,2880,0,960,1080

# Öffne das erste Terminal auf der linken Seite des Bildschirms
gnome-terminal -- bash  &
sleep 2
wmctrl -r :ACTIVE: -e 0,3840,0,960,1080

# Öffne das zweite Terminal auf der rechten Seite des Bildschirms
gnome-terminal -- bash -c "cd /home/sigma_ibo/Develop/Yocto_local/salamander/salamander-core2/build/tmp/deploy/qemu/sigmatek-core2/salamander-image && sudo ./qemu_def.sh" &
sleep 2
wmctrl -r :ACTIVE: -e 0,4800,0,960,1080

# Öffne Dateimanager auf Bildschirm 2
nautilus /home/sigma_ibo/Desktop/Masterarbeit &
sleep 2
wmctrl -r :ACTIVE: -e 0,5760,0,960,1080

nautilus /home/sigma_ibo/Desktop/salamander-image &
sleep 2
wmctrl -r :ACTIVE: -e 0,6720,0,960,1080

# Öffne Virt Manager
virt-manager &
sleep 2
wmctrl -r :ACTIVE: -e 0,5760,0,1920,1080


exit 0
