    /* 
    ========================================================================================
    Name : Q24.c
    Author: Subham Sourav
    Description : Write a program to create an orphan process.
    Date : 28-08-2024
    ========================================================================================
    */
     
     #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("Child process: My PID is %d and my parent PID is %d\n", getpid(), getppid());

        sleep(5);

        printf("\n Child process: My new parent PID is %d (init process)\n", getppid());
        
        sleep(2);
        printf("Child exited\n");
        exit(0);
    } else {
        sleep(1);
        printf("Parent process: My PID is %d, my child PID is %d\n", getpid(), pid);

        printf("Parent terminated\n");
        
    }

    return 0;
}

   
  /*
    Sample Execution:

    $ cc Q24.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
Child process: My PID is 41470 and my parent PID is 41469
Parent process: My PID is 41469, my child PID is 41470
Parent terminated
 $ 
 Child process: My new parent PID is 2022 (init process)
Child exited
    */