#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct Train {
    int ticket_count;
};

int main() {
    int fd;
    struct Train trains[3] = {{0}, {0}, {0}};  // Initialize three trains with zero tickets

    // Open or create the file
    fd = open("record.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Write the train records to the file
    write(fd, trains, sizeof(trains));

    // Close the file
    close(fd);
    printf("Initialized record.txt with three trains.\n");
    return 0;
}
