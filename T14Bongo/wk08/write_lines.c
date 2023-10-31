// code that writes all of stdin to a file

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr,  "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // TODO: open the file in write mode
    FILE *f = fopen(argv[1], "w");
    
    // read from stdin and put this into the file with fputs
    char line[MAX_LINE_LEN];
    // getting lines from stdin (the FILE * we use to access the standard input)
    // fgets returns the string, or null when eof is reached
    while (fgets(line, MAX_LINE_LEN, stdin) != NULL) {
        // TODO: output the line to the new file
        fputs(line, f);
    }

    // TODO: close the file when done
    fclose(f);
    return 0;
}