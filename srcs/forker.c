/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:02:50 by jalcayne          #+#    #+#             */
/*   Updated: 2020/12/20 17:48:18 by jalcayne         ###   ########.fr       */
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

void	ft_one_pipe(t_list **mini, int ***fd, t_list **env, char **envp)
{
	int pid;
	int status;
	int i;
	t_list *mini_aux;

	i = 0;
	mini_aux = (*mini);
	pid = fork();
	if (pid == 0)  
	{
		close ((*fd)[i][READ_END]);
		dup2((*fd)[i][WRITE_END], STDOUT_FILENO);
		close((*fd)[i][WRITE_END]);
		ft_select_build_function_fork(mini_aux, env, envp);
		exit(0);
	}
	waitpid();

}

void	ft_forker(t_list **mini, int ***fd, t_list **env, char **envp)
{
	int		pid;
	int		status;
	int i;
	t_list *mini_aux;

	mini_aux = (*mini);
	i = 0;
/*
** Hijo 1
*/
	pid = fork();
	if (pid == 0)  
	{
		close ((*fd)[i][READ_END]);
		dup2((*fd)[i][WRITE_END], STDOUT_FILENO);
		close((*fd)[i][WRITE_END]);
		ft_select_build_function_fork(mini_aux, env, envp);
		exit(0);
	}
	wait(&status);
	mini_aux = mini_aux->next;
	i++;
	close((*fd)[i - 1][WRITE_END]);
	while ((*fd)[i] && (*fd)[i + 1] != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			close((*fd)[i][READ_END]);
			dup2((*fd)[i - 1][READ_END], STDIN_FILENO);
			close((*fd)[i - 1][READ_END]);
			dup2((*fd)[i][WRITE_END], STDOUT_FILENO);
			close((*fd)[i][WRITE_END]);
			ft_select_build_function_fork(mini_aux, env, envp);
			exit(0);
		}
		else
			wait(&status);
		mini_aux = mini_aux->next;
		close((*fd)[i - 1][READ_END]);
		close((*fd)[i][WRITE_END]);
		i++;
	}
	pid = fork();
	if (pid == 0)
	{
		dup2((*fd)[i][READ_END], STDIN_FILENO);
		close((*fd)[i][READ_END]);
		ft_select_build_function_fork(mini, env, envp);
		exit(0);
	}
	wait(&status);

}
