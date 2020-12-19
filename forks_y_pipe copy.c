#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#define READ_END 0 //extremo de escritura
#define write_END 1 //extremo de lectura


int main (int argc, char **argv)
{
    int status, pid;
    int i;

    i = 0;
    pid = fork();
    i++;
    if (pid == 0) /*hijo 1\n*/
    {
        i++;
        exit(0);
    }
    else    /*padre*/
    {
                                

        pid = fork();
        i++;
        if (pid == 0)           /*hijo 2\n*/
        {
            i++;    
        }
        else /*padre*/
        {
            

            pid = fork();
            i++;
            if (pid == 0)
            {
          
            }
        }
    
    }
    printf("%d\n", i);
    wait(&status);
    wait(&status);
    wait(&status);
    return (0);
    
}