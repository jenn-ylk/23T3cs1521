// 

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_STR_LEN 256

// the function being called as a thread must be a 
// function pointer (void *)
void *thread_feed_me(void *data) {
    // print "feed me input!" once a second
    while (1) {
        printf("thread!\n");;
        // sleep(2); // sleep for 2 seconds (sleep takes values in seconds)
    }
    
    return NULL;
}

int main (void) {    
    
    // spawn a thread to ask for input
    pthread_t thread;
    int ret = pthread_create(&thread, NULL, thread_feed_me, NULL);
    
    // char string[MAX_STR_LEN] = {0};
    // while (fgets(string, MAX_STR_LEN, stdin) != NULL) {
    //     printf("You entered: ");
    //     fputs(string, stdout);
    // }

    while(1) {
        printf("main\n");
    }
    
}