.section .text
.globl main

main:
    la t0, trap_handler
    csrw mtvec, t0

    csrr t1, mstatus
    li t2, 8
    or t1, t1, t2
    csrw mstatus, t1

    csrr t1, mie
    li t2, 0x80
    or t1, t1, t2
    csrw mie, t1

    ecall

    j done

trap_handler:
    csrr t0, mcause

    csrr t1, mstatus
    li t2, ~8
    and t1, t1, t2
    csrw mstatus, t1

    ecall

    csrr t1, mstatus
    li t2, 8
    or t1, t1, t2
    csrw mstatus, t1

    csrr t2, mepc
    addi t2, t2, 4
    csrw mepc, t2

    mret

done:
    j done
