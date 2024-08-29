#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // File path and permission
    // New file will be created in present directory
    const char *f_path = "NewFile3.txt";
    int f_permissions = 0644; // Owner can read/write, others can read

    // Create the file 
    int f_d = creat(f_path, f_permissions);

    // Check 
    if (f_d == -1) {
        perror("Error creating the file");
        return 1;
    }

    // Print 
    printf("File desc: %d\n", f_d);

    // Close the file
    close(f_d);

    return 0;
}

