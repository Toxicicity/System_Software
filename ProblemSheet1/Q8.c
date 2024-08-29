#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define size 2048

int main() {
    int fd;
    ssize_t read_size;
    char buffer[size];
    char line[size];
    int j = 0;

    fd = open("NewFile3.txt", O_RDONLY);

    
    read_size = read(fd, buffer, size);
	    
        for (int i = 0; i < read_size; i++) {
            if (buffer[i] == '\n' || buffer[i] == '\r') {
              
                line[j] = '\0';  
                printf("%s\n", line);
	   sleep(1);	
                j = 0;                
            } else {
                
                line[j++] = buffer[i];
            }
        }
    

    
    close(fd);
    return 0;
}

