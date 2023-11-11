// A program that deciphers text using fseek
// Cipher where every 5th character (starting from 0th) is a valid character

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    FILE *ciphered = fopen(argv[1], "r");
    if (ciphered == NULL) {
        perror(argv[1]);
    }

    // read every 5th character and print it out
    char c = fgetc(ciphered);
    while (c != EOF) {
        putchar(c);
        // seek past the next 4 bytes (rather than reading the bytes from the file)
        fseek(ciphered, 4, SEEK_CUR);
        c = fgetc(ciphered);
    }

    fclose(ciphered);
    
    return 0;
}