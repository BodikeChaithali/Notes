.data
value:
        .word 10
value1:
        .word 20

.text
.global main
main:
        lw t0, value
        lw t1, value1

        mv t2, t0
        mv t0, t1
        mv t1, t2
