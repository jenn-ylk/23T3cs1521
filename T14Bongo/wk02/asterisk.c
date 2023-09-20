// Prints a right - angled triangle of asterisks, 10 rows high.

#include <stdio.h>

// Prints a right - angled triangle of asterisks, 10 rows high.

#include <stdio.h>

int main(void) {
    int i, j;
    // for (int j = 0; j < 5; j++) {
    //     printf("*\n");
    // }

    // Translation of the above for loop
loop_start:;    
    // For the C99 standard, initialisation can't be the line after a label, 
    // adding the empty statement ";" allows initialisation to happen
    i = 0;
loop_step:
    if (i >= 5) goto loop_end; 
    printf("*\n");
    i++;
    goto loop_step; // unconditional branch
loop_end:

    /*
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
    */
    i = 1;
outer_loop_cond:
    if (i > 5) goto outer_loop_end;
    j = 0;
inner_loop_cond:
    if (j >= i) goto inner_loop_end;
    printf("*");
    j++;
    goto inner_loop_cond;
inner_loop_end:
    printf("\n");
    i++;
    goto outer_loop_cond;
outer_loop_end:
    return 0;
}