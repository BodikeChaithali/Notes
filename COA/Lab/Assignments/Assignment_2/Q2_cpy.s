.data
src: .word 1,2,3,4,5
dst: .space 20

.text
.globl main

main:
    la a0, src    
    la a1, dst      
    li a2, 5        

    jal ra, copy_arr

    li a7, 10
    ecall

copy_arr:
    li t0, 0

loop:
    beq t0, a2, end

    lw t1, 0(a0)
    sw t1, 0(a1)

    addi a0, a0, 4
    addi a1, a1, 4
    addi t0, t0, 1

    j loop

end:
    ret
