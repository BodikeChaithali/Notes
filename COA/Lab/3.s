.section .data
.global msg
msg:
    .asciz "Gold"

.section .text
.global change_msg

change_msg:
    la t0, msg
    li t1, 'C'
    sb t1, 0(t0)
    ret
