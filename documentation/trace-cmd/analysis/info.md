## Tools
<a href="https://www.trace-cmd.org/" target="_blank">trace-cmd.org</a>  
<a href="https://kernelshark.org/" target="_blank">kernelshark.org</a>  

## Documentation
<a href="https://trace-cmd.org/Documentation/trace-cmd/" target="_blank">trace-cmd/documentation</a>  
<a href="https://kernelshark.org/Documentation.html" target="_blank">kernelshark/documentation</a>


## All information from LTS README
<a href="../LTS/trace-cmd-v3.2/README.md" target="_blank">trace-cmd</a>  
<a href="../LTS/kernel-shark-kernelshark-v2.1.0/README.md" target="_blank">kernel-shark</a>  
<a href="../LTS/libtracefs-1.8.0/README.md" target="_blank">libtracefs</a>  
<a href="../LTS/libtraceevent-1.8.2/README.md" target="_blank">libtraceevent</a>  
<a href="../LTS/trace-cmd-libtracecmd-1.5.1/README.md" target="_blank">libtracecmd</a>  


## Usage trace-cmd
trace-cmd [COMMAND] ...

| Command         | Description                                            |
|-----------------|--------------------------------------------------------|
| record          | Record a trace into a trace.dat file                    |
| set             | Set a ftrace configuration parameter                   |
| start           | Start tracing without recording into a file            |
| extract         | Extract a trace from the kernel                         |
| stop            | Stop the kernel from recording trace data               |
| restart         | Restart the kernel trace data recording                |
| show            | Show the contents of the kernel tracing buffer         |
| reset           | Disable all kernel tracing and clear the trace buffers  |
| clear           | Clear the trace buffers                                 |
| report          | Read out the trace stored in a trace.dat file           |
| stream          | Start tracing and read the output directly             |
| profile         | Start profiling and read the output directly           |
| hist            | Show a histogram of the trace.dat information           |
| stat            | Show the status of the running tracing (ftrace) system |
| split           | Parse a trace.dat file into smaller file(s)            |
| options         | List the plugin options available for trace-cmd report |
| listen          | Listen on a network socket for trace clients            |
| agent           | Listen on a vsocket for trace clients                   |
| setup-guest     | Create FIFOs for tracing guest VMs                      |
| list            | List the available events, plugins, or options          |
| restore         | Restore a crashed record                                |
| snapshot        | Take a snapshot of the running trace                    |
| stack           | Output, enable, or disable kernel stack tracing        |
| check-events    | Parse trace event formats                               |
| dump            | Read out the metadata from a trace file                  |
| attach          | Attach a host and guest trace.dat file                  |
| convert         | Convert a trace file to a different version             |


## Usage kernelshark
```
kernelshark # host only  
kernelshark trace.dat -a trace-Salamander4.dat #host with guest
```


