## Select best CPU for QEMU
```
sigma_ibo@pamhal:$ cat /sys/devices/system/cpu/cpu*/cpufreq/cpuinfo_max_freq
5000000
5000000
5000000
4000000
4000000
4000000
4000000
4000000
4000000
4000000
4000000
5000000
5000000
5000000
5200000
5200000
5200000
5200000 -> 17
5000000
5000000
```

## Check which IRQs use CPU 17
CPU17 is being used by IRQs with [check_smp_activity.sh](check_smp_activity.sh):
```
0
10
11
13
138
15
191
194
2
208
214
3
4
5
6
7
```

## Check the mask of IRQ
The mask for IRQ0 for example would be: 
```
cat /proc/irq/0/smp_affinity
fffff
```

## Change permissions for the IRQs
In order to change the mask, first give permissions:
```
chmod 777 /proc/irq/*/smp_affinity
```

## Change Mask of IRQ
Then change the mask with 
```
sudo echo dffff > /proc/irq/0/smp_affinity
```

## Check again the changed mask of IRQ
```
cat /proc/irq/0/smp_affinity
dffff
```

## Check again which IRQs use CPU 17
CPU17 is being used by IRQs with [check_smp_activity.sh](check_smp_activity.sh) (IRQ0 is not listed anymore): 
```
10
11
13
138
15
191
194
2
208
214
3
4
5
6
7
```



## Batch change permissions
```
sudo chmod 777 /proc/irq/10/smp_affinity
sudo chmod 777 /proc/irq/11/smp_affinity
sudo chmod 777 /proc/irq/13/smp_affinity
sudo chmod 777 /proc/irq/138/smp_affinity
sudo chmod 777 /proc/irq/15/smp_affinity
sudo chmod 777 /proc/irq/191/smp_affinity
sudo chmod 777 /proc/irq/194/smp_affinity
sudo chmod 777 /proc/irq/2/smp_affinity
sudo chmod 777 /proc/irq/208/smp_affinity
sudo chmod 777 /proc/irq/214/smp_affinity
sudo chmod 777 /proc/irq/3/smp_affinity
sudo chmod 777 /proc/irq/4/smp_affinity
sudo chmod 777 /proc/irq/5/smp_affinity
sudo chmod 777 /proc/irq/6/smp_affinity
sudo chmod 777 /proc/irq/7/smp_affinity
```

## Batch cat IRQ smp_affinity
```
cat /proc/irq/10/smp_affinity  -> fffff
cat /proc/irq/11/smp_affinity  -> fffff
cat /proc/irq/13/smp_affinity  -> fffff
cat /proc/irq/138/smp_affinity -> fffff
cat /proc/irq/15/smp_affinity  -> fffff
cat /proc/irq/191/smp_affinity -> 20000
cat /proc/irq/194/smp_affinity -> fffff
cat /proc/irq/2/smp_affinity   -> fffff
cat /proc/irq/208/smp_affinity -> 20000
cat /proc/irq/214/smp_affinity -> fffff
cat /proc/irq/3/smp_affinity   -> fffff
cat /proc/irq/4/smp_affinity   -> fffff
cat /proc/irq/5/smp_affinity   -> fffff
cat /proc/irq/6/smp_affinity   -> fffff
cat /proc/irq/7/smp_affinity   -> fffff
```

## Batch change IRQ smp_affinity of fffff
```
sudo echo dffff > /proc/irq/10/smp_affinity
sudo echo dffff > /proc/irq/11/smp_affinity
sudo echo dffff > /proc/irq/13/smp_affinity
sudo echo dffff > /proc/irq/138/smp_affinity
sudo echo dffff > /proc/irq/15/smp_affinity
sudo echo dffff > /proc/irq/3/smp_affinity
sudo echo dffff > /proc/irq/4/smp_affinity
sudo echo dffff > /proc/irq/5/smp_affinity
sudo echo dffff > /proc/irq/6/smp_affinity
sudo echo dffff > /proc/irq/7/smp_affinity
```

## COULD NOT BE CHANGED
```
191
194
2
208
214
```

## VALUES
```
cat /proc/irq/191/smp_affinity   -> 20000
cat /proc/irq/194/smp_affinity   -> fffff
cat /proc/irq/2/smp_affinity   -> fffff
cat /proc/irq/208/smp_affinity   -> 20000
cat /proc/irq/214/smp_affinity   -> fffff
```

## Batch check permissions
```
ll /proc/irq/0/smp_affinity
ll /proc/irq/10/smp_affinity
ll /proc/irq/11/smp_affinity
ll /proc/irq/13/smp_affinity
ll /proc/irq/138/smp_affinity
ll /proc/irq/15/smp_affinity
ll /proc/irq/191/smp_affinity
ll /proc/irq/194/smp_affinity
ll /proc/irq/2/smp_affinity
ll /proc/irq/208/smp_affinity
ll /proc/irq/214/smp_affinity
ll /proc/irq/3/smp_affinity
ll /proc/irq/4/smp_affinity
ll /proc/irq/5/smp_affinity
ll /proc/irq/6/smp_affinity
ll /proc/irq/7/smp_affinity
```

## Batch check values 
```
cat /proc/irq/0/smp_affinity
cat /proc/irq/10/smp_affinity
cat /proc/irq/11/smp_affinity
cat /proc/irq/13/smp_affinity
cat /proc/irq/138/smp_affinity
cat /proc/irq/15/smp_affinity
cat /proc/irq/191/smp_affinity
cat /proc/irq/194/smp_affinity
cat /proc/irq/2/smp_affinity
cat /proc/irq/208/smp_affinity
cat /proc/irq/214/smp_affinity
cat /proc/irq/3/smp_affinity
cat /proc/irq/4/smp_affinity
cat /proc/irq/5/smp_affinity
cat /proc/irq/6/smp_affinity
cat /proc/irq/7/smp_affinity
```



































