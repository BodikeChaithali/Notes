.section .text
.globl main

main:
    call add        # call function (no parameters)
    ret             # return from main


add:
    li t0, 5        # first number (inside function)
    li t1, 3        # second number (inside function)
    add t0, t0, t1  # t0 = 5 + 3
    ret

