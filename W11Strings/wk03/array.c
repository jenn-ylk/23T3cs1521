// A simple program that will read 10 numbers into an array

#define N_SIZE 5

#include <stdio.h>

int main(void) {
    int i;
    int numbers[N_SIZE] = {0};

    // TODO: read in the integers
    i = 0;
    while (i < N_SIZE) {
        scanf("%d", &numbers[i]);
        // i[numbers];
        i++;
    }

    // TODO: in MIPS, alter a value in the array


    // TODO: write the integers
    i = 0;
    while (i < N_SIZE) {
        printf("%d\n", numbers[i]);
        i++;
    }
}