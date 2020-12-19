/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:02:50 by jalcayne          #+#    #+#             */
/*   Updated: 2020/12/19 18:34:58 by jalcayne         ###   ########.fr       */
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

void	ft_forker(t_mini *mini, int ***fd, t_list **env, char **envp)
{
	int		pid;
	int		status;
	int i;

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
		ft_select_build_function_fork(mini, env, envp);
	}
}
