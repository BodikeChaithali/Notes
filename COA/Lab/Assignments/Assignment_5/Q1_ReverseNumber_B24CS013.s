.text
.globl main
main:

    li t0, 1234     
    li t1, 0        
    li t2, 10      
loop:
    beq t0, zero, end

    rem t3, t0, t2     
    mul t1, t1, t2     
    add t1, t1, t3     
    div t0, t0, t2     

    j loop

end:
	ret
