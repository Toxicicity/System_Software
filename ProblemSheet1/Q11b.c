#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd, fd1;
    char data[10];
  
    scanf("%s", data);
    
    fd = open("example.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    
    fd1 = dup2(fd,5);
    if (fd1 == -1) {
        perror("Error occured while  duplicating the file descp");
        close(fd);
        return 1;
    }

    // original file descriptor
    write(fd, data, sizeof(data));

    //     duplicated file descriptor
    write(fd1, data, sizeof(data));

  
    close(fd);
    close(fd1);

    return 0;
}

