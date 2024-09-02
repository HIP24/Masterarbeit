#!/bin/bash
# Check if a command line argument is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 directory_name"
    exit 1
fi

if [ ! -d $1/ ]; then
    # Use the command line argument as the directory name
    mkdir $1 
    mkdir $1/tasks $1/events
fi

trace-cmd report --cpu 0 > report_cpu0.txt && echo "report_cpu0 completed"&
trace-cmd report --cpu 1 > report_cpu1.txt && echo "report_cpu1 completed"&
# Wait for all background jobs to finish

wait
# Now run the Python scripts
python analyze_tasks.py report_cpu0.txt && echo "analyze_tasks for report_cpu0 completed"&
python analyze_events.py report_cpu0.txt && echo "analyze_events for report_cpu0 completed"&

python analyze_tasks.py report_cpu1.txt && echo "analyze_tasks for report_cpu1 completed"&
python analyze_events.py report_cpu1.txt && echo "analyze_events for report_cpu1 completed"&

wait
# Move and Copy elements in directory 
mv *.txt $1/
mv events_report_cpu* $1/events
mv tasks_report_cpu*  $1/tasks
cp start_kernelshark.sh *.dat $1

exit 0

