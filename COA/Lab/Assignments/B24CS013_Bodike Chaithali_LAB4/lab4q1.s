.data
first_name: .asciz "Bodike"
last_name: .asciz "Chaithali"


.globl roll
roll: .word 13


.text
.globl main


main:
	call getRank
	mv t0, a0
	la a0, first_name
	la a1, last_name
	mv a2, t0

	call print
	li a0, 0         
	li a7, 93         
	ecall
