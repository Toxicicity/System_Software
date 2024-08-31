/* 
========================================================================================
Name : Q6.c
Author: Subham Sourav
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date : 22-08-2024
========================================================================================
*/
#include <stdio.h>
#include <unistd.h>

#define size 2048

int main() {
    char buffer[size];
    ssize_t bytes_read;

    
    while ((bytes_read = read(STDIN_FILENO, buffer, size)) > 0) {
        
        write(STDOUT_FILENO, buffer, bytes_read);
    }
    if(bytes_read==0)
    {
	    perror("Every read has been succesfully printed");
    }

    if (bytes_read == -1) {
        perror("Error reading from STDIN");
        return 1;
    }

    return 0;
}


  /*  Sample Execution:


$ cc Q6.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
                     
*/