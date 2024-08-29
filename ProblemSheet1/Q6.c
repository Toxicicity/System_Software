#include <stdio.h>
#include <unistd.h>

#define size 2048

int main() {
    char buffer[size];
    ssize_t bytes_read;

    
    while ((bytes_read = read(STDIN_FILENO, buffer, size)) > 0) {
        
        write(STDOUT_FILENO, buffer, bytes_read);
    }
    if(bytes_read==0)
    {
	    perror("Every read has been succesfully printed");
    }

    if (bytes_read == -1) {
        perror("Error reading from STDIN");
        return 1;
    }

    return 0;
}

