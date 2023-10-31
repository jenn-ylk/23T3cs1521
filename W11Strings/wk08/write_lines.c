// code that writes all of stdin to a file

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr,  "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // open the file in write mode ("w") 
    // - this will truncate the file if it already existed, or create it if it didnt exist
    FILE *f = fopen(argv[1], "w");
    if (f == NULL) {
        perror(argv[1]);
    }

    // read from stdin and put this into the file with fputs
    char line[MAX_LINE_LEN];
    // getting lines from stdin (the FILE * we use to access the standard input)
    // fgets returns the string, or null when eof is reached
    while (fgets(line, MAX_LINE_LEN, stdin) != NULL) {
        // output the line to the new file
        fputs(line, f);
        
    }

    // close the file when done
    // at the end of the program, the operating system should close any files opened by the program 
    // as appropriate, but it is best practice to close files when done with them to free up memory 
    // and to not have too many files open
    fclose(f); // this does actually have a return value and can fail, not checked here
    return 0;
}