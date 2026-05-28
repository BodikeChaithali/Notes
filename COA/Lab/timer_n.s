.section .text
.globl main

# =========================================================
# Machine mode start
# =========================================================
main:
    csrw mstatus, zero   #reset

    la   t0, trap_handler
    csrw mtvec, t0            #set mtvec

    li   t0, (1 << 7)          # MTIE #10000000
    csrs mie, t0

    li   t0, (1 << 3)          # MIE #00001000
    csrs mstatus, t0

    # Program timer (single interrupt)
    li   t0, 0x2004000         # mtimecmp
    li   t1, 1000
    sd   t1, 0(t0)

    # Enter user mode
    la   t0, user_code
    csrw mepc, t0

    # Read mstatus
    csrr t1, mstatus     #global control panel
    li t2, 0x1800       # 0001 1000 0000 0000
    not t2, t2           # 1110 0111 1111 1111
    and t1, t1, t2      # ---0 0--- ---- ----
    csrw mstatus, t1      # Write back mstatus

    mret                      # → USER MODE


# =========================================================
# User mode (before interrupt)
# =========================================================
user_code:
    addi s0, zero, 1
    addi s0, s0, 1
    addi s0, s0, 1
    j user_code               # wait until timer fires


# =========================================================
# Trap handler (Machine mode)
# =========================================================
trap_handler:
    csrr t0, mcause 
    
    # DISABLE further timer interrupts
    li   t0, (1 << 7)          # MTIE
    csrc mie, t0

     # Read mstatus
    csrr t1, mstatus     #global control panel
    # Clear MPP bits (11 and 12) -> Mode 00 (User)
    li t2, 0x1800       # 0001 1000 0000 0000
    not t2, t2           # 1110 0111 1111 1111
    and t1, t1, t2      # ---0 0--- ---- ----
    csrw mstatus, t1      # Write back mstatus

    # Return to final user code
    la   t0, user_after
    csrw mepc, t0

   
    mret                      # → USER MODE


# =========================================================
# User mode (final)
# =========================================================
user_after:
    addi s1, zero, 5
    addi s1, s1, 5
    addi s1, s1, 5

stop:
    j stop                   # STOP forever

