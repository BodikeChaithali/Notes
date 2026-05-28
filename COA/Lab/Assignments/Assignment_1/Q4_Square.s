.text
.global main

main:
        li a1, 16       
        li a0, 0         

        li t0, 1         

loop:
        mul t1, t0, t0   
        beq t1, a1, square   
        bgt t1, a1, done     

        addi t0, t0, 1   
        j loop

square:
        li a0, 1        

done:
        li a7, 10 
    	ecall
