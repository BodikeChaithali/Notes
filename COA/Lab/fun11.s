.data
arr: .word 10, 20, 30, 40, 50
n:   .word 5

.text
.globl main

main:
    la a0, arr        # a0 = base address of array
    lw a1, n          # a1 = number of elements
    call array_sum
    ret               # result in a0

array_sum:
    addi t0, zero, 0  # sum = 0

loop:
    beqz a1, done     # if count == 0, exit
    lw t1, 0(a0)      # load current element
    add t0, t0, t1    # sum += element
    addi a0, a0, 4    # move to next element
    addi a1, a1, -1   # decrement count
    j loop

done:
    mv a0, t0         # return sum
    ret
