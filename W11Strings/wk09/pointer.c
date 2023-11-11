// Compiler options:
/**
 * By default, dcc uses the -Wall (all warnings), and -Werror (warnings interpreted as errors)
 * If compiling with gcc or clang, these arent automatically in use, though could be used to avoid 
 * some common issues. 
 * -Wpedantic adds even more warnings, including those about type casting, as in the second example,
 * requiring specification of the types of pointers (making pointer arithmetic well defined)
*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>

// static uint16_t a;

// int main(void)
// {
//     uint16_t b;

//     uint16_t *pa = &a;
//     uint16_t *pb = &b;
//     uint16_t *pc = malloc(sizeof(uint16_t));

//     *pa = 0xAAAA;
//     *pb = 0xBBBB;
//     *pc = 0xCCCC;

//     // type cast pointers
//     printf("a:\n\tvalue: 0x%X\n\taddress: %16p\n", *pa, (void *)pa);
//     printf("b:\n\tvalue: 0x%X\n\taddress: %16p\n", *pb, (void *)pb);
//     printf("c:\n\tvalue: 0x%X\n\taddress: %16p\n", *pc, (void *)pc);
// }

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void *next_byte(void *byte){
    return (char *)byte + 1;
}

int main(void)
{
    uint8_t  chars[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    uint32_t ints[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("%16p - %16p\n", (void *)&chars[0], (void *)next_byte(&chars[0]));
    printf("%16p - %16p\n", (void *)&ints[0],  (void *)next_byte(&ints[0]));
}