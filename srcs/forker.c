/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia- <emilioggo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:02:50 by jalcayne          #+#    #+#             */
/*   Updated: 2020/12/28 15:59:40 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_create_pipes(int num_pipes, int ***fd)
{
	int i;

	i = 0;
	(*fd) = (int **)malloc(sizeof( int *) * num_pipes + 1);
	while (num_pipes > 0)
	{
		(*fd)[i] = (int *)malloc(sizeof(int) * 2);
		num_pipes--;
		i++;
	}
	(*fd)[i] = NULL;
	i = 0;
	while ((*fd)[i])
		pipe((*fd)[i]);
}


void	ft_forker(t_list **tokens, int pipes, t_list **env, char **envp)
{
	int **fd;
	int i;
	int pid;
	int status;
	t_list *aux;
	int j;


	j = 0;
	aux = (*tokens);
	i = 0;
	fd = (int **)malloc(sizeof(int *) * pipes);
	while(i < pipes)
	{
		fd[i] = (int *)malloc(sizeof(int) * 2);
		pipe(fd[i++]);
	}
	i = 0;
	pid = fork();
	if (pid == 0)
	{
		close(fd[i][READ_END]);
		dup2(fd[i][WRITE_END],STDOUT_FILENO);
		close(fd[i][WRITE_END]);
		ft_select_build_function_fork(aux, env, envp);
		exit(0);
	}
	else
	{
		close(fd[i][WRITE_END]);
		aux = aux->next;
		while (j < (pipes - 1))
		{
			pid = fork();
			if (pid == 0)
			{
				close(fd[i + 1][READ_END]);
				dup2(fd[i][READ_END],STDIN_FILENO);
				close(fd[i][READ_END]);
				dup2(fd[i + 1][WRITE_END], STDOUT_FILENO);
				close(fd[i + 1][WRITE_END]);
				ft_select_build_function_fork(aux, env, envp);
				exit(0);
			}
			close(fd[i][READ_END]);
			close(fd[i + 1][WRITE_END]);
			j++;
			aux = aux->next;
			i++;
		}
		pid = fork();
		if (pid == 0)
		{
			dup2(fd[i][READ_END], STDIN_FILENO);
			close(fd[i][READ_END]);
			ft_select_build_function_fork(aux, env, envp);
			exit(0);
		}
	}
	j = 0;
	wait(&status);
	while (j < (pipes - 2))
		wait(&status);
	wait(&status);

}


/*int processes = 5;
int i;
for (i = 0; i < processes; ++i) {
    if (fork() == 0) {
        // do the job specific to the child process
        ...
        // don't forget to exit from the child
        exit(0);
    }
}
// wait all child processes
int status;
for (i = 0; i < processes; ++i)
    wait(&status);*/