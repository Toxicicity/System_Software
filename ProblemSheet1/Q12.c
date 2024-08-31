/* 
========================================================================================
Name : Q12.c
Author: Subham Sourav
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date : 27-08-2024
========================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
int x= open("NewFile3.txt",O_RDONLY);
int mod=fcntl(x,F_GETFL);
printf("%d\n",mod);
}


/*
$ cc Q12.c
subham@subham-GF75:~/ProblemSheet1$ ./a.out
32768
*/