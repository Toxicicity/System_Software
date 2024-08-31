    /* 
    ========================================================================================
    Name : Q26.c
    Author: Subham Sourav
    Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)

    Date : 29-08-2024
    ========================================================================================
    */
   
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>  // For strlen
#include <sys/types.h>
#include <sys/wait.h>  // For wait

int main() {
    int fd;
    pid_t pid;
    char input[] = "Hello from parent process\n";

    // Create a pipe
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork to create a child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        // Close the write end of the pipe
        close(pipefd[1]);

        // Redirect stdin to read from the pipe
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        // Execute the program (a.out)
        execl("./a.out", "a.out", (char *)NULL);
        perror("execl"); // Only reached if execl fails
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        // Close the read end of the pipe
        close(pipefd[0]);

        // Write input to the pipe
        write(pipefd[1], input, strlen(input));
        close(pipefd[1]);

        // Wait for the child to complete
        wait(NULL);
    }

    return 0;
}


   
  /*
    Sample Execution:

   $ cc Q26.c
subham@subham-GF75:~/ProblemSheet1$ cc -o aa Q26a.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
Received input: qwerty
You entered: qwerty
subham@subham-GF75:~/ProblemSheet1$ ./aa
Received input: You entered: Hello from parent process
*/