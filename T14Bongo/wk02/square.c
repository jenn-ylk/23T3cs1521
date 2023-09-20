// Squares a number, unless its square is too big for a 32-bit integer.
// If it is too big, prints an error message instead.

#include <stdio.h>

#define SQUARE_MAX 46340

int main(void) {
    int x, y;

    printf("Enter a number: ");
    scanf("%d", &x);

    // A translation with more labels (one for each branch)
    /*
    if (x > SQUARE_MAX) goto too_big;
    goto square;
too_big:
    printf("square too big for 32 bits\n");
    goto end;
square:
    y = x * x;
    printf("%d\n", y);

end:
    return 0;
    */

   // Translation with fewer labels (inverting if condition to the square case)
    if (x <= SQUARE_MAX) goto square;
    printf("square too big for 32 bits\n");
    goto end;
square:
    y = x * x;
    printf("%d\n", y);

end:
    return 0;
}