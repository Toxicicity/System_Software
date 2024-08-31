/* 
========================================================================================
Name : Q13.c
Author: Subham Sourav
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select)
Date : 27-08-2024
========================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set fds;
    struct timeval timeout;
    int ret;

    // Clear the set and add STDIN (file descriptor 0) to it
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    // Set the timeout to 10 seconds
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input on STDIN for 10 seconds \n");

    // Wait for input on STDIN using select
    ret = select(STDIN_FILENO + 1, &fds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select failed");
        return 1;
    } else if (ret == 0) {
        printf("No data was available within 10 seconds.\n");
    } else {
       // if (FD_ISSET(STDIN_FILENO, &readfds)) {
            char input_data[500];
            ssize_t b_read;

            b_read = read(STDIN_FILENO, input_data, sizeof(input_data) - 1);
            if (b_read > 0) {
                input_data[b_read] = '\0';
                printf("Data received: %s\n", input_data);
            } else {
                perror("read failed");
            }
       // }
    }

    return 0;
}


/*
$ cc Q13.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
Waiting for input on STDIN for 10 seconds 
hdhdh
Data received: hdhdh
*/
