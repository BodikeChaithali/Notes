.data

# ------------------------------------------------
# Instruction Cache (Program Memory)
# ------------------------------------------------

ICache:
.half 0x0123      # ADD  R1,R2,R3
.half 0x1456      # SUB  R4,R5,R6
.half 0x4789      # AND  R7,R8,R9
.half 0x5ABC      # OR   R10,R11,R12
.half 0xF000      # HLT


# ------------------------------------------------
# Register File
# ------------------------------------------------

RF:
.byte 0   # R0
.byte 0   # R1
.byte 4   # R2
.byte 3   # R3
.byte 0   # R4
.byte 10  # R5
.byte 2   # R6
.byte 0   # R7
.byte 6   # R8
.byte 5   # R9
.byte 0   # R10
.byte 8   # R11
.byte 1   # R12
.byte 0   # R13
.byte 0   # R14
.byte 0   # R15


# Program Counter
PC: .word 0


.text
.globl main

main:

# Base address of instruction cache
la s0, ICache

# Base address of register file
la s1, RF

# Address of PC
la t0, PC


# =================================================
# Processor Loop
# =================================================

loop:

# ---------------- FETCH ----------------

lw t1, 0(t0)

add t2, s0, t1

lh t3, 0(t2)

addi t1, t1, 2

sw t1, 0(t0)


# ---------------- DECODE ----------------

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


# ---------------- REGISTER READ ----------------

add t5, s1, a0
lb a0, 0(t5)

add t5, s1, a1
lb a1, 0(t5)


# ---------------- EXECUTE ----------------

li t5, 0
beq t4, t5, do_add

li t5, 1
beq t4, t5, do_sub

li t5, 4
beq t4, t5, do_and

li t5, 5
beq t4, t5, do_or

j loop


# ADD

do_add:
add a2, a0, a1
j write_back


# SUB

do_sub:
sub a2, a0, a1
j write_back


# AND

do_and:
and a2, a0, a1
j write_back


# OR

do_or:
or a2, a0, a1


# ---------------- WRITE BACK ----------------

write_back:

add t5, s1, t6
sb a2, 0(t5)

j loop


# ---------------- PROGRAM END ----------------

program_end:

halt:
j halt
