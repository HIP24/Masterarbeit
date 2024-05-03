#!/bin/bash
# Check if a command line argument is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 directory_name"
    exit 1
fi

if [ ! -d $1/ ]; then
    # Use the command line argument as the directory name
    mkdir $1 
fi

trace-cmd report | grep kvm_exit > kvm_exit_count.txt && echo "kvm_exit_count completed"&
trace-cmd report --cpu 19 > host_report.txt && echo "host_report completed"&
trace-cmd report -i trace-Salamander4.dat > guest_report.txt && echo "guest_report completed"&
# Wait for all background jobs to finish
wait
# Now run the Python scripts
python kvm_exit_count.py && echo "kvm_exit_count plot completed"&
python analyze_tasks.py host_report.txt && echo "analyze_tasks for host_report completed"&
python analyze_tasks.py guest_report.txt && echo "analyze_tasks for guest_report completed"&
wait
# Move and Copy elements in directory 
mv *.txt results_guest_report.md results_host_report.md *.png $1
cp merge.py failed_reason.py start_kernelshark.sh *.dat $1
cd $1
python merge.py && echo "host_report and guest_report merged"
exit 0

