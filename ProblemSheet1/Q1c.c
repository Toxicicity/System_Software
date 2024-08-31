/* 
========================================================================================
Name : Q1c.c
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
#include <sys/types.h>
#include <fcntl.h>
#include <linux/stat.h>

// prevent warning 
int mkfifo(const char *pathname, mode_t mode);

int main(void) {
  char fname[128];
  printf("enter the filename: ");
  scanf("%s", fname);
  mkfifo(fname, 0777);
  
  printf("open the fifo pipe\n");
  getchar();
  int fifo_fd = open(fname, O_WRONLY);
  char msg[] = "this is fifo system";
  int count = write(fifo_fd, msg, sizeof(msg)/sizeof(char));
  close(fifo_fd);
  printf("%d characters written \n", count);
  
  return 0;
}

/*
    Sample Execution:

 $ cc Q1c.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
enter the filename: /home/subham/ProblemSheet1/NewFile3.txt
open the fifo pipe
20 characters written 
*/