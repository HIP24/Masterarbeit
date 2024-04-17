## Without VAPIC
```
root@sigma-ibo:/home/sigma_ibo# kvmexit 10
Display kvm exit reasons and statistics for all threads after sleeping 10 secs.
PID      TID      KVM_EXIT_REASON                     COUNT
16761    16768    EXTERNAL_INTERRUPT                  93
16761    16768    HLT                                 5965
16761    16768    MSR_READ                            2
16761    16768    PAUSE_INSTRUCTION                   30
16761    16768    EOI_INDUCED                         79
16761    16768    EPT_VIOLATION                       1
16761    16768    EPT_MISCONFIG                       1189
16761    16768    PREEMPTION_TIMER                    119
16761    16768    APIC_WRITE                          13592
```
Total: 21 070


## With VAPIC
```
root@sigma-ibo:/home/sigma_ibo# kvmexit 10
Display kvm exit reasons and statistics for all threads after sleeping 10 secs.
PID      TID      KVM_EXIT_REASON                     COUNT
23708    23731    EXTERNAL_INTERRUPT                  363
23708    23731    HLT                                 5201
23708    23731    MSR_READ                            12
23708    23731    MSR_WRITE                           11122
23708    23731    EOI_INDUCED                         110
23708    23731    EPT_VIOLATION                       31
23708    23731    EPT_MISCONFIG                       1527
23708    23731    PREEMPTION_TIMER                    217
```
Total: 18 583
