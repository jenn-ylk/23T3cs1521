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

    // read every 5th character and print it out - use fseek to skip characters
    char c = fgetc(ciphered);
    while (c != EOF) {
        printf("%c", c);
        // skip to the next character with fseek
        fseek(ciphered, 4, SEEK_CUR);
        c = fgetc(ciphered);
    }

    fclose(ciphered);
    
    return 0;
}