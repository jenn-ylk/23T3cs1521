// code that will change file permissions to not be publically writeable 
// if it is publically writeable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        // stat the file, error if stat fails
        struct stat s;
        if (stat(argv[i], &s) == -1) {
            perror(argv[i]);
            continue;
        }


        
        // get the file mode from the stat struct, check whether it is public writable
        // change the permissions with chmod if the file is publically writeable
        if (s.st_mode & S_IWGRP) {
            printf("removing group write from %s\n", argv[i]);
            // change the permissions with chmod
            mode_t new_mode = s.st_mode & ~S_IWGRP;
            // !n => 0 (if n was non-zero), 1 (n was zero)
            // ~n => 0b0101 (if n was 0b1010)
            chmod(argv[i], new_mode);

        } else {
            printf("%s is not writable by group\n", argv[i]);
        }
    }
    
    return 0;
}