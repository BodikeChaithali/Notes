.data

# -----------------------------
# Instruction Cache
# -----------------------------

ICache:
.half 0x0345      # ADD  R3,R4,R5
.half 0x1678      # SUB  R6,R7,R8
.half 0x49AB      # AND  R9,R10,R11
.half 0x5CDE      # XOR  R12,R13,R14
.half 0xF000      # HLT


# -----------------------------
# Register File
# -----------------------------

RF:
.byte 0   # R0
.byte 0   # R1
.byte 0   # R2
.byte 0   # R3
.byte 5   # R4
.byte 7   # R5
.byte 0   # R6
.byte 12  # R7
.byte 4   # R8
.byte 0   # R9
.byte 6   # R10
.byte 3   # R11
.byte 0   # R12
.byte 9   # R13
.byte 2   # R14
.byte 0   # R15


# Program Counter
PC: .word 0


.text
.globl main

main:

la s0, ICache
la s1, RF
la t0, PC


loop:

# -------- FETCH --------

lw t1, 0(t0)
add t2, s0, t1
lh t3, 0(t2)
addi t1, t1, 2
sw t1, 0(t0)


# -------- DECODE --------

srli t4, t3, 12
andi t4, t4, 0xF

li t5, 15
beq t4, t5, program_end


# REG1

li t5, 0x0F00
and t6, t3, t5
srli t6, t6, 8


# REG2

li t5, 0x00F0
and a0, t3, t5
srli a0, a0, 4


# REG3

li t5, 0x000F
and a1, t3, t5


# -------- REGISTER READ --------

add t5, s1, a0
lb a0, 0(t5)

add t5, s1, a1
lb a1, 0(t5)


# -------- EXECUTE --------

li t5, 0
beq t4, t5, do_add

li t5, 1
beq t4, t5, do_sub

li t5, 4
beq t4, t5, do_and

li t5, 5
beq t4, t5, do_xor

j loop


do_add:
add a2, a0, a1
j write_back


do_sub:
sub a2, a0, a1
j write_back


do_and:
and a2, a0, a1
j write_back


do_xor:
xor a2, a0, a1


# -------- WRITE BACK --------

write_back:

add t5, s1, t6
sb a2, 0(t5)

j loop


program_end:

halt:
j halt
