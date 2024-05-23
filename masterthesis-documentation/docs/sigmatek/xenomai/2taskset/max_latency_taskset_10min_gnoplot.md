# gnuplot with taskset
```bash
# Calculate statistics
stats 'max_latency_with_taskset_10min.txt' using 2 nooutput

# Plot the data
plot 'max_latency_with_taskset_10min.txt' using 1:2 with linespoints title 'Latency Histogram'
```

![gnuplot_max_latency_taskset.png.png](gnuplot_max_latency_taskset.png)