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
