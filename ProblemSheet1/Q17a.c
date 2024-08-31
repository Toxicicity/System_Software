/*
========================================================================================
Name : Q17a.c
Author: Subham Sourav
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date : 28-08-2024
========================================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct Train {
    int ticket_count;
};

int main() {
    
    int fd;
    struct Train db;
    db.ticket_count=3;

    
    fd = open("sample.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    
    write(fd, &db, sizeof(db));

    
    close(fd);
    printf("Initialized record.txt with three trains.\n");
    return 0;
}
/*
$ cc Q17a.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
Initialized record.txt with three trains.

*/