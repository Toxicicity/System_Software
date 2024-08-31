/* 
========================================================================================
Name : Q5.c
Author: Subham Sourav
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date : 22-08-2024
========================================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fds[5];
    const char *files[] = {"file100.txt", "file200.txt", "file300.txt", "file400.txt", "file500.txt"};

    
    for (int i = 0; i < 5; i++) {
        fds[i] = open(files[i], O_RDWR | O_CREAT, 0644);
        if (fds[i] == -1) {
            perror("Error opening file");
            return 1;
        }
        printf("File %s opened with descriptor %d\n", files[i], fds[i]);
    }

    
    while (1) {
        sleep(2); 
    }

   
    for (int i = 0; i < 5; i++) {
        close(fds[i]);
    }

    return 0;
}


/*
    Sample Execution:

$ cc Q5.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
File file100.txt opened with descriptor 3
File file200.txt opened with descriptor 4
File file300.txt opened with descriptor 5
File file400.txt opened with descriptor 6
File file500.txt opened with descriptor 7
*/
