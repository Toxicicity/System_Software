    /* 
    ========================================================================================
    Name : Q22.c
    Author: Subham Sourav
    Description :     Write a program, open a file, call fork, and then write to the file by both the child as well as the
                    parent processes. Check output of the file.
    Date : 28-08-2024
    ========================================================================================
    */

    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include<string.h>

    int main() {
        int fd;
        pid_t pid;

        fd = open("output.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
        if (fd == -1) {
            perror("Error opening file");
            return 1;
        }

        pid = fork();

        if (pid == -1) {
        
            perror("fork failed");
            close(fd);
            return 1;
        } else if (pid == 0) {
            
            const char c_message[] = "This is the child process writing.\n";
            write(fd, c_message, strlen(c_message) );
        } else {
            
            const char *parent_m = "This is parent process writing.\n";
            write(fd, parent_m, strlen(parent_m)) ;
            
            
        
            wait(0);
        }

        
        close(fd);

        return 0;
    }


    /*
    Sample Execution:

    $  cc Q22.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
subham@subham-GF75:~/ProblemSheet1$ cat output.txt 
This is parent process writing.
This is the child process writing.
    */