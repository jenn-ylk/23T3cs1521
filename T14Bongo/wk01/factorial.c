// 

#include <stdlib.h>
#include <stdio.h>

int factorial_iter(int n) {
    int result = 1;

    for (int i = 1; i <= n; i++) {
        result = result * i;
    }

    return result;
}

// recursive implementation of factorial
int factorial_rec(int n) {
    // TODO:
    if (n <= 1) {
        // base case (assuming a number below 0 is never given)
        return 1;
    } else {
        return n * factorial_rec(n-1);
    }
}


int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);

    printf("%d! = %d\n", n, factorial_rec(n));

    return 0;
}