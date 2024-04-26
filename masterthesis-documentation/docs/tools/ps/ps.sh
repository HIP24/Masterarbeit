#!/bin/bash
ps -e > ps.txt
python amount.py
if [ ! -d "amount_generated" ]; then
  mkdir amount_generated
fi
mv amount.md amount_group.md ps.txt amount_generated

