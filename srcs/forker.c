/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:02:50 by jalcayne          #+#    #+#             */
/*   Updated: 2020/12/22 15:09:38 by jalcayne         ###   ########.fr       */
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

static void	ft_one_pipe(t_list **mini, t_list **env, char **envp)
{
	int	status;
	int	fd[2];
	int pid;
	t_list	*aux;
	aux = (*mini);

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close (fd[READ_END]);
		dup2(fd[WRITE_END],STDOUT_FILENO);
		close(fd[WRITE_END]);
		ft_select_build_function_fork(aux, env, envp);
		exit(0);
	}
	else
	{
		aux = aux->next;
		close(fd[WRITE_END]);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd[READ_END], STDIN_FILENO);
			close(fd[READ_END]);
			ft_select_build_function_fork(aux, env, envp);
			exit(0);
			//execlp("/usr/bin/wc", "wc", "-l", NULL);

		}
	}
	close(fd[READ_END]);
	wait(&status);
	wait(&status);
	return ;

}

void	ft_forker(t_list **mini, int pipes, t_list **env, char **envp)
{
	if (pipes == 1)
	{
		ft_one_pipe(mini, env, envp);
	}
	
}
