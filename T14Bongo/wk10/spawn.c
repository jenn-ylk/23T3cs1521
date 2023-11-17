#include <stdio.h>
//#include <stdlib.h>
#include <errno.h>
#include <string.h>
//#include <unistd.h>
#include <spawn.h>
#include <sys/types.h>
//#include <sys/stat.h>
#include <sys/wait.h>

// sets up environment for processes we'll spawn
extern char **environ;

void spawn_and_wait(char **args) {
    // set things up to spawn a process, then wait for it to finish
    pid_t pid;
    // spawn the process
    int err = posix_spawn(&pid, args[0], NULL, NULL, args, environ);
    if (err) {
        // print the error number to stdout
        printf("%s\n", strerror(args[0]));
    }
    
    
    // wait until child process dies
    int status;
    waitpid(pid, &status, 0);
    printf("Process exited with status %d\n", status);
}

int main(void) {
    // use whereis to find the locations of commands
    // call spawn and wait to get the date, user, hostname, current working directory
    spawn_and_wait((char *[]){"/usr/bin/date", "+%d-%m-%Y", NULL});
    


    // scan file names and cat each of them
    char fname[128];
    while (fgets(fname, 128, stdin)) {
        fname[strlen(fname) - 1] = 0; // strip the new line
        spawn_and_wait((char *[]){"/usr/bin/cat", fname, NULL});

    }
    return 0;
}