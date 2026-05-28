.section .text
.globl main

main:
    li a0, 4        # first parameter
    li a1, 6        # second parameter
    call multiply   # function call

    li a7, 93       # exit
    ecall


multiply:
    mul a0, a0, a1  # a0 = a0 * a1
    ret
