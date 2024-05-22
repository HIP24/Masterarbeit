<!DOCTYPE html>
<html>
<body>

<div style="display: flex; justify-content: space-around;">
  <div style="width: 48%;">
    <h3>Salamander 4 Hardware auf CP 841</h3>
    <img src="hardware/max_latency_hardware/max_latency_hardware.png" alt="Hardware" style="width:100%;">
    Average latency: 4.06us<br>
    Max latency: 10.709us<br>
    Min latency: 2.817us<br>
    Standard Deviation: 0.85us<br>
  </div>
  <div style="width: 48%;">
    <h3>Salamander 4 Default Yocto Build</h3>
    <img src="default/max_latency_default/max_latency_default.png" alt="Default" style="width:100%;">
    Average latency: 174.5us<br>
    Max latency: 4070.018us<br>
    Min latency: 6.963us<br>
    Standard Deviation: 359.27us<br>
  </div>
</div>

<div style="display: flex; justify-content: space-around;">
  <div style="width: 48%;">
    <h3>Nach taskset -c 13</h3>
    <img src="taskset/max_latency_taskset/max_latency_taskset.png" alt="Taskset" style="width:100%;">
    Average latency: 74.78us<br>
    Max latency: 457.545us<br>
    Min latency: 14.113us<br>
    Standard Deviation: 29.43us<br>
  </div>
  <div style="width: 48%;">
    <h3>Nach PREEMPT_RT Patch und Kernel Tuning</h3>
    <img src="rt/max_latency_rt/max_latency_rt.png" alt="RT" style="width:100%;">
    Average latency: 17.68us <br>
    Max latency: 32.216us<br>
    Min latency: 8.005us<br>
    Standard Deviation: 6.1us<br>
  </div>
</div>

</body>
</html>
