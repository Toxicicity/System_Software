/*
========================================================================================
Name : Q18.c
Author: Subham Sourav
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date : 28-08-2024
========================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct Record {
    int value_at_record;
};

int main() {

    int fd;
    struct Record records[3] = {{0}, {0}, {0}}; 

    fd = open("record.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    write(fd, &records[0], sizeof(records));

   
    close(fd);
    printf("Initialized record.txt with three records.\n");
    return 0;
}
/*
$ cc Q18a.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
Initialized record.txt with three records.
*/