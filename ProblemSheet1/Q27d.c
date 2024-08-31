/* 
========================================================================================
Name : Q27.c
Author: Subham Sourav
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp

Date : 31-08-2024
========================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    if (!fork()) {
        char *args[] = {"ls", "-Rl", NULL};
        return execv("/bin/ls", args);
    }

    wait(0);
    return 0;
}


/*
Sample Execution:

$  cc Q27d.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
.:
total 228
-rwxrwxr-x 1 subham subham 16432 Aug 30 15:09 a
-rwxrwxr-x 1 subham subham 16088 Aug 31 18:29 a.out
-rwxrwxr-x 1 subham subham 16168 Aug 30 15:10 b
-rw-rw-r-- 1 subham subham    27 Aug 29 03:07 example.txt
-rw-r--r-- 1 subham subham   109 Aug 22 01:20 NewFile3.txt
-rw-rw-r-- 1 subham subham   268 Aug 31 12:40 output.txt
-rw-rw-r-- 1 subham subham  1002 Aug 22 18:30 Q10.c
-rw-rw-r-- 1 subham subham   644 Aug 22 19:50 Q11a.c
-rw-rw-r-- 1 subham subham   647 Aug 22 19:52 Q11b.c
-rw-rw-r-- 1 subham subham   653 Aug 22 19:56 Q11c.c
-rw-rw-r-- 1 subham subham   155 Aug 24 16:42 Q12.c
-rw-rw-r-- 1 subham subham  1112 Aug 28 19:24 Q13.c
-rw-rw-r-- 1 subham subham  1286 Aug 29 10:27 Q14.c
-rw-rw-r-- 1 subham subham   351 Aug 29 01:44 Q15.c
-rw-rw-r-- 1 subham subham  1152 Aug 29 09:49 Q16a.c
-rw-rw-r-- 1 subham subham  1115 Aug 29 09:52 Q16b.c
-rw-rw-r-- 1 subham subham   461 Aug 30 18:29 Q17a.c
-rw-rw-r-- 1 subham subham   946 Aug 30 18:28 Q17.c
-rw-rw-r-- 1 subham subham   469 Aug 30 18:33 Q18a.c
-rw-rw-r-- 1 subham subham  1829 Aug 30 18:42 Q18.c
-rw-rw-r-- 1 subham subham   732 Aug 31 10:51 Q19.c
-rw-rw-r-- 1 subham subham  1084 Aug 31 11:28 Q20.c
-rw-rw-r-- 1 subham subham  1121 Aug 31 12:02 Q21.c
-rw-rw-r-- 1 subham subham  1616 Aug 31 12:40 Q22.c
-rw-rw-r-- 1 subham subham  1045 Aug 31 16:37 Q23.c
-rw-rw-r-- 1 subham subham  1350 Aug 31 17:07 Q24.c
-rw-rw-r-- 1 subham subham  1751 Aug 31 18:01 Q25.c
-rw-rw-r-- 1 subham subham     0 Aug 31 18:12 Q26a.c
-rw-rw-r-- 1 subham subham     0 Aug 31 18:12 Q26b.sh
-rw-rw-r-- 1 subham subham   825 Aug 31 18:12 Q26.c
-rw-rw-r-- 1 subham subham  3160 Aug 31 18:27 Q27a.c
-rw-rw-r-- 1 subham subham  3128 Aug 31 18:27 Q27b.c
-rw-rw-r-- 1 subham subham  3206 Aug 31 18:28 Q27c.c
-rw-rw-r-- 1 subham subham   736 Aug 31 18:29 Q27d.c
-rw-rw-r-- 1 subham subham   500 Aug 31 18:18 Q27e.c
-rw-rw-r-- 1 subham subham    69 Aug 21 20:55 Q2.c
-rw-rw-r-- 1 subham subham   549 Aug 21 17:57 Q3.c
-rw-rw-r-- 1 subham subham   678 Aug 21 20:46 Q4.c
-rw-rw-r-- 1 subham subham   603 Aug 21 21:50 Q5.c
-rwxrwxr-x 1 subham subham 16088 Aug 30 14:55 Q6
-rw-rw-r-- 1 subham subham   461 Aug 21 22:41 Q6.c
-rw-rw-r-- 1 subham subham   488 Aug 22 09:08 Q7.c
-rw-rw-r-- 1 subham subham   668 Aug 22 09:00 Q8.c
-rw-rw-r-- 1 subham subham   943 Aug 22 16:10 Q9.c
-rw-rw-r-- 1 subham subham    12 Aug 30 18:42 record.txt
-rw-rw-r-- 1 subham subham     4 Aug 30 16:40 sample.txt
lrwxrwxrwx 1 subham subham    12 Aug 22 01:07 sftlnk -> NewFile3.txt
*/