.section .text
.global strlen
.global main

main:
strlen:
	la a1,str
	li t0,0
1:
	add t1,t0,a1
	lb t1,0(t1)
	beqz t1,1f
	addi t0,t0,1
	j 1b
1:
	mv a0,t0
	ret
.data
str:
	.ascii "Hello World!"
