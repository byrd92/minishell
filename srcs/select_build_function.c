/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_build_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcayne <jalcayne@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:07:51 by jalcayne          #+#    #+#             */
/*   Updated: 2021/01/19 12:02:48 by jalcayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int    ft_select_build_function(t_mini *mini,  t_list **env, char **envp)
{
   	t_token *content;
	t_list *aux;
	int pid;
	int status;
	char *comando;

	aux = mini->tokens;
	while (aux)
	{
		content = (t_token *)aux->content;
		//ft_printf("->%s\n" , content->argv[1]);
		if(ft_strncmp(content->argv[0], "echo\0", 6) == 0)
			return (ft_echo(env ,content->argv));
		else if(ft_strncmp(content->argv[0], "export\0", 7) == 0)
			return (ft_export(env, content->argv[1]));
		else if(ft_strncmp(content->argv[0], "env\0", 4) == 0)
			return (ft_env(env));
		else if(ft_strncmp(content->argv[0], "unset\0", 6) == 0)
			return (ft_unset(env, content->argv));
		else if(ft_strncmp(content->argv[0], "pwd\0", 4) == 0)
			return (ft_pwd(env));
		else if(ft_strncmp(content->argv[0], "cd\0", 3) == 0)
			return (ft_cd(env, content->argv));
		else if (ft_strncmp(content->argv[0], "exit\0", 5) == 0)
			ft_exit(mini, env);
		else if (ft_strncmp(content->argv[0], "/", 1) == 0 ||
				ft_strncmp(content->argv[0], "./", 2) == 0 ||
				ft_strncmp(content->argv[0], "../", 3) == 0)
		{

					pid = fork();
					if (pid == 0)
					{
						execve(content->argv[0], content->argv, envp);
					}
					else
					wait(&status);
					return (0);

		}
		else
		{
			ft_printf("%s: command not found\n", content->argv[0]);
			return (127);
		}
		
		aux = aux->next;
	}
	return (0);
}

void    ft_select_build_function_fork(t_list *mini,  t_list **env, char **envp)
{
   	t_token *content;
	
	content = (t_token *)mini->content;
	if(ft_strncmp(content->argv[0], "echo\0", 6) == 0)
		ft_echo(env ,content->argv);
	else if(ft_strncmp(content->argv[0], "export\0", 7) == 0)
		ft_export(env, content->argv[1]);
	else if(ft_strncmp(content->argv[0], "env\0", 4) == 0)
		ft_env(env);
	else if(ft_strncmp(content->argv[0], "unset\0", 6) == 0)
		ft_unset(env, content->argv);
	else if(ft_strncmp(content->argv[0], "pwd\0", 4) == 0)
		ft_pwd(env);
	else if(ft_strncmp(content->argv[0], "cd\0", 3) == 0)
		ft_cd(env, content->argv);
	else if (ft_strncmp(content->argv[0], "exit\0", 5) == 0)
		;
	else if (search_path(env, content->argv[0]))
		execve(ft_strjoin(search_path(env, content->argv[0]),ft_strjoin("/", content->argv[0])), content->argv, envp);
	else
	{
		ft_printf("%s: command not found\n", content->argv[0]);
	}
	/*else
	{
		execve(ft_strjoin(search_path(env, content->argv[0]),ft_strjoin("/", content->argv[0])), content->argv, envp);
	}*/
	
	exit(0);
}