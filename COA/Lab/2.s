.section .text
.global main

main:
    # Function prologue
    addi sp, sp, -8
    sd ra, 0(sp)

    la a0, message
    li a1, 42
    jal ra, show      # return value in a0

    # store a0 into C variable result
    la t0, result
    sw a0, 0(t0)

    # print it from C
    jal ra, print_result

    # Function epilogue
    ld ra, 0(sp)
    addi sp, sp, 8
    ret



.section .data
message:
    .asciz "Value is"
