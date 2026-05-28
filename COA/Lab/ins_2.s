.data                   # Data section: used to store variables in memory

value:
        .byte 0x10       # Store one byte with value 0x10 (decimal 16)

value1:
        .byte 0x5       
                         

.text                   # Code section (instructions)
.global main             # Make 'main' visible to the linker

main:
        lbu t0, value     
                        
        lbu t1, value1
    
        sub t0, t0, t1   

