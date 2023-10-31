// Print lines containing  specified substring from the files specified as arguments

#include <stdio.h>
// stdin, stdout, stderr
//     0,      1,      2
#include <string.h>
#include <errno.h>

#define MAX_LINE 65536

void mygrep(FILE *stream, char stream_name[], char search_for[]);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <substring> [files]\n", argv[0]);
        return 1;
    } 
    
    if (argc == 2) {
        // search standard input stream for the substring
        // For example, ./fgrep wordtofind 
        // will search stdin for wordtofind
        mygrep(stdin, "<stdin>", argv[1]); 
    } else {
        // loop through all file names given to grep the files
        for (int i = 2; i < argc; i++) {
            // open a file in read mode (and print the appropriate error if it doesnt work)
            FILE *f = fopen(argv[i], "r");
            if (f == NULL) {
                perror("could not open file");
                return -1;
            }
            // Use the grep function on the file
            mygrep(f, argv[i], argv[1]);
            // make sure to close the file after use
            fclose(f);
            
        }
        // what mode do we open in
        // how do we check fopen was successful
        // use errno to print the appropriate error

    }

    return 0;
}

// Searches for a substring in a file stream.
void mygrep(FILE *stream, char stream_name[], char search_for[]) {
    char line[MAX_LINE];
    int line_number = 1;
    printf("%s:\n", stream_name);
    // Loop through each line in the stream and search
    while (fgets(line, MAX_LINE, stream) != NULL) {
        if (strstr(line, search_for) != NULL) {
            fputs(line, stdout);
        }
    }
    
}