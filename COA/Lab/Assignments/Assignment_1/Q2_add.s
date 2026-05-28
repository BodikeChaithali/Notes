.text
.global main

main:
        li t0, 15   
        li t1, 7        
        mul t2, t0, t1   

        li t0, 20     
        li t1, 4        
        div t3, t0, t1  

        add t4, t2, t3 
        addi t4, t4, -32 
