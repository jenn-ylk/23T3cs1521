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
    // stat and check for error
    if (stat(argv[1], &s) == -1) {
        perror("Stat failed");
    }

    // s.st_mode   // stat field containing file permissions
    // s.st_mode & S_IROTH // is readable other
    // <file type><user><group><public>
    // S_IRUSR // readable by user (bit)
    // S_IWUSR // writable by user
    // S_IXGRP // executable by group
    // S_IRGRP == (S_IRUSR >> 3)

    
    // print out the user id number and the digits of mode related to permissions
    printf(
        "%s is owned by user id %u, with permissions %o\n", 
        argv[1], 
        s.st_uid, 
        s.st_mode & 0777
    );

    return 0;
}