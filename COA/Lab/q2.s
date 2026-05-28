.section .data
.global main

main:
	addi sp,sp,-32
	sd ra,24(sp)
	sd s0,16(sp)
	addi s0,sp,32
	li a5,1
	sw a5,-20(s0)
	li a5,5
	sw a5,-24(s0)
	lw a4,-20(s0)
	lw a5,-24(s0)
	mulw a5,a4,a5

	ld ra,24(sp)
	ld s0,16(sp)
	addi sp,sp,32
	ret	
