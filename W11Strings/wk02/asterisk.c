// Prints a right - angled triangle of asterisks, 10 rows high.

#include <stdio.h>

// Prints a right - angled triangle of asterisks, 10 rows high.

#include <stdio.h>

int main(void) {
    // initialised here in order to make example code simpler
    int i, j;
    // for (int j = 0; j < 5; j++) {
    //     printf("*\n");
    // }
loop_start:;
    i = 0;
loop_cond:
    // invert condition to skip past the loop contents
    if (i >= 5) goto loop_end; 
        printf("*\n");
        i++;
        goto loop_cond;
loop_end:


    /*
    for (int i = 1; i <= 5; i++) {
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