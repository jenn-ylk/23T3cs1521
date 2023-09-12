#include <stdio.h>
// #include <string.h>

int main(void) {
    char str[10];
    str[0] = 'H';
    str[1] = 'i';
    str[2] = '\0';
    // or just use strcpy
    // strcpy(str, "Hi");
    printf("%s", str);
    return 0;
}


// get_num_ptr code

// #include <stdio.h>
// #include <stdlib.h>

// int *get_num_ptr(void);

// int main(void) {
//     int *num = get_num_ptr();

//     printf("%d\n", *num);
// }

// int *get_num_ptr(void) {
//     int *x = malloc(sizeof(int));
//     *x = 42;
//     return x;
// }

// int modify_num_ptr(int *x) {
//     *x = 42;
//     return x;
// }