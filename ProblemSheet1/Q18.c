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
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

struct Record {
    int value_at_record;
};

int main() {
    int fd, input;
    struct Record records;  

    fd = open("record.txt", O_RDWR);

    
    printf("Select record number (1, 2, 3): \n");
    scanf("%d", &input);

    
    struct flock lock;
    lock.l_type = F_WRLCK;  
    lock.l_whence = SEEK_SET;  
    lock.l_start = (input - 1) * sizeof(records);  // Start of the lock region
    lock.l_len = sizeof(records);  // Length of the lock region
    lock.l_pid = getpid();  

    // Move file pointer to the start of the selected train's record
    lseek(fd, (input - 1) * sizeof(records), SEEK_SET);
    read(fd, &records, sizeof(records));  // Read the record into 'records'

    printf("Before Entering into the critical section\n");

    // Lock the region for updating record count to avoid race conditions
    fcntl(fd, F_SETLKW, &lock);

    // Display the current ticket count for the selected train
    printf("Record count: %d \n", records.value_at_record);

    // Increment the ticket count
    records.value_at_record++;

    // Move the file pointer back to the beginning of the current record
    lseek(fd, -1 * sizeof(records), SEEK_CUR);

    // Write the updated ticket count back to the file
    write(fd, &records, sizeof(records));

    // Prompt the user to press Enter to book the ticket
    printf("To execute, press Enter: \n");
    getchar();  // Capture the newline character
    getchar();  // Wait for the user to press Enter

    // Unlock the file region
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Increased\n");
    printf("New record number is %d\n" , records.value_at_record);

    // Close the file
    close(fd);
    return 0;
}

/*
$ ./a.out
Select record number (1, 2, 3): 
2
Before Entering into the critical section
Record count: 0 
To execute, press Enter: 

Increased
New record number is 1
*/