/* 
========================================================================================
Name : Q1a.c
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
  char f[128], s[128];
  printf("enter the filename : ");
  scanf("%s", f);
  printf("enter link name: ");
  scanf("%s", s);
  symlink(f, s);
  perror("perror response: ");
  
  return 0;
}



/*
    Sample Execution:
$ cc Q1a.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
enter the filename : fiile
enter link name: llink
perror response: : Success
*/