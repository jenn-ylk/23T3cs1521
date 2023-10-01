// A simple loop that could calculate the length of a string

int main(void) {
    char string[64] = "Hello there!!";
    
    // Using a counter
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }

    // TODO: could this be done differently?

    printf("\"%s\" is %d characters long\n", string, i);

}