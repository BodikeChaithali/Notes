.data
.text
.global main

main:
        addi t0, zero, 1
        addi t1, zero, 1
        addi t2, zero, 5
loop:
        mul t0, t0, t1
        addi t1, t1, 1
        ble t1, t2, loop
~                           
