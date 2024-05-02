# gnuplot vapic
```bash
# Calculate statistics
stats 'max_latency_vapic_10min.txt' using 2 nooutput

# Plot the data
plot 'max_latency_vapic_10min.txt' using 1:2 with linespoints title 'Latency Histogram'
```

![gnuplot_max_latency_vapic.png](gnuplot_max_latency_vapic.png)