// Code that takes in a filename and provides some info (using stat struct)

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define MAX_LINE_LEN 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr,  "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // run stat on the file - if there is an error, print the error
    struct stat s;
    if (stat(argv[1], &s) == -1) {
        perror(argv[1]);
    }
    
    // print out the user id number and the digits of mode related to permissions
    printf(
        "%s is owned by user id %u, with permissions %o\n", 
        argv[1], 
        s.st_uid, 
        s.st_mode & 0777 // S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH
    );

    // For checking the type of entry, use the S_ISDIR macro
    // bitwise comparisons with each permission flag, e.g.:
    // if (s.st_mode & S_IRUSR) {}

    
    // // check each of the permissions 
    // // (every permission bit is next to one another, so could use bitshifts 
    // // - always check this against the documentation)
    // if (s.st_mode & (S_IRUSR >> i)) {
    //     if (i % 3 == 0) { /*readable*/ }
    //     // etc for the other modes
    // } else { /*-*/}

    return 0;
}