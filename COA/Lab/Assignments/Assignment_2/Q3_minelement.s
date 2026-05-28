.data
arr: .word 9, 4, 7, 2, 8

.text
.globl main

main:
    la a0, arr
    li a1, 5

    jal ra, find_min

    mv s0, a0

    li a7, 10
    ecall

find_min:
    lw t0, 0(a0)
    li t1, 1

loop:
    beq t1, a1, end

    lw t2, 4(a0)
    blt t2, t0, update

next:
    addi a0, a0, 4
    addi t1, t1, 1
    j loop

update:
    mv t0, t2
    j next

end:
    mv a0, t0
    ret
