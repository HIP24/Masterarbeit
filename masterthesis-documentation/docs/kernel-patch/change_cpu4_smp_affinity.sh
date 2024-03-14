#!/bin/bash
for IRQ in /proc/irq/*; do
    if [ -f "$IRQ/smp_affinity" ]; then
        echo fffbf > "$IRQ/smp_affinity"
    fi
done

