## Topic of Master's Thesis 
Virtualisation of a real-time operating system to control a robot with a focus on real-time compliance 

### Abstract 
Virtualization of real-time operating systems systems for robotic control has many advantages in comparison to traditional hardware-based approaches. Solutions based on pure hardware are often built for a distinct purpose and are hence limited in flexibility. It is difficult to adapt the hardware topology to new requirements and can be costly, especially when scaling operations. Physical access for updates and maintenance is challenging, leading to downtime and lost productivity. While virtualization addresses these issues, it introduces increased overhead and latency.  
This thesis investigates the virtualization of the proprietary Salamander 4 operating system, using QEMU/KVM. Salamander 4 is built with Yocto and employs hard real-time with Xenomai 3. The primary objective is to bridge the latency gap between the virtualized and bare metal versions in order to ensure deterministic and reliable behavior, which is crucial for real-time robotic applications.  
Initial latency measurements revealed a significant performance gap between the bare metal and virtualized setup. Thus, an extensive tuning process is carried out to achieve real-time performance and determinism. These modifications involve configurations spanning the BIOS, kernel, host operating system, QEMU/KVM virtualization layer, and the Salamander 4 operating system (guest) itself. The worst-case latency was brought down from 707.622μs to 17.134μs, closely aligning with the bare metal performance of 10.709μs. In addition, the improvement in real-time performance and determinism is validated using a robotic application, where the tuned virtualization is compared with the untuned and the hardware version.  
Altogether, this thesis provides a comprehensive blueprint for making a virtualized guest system real-time capable in a host system with deterministic behavior.  

Keywords{Virtualization, Real-Time Systems, Latency Reduction, Robotic Control}


### Documentation
`mkdocs gh-deploy`  
[Masterthesis documentation](https://hip24.github.io/Masterarbeit/)