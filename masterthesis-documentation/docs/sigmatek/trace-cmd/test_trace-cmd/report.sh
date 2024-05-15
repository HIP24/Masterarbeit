#!/bin/bash
# Check if a command line argument is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 directory_name"
    exit 1
fi

if [ ! -d $1/ ]; then
    # Use the command line argument as the directory name
    mkdir $1 
    mkdir $1/tasks $1/events $1/kvm_exits
fi

trace-cmd report --cpu 19 > host_report.txt && echo "host_report completed"
trace-cmd report -i trace-Salamander4.dat > guest_report.txt && echo "guest_report completed"
cat host_report.txt | grep kvm_exit > kvm_exit_count.txt && echo "kvm_exit_count completed"
# Wait for all background jobs to finish
wait
# Now run the Python scripts
python analyze_tasks.py host_report.txt && echo "analyze_tasks for host_report completed"&
python analyze_tasks.py guest_report.txt && echo "analyze_tasks for guest_report completed"&
python analyze_events.py host_report.txt && echo "analyze_events for host_report completed"&
python analyze_events.py guest_report.txt && echo "analyze_events for guest_report completed"&
python kvm_exit_count.py kvm_exit_count.txt && echo "kvm_exit_count plot completed"&
wait
# Move and Copy elements in directory 
mv *.txt $1/
mv events_host_report.* events_guest_report.*  $1/events
mv tasks_host_report.* tasks_guest_report.*  $1/tasks
mv kvm_exit_count.png  $1
cp merge.py failed_reason.py start_kernelshark.sh *.dat $1

# Merge host and guest report
cd $1
python merge.py && echo "host_report and guest_report merged"
mv kvm_exit_count.* kvm_exits
rm merge.py
exit 0
