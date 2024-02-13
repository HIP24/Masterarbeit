#!/bin/bash

# Öffne zwei Ordner mit dem Dateimanager
nautilus /home/sigma_ibo/Desktop/Masterarbeit &
nautilus /home/sigma_ibo/Desktop/salamander-image &

# Öffne ein Terminal und navigiere zu einem bestimmten Verzeichnis, dann öffne VS Code
gnome-terminal -- bash -c "cd /home/sigma_ibo/Develop/Yocto/salamander4 && code ."

# Öffne ein weiteres Terminal und navigiere zu einem anderen Verzeichnis, dann öffne VS Code
gnome-terminal -- bash -c "cd /home/sigma_ibo/Desktop/Masterarbeit && code ."

# Öffne ein Terminal, navigiere zu einem bestimmten Verzeichnis und führe ein Skript aus
gnome-terminal -- bash -c "cd /home/sigma_ibo/Develop/Yocto/salamander4/salamander-core2/build/tmp/deploy/qemu/sigmatek-core2/salamander-image && sudo ./qemu_def.sh"

# Öffne ein Terminal, navigiere zu einem bestimmten Verzeichnis und führe ein Skript aus
gnome-terminal -- bash 

# Öffne Microsoft Edge
microsoft-edge &

exit 0
