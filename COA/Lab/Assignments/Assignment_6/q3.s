.section .text
.globl main

main:
    la t0, illegal_trap
    csrw mtvec, t0

    # Switch to User mode
    csrr t1, mstatus
    li   t2, 0x1800   
    not  t2, t2
    and  t1, t1, t2
    csrw mstatus, t1
    la t0, user_code
    csrw mepc, t0
    mret

# Machine Mode
illegal_trap:
    csrr t0, mcause
    csrr t1, mepc
    csrr t2, mtval
    addi t1, t1, 4    
    csrw mepc, t1
    mret

# User Mode 
user_code:
    li t0, 1
    csrw mstatus, t0     
    j user_code

