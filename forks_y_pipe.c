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
    int fd1[2], fd2[2];
    int status, pid;

    pipe(fd1);      /*pipe para comunicar ls y grep*/
    pid = fork();
    if (pid == 0) /*hijo 1*/
    {
        close(fd1[READ_END]); /*cierra extremo pipe no necesario*/

        dup2(fd1[write_END], STDOUT_FILENO);    /* lo que el comando ls escribe en stdout lo escribe tambien en fd1[write_end]*/
        close(fd1[write_END]);                  /*se cierra ese extremo porque no se va  a usar ya*/

        execlp("/bin/ls", "ls", "-l", NULL);
    }
    else    /*padre*/
    {
        close(fd1[write_END]); /* se cierra porque no se va a usar ya*/
        
        pipe(fd2);              /*comunica grep y wc*/
        pid = fork();
        
        if (pid == 0)           /*hijo 2*/
        {
            close(fd2[READ_END]);

            dup2(fd1[READ_END], STDIN_FILENO);
            close(fd1[READ_END]);

            dup2(fd2[write_END], STDOUT_FILENO);
            close (fd2[write_END]);

            execlp("/bin/grep", "grep", "u", NULL);
            }
        else /*padre*/
        {
            close (fd1[READ_END]); /*no necesario*/
            close (fd2[write_END]); /* no necesario*/

            pid = fork();
            if (pid == 0)
            {
                dup2(fd2[READ_END], STDIN_FILENO);
                close (fd2[READ_END]);

                execlp("/usr/bin/wc", "wc", "-l", NULL);
            }
        }
    
    }
    close(fd2[READ_END]);
    wait(&status);
    wait(&status);
    wait(&status);
    return (0);
    
}