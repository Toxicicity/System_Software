/* 
========================================================================================
Name : Q1b.c
Author: Subham Sourav
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date : 20-08-2024
========================================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(void) {
  char f[128], h[128];
  printf("enter the path : ");
  scanf("%s", f);
  printf("enter  hard link name: ");
  scanf("%s", h);
  link(f, h);
  perror("perror response: ");
  
  return 0;
}




/*
    Sample Execution:

 $ cc Q1b.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
enter the path : /
enter  hard link name: qwerty
perror response: : Operation not permitted
subham@subham-GF75:~/ProblemSheet1$ ./a.out
enter the path : /home/subham/ProblemSheet1/NewFile3.txt
enter  hard link name: hardlink
perror response: : Success
*/