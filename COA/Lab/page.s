.section .text
.global main

main:
    # ---------------- MACHINE MODE ----------------

    # Set MPP = 01 (Supervisor Mode)
    li t1, 1
    slli t1, t1, 11        # 1 << 11 = 0x800 → sets mstatus[12:11] = 01
    csrs mstatus, t1       # mstatus.MPP = Supervisor

    # Set return address after mret
    la t4, supervisor
    csrrw zero, mepc, t4   # mepc = address of supervisor

    mret                   # Jump to supervisor mode

# ==========================================================
supervisor:

################## PAGE TABLE SETUP ########################

# -------- LEVEL 2 PAGE TABLE (ROOT) -----------------------
# Base address = 0x81000000

    li a0, 0x81000000      # a0 = base of L2 page table

# ---- Entry index 2 → offset = 2 * 8 = 16 bytes ----
    li a1, 0x82000         # Next level table PPN = 0x82000
    slli a1, a1, 10        # PTE format: shift PPN left by 10
                           # = 0x82000 << 10 = 0x20800000

    ori a1, a1, 0x01       # Set Valid bit (V=1)
                           # Final PTE = 0x20800001

    sd a1, 16(a0)          # Store at index 2

# ---- Identity mapping (VA 0 → PA 0) ----
    li a1, 0x82001
    slli a1, a1, 10        # = 0x82001 << 10 = 0x20800400
    ori a1, a1, 0x01       # V=1
    sd a1, 0(a0)           # Entry index 0

# ==========================================================
# -------- LEVEL 1 PAGE TABLE -------------------------------

    li a0, 0x82000000      # L1 table base

    li a1, 0x83000
    slli a1, a1, 10        # = 0x83000 << 10 = 0x20C00000
    ori a1, a1, 0x01       # V=1

    sd a1, 0(a0)

# ==========================================================
# -------- LEVEL 0 PAGE TABLE (FINAL MAPPING) ---------------

    li a0, 0x83000000      # L0 table base

# ---- Map VA → PA ----
    li a1, 0x80000         # Physical Page Number
    slli a1, a1, 10        # = 0x80000 << 10 = 0x20000000

    # 0xEF = 1110 1111 (binary)
    # Bit meaning:
    # V=1, R=1, W=1, X=1
    # U=0 (Supervisor only)
    # G=1, A=1, D=1
    ori a1, a1, 0xEF

    sd a1, 0(a0)

# ==========================================================
# -------- CODE MAPPING (USER EXECUTION) --------------------

    li a0, 0x82001000

    li a1, 0x83001
    slli a1, a1, 10        # = 0x83001 << 10
    ori a1, a1, 0x01       # Valid

    sd a1, 0(a0)

# ---- Final Code Page ----
    li a0, 0x83001000

    li a1, 0x80001
    slli a1, a1, 10        # = 0x80001 << 10

    # 0xFF = 1111 1111
    # V R W X U G A D all = 1
    ori a1, a1, 0xFF

    sd a1, 0(a0)

# ==========================================================
# -------- DATA MAPPING -------------------------------------

    li a1, 0x80002
    slli a1, a1, 10        # = 0x80002 << 10

    # 0xF7 = 1111 0111
    # V=1, R=1, W=1, X=0 (no execute)
    # U=1 (user accessible)
    ori a1, a1, 0xF7

    sd a1, 8(a0)           # next entry

################################################################

# ---------------- SWITCH TO USER MODE -------------------------

    # Set SPP = 0 → User Mode
    li t1, 0
    slli t1, t1, 8         # SPP bit position
    csrs sstatus, t1

# ==========================================================
# -------- SATP CONFIGURATION -------------------------------

    la t1, satp_config
    ld t2, 0(t1)

    sfence.vma zero, zero  # Flush old TLB

    csrrw zero, satp, t2   # Load new page table

    sfence.vma zero, zero  # Flush again

# ==========================================================
# -------- SET USER ENTRY POINT -----------------------------

    li t4, 0               # Virtual Address = 0
    csrrw zero, sepc, t4   # sepc = 0

    sret                   # Jump to user mode

# ==========================================================
# ---------------- USER MODE CODE ---------------------------

.align 12                  # Align to 4KB (page aligned)

user_code:
    la t1, var1            # Load VA of var1
    la t2, var2
    la t3, var3
    la t4, var4

    j user_code            # Infinite loop

# ==========================================================
# ---------------- DATA SECTION -----------------------------

.data
.align 12

var1:  .word 1
var2:  .word 2
var3:  .word 3
var4:  .word 4

# ==========================================================
# ---------------- SATP BREAKDOWN ---------------------------

.align 8
satp_config: .dword 0x8000000000081000
