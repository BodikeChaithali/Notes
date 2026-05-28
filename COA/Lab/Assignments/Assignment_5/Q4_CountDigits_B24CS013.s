.text
.globl main

main:
	li t0,98765
	li t1,0
	li t2,10

loop:
	beq t0,zero,end
	
	addi t1,t1,1
	div t0,t0,t2

	j loop

end:
	ret
