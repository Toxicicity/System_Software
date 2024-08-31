/* 
========================================================================================
Name : Q19.c
Author: Subham Sourav
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date : 28-08-2024
========================================================================================
*/



#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

int main(void) {
    clock_t begin, end;
    begin = clock();
    int pid = getpid();
    end = clock();
    double timeelapsed = end - begin;
    printf("getpid() took %lf seconds\n", (timeelapsed / CLOCKS_PER_SEC));

    return 0;
}

/*
Sample Execution:

$ cc Q19.c
 ./a.out
getpid() took 0.000015 seconds

*/