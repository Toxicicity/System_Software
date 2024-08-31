/* 
========================================================================================
Name : Q20.c
Author: Subham Sourav
Description : Find out the priority of your running program. Modify the priority with nice command
Date : 28-08-2024
========================================================================================
*/
#include <sys/types.h>

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    pid_t pid;
    int priority;

    
    pid = getpid();

    
    priority = getpriority(PRIO_PROCESS, pid);
    printf("Current priority for the process (PID: %d) is: %d\n", pid, priority);

    
    int new_nice_value = 10;
    int final = nice(new_nice_value);

    if (final == -1) {
        perror("Failed");
        return 1;
    }


    priority = getpriority(PRIO_PROCESS, pid);
    printf("New priority of the process (PID: %d) is: %d\n", pid, priority);

    return 0;
}





/*
Sample Execution:

$ cc Q20.c
./a.out
Current priority for the process (PID: 30758) is: 0
New priority of the process (PID: 30758) is: 10
*/