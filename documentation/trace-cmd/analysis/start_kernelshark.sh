#!/bin/bash

sudo trace-cmd convert -i trace.dat -o trace_v6.dat --file-version 6 --compression none
sudo rm trace.dat
mv trace_v6.dat trace.dat
sudo trace-cmd convert -i trace-Salamander4.dat -o trace_v6.dat --file-version 6 --compression none
sudo rm trace-Salamander4.dat
mv trace_v6.dat trace-Salamander4.dat
kernelshark trace.dat -a trace-Salamander4.dat
