.data

.text
.globl main

main:
    li s0, 10          
    li s1, 20          

    mv a0, s0          
    mv a1, s1        

    jal ra, add_func   

    mv s2, a0          

    li a7, 10          
    ecall

add_func:
    add a0, a0, a1     
    ret
