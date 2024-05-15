After 180 seconds -> overrun in QEMU
``
sigma_ibo@sigma-ibo:~$ sudo dmesg
```
Result
```
[ 1713.125529] rcu: INFO: rcu_preempt self-detected stall on CPU
[ 1713.125531] rcu:     13-....: (1 GPs behind) idle=763/1/0x4000000000000000 softirq=0/0 fqs=96965 
[ 1713.125534]  (t=195012 jiffies g=160309 q=122071)
[ 1713.125536] NMI backtrace for cpu 13
[ 1713.125537] CPU: 13 PID: 4606 Comm: qemu-system-x86 Not tainted 5.15.0-1063-realtime #71-Ubuntu
[ 1713.125538] Hardware name: Dell Inc. Precision 3581/0V8YXF, BIOS 1.12.0 03/11/2024
[ 1713.125539] Call Trace:
[ 1713.125540]  <IRQ>
[ 1713.125542]  show_stack+0x52/0x5c
[ 1713.125546]  dump_stack_lvl+0x4a/0x63
[ 1713.125549]  dump_stack+0x10/0x16
[ 1713.125550]  nmi_cpu_backtrace.cold+0x4d/0x92
[ 1713.125551]  ? __wake_up_klogd.part.0+0x64/0xd0
[ 1713.125554]  ? lapic_can_unplug_cpu+0xd0/0xd0
[ 1713.125555]  nmi_trigger_cpumask_backtrace+0x148/0x160
[ 1713.125558]  arch_trigger_cpumask_backtrace+0x19/0x20
[ 1713.125558]  rcu_dump_cpu_stacks+0x115/0x1b0
[ 1713.125561]  print_cpu_stall.cold+0x44/0xe7
[ 1713.125562]  ? account_guest_time+0xc8/0x160
[ 1713.125564]  check_cpu_stall+0x1d8/0x270
[ 1713.125565]  rcu_pending+0x45/0x1c0
[ 1713.125566]  ? __this_cpu_preempt_check+0x13/0x20
[ 1713.125568]  rcu_sched_clock_irq+0x66/0x1d0
[ 1713.125569]  update_process_times+0xa5/0xe0
[ 1713.125597]  tick_sched_handle+0x29/0x70
[ 1713.125598]  tick_sched_timer+0x7b/0xa0
[ 1713.125600]  ? tick_sched_do_timer+0xd0/0xd0
[ 1713.125601]  __hrtimer_run_queues+0x129/0x370
[ 1713.125603]  hrtimer_interrupt+0x118/0x250
[ 1713.125604]  __sysvec_apic_timer_interrupt+0x8f/0x1f0
[ 1713.125606]  sysvec_apic_timer_interrupt+0xab/0xd0
[ 1713.125608]  </IRQ>
[ 1713.125608]  <TASK>
[ 1713.125609]  asm_sysvec_apic_timer_interrupt+0x1b/0x20
[ 1713.125611] RIP: 0010:vmx_do_interrupt_nmi_irqoff+0x10/0x20 [kvm_intel]
[ 1713.125620] Code: 41 5b 41 5a 41 59 41 58 5e 5f 5a 59 58 5d e9 77 d1 61 e6 0f 1f 80 00 00 00 00 55 48 89 e5 48 83 e4 f0 6a 18 55 9c 6a 10 ff d7 <0f> 1f 00 48 89 ec 5d e9 54 d1 61 e6 0f 1f 40 00 0f 1f 44 00 00 55
[ 1713.125622] RSP: 0018:ffffb5d304213c78 EFLAGS: 00000082
[ 1713.125623] RAX: 000000000000000d RBX: ffff9796c94b8000 RCX: 000000000000440a
[ 1713.125624] RDX: ffffffff00000000 RSI: ffffffffc0c0c734 RDI: ffffffffa7000eb0
[ 1713.125625] RBP: ffffb5d304213c78 R08: 0000000000000000 R09: 0000000000000401
[ 1713.125626] R10: 0000000000000000 R11: 0000000000000000 R12: ffffffffa7000eb0
[ 1713.125626] R13: 0000000000000000 R14: 00000498e9d90a8a R15: ffff9796c94b8000
[ 1713.125627]  ? asm_sysvec_spurious_apic_interrupt+0x20/0x20
[ 1713.125629]  ? asm_sysvec_spurious_apic_interrupt+0x20/0x20
[ 1713.125632]  ? __this_cpu_preempt_check+0x13/0x20
[ 1713.125633]  vmx_handle_exit_irqoff+0x1a4/0x320 [kvm_intel]
[ 1713.125638]  vcpu_enter_guest+0x7ff/0x11b0 [kvm]
[ 1713.125674]  ? __this_cpu_preempt_check+0x13/0x20
[ 1713.125675]  ? trace_preempt_on+0x29/0x100
[ 1713.125677]  vcpu_run+0x62/0x2c0 [kvm]
[ 1713.125702]  ? fpu_swap_kvm_fpstate+0x79/0x160
[ 1713.125704]  kvm_arch_vcpu_ioctl_run+0xd7/0x5a0 [kvm]
[ 1713.125728]  kvm_vcpu_ioctl+0x29e/0x760 [kvm]
[ 1713.125747]  ? debug_smp_processor_id+0x17/0x20
[ 1713.125748]  ? user_return_notifier_unregister+0x42/0x90
[ 1713.125751]  ? trace_preempt_on+0x29/0x100
[ 1713.125754]  ? fire_user_return_notifiers+0x6d/0xd0
[ 1713.125760]  ? __fget_light+0xad/0x140
[ 1713.125762]  __x64_sys_ioctl+0x92/0xd0
[ 1713.125764]  x64_sys_call+0x1e5f/0x1fa0
[ 1713.125766]  do_syscall_64+0x56/0xb0
[ 1713.125768]  ? do_syscall_64+0x63/0xb0
[ 1713.125769]  ? debug_smp_processor_id+0x17/0x20
[ 1713.125770]  ? fpregs_assert_state_consistent+0x2a/0x50
[ 1713.125772]  ? exit_to_user_mode_prepare+0x42/0xf0
[ 1713.125773]  ? syscall_exit_to_user_mode+0x2d/0x50
[ 1713.125774]  ? do_syscall_64+0x63/0xb0
[ 1713.125776]  ? do_syscall_64+0x63/0xb0
[ 1713.125777]  ? do_syscall_64+0x63/0xb0
[ 1713.125778]  entry_SYSCALL_64_after_hwframe+0x67/0xd1
[ 1713.125780] RIP: 0033:0x7f057c3c294f
[ 1713.125781] Code: 00 48 89 44 24 18 31 c0 48 8d 44 24 60 c7 04 24 10 00 00 00 48 89 44 24 08 48 8d 44 24 20 48 89 44 24 10 b8 10 00 00 00 0f 05 <41> 89 c0 3d 00 f0 ff ff 77 1f 48 8b 44 24 18 64 48 2b 04 25 28 00
[ 1713.125782] RSP: 002b:00007f057a215460 EFLAGS: 00000246 ORIG_RAX: 0000000000000010
[ 1713.125784] RAX: ffffffffffffffda RBX: 000000000000ae80 RCX: 00007f057c3c294f
[ 1713.125784] RDX: 0000000000000000 RSI: 000000000000ae80 RDI: 000000000000000b
[ 1713.125785] RBP: 0000556735fad3c0 R08: 0000556734ca3f10 R09: 00000000ffffffff
[ 1713.125786] R10: 0000000000000001 R11: 0000000000000246 R12: 0000000000000000
[ 1713.125786] R13: 0000000000000000 R14: 0000000000000000 R15: 0000000000000000
[ 1713.125788]  </TASK>
```
