// Squares a number, unless its square is too big for a 32-bit integer.
// If it is too big, prints an error message instead.

#include <stdio.h>

#define SQUARE_MAX 46340

int main(void) {
    int x, y;

    printf("Enter a number: ");
    scanf("%d", &x);

//     if (x > SQUARE_MAX) goto too_big;
//     goto calc_square;
// too_big:
//     printf("square too big for 32 bits\n");
//     goto endif;
// calc_square:
//     y = x * x;
//     printf("%d\n", y);
// endif:

    // change the order:
    if (x > SQUARE_MAX) goto too_big;
    y = x * x;
    printf("%d\n", y);
    goto endif;
too_big:
    printf("square too big for 32 bits\n");
endif:

    // invert the condition
//     if (x <= SQUARE_MAX) goto calc_square;
//     printf("square too big for 32 bits\n");
//     goto endif;
// calc_square:
//     y = x * x;
//     printf("%d\n", y);
// endif:

    return 0;
}