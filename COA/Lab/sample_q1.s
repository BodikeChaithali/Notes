
.section .text
.global main

# --- Machine Mode Entry ---
main:
    # 1. Setup Trap Handler address
    la t0, simple_trap_handler
    csrw mtvec, t0

    # 2. Switch to User Mode
    # Read mstatus
    csrr t1, mstatus
    # Clear MPP bits (11 and 12) -> Mode 00 (User)
    li t2, 0x1800 
    not t2, t2
    and t1, t1, t2
    # Write back mstatus
    csrw mstatus, t1

    # 3. Set the Return Address for mret
    la t0, user_code
    csrw mepc, t0

    # 4. Enter User Mode
    mret

# --- Trap Handler (Machine Mode) ---
.align 2
simple_trap_handler:
    # Check cause
    csrr t0, mcause   # Should be 8 (User Ecall)

    # Move EPC to next instruction to avoid infinite loop
    csrr t1, mepc
    addi t1, t1, 4    # Skip 4 bytes (size of ecall)
    csrw mepc, t1

    # Return to User Mode
    mret

# --- User Code (User Mode) ---
user_code:
    li a0, 10
    li a1, 20
    
    # Trigger Exception!
    ecall
    
    # We return here!
    add a2, a0, a1   # a2 = 30
    
    # Loop forever
    j user_code
