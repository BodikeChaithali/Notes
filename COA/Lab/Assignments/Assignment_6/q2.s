.section .text
.global main

.equ MTIME,     0x0200BFF8
.equ MTIMECMP,  0x02004000

# Machine Mode 
main:
    la t0, timer_trap_handler
    csrw mtvec, t0

    csrr t1, mstatus
    li   t2, 0x8            
    or   t1, t1, t2
    csrw mstatus, t1

    li t0, 0x80          
    csrw mie, t0

    li t0, MTIME
    ld t1, 0(t0)

    li t0, MTIMECMP
    li t2, 5000
    add t1, t1, t2
    sd t1, 0(t0)

# Main Loop 
main_loop:
    j main_loop

timer_trap_handler:
    csrr t0, mcause

    csrr t1, mepc
    csrr t2, mstatus

    li t3, MTIME
    ld t4, 0(t3)

    li t3, MTIMECMP
    li t5, 5000
    add t4, t4, t5
    sd t4, 0(t3)

    mret
