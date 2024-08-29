#include <stdio.h>

// Declare the external variable
// environ is a array of pointers to string
// each string is in the form of key ans value
extern char **environ;

int main() {
    char **env = environ;

    // Loop through the array of environment variables
    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}

