#include <stdio.h>

int main(void) {
    int numbers[8] = {
        1, 
        8, 
        10,
        15,
        16,
        100,
        127,
        200 
    };

    // 24 in dec, bin, hex and octal
    24;
    0b00011000;
    0x18;
    030;

    for (int i = 0; i < 8; i++) {
        // change to print also in hex and octal 
        // (there is no builtin format string for binary, need to print that bit by bit manually)
        printf("%05d = 0x%02x = 0%03o \n", numbers[i], numbers[i], numbers[i]);
    }

    return 0;
}