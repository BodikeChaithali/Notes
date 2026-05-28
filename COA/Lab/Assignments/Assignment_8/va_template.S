.section .text
.global main

main:

    li t0, 1
    slli t0, t0, 11
    csrs mstatus, t0

    la t1, supervisor
    csrw mepc, t1

    mret


supervisor:

    li a0, 0x81000000        
    li a1, 0x82000          
    slli a1, a1, 10
    ori a1, a1, 0x01         

    sw a1, 0(a0)

    li a0, 0x82000000

    li a1, 0x80000
    slli a1, a1, 10
    ori a1, a1, 0xCF       

    sw a1, 0(a0)

    li a1, 0x80001
    slli a1, a1, 10
    ori a1, a1, 0xC7

    sw a1, 8(a0)

    la t0, satp_config
    ld t2, 0(t0)

    sfence.vma zero, zero
    csrrw zero, satp, t2
    sfence.vma zero,zero

    la t1, user_code
    csrw sepc, t1

    li t4, 0
    sret

.align 12
user_code:

    la t1, var1
    la t2, var2
    la t3, var3
    la t4, var4

loop:
    j loop

.data
.align 12

var1: .word 1
var2: .word 2
var3: .word 3
var4: .word 4

.align 4
satp_config:
    .dword 0x80081000
