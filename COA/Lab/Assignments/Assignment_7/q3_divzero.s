.section .data
.align 3

exception_count:
    .quad 0

.align 3
numerators:
    .quad 100,200,300,400,500,600,700,800

.align 3
denominators:
    .quad 10,0,5,0,25,0,50,0

.align 3
result_buffer:
    .space 64

.section .text
.globl main

main:

    la t0, trap_handler
    csrw mtvec, t0

    la s0, numerators
    la s1, denominators
    la s2, result_buffer

    li s3, 8

loop_start:
    beqz s3, end_program

    ld t0, 0(s0)
    ld t1, 0(s1)

    beqz t1, trigger_exception

do_div:
    div t2, t0, t1
    sd t2, 0(s2)

next_iter:
    addi s0, s0, 8
    addi s1, s1, 8
    addi s2, s2, 8
    addi s3, s3, -1
    j loop_start

trigger_exception:
    ecall
    j do_div

end_program:
end_loop:
    j end_loop

trap_handler:

    csrr t0, mcause
    csrr t1, mepc
    csrr t2, mtval
    csrr t3, mstatus

    li t4, 11
    bne t0, t4, return_from_trap

    la t5, exception_count
    ld t6, 0(t5)
    addi t6, t6, 1
    sd t6, 0(t5)

    li t1, 1
    sd t1, 0(s1)

    csrr t1, mepc
    addi t1, t1, 4
    csrw mepc, t1

return_from_trap:
    mret
