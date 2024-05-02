```bash
sigma_ibo@sigma-ibo:~$ ls /proc/464458/task | wc -l
6
sigma_ibo@sigma-ibo:~$ ps -e | grep qemu-system-x86
 464458 pts/1    00:00:19 qemu-system-x86
sigma_ibo@sigma-ibo:~$ top -H -p 464458
```
