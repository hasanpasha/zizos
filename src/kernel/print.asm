[BITS 16]

section _TEXT class=CODE

global _x86_video_writeCharTeletype
_x86_video_writeCharTeletype:
    PUSH bp
    MOV bp, sp

    PUSH bx

    MOV ah, 0x0E
    MOV al, [bp+4]
    MOV bh, [bp+6]
    INT 0x10

    POP bx

    MOV sp, bp
    POP bp

    RET

global _x86_div64_32
_x86_div64_32:
    PUSH bp
    MOV bp, sp

    PUSH bx

    MOV eax, [bp+8] ; upper 32 bits of dividends
    MOV ecx, [bp+12] ; divisor
    XOR edx, edx    ; will store remainder
    DIV ecx

    MOV bx, [bp+16] ; upper 32 bits of the quotient
    MOV [bx+4], eax

    MOV eax, [bp+4] ; lower 32 bits of dividends
    DIV ecx

    MOV [bx], eax ; lower 32 bits of the quotient
    MOV bx, [bp+18] ; remainder
    MOV [bx], edx

    POP bx

    MOV sp, bp
    POP bp

    RET