.data                  

value:
        .word 0x00110010       

.text                   
.global main             

main:
        lw t0, value     
    
        mv t1, t0   
