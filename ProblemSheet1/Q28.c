/* 
========================================================================================
Name : Q28.c
Author: Subham Sourav
Description : Write a program to get maximum and minimum real time priority.

Date : 31-08-2024
========================================================================================
*/

#include <stdio.h>
#include <sched.h>

int main() {
    int max_priority, min_priority;

    max_priority = sched_get_priority_max(SCHED_FIFO);
    if (max_priority == -1) {
        perror("sched_get_priority_max failed");
        return 1;
    }

    min_priority = sched_get_priority_min(SCHED_FIFO);
    if (min_priority == -1) {
        perror("sched_get_priority_min failed");
        return 1;
    }

    printf("Maximum real-time priority: %d\n", max_priority);
    printf("Minimum real-time priority: %d\n", min_priority);

     printf("round robin:\n  max: %d\n  min: %d\n", 
        sched_get_priority_max(SCHED_RR),
        sched_get_priority_min(SCHED_RR));    

    return 0;
}


/*
Sample Execution:

$ cc Q28.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
Maximum real-time priority: 99
Minimum real-time priority: 1
round robin:
  max: 99
  min: 1


*/