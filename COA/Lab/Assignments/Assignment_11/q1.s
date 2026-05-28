.section .text
.globl main

.option norvc

main:
    la t0, trap_handler
    csrw mtvec, t0

    ebreak

    addi t1, zero, 10
    addi t2, t1, 5

loop:
    j loop

trap_handler:
    csrr t0, mcause
    li t1, 3
    bne t0, t1, exit

    csrr t2, mepc
    addi t2, t2, 4
    csrw mepc, t2

exit:
    mret
