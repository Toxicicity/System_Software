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

