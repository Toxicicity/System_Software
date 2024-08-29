#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
int x= open("NewFile3.txt",O_RDONLY);
int mod=fcntl(x,F_GETFL);
printf("%d\n",mod);
}
