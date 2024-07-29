#!/bin/bash
python process-tree.py
if [ ! -d "process-tree_generated" ]; then
  mkdir process-tree_generated
fi
mv process-tree.md process-tree_generated


