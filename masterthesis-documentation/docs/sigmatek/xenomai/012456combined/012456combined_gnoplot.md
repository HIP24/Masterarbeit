# gnuplot combined
```bash
# Set output to a PNG file
set terminal pngcairo enhanced font 'Arial,12' size 1024,768
set output 'gnuplot_combined_max_latency.png'
set encoding utf8

# Set the title and labels
#set title "Latency Distribution"
set xlabel 'Time in {/Symbol=12 m}s'
set ylabel "Samples"

# Set the range for the x axis
set xrange [0:800] # Start from 10 to avoid log scale issues

# Set the x and y axes to logarithmic scale
set logscale x
set logscale y

# Remove minor ticks on the axes
set mxtics 1
set mytics 1

# Add grid lines for axes
set grid ytics
set grid xtics

# Set the y-axis format to 10^n
set format y "10^{%L}"

# Set custom-defined steps for the x-axis
set xtics (0, 1, 10, 100, 200, 400, 800)

# Plot the data with thicker lines and different colors
plot '../0hardware/max_latency_hardware_10min.txt' using 1:2 with lines linewidth 2 linecolor rgb "#800080" title 'Salamander 4 Bare Metal', \
     '../1default/max_latency_default_10min.txt' using 1:2 with lines linewidth 2 linecolor rgb "blue" title 'Untuned Salamander 4 Virtualization', \
     '../2taskset/max_latency_taskset_10min.txt' using 1:2 with lines linewidth 2 linecolor rgb "#fe06ba" title 'After BIOS Configurations', \
     '../4rt_kernelparam/max_latency_rt_kernelparam_10min.txt' using 1:2 with lines linewidth 2 linecolor rgb "#298a24" title 'After Kernel Configurations', \
     '../5rt_kernelparam_host/max_latency_rt_kernelparam_host_10min.txt' using 1:2 with lines linewidth 2 linecolor rgb "#f29105" title 'After Host Configurations', \
     '../6rt_kernelparam_host_qemu/max_latency_rt_kernelparam_host_qemu_10min.txt' using 1:2 with lines linewidth 2 linecolor rgb "#f20505" title 'After QEMU Configurations'
```

![gnuplot_combined_max_latency.png](gnuplot_combined_max_latency.png)
