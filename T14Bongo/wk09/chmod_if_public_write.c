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
        if (stat(argv[1], &s) == -1) {
            perror(argv[1]);
            continue;
        }
        
        // get the file mode from the stat struct, check whether it is public writable
        // change the permissions with chmod if the file is publically writeable
        if (s.st_mode & S_IWOTH) {
            printf("removing group write from %s\n", argv[i]);
            // keep all of the original mode, aside from setting public write off
            mode_t new_mode = s.st_mode & ~(S_IWOTH);
            if (chmod(argv[1], new_mode) == -1) {
                perror(argv[1]);
                continue;
            }
        } else {
            printf("%s is not writable by group\n", argv[i]);
        }
    }
    
    return 0;
}