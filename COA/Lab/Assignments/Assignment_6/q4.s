.section .text
.globl main

main:
    la t0, scratch_trap
    csrw mtvec, t0

    li t0, 0x12345678
    csrw mscratch, t0

    li t1, 11
    li t2, 22

    ecall

main_loop:
    j main_loop


# Machine Mode
scratch_trap:
    csrr t3, mscratch

    mv t4, t1        
    mv t5, t2       

    csrr t0, mcause
    csrr t1, mepc

    addi t1, t1, 4
    csrw mepc, t1

    mv t1, t4
    mv t2, t5

    mret
