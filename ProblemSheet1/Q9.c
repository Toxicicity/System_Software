/* 
========================================================================================
Name : Q9.c
Author: Subham Sourav
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date : 25-08-2024
========================================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    struct stat file_stat;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &file_stat) == -1) {
        perror("Error retrieving file status");
        return 1;
    }

    
    printf("Inode: %lu\n", file_stat.st_ino);
    printf("Number of hard links: %lu\n", file_stat.st_nlink);
    printf("UID: %u\n", file_stat.st_uid);
    printf("GID: %u\n", file_stat.st_gid);
    printf("Size: %ld bytes\n", file_stat.st_size);
    printf("Block size: %ld bytes\n", file_stat.st_blksize);
    printf("Number of blocks: %ld\n", file_stat.st_blocks);
    printf("Time of last access: %s", ctime(&file_stat.st_atime));
    printf("Time of last modification: %s", ctime(&file_stat.st_mtime));
    printf("Time of last change: %s", ctime(&file_stat.st_ctime));

    return 0;
}
/*
$ cc Q9.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
Usage: ./a.out <file_name>
*/
