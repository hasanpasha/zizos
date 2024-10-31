set disassembly-flavor intel
set architecture i8086
target remote localhost:1234
layout asm
break *0x7C00
continue
