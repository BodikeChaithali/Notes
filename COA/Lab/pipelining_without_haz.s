.data

# ------------------------------------------------
# Instruction Cache (Program Memory)
# Each instruction = 16 bits
#
# Instruction format:
# [ opcode ][ REG1 ][ REG2 ][ REG3 ]
#
# opcode : operation type
# REG1   : destination register field
# REG2   : source register field 1
# REG3   : source register field 2
#
# Actual registers are named R0, R1 ... R15
# ------------------------------------------------

ICache:
.half 0x0123      # ADD  R1,R2,R3
                  # opcode=0  REG1=1 REG2=2 REG3=3

.half 0x1456      # SUB  R4,R5,R6
                  # opcode=1  REG1=4 REG2=5 REG3=6

.half 0x4789      # AND  R7,R8,R9
                  # opcode=4  REG1=7 REG2=8 REG3=9

.half 0xF000      # HLT instruction (opcode = 15)


# ------------------------------------------------
# Register File (16 registers)
# Each register stores 1 byte
# ------------------------------------------------

RF:
.byte 0   # R0
.byte 0   # R1
.byte 2   # R2
.byte 3   # R3
.byte 0   # R4
.byte 7   # R5
.byte 4   # R6
.byte 0   # R7
.byte 6   # R8
.byte 5   # R9
.byte 0   # R10
.byte 0   # R11
.byte 0   # R12
.byte 0   # R13
.byte 0   # R14
.byte 0   # R15


# ------------------------------------------------
# Program Counter (PC)
# Stores address of next instruction
# ------------------------------------------------

PC: .word 0


.text
.globl main

main:

# Load base address of instruction cache
la s0, ICache

# Load base address of register file
la s1, RF

# Load address of PC variable
la t0, PC


# =================================================
# MAIN PROCESSOR LOOP
# Simulates instruction execution cycle
# =================================================

loop:

# -------------------------------------------------
# INSTRUCTION FETCH STAGE
# -------------------------------------------------

lw t1, 0(t0)        # Load current PC value

add t2, s0, t1      # Compute instruction address
                    # instruction_address = ICache + PC

lh t3, 0(t2)        # Fetch instruction from memory

addi t1, t1, 2      # Increment PC by 2 bytes
                    # because each instruction = 16 bits

sw t1, 0(t0)        # Store updated PC back


# -------------------------------------------------
# INSTRUCTION DECODE STAGE
# -------------------------------------------------

srli t4, t3, 12     # Extract opcode (top 4 bits)
andi t4, t4, 0xF    # Keep only 4 bits

# Check if instruction is HLT
li t5, 15
beq t4, t5, program_end


# -------- Extract REG1 (destination register field) --------

li t5, 0x0F00       # Mask bits 11–8
and t6, t3, t5
srli t6, t6, 8      # REG1 now contains destination register index


# -------- Extract REG2 (source register field 1) --------

li t5, 0x00F0       # Mask bits 7–4
and a0, t3, t5
srli a0, a0, 4      # REG2 register index


# -------- Extract REG3 (source register field 2) --------

li t5, 0x000F       # Mask bits 3–0
and a1, t3, t5      # REG3 register index


# -------------------------------------------------
# REGISTER READ STAGE
# -------------------------------------------------

add t5, s1, a0      # Address of register REG2
lb a0, 0(t5)        # Load value stored in source register

add t5, s1, a1      # Address of register REG3
lb a1, 0(t5)        # Load second operand


# -------------------------------------------------
# EXECUTE STAGE (ALU)
# -------------------------------------------------

# Select ALU operation based on opcode

li t5, 0
beq t4, t5, do_add  # opcode 0 → ADD

li t5, 1
beq t4, t5, do_sub  # opcode 1 → SUB

li t5, 4
beq t4, t5, do_and  # opcode 4 → AND

j loop              

# -------- ADD OPERATION --------
# R(REG1) = R(REG2) + R(REG3)

do_add:
add a2, a0, a1
j write_back


# -------- SUB OPERATION --------
# R(REG1) = R(REG2) - R(REG3)

do_sub:
sub a2, a0, a1
j write_back


# -------- AND OPERATION --------
# R(REG1) = R(REG2) & R(REG3)

do_and:
and a2, a0, a1


# -------------------------------------------------
# WRITE BACK STAGE
# -------------------------------------------------

write_back:

add t5, s1, t6      # Compute address of destination register
sb a2, 0(t5)        # Store ALU result into register file

j loop              


# -------------------------------------------------
# PROGRAM TERMINATION
# -------------------------------------------------

program_end:

halt:
j halt              
