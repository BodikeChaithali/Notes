.section .text
.globl main

main:
    la t0, trap_handler
    csrw mtvec, t0

    la t0, user_code
    csrw mepc, t0

    csrr t1, mstatus
    li t2, ~(3 << 11)      
    and t1, t1, t2
    csrw mstatus, t1

    mret                  

# USER MODE
user_code:
    csrr t0, mtvec     

    addi a0, zero, 1  

    j end_program

# Machine Mode
trap_handler:
    csrr t1, mcause    
    csrr t2, mepc     
    csrr t3, mtval    

    addi t2, t2, 4
    csrw mepc, t2

    mret             

end_program:
    li a7, 93  
    ecall
