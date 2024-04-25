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

## Check which IRQs use CPU x
[check_smp_affinity.sh](check_smp_affinity.sh):
```
./check_smp_affinity.sh 19
CPU 19 IRQ affinity:
0
2
3
4
5
6
7
10
11
13
15
131
172
188
189
192
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
sudo chmod 777 /proc/irq/*/smp_affinity
```

## Change Mask of IRQ
Then change the mask with 
```
sudo echo 7ffff > /proc/irq/0/smp_affinity
```

## Check again the changed mask of IRQ
```
cat /proc/irq/0/smp_affinity
dffff
```

## Check again which IRQs use CPU 17
CPU17 is being used by IRQs with [check_smp_affinity.sh](check_smp_affinity.sh) (IRQ0 is not listed anymore): 
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
sudo chmod 777 /proc/irq/0/smp_affinity
sudo chmod 777 /proc/irq/2/smp_affinity
sudo chmod 777 /proc/irq/3/smp_affinity
sudo chmod 777 /proc/irq/4/smp_affinity
sudo chmod 777 /proc/irq/5/smp_affinity
sudo chmod 777 /proc/irq/6/smp_affinity
sudo chmod 777 /proc/irq/7/smp_affinity
sudo chmod 777 /proc/irq/10/smp_affinity
sudo chmod 777 /proc/irq/11/smp_affinity
sudo chmod 777 /proc/irq/13/smp_affinity
sudo chmod 777 /proc/irq/15/smp_affinity
sudo chmod 777 /proc/irq/131/smp_affinity
sudo chmod 777 /proc/irq/172/smp_affinity
sudo chmod 777 /proc/irq/188/smp_affinity
sudo chmod 777 /proc/irq/189/smp_affinity
sudo chmod 777 /proc/irq/192/smp_affinity
```


## Batch cat IRQ smp_affinity
```
cat /proc/irq/0/smp_affinity   # -> fffff
cat /proc/irq/2/smp_affinity   # -> fffff             
cat /proc/irq/3/smp_affinity   # -> fffff             
cat /proc/irq/4/smp_affinity   # -> fffff            
cat /proc/irq/5/smp_affinity   # -> fffff             
cat /proc/irq/6/smp_affinity   # -> fffff            
cat /proc/irq/7/smp_affinity   # -> fffff            
cat /proc/irq/10/smp_affinity  # -> fffff              
cat /proc/irq/11/smp_affinity  # -> fffff            
cat /proc/irq/13/smp_affinity  # -> fffff            
cat /proc/irq/15/smp_affinity  # -> fffff              
cat /proc/irq/131/smp_affinity # -> fffff              
cat /proc/irq/172/smp_affinity # -> 80000              
cat /proc/irq/188/smp_affinity # -> 80000              
cat /proc/irq/189/smp_affinity # -> fffff              
cat /proc/irq/192/smp_affinity # -> fffff              
```


## Batch change IRQ smp_affinity of fffff
```
sudo echo 7ffff > /proc/irq/0/smp_affinity
sudo echo 7ffff > /proc/irq/2/smp_affinity  # stays fffff
sudo echo 7ffff > /proc/irq/3/smp_affinity
sudo echo 7ffff > /proc/irq/4/smp_affinity
sudo echo 7ffff > /proc/irq/5/smp_affinity
sudo echo 7ffff > /proc/irq/6/smp_affinity
sudo echo 7ffff > /proc/irq/7/smp_affinity
sudo echo 7ffff > /proc/irq/10/smp_affinity
sudo echo 7ffff > /proc/irq/11/smp_affinity
sudo echo 7ffff > /proc/irq/13/smp_affinity
sudo echo 7ffff > /proc/irq/15/smp_affinity
sudo echo 7ffff > /proc/irq/131/smp_affinity
sudo echo 7ffff > /proc/irq/172/smp_affinity    # stays 80000
sudo echo 7ffff > /proc/irq/188/smp_affinity    # stays 80000
sudo echo 7ffff > /proc/irq/189/smp_affinity    # stays fffff
sudo echo 7ffff > /proc/irq/192/smp_affinity    # stays fffff
```

## COULD NOT BE CHANGED
```
2
172
188
189
192
```

## VALUES
```
cat /proc/irq/2/smp_affinity    #-> fffff
cat /proc/irq/172/smp_affinity  #-> 80000
cat /proc/irq/188/smp_affinity  #-> 80000
cat /proc/irq/189/smp_affinity  #-> fffff
cat /proc/irq/192/smp_affinity  #-> fffff
```

## Batch check permissions
```
ll /proc/irq/0/smp_affinity
ll /proc/irq/2/smp_affinity
ll /proc/irq/3/smp_affinity
ll /proc/irq/4/smp_affinity
ll /proc/irq/5/smp_affinity
ll /proc/irq/6/smp_affinity
ll /proc/irq/7/smp_affinity
ll /proc/irq/10/smp_affinity
ll /proc/irq/11/smp_affinity
ll /proc/irq/13/smp_affinity
ll /proc/irq/15/smp_affinity
ll /proc/irq/131/smp_affinity
ll /proc/irq/172/smp_affinity
ll /proc/irq/188/smp_affinity
ll /proc/irq/189/smp_affinity
ll /proc/irq/192/smp_affinity
```

## Batch check values 
```
cat /proc/irq/0/smp_affinity
cat /proc/irq/2/smp_affinity
cat /proc/irq/3/smp_affinity
cat /proc/irq/4/smp_affinity
cat /proc/irq/5/smp_affinity
cat /proc/irq/6/smp_affinity
cat /proc/irq/7/smp_affinity
cat /proc/irq/10/smp_affinity
cat /proc/irq/11/smp_affinity
cat /proc/irq/13/smp_affinity
cat /proc/irq/15/smp_affinity
cat /proc/irq/131/smp_affinity
cat /proc/irq/172/smp_affinity
cat /proc/irq/188/smp_affinity
cat /proc/irq/189/smp_affinity
cat /proc/irq/192/smp_affinity
```



































