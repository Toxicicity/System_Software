/* 
========================================================================================
Name : Q1c.c
Author: Subham Sourav
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date : 20-08-2024
========================================================================================
*/
echo -n "Enter the name for the FIFO pipe: "
read fname

if mkfifo "$fname"; then
    echo "FIFO pipe '$fname' created successfully."
    echo "Please open the pipe in read mode to retrieve the message."
    echo "Hello there, this message was written to the FIFO pipe!" > "$fname"
else
    echo "Failed to create the FIFO pipe."
fi



/*
    Sample Execution:

*/