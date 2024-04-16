#!/bin/bash
trace-cmd report | grep kvm_exit > kvm_exit_count.txt && echo "kvm_exit_count completed"&
trace-cmd report --cpu 19 > host_report.txt && echo "host_report completed"&
trace-cmd report -i trace-Salamander4.dat > guest_report.txt && echo "guest_report completed"&
# Wait for all background jobs to finish
wait
# Now run the Python scripts
python analyze_trace.py host_report.txt && echo "analyze_trace for host_report completed"&
python analyze_trace.py guest_report.txt && echo "analyze_trace for guest_report completed"&
wait
exit 0