/* 
========================================================================================
Name : Q4.c
Author: Subham Sourav
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date : 21-08-2024
========================================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *f_path = "temp.txt";  

     int f_descriptor = open(f_path, O_RDWR | O_CREAT | O_EXCL, 0644);
 
    if (f_descriptor == -1) {
        perror("Error opening the file");
        return 1;
    }

  
    printf("File opened successfully with descriptor: %d\n", f_descriptor);

    const char *data = "Hello    World!";
    ssize_t b = write(f_descriptor, data, sizeof(data));

    if (b == -1) {
        perror("Error writing to the file");
        close(f_descriptor);
        return 1;
    }

    printf("Wrote %ld bytes to the file.\n", b);

    
    close(f_descriptor);

    return 0;
}

/*
    Sample Execution:

$ cc Q4.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
File opened successfully with descriptor: 3
Wrote 8 bytes to the file.
*/

