.section .text
.global main

# Machine Code
main:
     la t0, trap_handler
    csrw mtvec, t0

    csrr t1, mstatus
    li t2, 0x1800         
    not t2, t2
    and t1, t1, t2       
    csrw mstatus, t1

    la t0, user_code
    csrw mepc, t0

    mret

trap_handler:
    csrr t0, mcause       
    csrr t1, mepc         

    addi t1, t1, 4        
    csrw mepc, t1

    mret                  

# User Code
user_code:
    li a0, 5
    li a1, 6
    add a2, a0, a1     

    ecall                

    j user_code
