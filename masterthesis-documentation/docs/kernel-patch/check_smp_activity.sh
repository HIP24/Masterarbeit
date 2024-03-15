#!/bin/bash
for IRQ in /proc/irq/*; do
    if [ -f "$IRQ/smp_affinity" ]; then
        # Read the current smp_affinity
        AFFINITY=$(cat "$IRQ/smp_affinity")
        # Check if the bit for CPU17 is set
        if (( (0x$AFFINITY & (1 << 17)) != 0 )); then
            # Print the IRQ number
            echo "${IRQ#/proc/irq/}"
        fi
    fi
done
