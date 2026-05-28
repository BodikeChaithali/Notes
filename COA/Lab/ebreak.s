.section .text
.globl main

# ==================================================
# Start in Machine Mode
# ==================================================
main:

    # ----------------------------------------------
    # 1. Set trap handler (mtvec)
    # ----------------------------------------------
    la   t0, trap_handler
    csrw mtvec, t0

    # ----------------------------------------------
    # 2. Normal execution before ebreak
    # ----------------------------------------------
    li   t1, 5
    li   t2, 10
    add  t3, t1, t2      # t3 = 15

    # ----------------------------------------------
    # 3. Generate breakpoint exception
    # ----------------------------------------------
    ebreak               # <-- interrupt (exception) occurs here

    # ----------------------------------------------
    # 4. Execution continues after handling
    # ----------------------------------------------
    addi t3, t3, 1       # t3 = 16 (should execute after return)

loop:
    j loop


# ==================================================
# Trap Handler
# ==================================================
trap_handler:

    # Read cause
    csrr t0, mcause

    # Check for ebreak (mcause = 3)
    li   t1, 3
    beq  t0, t1, handle_ebreak

    j .   # unknown exception


handle_ebreak:
    # Skip ebreak instruction
    csrr t2, mepc
    addi t2, t2, 4
    csrw mepc, t2

    # Return
    mret  
