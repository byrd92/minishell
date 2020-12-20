/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_build_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:07:51 by jalcayne          #+#    #+#             */
/*   Updated: 2020/12/20 17:38:49 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    ft_select_build_function(t_list *mini,  t_list **env, char **envp)
{
   	t_mini *content;
	t_list *aux;
	int pid;
	int status;
	
	aux = mini;
	while (aux)
	{
		content = (t_mini *)aux->content;
		ft_printf("->%s\n" , content->argv[0]);
		if(ft_strncmp(content->argv[0], "echo\0", 6) == 0)
			ft_echo(env ,content->argv);
		else if(ft_strncmp(content->argv[0], "export\0", 7) == 0)
			ft_export(env, content->argv);
		else if(ft_strncmp(content->argv[0], "env\0", 4) == 0)
			ft_env(env);
		else if(ft_strncmp(content->argv[0], "unset\0", 6) == 0)
			ft_unset(env, content->argv);
		else if(ft_strncmp(content->argv[0], "pwd\0", 4) == 0)
			ft_pwd(env);
		else if(ft_strncmp(content->argv[0], "cd\0", 3) == 0)
			ft_cd(env, content->argv);
		else
		{
			pid = fork();
			if (pid == 0)
			{
				execve(ft_strjoin(search_path(env, content->argv[0]),ft_strjoin("/", content->argv[0])), content->argv, envp);
			}
			else
				wait(&status);
			
		}
		aux = aux->next;
	}
}

void    ft_select_build_function_fork(t_list *mini,  t_list **env, char **envp)
{
   	t_mini *content;
	int pid;
	int status;

	content = (t_mini *)mini->content;
	ft_printf("->%s\n" , content->argv[0]);
	if(ft_strncmp(content->argv[0], "echo\0", 6) == 0)
		ft_echo(env ,content->argv);
	else if(ft_strncmp(content->argv[0], "export\0", 7) == 0)
		ft_export(env, content->argv);
	else if(ft_strncmp(content->argv[0], "env\0", 4) == 0)
		ft_env(env);
	else if(ft_strncmp(content->argv[0], "unset\0", 6) == 0)
		ft_unset(env, content->argv);
	else if(ft_strncmp(content->argv[0], "pwd\0", 4) == 0)
		ft_pwd(env);
	else if(ft_strncmp(content->argv[0], "cd\0", 3) == 0)
		ft_cd(env, content->argv);
	else
		execve(ft_strjoin(search_path(env, content->argv[0]),ft_strjoin("/", content->argv[0])), content->argv, envp);	
	exit(0);
}