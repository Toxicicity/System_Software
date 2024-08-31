/* 
========================================================================================
Name : Q10.c
Author: Subham Sourav
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date : 25-08-2024
========================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    ssize_t bytes_written;
    off_t offset;
    char data1[10] = "1234567890";  
    char data2[10] = "abcdefghij"; 

    
    fd = open("text.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

   
    bytes_written = write(fd, data1, 10);
    if (bytes_written != 10) {
        perror("Error writing the first 10 bytes");
        close(fd);
        return 1;
    }

   
    offset = lseek(fd, 10, SEEK_CUR);
    if (offset == -1) {
        perror("Error using lseek");
        close(fd);
        return 1;
    } 

    
    bytes_written = write(fd, data2, 10);
    if (bytes_written != 10) {
        perror("Error writing the second 10 bytes");
        close(fd);
        return 1;
    }

    printf("lseek returned offset: %ld\n", lseek(fd,0,SEEK_CUR));
    
    close(fd);
 //use this after running this file,  od -c example.txt

    return 0;
}

/*
$ cc Q10.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
lseek returned offset: 30
*/