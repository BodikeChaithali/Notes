.data                   # Data section: used to store variables in memory

value:
        .byte 0x10       # Store one byte with value 0x10 (decimal 16)

value1:
        .byte 0xF6       # Store one byte with value 0xF6
                         # As a signed 8-bit value, this represents −10

.text                   # Code section (instructions)
.global main             # Make 'main' visible to the linker

main:
        lb t0, value     # Load 1 byte from memory at 'value'
                          # 'lb' = load byte (signed)
                          # 0x10 → sign-extended → t0 = 16

        lb t1, value1    # Load 1 byte from memory at 'value1'
                          # 0xF6 has MSB = 1, so it is negative
                          # Sign-extended → t1 = −10 (0xfffffffffffffff6)

        add t0, t0, t1   # Add contents of t0 and t1
                          # t0 = 16 + (−10) = 6

