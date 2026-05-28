.text
.global main

main:
        li a1, 5          
        jal ra, fact      
        j done

fact:
        addi sp, sp, -16  
        sd ra, 8(sp)     
        sd a1, 0(sp)    

        li t0, 1
        ble a1, t0, base 

        addi a1, a1, -1
        jal ra, fact     

        ld t1, 0(sp)     
        mul a0, a0, t1  
        j restore

base:
        li a0, 1         

restore:
        ld ra, 8(sp)     
        addi sp, sp, 16 
        ret

done:
        li a7, 10
        ecall
