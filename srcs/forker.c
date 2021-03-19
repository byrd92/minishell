/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:28:14 by jalcayne          #+#    #+#             */
/*   Updated: 2019/11/06 15:30:57 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	first_fork(int ***fd, t_list **aux, t_env_envp *aux2)
{
	close((*fd)[0][READ_END]);
	dup2((*fd)[0][WRITE_END], STDOUT_FILENO);
	close((*fd)[0][WRITE_END]);
	ft_select_build_function_fork((*aux), aux2->env, aux2->envp);
	exit(0);
}

static void	while_fork(int ***fd, t_list **aux, t_env_envp *aux2, int i)
{
	if (!fork())
	{
		close((*fd)[i + 1][READ_END]);
		dup2((*fd)[i][READ_END], STDIN_FILENO);
		close((*fd)[i][READ_END]);
		dup2((*fd)[i + 1][WRITE_END], STDOUT_FILENO);
		close((*fd)[i + 1][WRITE_END]);
		exit(ft_select_build_function_fork((*aux), aux2->env, aux2->envp));
	}
	close((*fd)[i][READ_END]);
	close((*fd)[i + 1][WRITE_END]);
}

static void	middle_fork(int ***fd, t_list **aux, t_env_envp *aux2, int pipes)
{
	int i;
	int j;

	i = 0;
	j = 0;
	close((*fd)[i][WRITE_END]);
	(*aux) = (*aux)->next;
	while (j < (pipes - 1))
	{
		while_fork(fd, aux, aux2, i);
		j++;
		(*aux) = (*aux)->next;
		i++;
	}
	if (!fork())
	{
		dup2((*fd)[i][READ_END], STDIN_FILENO);
		close((*fd)[i][READ_END]);
		ft_select_build_function_fork((*aux), aux2->env, aux2->envp);
		exit(0);
	}
}

int			ft_forker(t_mini *mini, int pipes, t_list **env, char **envp)
{
	int			**fd;
	t_list		*aux;
	int			j;
	t_env_envp	aux2;

	aux2.env = env;
	aux2.envp = envp;
	aux = mini->tokens;
	create_pipe(pipes, &fd);
	if (!fork())
		first_fork(&fd, &aux, &aux2);
	else
		middle_fork(&fd, &aux, &aux2, pipes);
	j = 0;
	wait(&mini->dolar);
	while (j++ < (pipes - 1))
		wait(&mini->dolar);
	wait(&mini->dolar);
	mini->dolar /= 256;
	j = 0;
	while (j < pipes)
		free(fd[j++]);
	free(fd);
	return (mini->dolar);
}
