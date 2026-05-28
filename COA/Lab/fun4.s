.section .text
.globl main

main:
    li a0, 3          # parameter n = 3
    call sum          # recursive function call
    ret


# -------- recursive sum function --------
# a0 = n
# returns sum(n) in a0
sum:
    addi sp, sp, -16  # create stack frame
    sd ra, 8(sp)     # save return address
    sd a0, 0(sp)     # save parameter n

    beqz a0, base    # if n == 0, go to base case

    addi a0, a0, -1  # n = n - 1
    call sum         # recursive call

    ld t0, 0(sp)     # load original n
    add a0, a0, t0   # a0 = sum(n-1) + n
    j end_sum

base:
    li a0, 0         # base case return value

end_sum:
    ld ra, 8(sp)     # restore return address
    addi sp, sp, 16  # destroy stack frame
    ret
