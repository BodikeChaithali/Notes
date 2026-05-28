.section .text
.global main

main:

    # Load value 1 into register t0
    li t0, 1

    # Shift left by 11 bits to place the value in MPP field of mstatus
    # MPP bits determine the next privilege mode after mret
    slli t0, t0, 11

    # Set the MPP bits in the mstatus register
    # This configures the processor to switch to Supervisor Mode
    csrs mstatus, t0

    # Load the address of the supervisor label into register t1
    la t1, supervisor

    # Write this address into the mepc register
    # mepc stores the return address for mret
    csrw mepc, t1

    # Return from machine mode
    # Execution continues in Supervisor Mode at address stored in mepc
    mret


############## Supervisor Mode ##############
supervisor:

################ PAGE TABLE SETUP #################

# Load the base address of the Root Page Table (Level 1)
# Root page table will be stored at physical address 0x81000000
    li a0, 0x81000000

# Load the Physical Page Number (PPN) of the Level 0 page table
# Level 0 table will be located at physical address 0x82000000
    li a1, 0x82000

# Shift left by 10 bits to position the PPN correctly in the Page Table Entry
    slli a1, a1, 10

# Set the Valid (V) bit in the page table entry
# This indicates that the entry is valid and points to the next level page table
    ori a1, a1, 0x01

# Store the entry into the root page table
# This creates a link from the Level 1 table to the Level 0 table
    sw a1, 0(a0)

###################################################

# Now configure the Level 0 page table
# Load its base address
    li a0, 0x82000000

# Create mapping for program code page
# Virtual Address 0x00000000 -> Physical Address 0x80000000

# Load physical page number of the code page
    li a1, 0x80000

# Shift to proper PTE position
    slli a1, a1, 10

# Add permission bits:
# D = Dirty
# A = Accessed
# X = Execute
# W = Write
# R = Read
# V = Valid
    ori a1, a1, 0xCF

# Store the entry in Level 0 page table
    sw a1, 0(a0)

# Create mapping for data page
# Virtual Address 0x00001000 -> Physical Address 0x80001000

# Load physical page number of data page
    li a1, 0x80001

# Shift to correct position in PTE
    slli a1, a1, 10

# Add permission bits
# D A W R V
    ori a1, a1, 0xC7

# Store the second entry in Level 0 page table
    sw a1, 4(a0)

########## Enable paging using the SATP register (Sv32) ############


# Load address of satp configuration value
    la t0, satp_config

# Load the satp value into register t1
    lw t1, 0(t0)

# Flush old virtual memory translations from the TLB
    sfence.vma

# Write the satp register
# This enables paging and sets the root page table address
    csrw satp, t1

# Flush TLB again so that new page table mappings are used
    sfence.vma

################### Prepare to switch to User Mode ######################

# Load 0 into register t0
    li t0, 0

# Shift left by 8 bits (preparing bit position for user mode configuration)
    slli t0, t0, 8

# Update the sstatus register
# This prepares the processor for switching to User Mode
    csrs sstatus, t0

# Load address of the user program
    la t1, user_code

# Store this address in sepc
# sepc is the return address used by sret
    csrw sepc, t1

# Return from supervisor mode
# Execution continues in User Mode
    sret


############### User Mode Code ################
# Align the user code to a 4KB boundary (page boundary)
.align 12
user_code:

    # Load address of variable var1
    la t1, var1

    # Load address of variable var2
    la t2, var2

# Infinite loop so program keeps running
loop:
    j loop


############ Data Section ##############
.data

# Align data to page boundary
.align 12

# Define variable var1 with value 1
var1: .word 1

# Define variable var2 with value 2
var2: .word 2


################# SATP Configuration ####################
.align 4

# SATP register configuration for Sv32 paging
# MODE = 1  (Sv32 paging enabled)
# PPN  = 0x81000 (root page table address)

satp_config:
    .word 0x80081000
