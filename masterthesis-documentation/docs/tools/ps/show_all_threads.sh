#!/bin/bash
ps axHo pid,lwp,comm,policy,nice,rtprio > show_all_threads.txt
python show_all_threads.py
if [ ! -d "show_all_threads_generated" ]; then
  mkdir show_all_threads_generated
fi
mv show_all_threads.txt show_all_threads.md show_all_threads_grouped.md show_all_threads_generated

