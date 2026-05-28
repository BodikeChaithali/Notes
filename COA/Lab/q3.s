.section .text
.global main

main:
	li a0,5
	li a1,7
	jal ra,sum_function
	ret

.global sum_function

sum_function:
	add a0,a0,a1
	ret
