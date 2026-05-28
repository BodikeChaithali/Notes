.data
.globl result
result:
    .space 100        
    .text
    .globl concat

concat:
    la t0, result        
    li t1, 0             

copy_s1:
    lb t2, 0(a0)        
    beq t2, zero, copy_s2
    sb t2, 0(t0)         
    addi a0, a0, 1
    addi t0, t0, 1
    addi t1, t1, 1
    j copy_s1

copy_s2:
    lb t2, 0(a1)        
    beq t2, zero, done
    sb t2, 0(t0)
    addi a1, a1, 1
    addi t0, t0, 1
    addi t1, t1, 1
    j copy_s2

done:
    sb zero, 0(t0)        
    mv a0, t1             
    ret
