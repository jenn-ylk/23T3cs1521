#include <stdlib.h>
#include <stdio.h>
// #include <string.h>

int factorial_iter(int n) {
    int result = 1;

    for (int i = 1; i <= n; i++) {
        result = result * i;
    }

    return result;
}

// recursive implementation of factorial
int factorial_rec(int n) {
    // base case
    if (n <= 1) {
        return 1;
    }
    return n * factorial_rec(n - 1);
}

// ./print_arguments I love MIPS
// -> {"./print_arguments", "I", "love", "MIPS"}

// Reads in a command line argument for the number to calculate factorial of
int main(int argc, char *argv[]) {
    // Command line arguments being read in
    // printf("argc=%d\n", argc);
    // for (int i = 0; i < argc; i++) {
    //     // strcpy(argv[i], "a longer string");
    //     printf("argv[%d]=%s\n", i, argv[i]);
    // }
    // return 0;

    int n = atoi(argv[1]);

    printf("%d! = %d\n", n, factorial_rec(n));

    return 0;
}