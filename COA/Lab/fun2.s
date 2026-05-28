.section .text
.globl main

main:
    call add
    ret


# -------- add function --------
add:
    li a0, 5          # pass N = 5 in a0
    call recurse      # result returned in a0
    ret


# -------- recursive sum --------
# a0 = n
# returns sum(n) in a0
recurse:
    addi sp, sp, -16
    sd ra, 8(sp)
    sd a0, 0(sp)      # save current n

    beqz a0, base

    addi a0, a0, -1   #t0 = t0-1
    call recurse      # sum(n-1)# recursive call

    ld t0, 0(sp)      # restore n
    add a0, a0, t0    # sum(n) = sum(n-1) + n
    j done

base:
    li a0, 0

done:
    ld ra, 8(sp)
    addi sp, sp, 16
    ret

