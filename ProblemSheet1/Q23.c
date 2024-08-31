    /* 
    ========================================================================================
    Name : Q23.c
    Author: Subham Sourav
    Description : Write a program to create a Zombie state of the running program.
    Date : 28-08-2024
    ========================================================================================
    */
     
     #include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    int pid = fork();
    if (!pid) {
        // This is zombie section
        printf("This is %d a zombie process, \n", getpid());
        return 0;
    }
    sleep(3);
    printf("press enter to view status of child process:");
    getchar(); 
    char buffer[128];
    sprintf(buffer, "cat /proc/%d/status | head -n 6", pid);
    return system(buffer);
}
   
  /*
    Sample Execution:

    $ c Q23.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
This is 39418 a zombie process, 
press enter to view status of child process:
Name:   a.out
State:  Z (zombie)
Tgid:   39418
Ngid:   0
Pid:    39418
PPid:   39417
    */