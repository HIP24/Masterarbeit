#!/bin/bash

# Überprüfen, ob ein Prozess mit "msedge" im Namen läuft
if ! ps aux | grep -i "msedge" | grep -v "grep"
then
    # Starte Microsoft Edge, wenn es nicht bereits läuft
    microsoft-edge &
fi

# Öffne nautilus Dateimanager
#nautilus /home/sigma_ibo/Desktop/Masterarbeit &
#nautilus /home/sigma_ibo/Desktop/salamander-image &

# VS Code
konsole --new-tab -e bash -c "cd /home/sigma_ibo/Develop/Yocto_local/salamander && code ."&
konsole --new-tab -e bash -c "cd /home/sigma_ibo/Desktop/Masterarbeit && code ."&
konsole --new-tab -e bash -c "cd /home/sigma_ibo && code ."&

# Konsole 
konsole &
konsole --new-tab -e bash -c "cd /home/sigma_ibo/Develop/Yocto_local/salamander/salamander-core2/build/tmp/deploy/qemu/sigmatek-core2/salamander-image && sudo ./qemu_def.sh"&

# Öffne Virt Manager
virt-manager &

exit 0
