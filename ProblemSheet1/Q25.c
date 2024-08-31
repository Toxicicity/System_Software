    /* 
    ========================================================================================
    Name : Q25.c
    Author: Subham Sourav
    Description : Write a program to create an orphan process.
    Date : 28-08-2024
    ========================================================================================
    */
    #include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    char cmd[128];
    int pid_1 = fork();
    if (!pid_1) {
        // child 1
        printf(" first child, pid %d\n", getpid());
        return 0;
    }
    int pid_2 = fork();
    if (!pid_2) {
        // child 2
        printf("second child, pid %d\n", getpid());
        return 0;
    }
    int pid_3 = fork();
    if (!pid_3) {
        // child 3
        printf("favourite child, pid %d\n", getpid());
        return 0;
    }
    waitpid(pid_3, NULL, 0);
    printf("\nfirst child status:\n");
    sprintf(cmd, "cat /proc/%d/status | head -n 7", pid_1);
    system(cmd);
    printf("\nsecond child status:\n");
    sprintf(cmd, "cat /proc/%d/status | head -n 7", pid_2);
    system(cmd);
    printf("\nfavourite child status:\n");
    sprintf(cmd, "cat /proc/%d/status | head -n 7", pid_3);
    system(cmd);
    
    
}

/*

   
  /*
    Sample Execution:

    $ cc Q25.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
 first child, pid 43979
second child, pid 43980
favourite child, pid 43981

first child status:
Name:   a.out
State:  Z (zombie)
Tgid:   43979
Ngid:   0
Pid:    43979
PPid:   43978
TracerPid:      0

second child status:
Name:   a.out
State:  Z (zombie)
Tgid:   43980
Ngid:   0
Pid:    43980
PPid:   43978
TracerPid:      0

favourite child status:
cat: /proc/43981/status: No such file or directory
    */