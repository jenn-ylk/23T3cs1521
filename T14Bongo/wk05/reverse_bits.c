// Code containing a function that will reverse the bits of an unsigned int

#include <stdint.h>
#include <stdio.h>

#define WORD_BITS 32

typedef uint32_t Word;

void printBits(Word w) {
    // how does this code work to print bits of a number
    for (int shift = WORD_BITS-1; shift >= 0; shift--) {
        printf("%d", (w >> shift) & 1);
    }
    printf("\n");
}

// a function that reverses the bit order of a word
Word reverseBits(Word w) {
    Word new_word = 0;
    // reverse the bits of the word (32 bit int) using this function
    for (int i = 0; i < WORD_BITS; i++) {
        // get a bit from the original number
        // shift new word up once
        // place the new bit at the bottom
        new_word = (new_word << 1) | (w >> i) & 1;
    }
    return new_word;
}

int main(void) {
    Word w = 0x4A1900FF; // 0x01234567;
    printBits(w);
    printBits(reverseBits(w));
    printBits(reverseBits(reverseBits(w)));
}