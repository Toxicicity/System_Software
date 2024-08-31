/* 
========================================================================================
Name : Q21.c
Author: Subham Sourav
Description : Write a program, call fork and print the parent and child process id.
Date : 28-08-2024
========================================================================================
*/
#include<sys/types.h>
#include <stdio.h>
#include <unistd.h>  

int main() {
    
    pid_t pid = fork();

    if (pid == -1) {
    
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("\n");
        printf("below statement is executed by child process\n");
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        
                printf("below statement is executed by parent process\n");

        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}




/*
Sample Execution:

cc Q21.c
./a.out
below statement is executed by parent process
Parent process: PID = 32613, Child PID = 32614

below statement is executed by child process
Child process: PID = 32614, Parent PID = 32613
*/