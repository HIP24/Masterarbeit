# gnuplot with taskset
```bash
# Set output to a PNG file
set terminal pngcairo enhanced font 'Arial,12' size 1024,768
set output 'gnuplot_max_latency_rt_kernelparam_host_qemu.png'
set encoding utf8

# Set the title and labels
#set title "Latency Distribution"
set xlabel 'Time in {/Symbol=12 m}s'
set ylabel "Samples"

# Set the range for the x axis
set xrange [0:18] 

# Set the x and y axes to logarithmic scale
#set logscale x
set logscale y

# Remove minor ticks on the axes
set mxtics 1
set mytics 1

# Add grid lines for axes
set grid ytics
set grid xtics

# Set the y-axis format to 10^n
set format y "10^{%L}"

# Plot the data with thicker lines
plot 'max_latency_rt_kernelparam_host_qemu_10min.txt' using 1:2 with lines linewidth 3 linecolor rgb "#f20505" title ''
```

![gnuplot_max_latency_rt_kernelparam_host_qemu.png](gnuplot_max_latency_rt_kernelparam_host_qemu.png)