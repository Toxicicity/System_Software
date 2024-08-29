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
