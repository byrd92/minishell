#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int     main(void)
{
    int stdout1;
    int stdout2;
    int stdoutback;
    stdout1 = open("out1.txt",O_WRONLY | O_CREAT);
    stdout2 = open("out2.txt",O_WRONLY | O_CREAT);
     if(stdout1 < 0) 
        printf("Error opening the file\n");
    stdoutback = dup(1);
    dup2(stdout1,1);
    dup2(stdout2,1);
    printf("hola files");
    close (stdout1);
    return (0);
}