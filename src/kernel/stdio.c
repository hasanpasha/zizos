#include "stdio.h"
#include "print.h"

void putc(char c) {
    x86_video_writeCharTeletype(c, 0);
}


void puts(const char* str) {
    while (*str != 0){
        putc(*str);
        str++;
    }

}
