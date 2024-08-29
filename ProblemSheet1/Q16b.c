#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void lock_file(int fd, int lock_type) {
    struct flock lock;

    lock.l_type = lock_type; // F_RDLCK for read lock, F_WRLCK for write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; // 0 means to lock the entire file

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Locking failed");
        exit(1);
    } else {
        printf("File locked successfully.\n");
    }
}

int main() {
    int fd;
    const char *filename = "example.txt";

    // Open the file for reading and writing
    fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Apply a read lock (F_RDLCK)
    lock_file(fd, F_RDLCK);

    // Read from the file
    char buffer[100]="This is read file";
    read(fd, buffer, sizeof(buffer) - 1);
    printf("File contents: %s\n", buffer);

    // Pause to hold the lock
    printf("Holding read lock. Press Enter to release lock and exit.\n");
    getchar();

    // Close the file
    close(fd);

    return 0;
}

