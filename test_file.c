#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int     main(int argc, char **argv, char **envp)
{
    int stdout;
    stdout = open("output2.txt",O_WRONLY | O_CREAT);
     if(stdout < 0) 
        printf("Error opening the file\n"); 
    dup2(stdout,1);
    execve("/bin/echo", argv, envp);
    close(stdout);
    return (0);
}