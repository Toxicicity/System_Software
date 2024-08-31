/*
========================================================================================
Name : Q17.c
Author: Subham Sourav
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date : 28-08-2024
========================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


struct Train {
    int ticket_count;  
};

int main() {
    int fd;
    struct Train db;  
    fd = open("sample.txt", O_RDWR);

    
    struct flock lock;
    lock.l_type = F_WRLCK;  
    lock.l_whence = SEEK_SET;  
    lock.l_start = 0;
    lock.l_len = 0; 
    lock.l_pid = getpid();  

    
    read(fd, &db, sizeof(db));  

    printf("Before Entering into the critical section\n");

    fcntl(fd, F_SETLKW, &lock);

    printf("Ticket count: %d \n", db.ticket_count);

    db.ticket_count++;

    lseek(fd, -1 * sizeof(db), SEEK_CUR);

    write(fd, &db, sizeof(db));

    printf("To Book Ticket, press Enter: \n");
    getchar();  


    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Booked\n");
    printf("New ticket number is %d\n" , db.ticket_count);

    
    close(fd);
    return 0;
}

/*
$ cc Q17.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
Before Entering into the critical section
Ticket count: 0 
To Book Ticket, press Enter: 

Booked
New ticket number is 1
*/