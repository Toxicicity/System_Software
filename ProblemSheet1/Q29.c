/* 
========================================================================================
Name : Q29.c
Author: Subham Sourav
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).

Date : 31-08-2024
========================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void print_policy(int policy) {
    switch(policy) {
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER (Default)\n");
            break;
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO (Real-time)\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR (Round-robin)\n");
            break;
        default:
            printf("Unknown policy!\n");
            break;
    }
}

int main(int argc, char *argv[]) {
    struct sched_param param;
    int policy;
    int new_policy;
    
    policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("sched_getscheduler failed");
        return 1;
    }

    print_policy(policy);

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <policy>\n", argv[0]);
        fprintf(stderr, "policy: FIFO or RR\n");
        return 1;
    }

    if (strcmp(argv[1], "FIFO") == 0) {
        new_policy = SCHED_FIFO;
    } else if (strcmp(argv[1], "RR") == 0) {
        new_policy = SCHED_RR;
    } else {
        fprintf(stderr, "Invalid policy. Use 'FIFO' or 'RR'.\n");
        return 1;
    }

    param.sched_priority = sched_get_priority_max(new_policy);
    if (param.sched_priority == -1) {
        perror("et_priority_max failed");
        return 1;
    }

    if (sched_setscheduler(0, new_policy, &param) == -1) {
        perror("sched_setscheduler failed");
        return 1;
    }

    // Verify the change by getting the policy again
    policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("getscheduler failed");
        return 1;
    }

    print_policy(policy);

    return 0;
}



/*
Sample Execution:

$ cc Q29.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
Current scheduling policy: SCHED_OTHER (Default)
Usage: ./a.out <policy>
policy: FIFO or RR
subham@subham-GF75:~/ProblemSheet1$ ./a.out RR
Current scheduling policy: SCHED_OTHER (Default)
sched_setscheduler failed: Operation not permitted
subham@subham-GF75:~/ProblemSheet1$ sudo ./a.out RR
[sudo] password for subham: 
Current scheduling policy: SCHED_OTHER (Default)
Current scheduling policy: SCHED_RR (Round-robin)


*/