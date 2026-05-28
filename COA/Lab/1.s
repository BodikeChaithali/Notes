.section .text
.global main

main:
    # Initialize x from assembly
    la t0, x
    li t1, 42
    sw t1, 0(t0)

    # Call C function to print x
    jal ra, print_x
    
    li a0, 0        # exit code
    li a7, 93       # exit syscall
    ecall
