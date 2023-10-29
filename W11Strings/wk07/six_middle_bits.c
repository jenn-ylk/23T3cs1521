#include <stdio.h>
#include <stdint.h>

// a function that uses bitwise operations to 
// return the six middle bits of a 32 bit number, 
// shifted into the least significant 6 bits
uint32_t six_middle_bits(uint32_t u) {
    // e.g.: 0b 00000000 00001110 01010000 00001010 -> 
    //          00000000 00000000 00000000 00110010
    // TODO: complete this (note: there are two methods that could be used)
    // shift then mask (13 to reach the middle)
    return (u >> 13) & 0x3F; // 0b111111
}

int main (void) {
    int16_t res = 30000 + 30000;
    printf("%d + %d = %d\n", 30000, 30000, res);

    uint32_t num = 0x000e5005;
    uint32_t result = six_middle_bits(num);
    printf("The middle six bits of %d (%x) are %d (%x)\n", num, num, result, result);
}