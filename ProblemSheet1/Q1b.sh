/* 
========================================================================================
Name : Q1b.c
Author: Subham Sourav
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date : 20-08-2024
========================================================================================
*/


echo -n "enter the path : ";
read fname;
echo -n "enter link name: ";
read hlname;
if ln $fname $hlname
then
    echo "success";
else
    echo "failed";
fi



/*
    Sample Execution:


*/