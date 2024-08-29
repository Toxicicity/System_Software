#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

// Define the Train structure to store ticket information
struct Train {
    int ticket_count;  
};

int main() {
    int fd, input;
    struct Train db;  // This will hold the ticket info for the selected train

    // Open the file in read-write mode. Ensure 'record.txt' exists with appropriate initial data.
    fd = open("record.txt", O_RDWR);

    // Prompt user to select a train number
    printf("Select train number (1, 2, 3): \n");
    scanf("%d", &input);

    // Initialize file lock structure to manage concurrent file access safely
    struct flock lock;
    lock.l_type = F_WRLCK;  // Set type of lock to write lock
    lock.l_whence = SEEK_SET;  // Base for the lock offset
    lock.l_start = (input - 1) * sizeof(db);  // Start of the lock region
    lock.l_len = sizeof(db);  // Length of the lock region
    lock.l_pid = getpid();  // PID of the locking process

    // Move file pointer to the start of the selected train's record
    lseek(fd, (input - 1) * sizeof(db), SEEK_SET);
    read(fd, &db, sizeof(db));  // Read the record into 'db'

    printf("Before Entering into the critical section\n");

    // Lock the region for updating ticket count to avoid race conditions
    fcntl(fd, F_SETLKW, &lock);

    // Display the current ticket count for the selected train
    printf("Ticket number: %d \n", db.ticket_count);

    // Increment the ticket count
    db.ticket_count++;

    // Move the file pointer back to the beginning of the current record
    lseek(fd, -1 * sizeof(db), SEEK_CUR);

    // Write the updated ticket count back to the file
    write(fd, &db, sizeof(db));

    // Prompt the user to press Enter to book the ticket
    printf("To Book Ticket, press Enter: \n");
    getchar();  // Capture the newline character
    getchar();  // Wait for the user to press Enter

    // Unlock the file region
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Booked\n");
    printf("New ticket number is %d\n" , db.ticket_count);

    // Close the file
    close(fd);
    return 0;
}
