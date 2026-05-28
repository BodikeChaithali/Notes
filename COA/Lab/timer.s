.section .text
.globl main

# =========================================================
# Machine mode start
# =========================================================
main:
    csrw mstatus, zero

    la   t0, trap_handler
    csrw mtvec, t0

    li   t0, (1 << 7)          # MTIE
    csrs mie, t0

    li   t0, (1 << 3)          # MIE
    csrs mstatus, t0

    # Program timer (single interrupt)
    li   t0, 0x2004000         # mtimecmp
    li   t1, 1000
    sd   t1, 0(t0)

    # Enter user mode
    la   t0, user_code
    csrw mepc, t0

    csrr t1, mstatus
    li   t2, ~(3 << 11)        # clear MPP
    and  t1, t1, t2
    csrw mstatus, t1

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
    # DISABLE further timer interrupts
    li   t0, (1 << 7)          # MTIE
    csrc mie, t0

    # Return to final user code
    la   t0, user_after
    csrw mepc, t0

    csrr t1, mstatus
    li   t2, ~(3 << 11)        # MPP = User
    and  t1, t1, t2
    csrw mstatus, t1

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

