#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


void    ft_alter(char *str)
{
    str = strdup("OTRA COSA");
}
int     main(int argc, char **argv, char **envp)
{
    int stdout;
    /*
    stdout = open("output2.txt",O_WRONLY | O_CREAT);
     if(stdout < 0) 
        printf("Error opening the file\n"); 
    dup2(stdout,1);
    */
   
    pid_t pid = fork();
    return (0);
}