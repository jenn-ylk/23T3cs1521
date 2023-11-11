// Simple code that accesses the HOME environment variable to open and read
// $HOME/.diary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LEN 128
#define MAX_LINE_LEN 512

int main(void) {
    // Get the required environment variables - the user and the home path
    char *user_name = getenv("USER");
    // note: getenv doesnt set errno
    if (user_name == NULL) {
        printf("%s is not an env variable\n", "USER");
        exit(1);
    }
    printf("About to print %s's .diary\n", user_name);

    // Construct the diary path name (concatenate with ./diary)
    char *home = getenv("HOME");
    char diary[MAX_PATH_LEN];
    snprintf(diary, MAX_PATH_LEN, "%s/.diary", home);

    printf("Diary is at %s\n", diary);
    // Open the diary, print an error if not doable
    FILE *f = fopen(diary, "r");
    
    // read the diary line by line and print
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, f)) {
        fputs(line, stdout);
    }

    // close the diary
    fclose(f);
    
    return 0;
}