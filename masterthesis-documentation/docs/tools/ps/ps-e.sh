#!/bin/bash
ps -e > ps-e.txt
python ps-e.py
if [ ! -d "ps-e_generated" ]; then
  mkdir ps-e_generated
fi
mv ps-e_amount.md ps-e_amount_group.md ps-e.txt ps-e_generated

