.text
.global main

main:
        li a1, 6        
        li a0, 1          

        li t0, 2          

check:
        mul t1, t0, t0    
        bgt t1, a1, done  

        rem t2, a1, t0    
        beqz t2, notprime 

        addi t0, t0, 1    
        j check

notprime:
        li a0, 0          

done:
        nop
