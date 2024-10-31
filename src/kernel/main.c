#include "include/stdint.h"
#include "include/stdio.h"

void _cdecl cstart_() {
    int age = 23;
    puts("Hello world from C!\r\n");
    printf("Formatted: %% %c %s\r\n", 'f', "Hello");
    printf("my age in hex is %X\r\n", age);
    printf("my age in oct is %o\r\n", age);
    printf("my age in bin is %b\r\n", age);
    printf("%lX, %p\r\n", 0xC0FFEE, 0xab);
    printf("%d, %i, %x, %p\r\n", 1234, -4321, 0xaa, 0xcc);
}
