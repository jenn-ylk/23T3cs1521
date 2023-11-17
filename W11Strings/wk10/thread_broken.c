#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// the function to be used to create a thred
// note: void *data can be cast to a different type (int *) when needed
void *thread_run(void *data) {
    printf("Hello from thread!\n");
    printf("data is %p, value is %d\n", data, (*(int *)data));
    return NULL;
}

int main(void) {
    pthread_t thread;
    int val = 5;
    // create thread, to run the thread_run function
    pthread_create(&thread, NULL, thread_run, &val);

    int ret;
    pthread_join(thread, NULL);
    return 0;
}
