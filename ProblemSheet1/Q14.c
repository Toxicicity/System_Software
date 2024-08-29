#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

void print_file_type(struct stat *file_stat) {
    if (S_ISREG(file_stat->st_mode)) {
        printf("This is a regular file.\n");
    } else if (S_ISDIR(file_stat->st_mode)) {
        printf("This is  a directory.\n");
    } else if (S_ISCHR(file_stat->st_mode)) {
        printf("This is  a character device.\n");
    } else if (S_ISBLK(file_stat->st_mode)) {
        printf("Thegiven file is a block device.\n");
    } else if (S_ISFIFO(file_stat->st_mode)) {
        printf("The file is a FIFO (named pipe).\n");
    } else if (S_ISLNK(file_stat->st_mode)) {
        printf("The file is a symbolic link.\n");
    } else if (S_ISSOCK(file_stat->st_mode)) {
        printf("The file is a socket.\n");
    } else {
        printf("unknow type of file.\n");
    }
}

int main(int argc, char *argv[]) {
    struct stat file_stat;

                     // Check if the number of arguments is correct
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

                 // Get file status using stat()
    if (lstat(argv[1], &file_stat) == -1) {
        perror("Error getting file status");
        return 1;
    }

    
    print_file_type(&file_stat);

    return 0;
}

