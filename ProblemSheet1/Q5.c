
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fds[5];
    const char *files[] = {"file100.txt", "file200.txt", "file300.txt", "file400.txt", "file500.txt"};

    
    for (int i = 0; i < 5; i++) {
        fds[i] = open(files[i], O_RDWR | O_CREAT, 0644);
        if (fds[i] == -1) {
            perror("Error opening file");
            return 1;
        }
        printf("File %s opened with descriptor %d\n", files[i], fds[i]);
    }

    
    while (1) {
        sleep(2); 
    }

   
    for (int i = 0; i < 5; i++) {
        close(fds[i]);
    }

    return 0;
}

