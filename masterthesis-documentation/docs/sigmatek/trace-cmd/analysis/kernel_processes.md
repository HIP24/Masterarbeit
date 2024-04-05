## Events
Events on Host CPU17 hindering execution of Guest Salamander4 CPU0

|   Task     | Event |
|------------|-------|
| qemu-system-x86 | irq_vectors/local_timer_entry |
| qemu-system-x86 | irq_vectors/local_timer_exit |
| qemu-system-x86 | timer/hrtimer_start |
| qemu-system-x86 | timer/hrtimer_cancel |
| qemu-system-x86 | timer/hrtimer_expire_entry |
| qemu-system-x86 | timer/hrtimer_expire_exit |
| qemu-system-x86 | notifier/notifier_run |
| qemu-system-x86 | rcu/rcu_utilization |
| qemu-system-x86 | rseq/rseq_update |
| qemu-system-x86 | msr/write_msr |
| qemu-system-x86 | msr/read_msr |
| qemu-system-x86 | sched/shed_stat_runtime |
| qemu-system-x86 | sched/shed_switch |
| qemu-system-x86 | kvm/kvm_entry |
| qemu-system-x86 | kvm/kvm_exit |
| qemu-system-x86 | kvm/kvm_apic |
| qemu-system-x86 | kvm/kvm_apicv_accept_irq |
| qemu-system-x86 | kvm/kvm_apic_accept_irq |
| qemu-system-x86 | kvm/kvm_pv_tlb_flush |
| qemu-system-x86 | kvm/kvm_hv_timer_state |
| qemu-system-x86 | kvm/kvm_wait_lapic_expire |
| qemu-system-x86 | kvm/kvm_vcpu_wakeup |
| vhost-12398 | kmem/kmem_cache_free |
| vhost-12398 | skb/skb_copy_datagram_iovec |
| vhost-12398 | skb/consume_skb |
| vhost-12398 | sched/sched_waking |
| vhost-12398 | sched/sched_wakeup |
| vhost-12398 | ipi/ipi_send_cpu |
| vhost-12398 | rcu/rcu_utilization |
| vhost-12398 | sched/shed_stat_runtime |
| vhost-12398 | sched/shed_switch |
| rcuc/17 | rcu/rcu_utilization  |
| rcuc/17 | sched/shed_stat_runtime |
| rcuc/17 | sched/shed_switch |

## Pattern 1
|   Task     | Event |
|------------|-------|
| qemu-system-x86 | msr/write_msr |
| qemu-system-x86 | kvm/kvm_exit |
| qemu-system-x86 | kvm/kvm_apic_accept_irq |
| qemu-system-x86 | kvm/kvm_apicv_accept_irq |
| qemu-system-x86 | kvm/kvm_entry |
| qemu-system-x86 | kvm/kvm_wait_lapic_expire |
| qemu-system-x86 | rcu/rcu_utilization |
| qemu-system-x86 | rcu/rcu_utilization |

## Pattern 2
|   Task     | Event |
|------------|-------|
| qemu-system-x86 | msr/write_msr |
| qemu-system-x86 | kvm/kvm_exit |
| qemu-system-x86 | kvm/kvm_apic |
| qemu-system-x86 | kvm/kvm_hv_timer_state |
| qemu-system-x86 | kvm/kvm_entry |
| qemu-system-x86 | rcu/rcu_utilization |
| qemu-system-x86 | rcu/rcu_utilization |

## Pattern 3
|   Task     | Event |
|------------|-------|
| qemu-system-x86 | msr/write_msr |
| qemu-system-x86 | kvm/kvm_exit |
| qemu-system-x86 | timer/hrtimer_start |
| qemu-system-x86 | msr/write_msr |
| qemu-system-x86 | kvm/kvm_hv_timer_state |
| qemu-system-x86 | irq_vectors/local_timer_entry |
| qemu-system-x86 | timer/hrtimer_cancel |
| qemu-system-x86 | timer/hrtimer_expire_entry |
| qemu-system-x86 | timer/hrtimer_expire_exit |
| qemu-system-x86 | msr/write_msr |
| qemu-system-x86 | irq_vectors/local_timer_exit |
| qemu-system-x86 | kvm/kvm_vcpu_wakeup |
| qemu-system-x86 | kvm/kvm_apic_accept_irq |
| qemu-system-x86 | kvm/kvm_apicv_accept_irq |
| qemu-system-x86 | kvm/kvm_entry |
| qemu-system-x86 | rcu/rcu_utilization |
| qemu-system-x86 | rcu/rcu_utilization |

## Pattern 4
|   Task     | Event |
|------------|-------|
| qemu-system-x86 | msr/write_msr |
| qemu-system-x86 | kvm/kvm_exit |
| qemu-system-x86 | timer/hrtimer_start |
| qemu-system-x86 | kvm/kvm_hv_timer_state |
| qemu-system-x86 | irq_vectors/local_timer_entry |
| qemu-system-x86 | timer/hrtimer_cancel |
| qemu-system-x86 | timer/hrtimer_expire_entry |
| qemu-system-x86 | notifier/notifier_run |
| qemu-system-x86 | rcu/rcu_utilization |
| qemu-system-x86 | rcu/rcu_utilization |
| qemu-system-x86 | msr/read_msr |
| qemu-system-x86 | msr/read_msr |
| qemu-system-x86 | sched/shed_stat_runtime |
| qemu-system-x86 | timer/hrtimer_expire_exit |
| qemu-system-x86 | timer/hrtimer_start |
| qemu-system-x86 | msr/write_msr |
| qemu-system-x86 | irq_vectors/local_timer_exit |
| qemu-system-x86 | irq_vectors/local_timer_entry |
| qemu-system-x86 | timer/hrtimer_cancel |
| qemu-system-x86 | timer/hrtimer_expire_entry |
| qemu-system-x86 | timer/hrtimer_expire_exit |
| qemu-system-x86 | msr/write_msr |
| qemu-system-x86 | irq_vectors/local_timer_exit |
| qemu-system-x86 | kvm/kvm_vcpu_wakeup |
| qemu-system-x86 | kvm/kvm_apic_accept_irq |
| qemu-system-x86 | kvm/kvm_apicv_accept_irq |
| qemu-system-x86 | kvm/kvm_entry |
| qemu-system-x86 | rcu/rcu_utilization |
| qemu-system-x86 | rcu/rcu_utilization |