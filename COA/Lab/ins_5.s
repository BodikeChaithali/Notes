.data
.text
.global main             

main:
        li t0, 0x01011101 
	li t1, 0x11010111    
    
        xor t2, t0, t1   
