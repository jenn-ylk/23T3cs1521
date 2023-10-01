// A simple loop that could calculate the length of a string

#include <stdio.h>

int main(void) {
    char string[64] = "Hello there!!";
    
    // Using a counter
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }

    // TODO: could this be done differently?
    char *s = &string[0];
    i = 0;
    while (*s != '\0') {
        s++;
        i++;
    }

    printf("\"%s\" is %d characters long\n", string, i);

    int *p = &i;
    s = &string[0];
    printf("s = %p, s + 1 = %p\n", s, s + 1);
    printf("p = %p, p + 1 = %p\n", p, p + 1);

}