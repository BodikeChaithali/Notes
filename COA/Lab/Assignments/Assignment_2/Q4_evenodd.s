.data
arr: .word 1,2,3,4,5,6

.text
.globl main

main:
    la a0, arr
    li a1, 6

    jal ra, count_even_odd

    mv s0, a0     
    mv s1, a1     

    li a7, 10
    ecall

count_even_odd:
    li t0, 0      
    li t1, 0      
    li t2, 0      

loop:
    beq t0, a1, end

    lw t3, 0(a0)
    andi t4, t3, 1
    beq t4, zero, even

odd:
    addi t2, t2, 1
    j next

even:
    addi t1, t1, 1

next:
    addi a0, a0, 4
    addi t0, t0, 1
    j loop

end:
    mv a0, t1
    mv a1, t2
    ret

