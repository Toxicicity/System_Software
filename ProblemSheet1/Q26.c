    /* 
    ========================================================================================
    Name : Q26.c
    Author: Subham Sourav
    Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
    Date : 29-08-2024
    ========================================================================================
    */
   
#include <stdio.h>

int main() {
    char buffer[100];

    printf("Received input: ");
    fgets(buffer, sizeof(buffer), stdin); // Read input from stdin
    printf("You entered: %s", buffer);

    return 0;
}



  /*
    Sample Execution:

   $ cc Q26.c
subham@subham-GF75:~/ProblemSheet1$ cc -o aa Q26a.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
Received input: qwerty
You entered: qwerty
subham@subham-GF75:~/ProblemSheet1$ ./aa
Received input: You entered: Hello from parent process
*/