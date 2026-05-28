.text
.globl main
main:
	li t0,123 #121
	mv t5,t0
	li t1,0
	li t2,10
loop:
	beq t0,zero,check
	rem t3,t0,t2
	mul t1,t1,t2
	add t1,t1,t3
	div t0,t0,t2
	j loop
check:
	beq t1,t5,pal
	li t6,0
 	j end
pal:
	li t6,1
end:
	ret
