#include <stdio.h>
#include <stdlib.h>
//#include <errno.h>
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
    int status = posix_spawn(&pid, args[0], NULL, NULL, args, environ);
    if (status) {
        printf("spawn: %s\n", strerror(status));
        exit(1);
    }
    // wait for the process to end, print the status
    // wont pass this point till after the process is done
    waitpid(pid, &status, 0);
    printf("process %d exited with status %d\n", pid, status);
}

int main(void) {
    // use whereis to find the locations of commands
    // call spawn and wait to get the date, user, hostname, current working directory
    spawn_and_wait((char *[]){"/usr/bin/date", "+%d-%m-%Y", NULL});

    // scan file names and cat each of them
    char line[128];
    while (fgets(line, 128, stdin)) {
        line[strlen(line) - 1] = 0; // remove newline
        spawn_and_wait((char *[]){"/usr/bin/cat", line, NULL});
    }
    return 0;
}