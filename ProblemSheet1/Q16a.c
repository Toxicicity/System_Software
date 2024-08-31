/* 
========================================================================================
Name : Q16a.c
Author: Subham Sourav
Description : Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
Date : 28-08-2024
========================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int f=0;
void lock_file(int fd, int lock_type) {
    struct flock lock;

    lock.l_type = lock_type; // F_WRLCK for write lock, F_RDLCK for read lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; // 0 means to lock the entire file

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Locking failed");
        exit(1);
    } else {
	    if(f==0)
        printf("File locked  successfully.\n");
	    else
	printf("file unlcoked success .\n");
    }
}

int main() {
    int fd;
    const char *filename = "NewFile3.txt";

    // Open the file for reading and writing
    fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Apply a write lock (F_WRLCK)
    lock_file(fd, F_WRLCK);

    // Write to the file
    write(fd, "This is a write lock test.\n", 27);

    // Pause to hold the lock
    printf("Holding write lock. Press Enter to release lock and exit.\n");
    getchar();
    f=1;
    lock_file(fd,F_UNLCK);

    // Close the file
    close(fd);
     
    return 0;
}

/*
$ cc Q16a.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
File locked  successfully.
Holding write lock. Press Enter to release lock and exit.

file unlcoked success .

*/