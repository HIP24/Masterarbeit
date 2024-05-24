# gnuplot with taskset
```bash
# Calculate statistics
stats 'gnup.txt' using 2 nooutput

# Plot the data
plot 'gnup.txt' using 1:2 with linespoints title 'Latency Histogram'
```

![.png](.png)