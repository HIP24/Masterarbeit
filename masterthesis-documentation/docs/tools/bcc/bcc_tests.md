## Without VAPIC
```bash
root@sigma-ibo:/home/sigma_ibo# kvmexit 10
Display kvm exit reasons and statistics for all threads after sleeping 100 secs.
PID      TID      KVM_EXIT_REASON                     COUNT
159607   159615   EXTERNAL_INTERRUPT                  1246    
159607   159615   HLT                                 53760   
159607   159615   MSR_READ                            20      
159607   159615   PAUSE_INSTRUCTION                   290     
159607   159615   EOI_INDUCED                         1119    
159607   159615   EPT_VIOLATION                       134     
159607   159615   EPT_MISCONFIG                       15444   
159607   159615   PREEMPTION_TIMER                    1703    
159607   159615   APIC_WRITE                          118014   
```
Total: 191 730


## With enlightment
-cpu host,hv-passthrough \
```bash
Display kvm exit reasons and statistics for all threads after sleeping 100 secs.
PID      TID      KVM_EXIT_REASON                     COUNT
158466   158474   EXTERNAL_INTERRUPT                  997     
158466   158474   HLT                                 56840   
158466   158474   MSR_READ                            121     
158466   158474   MSR_WRITE                           127832  
158466   158474   EOI_INDUCED                         1152    
158466   158474   EPT_VIOLATION                       21      
158466   158474   EPT_MISCONFIG                       15808   
158466   158474   PREEMPTION_TIMER                    1835 
```
Total: 204 606


## With hlt
-smp cores=1,threads=1 \
```bash
Display kvm exit reasons and statistics for all threads after sleeping 100 secs.
PID      TID      KVM_EXIT_REASON                     COUNT
162578   162586   EXTERNAL_INTERRUPT                  1524    
162578   162586   HLT                                 55788   
162578   162586   MSR_READ                            120     
162578   162586   MSR_WRITE                           122986  
162578   162586   EOI_INDUCED                         1153    
162578   162586   EPT_VIOLATION                       509     
162578   162586   EPT_MISCONFIG                       15819   
162578   162586   PREEMPTION_TIMER                    1677  
```
Total: 204 606


## kvm off
-cpu host,kvm=off \
```bash
Display kvm exit reasons and statistics for all threads after sleeping 100 secs.
PID      TID      KVM_EXIT_REASON                     COUNT
164064   164072   EXTERNAL_INTERRUPT                  1066    
164064   164072   HLT                                 54289   
164064   164072   MSR_READ                            120     
164064   164072   MSR_WRITE                           120032  
164064   164072   EOI_INDUCED                         1041    
164064   164072   EPT_VIOLATION                       464     
164064   164072   EPT_MISCONFIG                       15185   
164064   164072   PREEMPTION_TIMER                    1708  
```
Total: 204 606

