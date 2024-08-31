/* 
========================================================================================
Name : Q3.c
Author: Subham Sourav
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call.
Date : 20-08-2024
========================================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
   
    const char *f_path = "NewFile3.txt";
    int f_permissions = 0644; // Owner can read/write, others can read

    // Create the file 
    int f_d = creat(f_path, f_permissions);

    // Check 
    if (f_d == -1) {
        perror("Error creating the file");
        return 1;
    }

    // Print 
    printf("File desc: %d\n", f_d);

    // Close the file
    close(f_d);

    return 0;
}

/*
    Sample Execution:

$ cc Q3.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
File desc: 3
*/
