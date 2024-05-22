## from Paper Virt. mixed...

Instead, the PREEMPT RT
patch provides several mechanisms like high-resolution timers, threaded interrupt handlers, priority inheritance implementation, Preemptible Read-Copy-Update (RCU), real-time schedulers, and a memory allocator.





## NUMA

```
sigma_ibo@sigma-ibo:~$ numactl --hardware
available: 1 nodes (0)
node 0 cpus: 0 1 2 3 4 5 6 7 8 9 10 11 12 13
node 0 size: 31772 MB
node 0 free: 10107 MB
node distances:
node   0 
  0:  10
```

The output of the numactl --hardware command shows the Non-Uniform Memory Access (NUMA) configuration of your system.

Here’s what each line means:

available: 1 nodes (0): This means that your system has 1 NUMA node available, and it is identified as node 0.
node 0 cpus: 0 1 2 3 4 5 6 7 8 9 10 11 12 13: This line lists the CPUs that are part of node 0. In this case, CPUs 0 through 13 are part of this node.
node 0 size: 31772 MB: This indicates that node 0 has a total of 31772 MB of memory.
node 0 free: 10107 MB: This shows that out of the total memory, 10107 MB is currently free and available for use.
node distances:: This section provides the relative distances between different NUMA nodes. Since you only have one node, there is only one entry here.
0: 10: This indicates that the distance from node 0 to itself is 10. The distance is a relative measure of the latency of memory access between nodes. A lower number means lower latency.
Since your system has only one NUMA node, all memory access is local, and you don’t need to worry about cross-node memory access. However, if you add more nodes in the future, you’ll need to consider the placement of processes and memory to minimize cross-node memory access. This can be done by setting CPU and memory affinity for your processes or threads, partitioning data across the NUMA nodes, and using NUMA-aware allocators. Always remember to measure and profile the NUMA characteristics of your application to identify areas where cross-node access is high. If you’re not comfortable making these changes yourself, it might be a good idea to seek help from someone who is.

The “distance” in NUMA architecture doesn’t refer to a physical distance, but rather to a measure of memory access latency. In this context, the distance from a node to itself is the baseline latency for accessing its own local memory.

The value “10” is a relative measure. It doesn’t represent an absolute time or delay, but serves as a reference point for comparing memory access latencies within the system. When comparing this to the latency of accessing memory on other nodes (in a multi-node system), a lower value would indicate lower latency.

So, when it says the distance from node 0 to itself is 10, it means that the latency for accessing local memory is set as the baseline reference value of 10. If there were other nodes, their distances would be compared to this baseline to determine whether accessing memory on those nodes would be faster or slower.

In a single-node system like yours, this value doesn’t have much practical impact since all memory access is local. But in a multi-node system, understanding these distances can be crucial for optimizing performance and minimizing latency.